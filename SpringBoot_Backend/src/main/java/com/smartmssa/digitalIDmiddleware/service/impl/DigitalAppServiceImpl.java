package com.smartmssa.digitalIDmiddleware.service.impl;

import com.opencsv.CSVWriter;
import com.smartmssa.digitalIDmiddleware.client.AnrptsClient;
import com.smartmssa.digitalIDmiddleware.client.CasIdpClient;
import com.smartmssa.digitalIDmiddleware.client.IdEncodeClient;
import com.smartmssa.digitalIDmiddleware.client.OpenAmClient;
import com.smartmssa.digitalIDmiddleware.config.RsaEncryptionConfig;
import com.smartmssa.digitalIDmiddleware.dto.*;
import com.smartmssa.digitalIDmiddleware.model.QrCode;
import com.smartmssa.digitalIDmiddleware.model.QrCodeSession;
import com.smartmssa.digitalIDmiddleware.model.User;
import com.smartmssa.digitalIDmiddleware.repository.QrCodeRepository;
import com.smartmssa.digitalIDmiddleware.repository.QrCodeSessionRepository;
import com.smartmssa.digitalIDmiddleware.repository.UserRepository;
import com.smartmssa.digitalIDmiddleware.service.DigitalAppService;
import com.smartmssa.digitalIDmiddleware.utils.Credentials;
import org.apache.commons.codec.digest.DigestUtils;
import org.keycloak.OAuth2Constants;
import org.keycloak.admin.client.Keycloak;
import org.keycloak.admin.client.KeycloakBuilder;
import org.keycloak.admin.client.resource.RealmResource;
import org.keycloak.admin.client.resource.UserResource;
import org.keycloak.admin.client.resource.UsersResource;
import org.keycloak.representations.idm.CredentialRepresentation;
import org.keycloak.representations.idm.UserRepresentation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.mock.web.MockMultipartFile;
import org.springframework.stereotype.Service;
import org.springframework.util.Base64Utils;
import org.springframework.web.multipart.MultipartFile;

import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;
import java.io.*;
import java.security.Key;
import java.security.SecureRandom;
import java.security.Signature;
import java.time.Instant;
import java.util.*;

@Service
public class DigitalAppServiceImpl implements DigitalAppService {

    @Autowired
    private AnrptsClient anrptsClient;
    @Autowired
    private IdEncodeClient idEncodeClient;
    @Autowired
    private CasIdpClient casIdpClient;
    @Autowired
    private OpenAmClient openAmClient;
    @Autowired
    private UserRepository userRepository;
    @Autowired
    private QrCodeSessionRepository qrCodeSessionRepository;
    @Autowired
    private QrCodeRepository qrCodeRepository;

    @Value("${admin.keycloak.auth.url}")
    private String serverUrl;
    @Value("${keycloak.realm}")
    private String realm;
    @Value("${keycloak.resource}")
    private String clientId;
    @Value("${admin.keycloak.credentials.secret}")
    private String clientSecret;
    @Value("${user.keycloak.username}")
    private String kcusername;
    @Value("${user.keycloak.password}")
    private String kcpassword;

    private final String secretKey = "TkrL!%6*XitaZ@$-m28_&bHYW&i%ZFKQ";


    //Set up keycloak Admin REST API
    private Keycloak getInstance() {
        return KeycloakBuilder.builder().serverUrl(serverUrl)
                .realm(realm).grantType(OAuth2Constants.PASSWORD).clientId(clientId).clientSecret(clientSecret).username(kcusername).password(kcpassword).build();
    }

    /**
     * API to get the cryptography
     * **/
    @Override
    public ResponseEntity<?> getCryptography(UserAttributesDto userAttributesDto) {

        String data = userAttributesDto.getPin() + "," + userAttributesDto.getFirstName() + "," +
                userAttributesDto.getLastName() + "," + userAttributesDto.getBirthDate();
        // Data hash
        String dataHash = DigestUtils.sha256Hex(data);
        // Encrypt the hash
        String encryptedDataHash = null;
        try {
            RsaEncryptionConfig rsaEncryptionConfig = new RsaEncryptionConfig();
            Signature signature = rsaEncryptionConfig.getInitSignature();
            signature.update(dataHash.getBytes());
            byte[] ds = signature.sign();
            encryptedDataHash = Base64.getEncoder().encodeToString(ds);
        } catch (Exception e) {
           return new ResponseEntity<>(new FailureResponseDto("Data hash encryption failed!"), HttpStatus.BAD_REQUEST);
        }

        // Build Idencode cryptography content
        CryptographyContentDto cryptographyContentDto = new CryptographyContentDto(userAttributesDto.getFaceTemplate(),encryptedDataHash,data);
        List<MultipartFile> idEncodeRequestFiles = loadIdEncodeCryptographyParams(cryptographyContentDto);

        if(idEncodeRequestFiles == null) {
            return new ResponseEntity<>(new FailureResponseDto("IdEncode cryptography content failed!"), HttpStatus.BAD_REQUEST);
        }

        // Send cryptography content to IdEncode server
        CryptographyDto idEncodeCryptographyReusult = sentDataToIdEncode(idEncodeRequestFiles, encryptedDataHash);
        if(idEncodeCryptographyReusult == null)
            return new ResponseEntity<>(new FailureResponseDto("IdEncode cryptography generation failed!"), HttpStatus.BAD_REQUEST);
        return new ResponseEntity<>(idEncodeCryptographyReusult, HttpStatus.OK);
    }

    private List<MultipartFile> loadIdEncodeCryptographyParams(CryptographyContentDto cryptographyContentDto){
        try {
            InputStream pipeline = new ClassPathResource("/idencode/pipeline.json").getInputStream();
            //Add user attributes to demog file
            addUserAttributesToDemogFile(cryptographyContentDto.getData());
            InputStream demog = new FileInputStream(addUserAttributesToDemogFile(cryptographyContentDto.getData()));
            byte[] faceTemplate = Base64.getDecoder().decode(cryptographyContentDto.getFaceTemplate());
            InputStream faceTemplateIS = new ByteArrayInputStream(faceTemplate);
            byte[] byteArray = Base64.getDecoder().decode(cryptographyContentDto.getEncryptedDataHash());
            InputStream dsis = new ByteArrayInputStream(byteArray);
            MockMultipartFile ds = new MockMultipartFile("digital_signature", "digital_signature", "application/octet-stream", dsis);
            MockMultipartFile pipelineFile = new MockMultipartFile("pipeline", "pipeline.json", "application/json", pipeline);
            MockMultipartFile demogFile = new MockMultipartFile("demog", "demog.csv", "application/octet-stream", demog);
            MockMultipartFile faceTemplateFile = new MockMultipartFile("face_template", "face_template", "application/octet-stream", faceTemplateIS);
            return Arrays.asList(new MockMultipartFile[]{faceTemplateFile,pipelineFile,demogFile,ds});
        }catch (Exception e){
            System.err.println(e.getMessage());
            return null;
        }
    }

    private File addUserAttributesToDemogFile(String attributes) throws IOException {
        File path = new File("demog.csv");
        FileWriter fileWriter = new FileWriter(path);
        CSVWriter csvWriter = new CSVWriter(fileWriter);
        csvWriter.writeNext(attributes.split(","));
        csvWriter.close();
        fileWriter.close();
        return path;
    }
    @Override
    public String getRsaPublicKey() {
        try {
            Resource resource = new ClassPathResource("/rsakeys/publicKey");
            if (resource.exists() || resource.isReadable()) {
                return Base64Utils.encodeToString(resource.getInputStream().readAllBytes());
            } else {
                return null;
            }
        } catch (Exception e) {
            System.err.println(e.getMessage());
            return null;
        }
    }


    @Override
    public ResponseEntity<?> addUserToCas(CasUserDto casUserDto) {
        try{
            ResponseEntity<CasUserDto> casUserRegisterResult = casIdpClient.addUserToCas(casUserDto);
            return new ResponseEntity<>(casUserRegisterResult.getBody(), HttpStatus.OK);
        }catch (Exception e){
            System.err.println(e.getMessage());
            return new ResponseEntity<>(new FailureResponseDto("Regsiter user to cas failed"), HttpStatus.BAD_REQUEST);
        }
    }
    private CryptographyDto sentDataToIdEncode(List<MultipartFile> files, String hashedData){
        try{
            IdEncodeSendCryptographyDto idEncodeSendCryptographyDto = new IdEncodeSendCryptographyDto();
            idEncodeSendCryptographyDto.setFace_template(files.get(0));
            idEncodeSendCryptographyDto.setPipeline(files.get(1));
            idEncodeSendCryptographyDto.setDemog(files.get(2));
            idEncodeSendCryptographyDto.setDigital_signature(files.get(3));
            ResponseEntity<CryptographyDto> cryptographyResult = idEncodeClient.getCryptography(idEncodeSendCryptographyDto);
            return cryptographyResult.getBody();
        }catch (Exception e){
            System.err.println(e.getMessage());
            return null;
        }
    }

    @Override
    public ResponseEntity<?> registerOpenAmUser(RegisterUserDto registerOpenAmUserDto){
        try {
            Optional<User> user = userRepository.findByUsername(registerOpenAmUserDto.getPin());

            if(user.isPresent()){
                String password = passwordEncryption(user.get().getPassword(), false);
                return new ResponseEntity<>(new UserRegistrationResponseDto(password), HttpStatus.OK);
            }

            OpenAmUserDto openAmUserDto = new OpenAmUserDto();
            openAmUserDto.setUsername(registerOpenAmUserDto.getPin());
            openAmUserDto.setGivenName(registerOpenAmUserDto.getFirstName());
            String password = generatePassword(registerOpenAmUserDto.getPin());
            openAmUserDto.setUserPassword(password);
            System.err.println(password);
            openAmUserDto.setInetUserStatus("Active");
            OpenAmUserRegistrationDto openAmUserRegistrationDto = new OpenAmUserRegistrationDto(openAmUserDto);
            OpenUserRegistrationPayloadDto payloadDto = new OpenUserRegistrationPayloadDto(openAmUserRegistrationDto);
            ResponseEntity<OpenAmResponseDto> openAmUserRegistrationResponse = openAmClient.registerUserToOpenAm(payloadDto);
            if(openAmUserRegistrationResponse.getStatusCode() == HttpStatus.OK) {
                String pass = passwordEncryption(password, true);
                User newUser = new User();
                newUser.setUsername(registerOpenAmUserDto.getPin());
                newUser.setPassword(pass);
                userRepository.save(newUser);
                return new ResponseEntity<>(new UserRegistrationResponseDto(password), HttpStatus.OK);
            }
            return new ResponseEntity<>(new FailureResponseDto("User registration Failed"), HttpStatus.BAD_REQUEST);
        }catch (Exception e){
            System.err.println(e.getMessage());
            return new ResponseEntity<>(new FailureResponseDto("User registration Failed"), HttpStatus.BAD_REQUEST);
        }
    }

    @Override
    public ResponseEntity getQrCodeString(){
        int length = 140;
        SecureRandom random = new SecureRandom();
        byte[] bytes = new byte[length];
        random.nextBytes(bytes);
        String randomString = Base64.getUrlEncoder().encodeToString(bytes).substring(0, length);
        QrCode qrCode =  new QrCode();
        qrCode.setValue(randomString);
        qrCodeRepository.save(qrCode);
        return new ResponseEntity(new QrCodeDto(randomString),HttpStatus.OK);
    }

    @Override
    public ResponseEntity getCredentials(QrCodeDto qrCodeDto) throws Exception {
        try {
            Optional<QrCodeSession> qrCodeSession = qrCodeSessionRepository.findByQrAuthAndCreatedAtGreaterThan(qrCodeDto.getValue(), Instant.now().minusSeconds(300));
            if (qrCodeSession.isEmpty()) {
                return new ResponseEntity(new FailureResponseDto("AUTH_REFRENCED_INVALID"), HttpStatus.NO_CONTENT);
            }
            Optional<User> user = ckeckIfUserExist(qrCodeSession.get().getUsername());

            if (user.isEmpty()) {
                return new ResponseEntity(new FailureResponseDto("USER_NOT_FOUND"), HttpStatus.NO_CONTENT);
            }
            QrCodeResponseDto qrCodeResponseDto = new QrCodeResponseDto();
            String password = passwordEncryption(user.get().getPassword(), false);
            qrCodeResponseDto.setUsername(user.get().getUsername());
            qrCodeResponseDto.setValue(password);
            removeExpiredSessions(qrCodeDto);
            return new ResponseEntity(qrCodeResponseDto, HttpStatus.OK);
        }catch (Exception e){
            System.err.println("Get Creden Error" + e.getMessage()) ;
            return new ResponseEntity(new FailureResponseDto("ERROR_OCCURRED"), HttpStatus.NO_CONTENT);
        }
    }

    @Override
    public ResponseEntity establishQrCodeSession(QrCodeEstablishConnectionDto qrCodeEstablishConnectionDto) {
        try {
            qrCodeRepository.deleteByCreatedAtLessThan(Instant.now().minusSeconds(360));
            QrCodeSession qrCodeSession = new QrCodeSession();
            Optional<User> user = ckeckIfUserExist(qrCodeEstablishConnectionDto.getUsername());

            if (user.isEmpty()) {
                return new ResponseEntity(new FailureResponseDto("USER_NOT_FOUND"), HttpStatus.BAD_REQUEST);
            }
            Optional<QrCode> qrCodeCheck = qrCodeRepository.findByValueAndCreatedAtGreaterThan(qrCodeEstablishConnectionDto.getQrAuth(),Instant.now().minusSeconds(300));
            if(qrCodeCheck.isEmpty()){
                return new ResponseEntity(new FailureResponseDto("QRCODE_EXPIRED"), HttpStatus.BAD_REQUEST);
            }

            Optional<QrCodeSession> qrCode = qrCodeSessionRepository.findByQrAuthAndCreatedAtGreaterThan(qrCodeEstablishConnectionDto.getQrAuth(), Instant.now().minusSeconds(300));
            if (qrCode.isPresent()) {
                return new ResponseEntity(new QrCodeEstablishConnectionDto(qrCodeEstablishConnectionDto, qrCode.get().getCreatedAt()), HttpStatus.OK);
            }
            qrCodeSession.setUsername(qrCodeEstablishConnectionDto.getUsername());
            qrCodeSession.setQrAuth(qrCodeEstablishConnectionDto.getQrAuth());
            QrCodeSession qrCodeSessionSave =  qrCodeSessionRepository.save(qrCodeSession);
            return new ResponseEntity(new QrCodeEstablishConnectionDto(qrCodeEstablishConnectionDto,qrCodeSessionSave.getCreatedAt()), HttpStatus.OK);
        }catch (Exception e){
            System.err.println("Establish Session Error" + e.getMessage()) ;
            return new ResponseEntity(new FailureResponseDto("SESSION_FAILED"), HttpStatus.BAD_REQUEST);
        }
    }

    private Optional<User> ckeckIfUserExist(String username){
        RealmResource realmResource = getInstance().realm(realm);
        List<UserRepresentation> searchUsers = getInstance().realm(realm).users()
                .search(username);
        Optional<User> user = userRepository.findByUsername(username);
        if(user.isPresent() && searchUsers.size() != 0)
            return user;
        return Optional.empty();
    }

    @Override
    public ResponseEntity addUserToKeycloak(RegisterUserDto registerUserDto) {
        try{
            RealmResource realmResource = getInstance().realm(realm);
            Optional<User> user = userRepository.findByUsername(registerUserDto.getPin());
            List<UserRepresentation> searchUsers = getInstance().realm(realm).users()
                    .search(registerUserDto.getPin());

            if(user.isPresent()){
                if(searchUsers.isEmpty()){
                    userRepository.deleteByUsername(registerUserDto.getPin());
                }else {
                    String password = passwordEncryption(user.get().getPassword(), false);
                    return new ResponseEntity<>(new UserRegistrationResponseDto(password), HttpStatus.OK);
                }
            }

            String password = generatePassword(registerUserDto.getPin());

            if(searchUsers.size() != 0 ){
                UserRepresentation userRepresentation = realmResource.users().get(searchUsers.get(0).getId()).toRepresentation();
                CredentialRepresentation credential = Credentials
                        .createPasswordCredentials(password);
                userRepresentation.setCredentials(Collections.singletonList(credential));
                realmResource.users().get(searchUsers.get(0).getId()).update(userRepresentation);
                User newUser = new User();
                newUser.setUsername(registerUserDto.getPin());
                newUser.setPassword(passwordEncryption(password, true));
                userRepository.save(newUser);
                return new ResponseEntity<>(new UserRegistrationResponseDto(password), HttpStatus.OK);
            }

            CredentialRepresentation credential = Credentials
                    .createPasswordCredentials(password);
            UserRepresentation kcUser = new UserRepresentation();
            kcUser.setUsername(registerUserDto.getPin());
            kcUser.setFirstName(registerUserDto.getFirstName());
            kcUser.setLastName(registerUserDto.getLastName());
            kcUser.setEmail(registerUserDto.getPin().concat("-change-email@email.com"));
            kcUser.setCredentials(Collections.singletonList(credential));
            kcUser.setEnabled(true);
            UsersResource instance = getInstance().realm(realm).users();
            instance.create(kcUser);
            List<UserRepresentation> searchUser = getInstance().realm(realm).users()
                    .search(registerUserDto.getPin());
            UserResource userResource = realmResource.users().get(searchUser.get(0).getId());
            UserRepresentation userRepresentation = userResource.toRepresentation();
            var group = realmResource.groups().groups().stream().filter(
                    groupRepresentation -> groupRepresentation.getName().equals("citizens")).findAny().get();
            var defaultGroup = realmResource.groups().groups().stream().filter(
                    groupRepresentation -> groupRepresentation.getName().equals("default")).findAny().get();
            Map<String, List<String>> map = new HashMap<>();
            map.put("nni", Arrays.asList(registerUserDto.getPin()));
            map.put("birthDate", Arrays.asList(registerUserDto.getBirthDate()));
            userRepresentation.setAttributes(map);
            userResource.leaveGroup(defaultGroup.getId());
            userResource.joinGroup(group.getId());
            userResource.update(userRepresentation);
            String pass = passwordEncryption(password, true);
            User newUser = new User();
            newUser.setUsername(registerUserDto.getPin());
            newUser.setPassword(pass);
            userRepository.save(newUser);
            return new ResponseEntity<>(new UserRegistrationResponseDto(password), HttpStatus.OK);
        }catch (Exception e){
            System.err.println("Adding user to keycloak = " + e.getMessage());
            return new ResponseEntity<>(new FailureResponseDto("User registration Failed"), HttpStatus.BAD_REQUEST);

        }
    }

    private void removeExpiredSessions(QrCodeDto qrCodeDto) {
        qrCodeSessionRepository.deleteByQrAuth(qrCodeDto.getValue());
    }

    private String generatePassword(String pin) {
        String upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String lowerCase = "abcdefghijklmnopqrstuvwxyz";
        String values = upperCase + lowerCase + pin;

        SecureRandom random = new SecureRandom();
        char[] password = new char[8];
        for (int i = 0; i < 8; i++) {
            password[i] = values.charAt(random.nextInt(values.length()));
        }
        return new String(password);
    }

    private String passwordEncryption(String password, boolean toBeEncrypted) throws Exception{
        Key aesKey = new SecretKeySpec(secretKey.getBytes(), "AES");
        Cipher cipher = Cipher.getInstance("AES");
        if(toBeEncrypted){
            cipher.init(Cipher.ENCRYPT_MODE, aesKey);
            byte[] encrypted = cipher.doFinal(password.getBytes());
            Base64.Encoder encoder = Base64.getEncoder();
            String encryptedString = encoder.encodeToString(encrypted);
            return encryptedString;
        }else{
            Base64.Decoder decoder = Base64.getDecoder();
            cipher.init(Cipher.DECRYPT_MODE, aesKey);
            String decrypted = new String(cipher.doFinal(decoder.decode(password)));
            return decrypted;
        }
    }
}

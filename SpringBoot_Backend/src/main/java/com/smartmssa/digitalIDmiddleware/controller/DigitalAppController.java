package com.smartmssa.digitalIDmiddleware.controller;

import com.smartmssa.digitalIDmiddleware.controller.api.DigitalAppControllerApi;
import com.smartmssa.digitalIDmiddleware.dto.*;
import com.smartmssa.digitalIDmiddleware.service.DigitalAppService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RestController;


@RestController
public class DigitalAppController implements DigitalAppControllerApi {
    @Autowired
    private DigitalAppService digitalAppService;

    @Override
    public ResponseEntity<?> getCryptography(UserAttributesDto userAttributesDto) {
        return digitalAppService.getCryptography(userAttributesDto);
    }

    @Override
    public ResponseEntity<?> addUserToCas(CasUserDto casUserDto) {
        return digitalAppService.addUserToCas(casUserDto);
    }

    @Override
    public ResponseEntity<?> addUserToOpenAm(RegisterUserDto registerOpenAmUserDto) {
        return digitalAppService.registerOpenAmUser(registerOpenAmUserDto);
    }

    @Override
    public ResponseEntity<?> getRsaPublicKey(){
        String publicKey = digitalAppService.getRsaPublicKey();
        if(publicKey == null)
            return new ResponseEntity<>(new FailureResponseDto("Public key not available!"), HttpStatus.BAD_REQUEST);
        return new ResponseEntity<>(new PublicKeyDto(publicKey), HttpStatus.OK);
    }

    @Override
    public ResponseEntity establishQrCodeSession(QrCodeEstablishConnectionDto qrCodeEstablishConnectionDto) {
        return digitalAppService.establishQrCodeSession(qrCodeEstablishConnectionDto);
    }

    @Override
    public ResponseEntity addUserToKeycloak(RegisterUserDto registerUserDto) {
        return digitalAppService.addUserToKeycloak(registerUserDto);
    }

    @Override
    public ResponseEntity getQrCodeString() {
        return digitalAppService.getQrCodeString();
    }

    @Override
    public ResponseEntity getCredentials(QrCodeDto qrCodeDto) throws Exception {
        return digitalAppService.getCredentials(qrCodeDto);
    }

}

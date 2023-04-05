package com.smartmssa.digitalIDmiddleware.service;


import com.smartmssa.digitalIDmiddleware.dto.*;
import org.springframework.http.ResponseEntity;

public interface DigitalAppService {
    ResponseEntity<?> getCryptography(UserAttributesDto userAttributesDto);

    String getRsaPublicKey();

    ResponseEntity<?> addUserToCas(CasUserDto casUserDto);

    ResponseEntity<?> registerOpenAmUser(RegisterUserDto registerOpenAmUserDto);

    ResponseEntity getCredentials(QrCodeDto qrCodeDto) throws Exception;

    ResponseEntity establishQrCodeSession(QrCodeEstablishConnectionDto qrCodeEstablishConnectionDto);

    ResponseEntity getQrCodeString();

    ResponseEntity addUserToKeycloak(RegisterUserDto registerUserDto);
}

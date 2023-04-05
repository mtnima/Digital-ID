package com.smartmssa.digitalIDmiddleware.controller.api;

import com.smartmssa.digitalIDmiddleware.dto.*;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import static com.smartmssa.digitalIDmiddleware.utils.Constants.app;
import javax.validation.Valid;
@CrossOrigin("*")
public interface DigitalAppControllerApi {
    @PostMapping(value = app + "/getCryptography")
    ResponseEntity<?> getCryptography(@Valid @RequestBody UserAttributesDto userAttributesDto);
    @PostMapping(app + "/registerCasUser")
    ResponseEntity<?> addUserToCas(@Valid @RequestBody CasUserDto casUserDto);

    @PostMapping(app + "/registerUser")
    ResponseEntity<?> addUserToOpenAm(@Valid @RequestBody RegisterUserDto registerOpenAmUserDto);
    @GetMapping(app + "/getPublicKey")
    ResponseEntity<?> getRsaPublicKey();
    @PostMapping("/getValues")
    ResponseEntity getCredentials(@Valid @RequestBody QrCodeDto qrCodeDto) throws Exception;

    @PostMapping(app + "/establishConnection")
    ResponseEntity establishQrCodeSession(@Valid @RequestBody QrCodeEstablishConnectionDto qrCodeEstablishConnectionDto);

    @PostMapping(app + "/addUser")
    ResponseEntity addUserToKeycloak(@Valid @RequestBody RegisterUserDto registerUserDto);

    @PostMapping("/getQrCodeString")
    ResponseEntity getQrCodeString();

}

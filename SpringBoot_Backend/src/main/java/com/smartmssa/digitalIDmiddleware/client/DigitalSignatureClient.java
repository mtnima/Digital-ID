package com.smartmssa.digitalIDmiddleware.client;

import com.smartmssa.digitalIDmiddleware.dto.CasUserDto;
import com.smartmssa.digitalIDmiddleware.dto.DigitalSignatureDto;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;

import static com.smartmssa.digitalIDmiddleware.utils.Constants.digitalSignatureUrl;

@FeignClient(name="DigitalSignatureClient", url= digitalSignatureUrl)
public interface DigitalSignatureClient {
    @PostMapping(value = "/signserver/process")
    ResponseEntity<?> getDigitalSignature(DigitalSignatureDto digitalSignatureDto);
}

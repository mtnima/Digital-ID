package com.smartmssa.digitalIDmiddleware.client;

import com.smartmssa.digitalIDmiddleware.config.AnrptsClientConfig;
import com.smartmssa.digitalIDmiddleware.dto.CasUserDto;
import com.smartmssa.digitalIDmiddleware.dto.OpenAmResponseDto;
import com.smartmssa.digitalIDmiddleware.dto.OpenUserRegistrationPayloadDto;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;

import static com.smartmssa.digitalIDmiddleware.utils.Constants.openAmUrl;

@FeignClient(name="OpenAmClient", url=openAmUrl)
public interface OpenAmClient {
    @PostMapping(value = "/openam/json/realms/root/selfservice/userRegistration?_action=submitRequirements")
    ResponseEntity<OpenAmResponseDto> registerUserToOpenAm(OpenUserRegistrationPayloadDto casUserDto);
}

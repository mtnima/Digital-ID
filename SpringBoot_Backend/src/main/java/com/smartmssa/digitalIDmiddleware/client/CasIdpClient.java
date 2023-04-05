package com.smartmssa.digitalIDmiddleware.client;

import com.smartmssa.digitalIDmiddleware.dto.CasUserDto;
import com.smartmssa.digitalIDmiddleware.dto.UserAttributesDto;
import com.smartmssa.digitalIDmiddleware.dto.UserPhotoDto;
import com.smartmssa.digitalIDmiddleware.dto.UserPinDto;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;

import static com.smartmssa.digitalIDmiddleware.utils.Constants.casIdpUrl;

@FeignClient(name="CasIdpClient", url= casIdpUrl)
public interface CasIdpClient {
    @PostMapping(value = "/users")
    ResponseEntity<CasUserDto> addUserToCas(CasUserDto casUserDto);
}

package com.smartmssa.digitalIDmiddleware.client;


import com.smartmssa.digitalIDmiddleware.config.AnrptsClientConfig;
import com.smartmssa.digitalIDmiddleware.dto.UserAttributesDto;
import com.smartmssa.digitalIDmiddleware.dto.UserPhotoDto;
import com.smartmssa.digitalIDmiddleware.dto.UserPinDto;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import static com.smartmssa.digitalIDmiddleware.utils.Constants.anrptsBaseUrl;
@FeignClient(name="AnrptsClient", url= anrptsBaseUrl, configuration = AnrptsClientConfig.class)
public interface AnrptsClient {
    @PostMapping(value = "/getUserPhoto")
    ResponseEntity<UserPhotoDto> getUserAttributesAndPhoto(UserPinDto userPinDto);
}

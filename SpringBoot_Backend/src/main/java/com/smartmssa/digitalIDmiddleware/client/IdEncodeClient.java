package com.smartmssa.digitalIDmiddleware.client;

import com.smartmssa.digitalIDmiddleware.config.AnrptsClientConfig;
import com.smartmssa.digitalIDmiddleware.dto.CryptographyDto;
import com.smartmssa.digitalIDmiddleware.dto.IdEncodeSendCryptographyDto;
import com.smartmssa.digitalIDmiddleware.dto.UserPhotoDto;
import com.smartmssa.digitalIDmiddleware.dto.UserPinDto;
import feign.Body;
import feign.Headers;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.http.HttpEntity;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestPart;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

import static com.smartmssa.digitalIDmiddleware.utils.Constants.idEncodeUrl;

@FeignClient(name="IdEncodeClient", url= idEncodeUrl)
public interface IdEncodeClient {
    @PostMapping(value = "/v1/enroll", consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
    ResponseEntity<CryptographyDto> getCryptography(IdEncodeSendCryptographyDto idEncodeSendCryptographyDto);
}

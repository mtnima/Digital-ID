package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

@Data
@NoArgsConstructor
public class IdEncodeSendCryptographyDto {
    private MultipartFile face_template;
    private MultipartFile digital_signature;
    private String data;
    private MultipartFile pipeline;
    private MultipartFile demog;
}

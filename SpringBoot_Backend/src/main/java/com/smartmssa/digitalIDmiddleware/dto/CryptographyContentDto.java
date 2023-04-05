package com.smartmssa.digitalIDmiddleware.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class CryptographyContentDto {
    private String faceTemplate;
    private String encryptedDataHash;
    private String data;

}

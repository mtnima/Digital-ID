package com.smartmssa.digitalIDmiddleware.dto;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.Instant;

@Data
@NoArgsConstructor
public class CryptographyDto {
    private String uuid;
    private String image;
    public CryptographyDto(String image) {
        this.image = image;
    }
}

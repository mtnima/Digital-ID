package com.smartmssa.digitalIDmiddleware.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.Instant;

@Data
@NoArgsConstructor
public class PublicKeyDto {
    private String publicKey;

    public PublicKeyDto(String publicKey) {
        this.publicKey = publicKey;
    }

    private Instant timestamp=Instant.now();
}

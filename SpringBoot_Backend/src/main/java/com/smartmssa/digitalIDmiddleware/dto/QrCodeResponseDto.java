package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;

import java.time.Instant;

@Data
public class QrCodeResponseDto {
    private String username;
    private String value;
    private Instant timestamp = Instant.now();
}

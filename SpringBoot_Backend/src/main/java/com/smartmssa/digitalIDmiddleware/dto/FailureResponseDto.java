package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotEmpty;
import java.time.Instant;

@Data
@NoArgsConstructor
public class FailureResponseDto {
    private String error;
    private Instant timestamp = Instant.now();
    public FailureResponseDto(String response) {
        this.error = response;
    }
}

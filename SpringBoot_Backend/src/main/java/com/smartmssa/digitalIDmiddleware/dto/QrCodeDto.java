package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotEmpty;
import java.time.Instant;

@Data
@NoArgsConstructor
public class QrCodeDto {
    @NotEmpty
    private String value;
    private Instant timestamp = Instant.now();

    public QrCodeDto(String value) {
        this.value = value;
    }
}

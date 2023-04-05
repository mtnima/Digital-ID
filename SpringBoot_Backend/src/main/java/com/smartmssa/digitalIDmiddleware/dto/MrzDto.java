package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;
import lombok.NoArgsConstructor;

import java.time.Instant;

@Data
@NoArgsConstructor
public class MrzDto {
    private String mrz;
    private Instant timeStamp = Instant.now();
    public MrzDto(String mrz){
        this.mrz = mrz;
    }
}

package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;

import java.time.Instant;

@Data
public class UserRegistrationResponseDto {
    private String value;
    private Instant timestamp = Instant.now();
    public UserRegistrationResponseDto(String data){
        this.value = data;
    }

}

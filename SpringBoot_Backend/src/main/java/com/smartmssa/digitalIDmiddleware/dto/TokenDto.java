package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;

@Data
public class TokenDto {
    private String access_token;
    private String refresh_token;
}

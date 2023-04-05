package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;

@Data
public class OpenAmUserDto {
    private String username;
    private String givenName;
    private String mail;
    private String userPassword;
    private String inetUserStatus;
}

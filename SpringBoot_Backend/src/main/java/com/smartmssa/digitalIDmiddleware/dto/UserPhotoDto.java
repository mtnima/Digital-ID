package com.smartmssa.digitalIDmiddleware.dto;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.web.multipart.MultipartFile;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class UserPhotoDto {
    private String pin;
    private String firstName;
    private String lastName;
    private String birthDate;
    private String photo;
}

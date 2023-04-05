package com.smartmssa.digitalIDmiddleware.dto;

import com.smartmssa.digitalIDmiddleware.exception.NNIValidation;
import lombok.Data;

import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;

@Data
public class RegisterUserDto {
    @NotEmpty
    @Size(min = 10, max = 10)
    private String pin;
    @NotEmpty
    private String firstName;
    @NotEmpty
    private String lastName;
    @NotEmpty
    private String birthDate;
}

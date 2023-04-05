package com.smartmssa.digitalIDmiddleware.dto;

import com.smartmssa.digitalIDmiddleware.exception.NNIValidation;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class UserAttributesDto {
    @NotEmpty
    @Size(min = 10, max = 10)
    private String pin;
    @NotEmpty
    private String firstName;
    @NotEmpty
    private String lastName;
    @NotEmpty
    private String birthDate;
    @NotEmpty
    private String faceTemplate;
}

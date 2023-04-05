package com.smartmssa.digitalIDmiddleware.dto;

import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.criteria.CriteriaBuilder;
import java.time.Instant;
@Data
@NoArgsConstructor
public class SuccessResponseDto {
    private String success;
    private Instant timestamp = Instant.now();

    public SuccessResponseDto(String success) {
        this.success = success;
    }
}

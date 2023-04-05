package com.smartmssa.digitalIDmiddleware.dto;

import com.smartmssa.digitalIDmiddleware.exception.NNIValidation;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.persistence.criteria.CriteriaBuilder;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;
import java.time.Instant;

@Data
@NoArgsConstructor
public class QrCodeEstablishConnectionDto {
    @NotEmpty
    @Size(min = 10, max = 10)
    private String username;
    @NotEmpty
    private String qrAuth;
    private Instant createdAt = Instant.now();

    public QrCodeEstablishConnectionDto(QrCodeEstablishConnectionDto qrCodeEstablishConnectionDto, Instant timestamp){
        this.setUsername(qrCodeEstablishConnectionDto.getUsername());
        this.setQrAuth(qrCodeEstablishConnectionDto.getQrAuth());
        this.setCreatedAt(timestamp);
    }
}

package com.smartmssa.digitalIDmiddleware.model;

import lombok.Data;
import org.hibernate.annotations.CreationTimestamp;

import javax.persistence.*;
import java.time.Instant;

@Data
@Entity
public class QrCodeSession {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @CreationTimestamp
    private Instant createdAt;
    private String username;
    @Column(unique = true)
    private String qrAuth;
}

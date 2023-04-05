package com.smartmssa.digitalIDmiddleware.repository;

import com.smartmssa.digitalIDmiddleware.model.QrCode;
import org.springframework.data.jpa.repository.JpaRepository;

import javax.transaction.Transactional;
import java.time.Instant;
import java.util.Optional;

public interface QrCodeRepository extends JpaRepository<QrCode, Long> {
    Optional<QrCode> findByValueAndCreatedAtGreaterThan(String value, Instant expiry);

    @Transactional
    void deleteByCreatedAtLessThan(Instant expiry);
}

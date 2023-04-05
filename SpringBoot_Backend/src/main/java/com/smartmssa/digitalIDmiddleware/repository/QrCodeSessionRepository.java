package com.smartmssa.digitalIDmiddleware.repository;

import com.smartmssa.digitalIDmiddleware.model.QrCodeSession;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.stereotype.Repository;

import javax.transaction.Transactional;
import java.beans.Transient;
import java.time.Instant;
import java.util.Optional;

@Repository
public interface QrCodeSessionRepository extends JpaRepository<QrCodeSession, Long> {
    Optional<QrCodeSession> findByQrAuthAndCreatedAtGreaterThan(String qrAuth, Instant expiry);
    @Transactional
    void deleteByQrAuth(String qrAuth);
    @Transactional
    void deleteByQrAuthAndCreatedAtLessThan(String qrAuth, Instant expiry);
}

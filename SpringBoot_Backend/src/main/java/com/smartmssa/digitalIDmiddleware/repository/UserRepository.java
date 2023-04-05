package com.smartmssa.digitalIDmiddleware.repository;

import com.smartmssa.digitalIDmiddleware.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import javax.transaction.Transactional;
import java.util.Optional;

@Repository
public interface UserRepository extends JpaRepository<User, Long> {
    Optional<User> findByUsername(String username);

    @Transactional
    void deleteByUsername(String username);
}

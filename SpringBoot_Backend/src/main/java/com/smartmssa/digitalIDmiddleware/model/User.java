package com.smartmssa.digitalIDmiddleware.model;

import lombok.Data;

import javax.persistence.*;

@Data
@Entity
@Table(name = "user_table")
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @Column(unique = true)
    private String username;
    private String password;
}

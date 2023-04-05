package com.smartmssa.digitalIDmiddleware;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.openfeign.EnableFeignClients;

@SpringBootApplication
@EnableFeignClients
public class DigitalIdMiddlewareApplication {
	public static void main(String[] args) {
		SpringApplication.run(DigitalIdMiddlewareApplication.class, args);
	}
}

package com.smartmssa.digitalIDmiddleware.controller;

import com.smartmssa.digitalIDmiddleware.dto.QrCodeDto;
import com.smartmssa.digitalIDmiddleware.dto.QrCodeResponseDto;
import com.smartmssa.digitalIDmiddleware.model.QrCodeSession;
import com.smartmssa.digitalIDmiddleware.repository.QrCodeSessionRepository;
import com.smartmssa.digitalIDmiddleware.service.DigitalAppService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.messaging.handler.annotation.MessageMapping;
import org.springframework.messaging.handler.annotation.SendTo;
import org.springframework.stereotype.Controller;

import java.time.Instant;
import java.util.Optional;

@Controller
public class IDPController {
  @Autowired
  private DigitalAppService digitalAppService;

  @MessageMapping("/values")
  @SendTo("/topic/idp")
  public ResponseEntity getIDPCredentials(QrCodeDto qrCodeDto) throws Exception {
    System.err.println("Socket called! data = " + qrCodeDto);
    return digitalAppService.getCredentials(qrCodeDto);
  }
}
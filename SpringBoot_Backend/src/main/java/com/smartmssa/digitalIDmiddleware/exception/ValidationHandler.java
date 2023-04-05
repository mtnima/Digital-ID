package com.smartmssa.digitalIDmiddleware.exception;

import java.util.HashMap;
import java.util.Map;

import com.smartmssa.digitalIDmiddleware.dto.FailureResponseDto;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.FieldError;
import org.springframework.validation.ObjectError;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.context.request.WebRequest;
import org.springframework.web.servlet.mvc.method.annotation.ResponseEntityExceptionHandler;

@ControllerAdvice
public class ValidationHandler extends ResponseEntityExceptionHandler{
	@Override
	protected ResponseEntity<Object> handleMethodArgumentNotValid(MethodArgumentNotValidException ex,
			HttpHeaders headers, HttpStatus status, WebRequest request) {
		Map<String, String> errors = new HashMap<>();
		FailureResponseDto failureResponseDto = new FailureResponseDto();
		String failure = null;
		for(ObjectError error : ex.getBindingResult().getAllErrors()){
			String fieldName = ((FieldError) error).getField();
			String message = error.getDefaultMessage();
			if(failure == null)
				failure = fieldName + ": " + message + ".  ";
			else
				failure += fieldName + ": " + message + ".  ";
			failureResponseDto.setError(failure);
		}
		return new ResponseEntity<Object>(failureResponseDto, HttpStatus.BAD_REQUEST);
	}
}
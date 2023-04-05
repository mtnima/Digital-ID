package com.smartmssa.digitalIDmiddleware;

import com.smartmssa.digitalIDmiddleware.client.IdEncodeClient;
import com.smartmssa.digitalIDmiddleware.config.RsaEncryptionConfig;
import com.smartmssa.digitalIDmiddleware.dto.*;
import com.smartmssa.digitalIDmiddleware.service.DigitalAppService;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.AssertionsForClassTypes.assertThat;
import static org.junit.jupiter.api.Assertions.*;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.HttpStatus;

import javax.crypto.BadPaddingException;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import java.io.*;
import java.security.*;
import java.security.spec.InvalidKeySpecException;
import java.util.Base64;

@SpringBootTest
class DigitalIdMiddlewareApplicationTests {
	@Autowired
	private IdEncodeClient idEncodeClient;
	@Autowired
	private DigitalAppService digitalAppService;


	@Test
	void getCryptography() throws IOException {
		UserAttributesDto userAttributesDto = new UserAttributesDto("1212121212","fsnametest","lstnametest","1986-12-25","ACAfwACAHEBXgc9fnTNawYuJb67PuFz4c4Ga9U12n56Ng6tAill3/5KFmYq8sWx7kJ17VKieTKZtryiuZ6eMWmOOoaMfGF/NgDBiAJicd4U7sT90gruiX5M++IrNKVmee4VMSUkwsFF3iORisytbr0FiXo5hQaSqoLN5KM5bd7dUnKR/q2h+jw==");
		var result = digitalAppService.getCryptography(userAttributesDto);
		assertThat(result.getStatusCode() == HttpStatus.OK).isTrue();
	}

	@Test
	void getPublicKey(){
		assertNotNull(digitalAppService.getRsaPublicKey());
	}
	@Test
	void RSATest() throws IOException, NoSuchAlgorithmException, InvalidKeySpecException, IllegalBlockSizeException, NoSuchPaddingException, BadPaddingException, InvalidKeyException {
		String hello = "hello";
		RsaEncryptionConfig rsaEncryptionConfig = new RsaEncryptionConfig();
		byte[] encryptHello = rsaEncryptionConfig.encrypt(hello);
		String decryptHello = rsaEncryptionConfig.decrypt(encryptHello);
		assertEquals("hello", decryptHello);
	}

	@Test
	void rsaSigning() throws Exception {
		String data = "Hello world!";
		RsaEncryptionConfig rsaEncryptionConfig = new RsaEncryptionConfig();
		Signature signature = rsaEncryptionConfig.getInitSignature();
		signature.update(data.getBytes());
		byte[] ds = signature.sign();
		Signature signature1 = rsaEncryptionConfig.getVerifySignature();
		signature1.update(data.getBytes());
		boolean bool = signature1.verify(ds);
		assertTrue(bool);
	}

}

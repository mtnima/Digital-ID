package com.smartmssa.digitalIDmiddleware.config;

import org.springframework.core.io.ClassPathResource;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import java.io.IOException;
import java.security.*;
import java.security.spec.EncodedKeySpec;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

public class RsaEncryptionConfig {

    private PrivateKey privateKey;
    private PublicKey publicKey;


    public RsaEncryptionConfig() throws IOException, NoSuchAlgorithmException, InvalidKeySpecException {
        byte[] publicKeyBytes = new ClassPathResource("/rsakeys/publicKey").getInputStream().readAllBytes();
        KeyFactory publicKeyFactory = KeyFactory.getInstance("RSA");
        EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(publicKeyBytes);
        PublicKey publicKey = publicKeyFactory.generatePublic(publicKeySpec);
        this.publicKey = publicKey;

        byte[] privateKeyBytes = new ClassPathResource("/rsakeys/privateKey").getInputStream().readAllBytes();
        KeyFactory privateKeyFactory = KeyFactory.getInstance("RSA");
        EncodedKeySpec privateKeySpec = new PKCS8EncodedKeySpec(privateKeyBytes);
        PrivateKey privateKey = privateKeyFactory.generatePrivate(privateKeySpec);
        this.privateKey = privateKey;
    }

    public Signature getInitSignature() throws NoSuchAlgorithmException, InvalidKeyException {
        Signature signature= Signature.getInstance("SHA256withRSA");
        signature.initSign(this.privateKey);
        return signature;
    }

    public Signature getVerifySignature() throws NoSuchAlgorithmException, InvalidKeyException {
        Signature signature= Signature.getInstance("SHA256withRSA");
        signature.initVerify(this.publicKey);
        return signature;
    }

    public byte[] encrypt(String data) throws BadPaddingException, IllegalBlockSizeException, InvalidKeyException, NoSuchPaddingException, NoSuchAlgorithmException {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, this.privateKey);
        return cipher.doFinal(data.getBytes());
    }


    public String decrypt(byte[] data) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, BadPaddingException, IllegalBlockSizeException {
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.DECRYPT_MODE, this.publicKey);
        return new String(cipher.doFinal(data));
    }
}

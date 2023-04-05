package com.digitalid.mauritania.utils;

import android.security.keystore.KeyGenParameterSpec;
import android.security.keystore.KeyProperties;
import android.util.Log;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.UnrecoverableEntryException;
import java.security.cert.CertificateException;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.KeyGenerator;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.SecretKey;
import javax.crypto.spec.IvParameterSpec;

/**
 * Manage cryptographic key in keystore
 * requires previous user authentication to have been performed
 */
public class CryptographUtil {

    private static final String ALGORITHM = KeyProperties.KEY_ALGORITHM_AES;
    private static final String BLOCK_MODE = KeyProperties.BLOCK_MODE_CBC;
    private static final String PADDING = KeyProperties.ENCRYPTION_PADDING_PKCS7;

    private static final String TRANSFORMATION = ALGORITHM + "/" + BLOCK_MODE + "/" + PADDING;
    private static final String ANDROID_KEY_STORE = "AndroidKeyStore";


    private final String keyName;
    private KeyStore keyStore;
    private SecretKey secretKey;


    public CryptographUtil(String keyName) throws CertificateException, NoSuchAlgorithmException, KeyStoreException,
            IOException, InvalidAlgorithmParameterException {
        this.keyName = keyName;
        initKeystore();
        loadOrGenerateKey();
    }

    private void loadOrGenerateKey() throws NoSuchAlgorithmException, InvalidAlgorithmParameterException {
        secretKey = getKey();
        if (secretKey == null) {
            secretKey = generateKey();
        }
    }

    private void initKeystore() throws KeyStoreException, CertificateException, NoSuchAlgorithmException, IOException {
        keyStore = KeyStore.getInstance(ANDROID_KEY_STORE);
        keyStore.load(null);
    }

    private SecretKey getKey() {
        try {
            final KeyStore.SecretKeyEntry secretKeyEntry = (KeyStore.SecretKeyEntry) keyStore.getEntry(keyName, null);
            // if no key was found -> generate new
            if (secretKeyEntry != null) {
                return secretKeyEntry.getSecretKey();
            }
        } catch (KeyStoreException | NoSuchAlgorithmException | UnrecoverableEntryException e) {


            Log.d("TAG", "failed to retrieve secret key  ");

        }

        return null;
    }
   @SuppressWarnings("java:S6288")
    private SecretKey generateKey() throws NoSuchAlgorithmException, InvalidAlgorithmParameterException {

        final KeyGenerator keyGenerator = KeyGenerator.getInstance(ALGORITHM);

        final KeyGenParameterSpec keyGenParameterSpec = new KeyGenParameterSpec
                .Builder(keyName, KeyProperties.PURPOSE_ENCRYPT | KeyProperties.PURPOSE_DECRYPT)
                .setBlockModes(BLOCK_MODE)
                .setEncryptionPaddings(PADDING)
                .setUserAuthenticationRequired(false)
                .build();
        keyGenerator.init(keyGenParameterSpec);
        return keyGenerator.generateKey();


    }

    public byte[] encrypt(byte[] data) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidKeyException, BadPaddingException, IllegalBlockSizeException, IOException {


        final Cipher cipher = Cipher.getInstance(TRANSFORMATION);
        cipher.init(Cipher.ENCRYPT_MODE, secretKey);

        byte[] iv = cipher.getIV();
        byte[] encrypted = cipher.doFinal(data);
        int ivLength = iv.length;
        int encryptedDataLength = encrypted.length;


        try (ByteArrayOutputStream outputStream = new ByteArrayOutputStream()) {

            outputStream.write(intToBytes(ivLength));
            outputStream.write(iv);
            outputStream.write(intToBytes(encryptedDataLength));
            outputStream.write(encrypted);

            return outputStream.toByteArray();

        }

    }

    @SuppressWarnings("java:S3329")
    public byte[] decrypt(byte[] encryptedData) throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidAlgorithmParameterException, InvalidKeyException, BadPaddingException, IllegalBlockSizeException, IOException {

        try (ByteArrayInputStream btStream = new ByteArrayInputStream(encryptedData); DataInputStream stream = new DataInputStream(btStream)) {

            int ivLength = stream.readInt();
            byte[] iv = new byte[ivLength];
            int ivLengthReaded = stream.read(iv);
            Log.d("TAG", "ivLengthReaded : " + ivLengthReaded);

            int encryptedDataLength = stream.readInt();
            byte[] encryptedBytes = new byte[encryptedDataLength];
            int encryptedBytesReaded = stream.read(encryptedBytes);

            Log.d("TAG", "encryptedBytesReaded : " + encryptedBytesReaded);


            final Cipher cipher = Cipher.getInstance(TRANSFORMATION);
            IvParameterSpec spec = new IvParameterSpec(iv);
            cipher.init(Cipher.DECRYPT_MODE, secretKey, spec);
            return cipher.doFinal(encryptedBytes);

        }
    }


    public byte[] intToBytes(final int i) {
        ByteBuffer bb = ByteBuffer.allocate(4);
        bb.putInt(i);
        return bb.array();
    }


}

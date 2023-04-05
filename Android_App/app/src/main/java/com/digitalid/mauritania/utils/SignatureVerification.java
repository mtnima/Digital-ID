package com.digitalid.mauritania.utils;

import android.util.Base64;
import android.util.Log;

import java.nio.charset.StandardCharsets;
import java.security.InvalidKeyException;
import java.security.KeyFactory;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.PublicKey;
import java.security.Signature;
import java.security.SignatureException;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.X509EncodedKeySpec;

public class SignatureVerification {





    public boolean validateSignature(String publicKeyString, byte[] digitalSignatureFromCryptograph, String data) throws
            NoSuchAlgorithmException, InvalidKeySpecException, InvalidKeyException, SignatureException {

        Log.d("TAG", "Validating signature.........");


        byte[] pkBytes = Base64.decode(publicKeyString, Base64.NO_WRAP);

        PublicKey publicKey = getPublicKey(pkBytes);

        // Creating a Signature object
        Signature sign = Signature.getInstance("SHA256withRSA");

        String hash = sha256(data);

        // Initializing the signature
        sign.initVerify(publicKey);
        sign.update(hash.getBytes());

        // Verifying the signature
        return sign.verify(digitalSignatureFromCryptograph);

    }


    public static String sha256(final String base) throws NoSuchAlgorithmException {


        final MessageDigest digest = MessageDigest.getInstance("SHA-256");
        final byte[] hash = digest.digest(base.getBytes(StandardCharsets.UTF_8));
        final StringBuilder hexString = new StringBuilder();
        for (int i = 0; i < hash.length; i++) {
            final String hex = Integer.toHexString(0xff & hash[i]);
            if (hex.length() == 1)
                hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();

    }


    public static PublicKey getPublicKey(byte[] publicKeyBytes) throws NoSuchAlgorithmException, InvalidKeySpecException {

        X509EncodedKeySpec spec =
                new X509EncodedKeySpec(publicKeyBytes);
        KeyFactory kf = KeyFactory.getInstance("RSA");
        return kf.generatePublic(spec);
    }
}

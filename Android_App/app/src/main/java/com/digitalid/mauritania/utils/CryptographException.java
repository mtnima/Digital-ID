package com.digitalid.mauritania.utils;

public class CryptographException extends Exception{


    public CryptographException(String message) {
        super(message);
    }

    public CryptographException(Exception exp) {
        super(exp);
    }

    public CryptographException(String message, Exception exp) {
        super(message, exp);
    }

    public CryptographException() {
        super("error decoding cryptogarph");
    }
}

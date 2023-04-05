package com.digitalid.mauritania.tlvdecoder;

public class TLVDecodeException extends Exception {
    public TLVDecodeException(String message) {
        super(message);
    }

    public TLVDecodeException(Exception exp) {
        super(exp);
    }

    public TLVDecodeException(String message, Exception exp) {
        super(message, exp);
    }

    public TLVDecodeException() {
        super("Can't decode tlv array");
    }
}

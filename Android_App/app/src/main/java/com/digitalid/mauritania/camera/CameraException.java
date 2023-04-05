package com.digitalid.mauritania.camera;

public class CameraException extends Exception {


    public CameraException(String message) {
        super(message);
    }

    public CameraException(Exception exp) {
        super(exp);
    }

    public CameraException(String message, Exception exp) {
        super(message, exp);
    }


}

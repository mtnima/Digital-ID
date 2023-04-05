package com.digitalid.mauritania.models;

import java.util.List;

public class AuthoriseResponse {


    private String authId;
    private String template;
    private String stage;
    private String header;
    private List<Object> infoText;
    private List<CallBackRequest> callbacks;


    public String getAuthId() {
        return authId;
    }

    public void setAuthId(String authId) {
        this.authId = authId;
    }

    public String getTemplate() {
        return template;
    }

    public void setTemplate(String template) {
        this.template = template;
    }

    public String getStage() {
        return stage;
    }

    public void setStage(String stage) {
        this.stage = stage;
    }

    public String getHeader() {
        return header;
    }

    public void setHeader(String header) {
        this.header = header;
    }

    public List<Object> getInfoText() {
        return infoText;
    }

    public void setInfoText(List<Object> infoText) {
        this.infoText = infoText;
    }

    public List<CallBackRequest> getCallbacks() {
        return callbacks;
    }

    public void setCallbacks(List<CallBackRequest> callbacks) {
        this.callbacks = callbacks;
    }


}
package com.digitalid.mauritania.models;

import java.util.List;

public class CallBackRequest {

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public List<InputOutput> getOutput() {
        return output;
    }

    public void setOutput(List<InputOutput> output) {
        this.output = output;
    }

    public List<InputOutput> getInput() {
        return input;
    }

    public void setInput(List<InputOutput> input) {
        this.input = input;
    }

    private  String type;
    private  List<InputOutput> output;
    private List<InputOutput> input;
}
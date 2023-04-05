package com.digitalid.mauritania.tlvdecoder;

public class TLVRecord implements ITLVRecord {
    private IDEncodeFieldType type;
    private byte[] data;

    TLVRecord(IDEncodeFieldType typeIn, byte[] rawData) {
        type = typeIn;
        data = rawData;
    }

    @Override
    public IDEncodeFieldType getType() {
        return type;
    }

    @Override
    public byte[] getData() {
        return data;
    }
}

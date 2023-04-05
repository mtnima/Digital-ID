package com.digitalid.mauritania.tlvdecoder;

import java.util.List;

public interface ITLVDecoder {
    List<ITLVRecord> decode(byte[] tlvEncodedData) throws TLVDecodeException, IllegalArgumentException;
}

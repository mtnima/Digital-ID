package com.digitalid.mauritania.tlvdecoder;

import android.util.Log;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class TLVDecoderImplementation implements ITLVDecoder {
    @SuppressWarnings("java:S3776")
    @Override
    public List<ITLVRecord> decode(byte[] tlvEncodedData) throws TLVDecodeException, IllegalArgumentException {
        if (tlvEncodedData == null || tlvEncodedData.length < 2) {
            throw new IllegalArgumentException("tlvEncodedData length can't be < 2");
        }

        ByteArrayInputStream btStream = new ByteArrayInputStream(tlvEncodedData);
        DataInputStream stream = new DataInputStream(btStream);

        List<ITLVRecord> result = new ArrayList<>();

        try {
            byte openFirstByte = stream.readByte();
            byte openSecondByte = stream.readByte();
            boolean withoutExpTime = openFirstByte == 'P' && openSecondByte == 'K';

            int intFirstByte = openFirstByte & 0xFF;
            int intSecondByte = openSecondByte & 0x55;
            boolean withExpTime = intFirstByte == 0xFF && intSecondByte == 0x55;

            if (!withoutExpTime && !withExpTime) {
                throw new TLVDecodeException("Wrong first 2 bytes!");
            }

            if (withExpTime) {
                if (stream.available() < Integer.BYTES) {
                    throw new TLVDecodeException("Data corrupted!");
                }

                // we have unsigned int here
                long type = stream.readInt();


                Log.d("TAG", "expiry date " + type);


                // we create instance of the Date and pass milliseconds to the constructor
                Date res = new Date(type);

                Log.d("TAG", "expiry date " + res);
                if (stream.available() == 0) {
                    Log.d("TAG", "expired  ");
                    throw new TLVDecodeException("Expired!");


                }
            }

            int fullDataLength = 0;

            while (stream.available() > Short.BYTES * 2) {
                int type = stream.readShort();

                short recordDataLength = stream.readShort();
                if (stream.available() < recordDataLength) {
                    throw new TLVDecodeException("Data length corrupted!");
                }

                byte[] tmp = new byte[recordDataLength];
                stream.read(tmp, 0, recordDataLength);

                ITLVRecord.IDEncodeFieldType enumType = ITLVRecord.IDEncodeFieldType.fromInteger(type);
                if (enumType == null) {
                    throw new TLVDecodeException("Unknown TLV type!");
                }
                TLVRecord tlvRecord = new TLVRecord(enumType, tmp);
                result.add(tlvRecord);


                fullDataLength += Short.BYTES * 2 + recordDataLength;
            }


            Log.d("TAG", "full data length :" + fullDataLength);


        } catch (IOException e) {
            throw new TLVDecodeException("Data corrupted!", e);
        }

        return result;
    }
}

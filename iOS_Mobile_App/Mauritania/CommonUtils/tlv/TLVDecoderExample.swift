import Foundation
class StreamReader {
    
    public init(stream: InputStream) {
        _stream = stream
        _stream.open()
        
    }
    
    deinit {
        _stream.close()
    }
    
    public func readByte() throws -> UInt8 {
        var byte = UInt8(0);
        let dataToRead = MemoryLayout.size(ofValue: byte)
        if _stream.read(&byte, maxLength: dataToRead) != dataToRead {
            throw BufferReaderError.error(message: "Stream read error!")
        }
        
        return byte
    }
    
    public func readUInt16BigEndian() throws -> UInt16 {
        let value : UInt16 = (UInt16(try readByte()) << 8) | UInt16(try readByte());
        return value
    }
    
    //
    //    public func readUInt16LittleEndian() throws -> UInt16 {
    //        let value : UInt16 =   UInt16(try readByte()) | (UInt16(try readByte()) << 8) | (UInt16(try readByte()) << 8) | (UInt16(try readByte()) << 8)
    //
    //        return value
    //    }
    
    public func readBytes(count: Int) throws -> [UInt8] {
        var bytes: Array<UInt8> = Array(repeating: 0, count: count);
        if _stream.read(&bytes, maxLength: count) != count {
            throw BufferReaderError.error(message: "Stream read error!")
        }
        return bytes
        
        
    }
    
    
    private let _stream : InputStream
}

public class TLVDecoderExample : NSObject, ITLVDecoder {
    
    
    
    public func decode(tlvEncodedData: [UInt8]) throws -> [ITLVRecord] {
        var fullDataLength: Int = 0;
        var result: [TLVRecordExample] = []
        
        
        
        let reader = BufferReader(data: tlvEncodedData)
        
        do {
            
            
            //            byte openFirstByte = stream.readByte();
            //            byte openSecondByte = stream.readByte();
            //            boolean withoutExpTime = openFirstByte == 'P' && openSecondByte == 'K';
            //
            //            int intFirstByte = openFirstByte & 0xFF;
            //            int intSecondByte = openSecondByte & 0x55;
            //            boolean withExpTime = intFirstByte == 0xFF && intSecondByte == 0x55;
            //
            //            if (!withoutExpTime && !withExpTime) {
            //                throw new TLVDecodeException("Wrong first 2 bytes!");
            //            }
            
            
            let openFirstByte = try reader.readByte()
            let openSecondByte = try reader.readByte()
            
            let withoutExpTime = (openFirstByte == Character("P").asciiValue) && (openSecondByte == Character("K").asciiValue)
            
            let intFirstByte = openFirstByte & 0xFF;
            let intSecondByte = openSecondByte & 0x55;
            
            let withExpTime =  intFirstByte == 0xFF && intSecondByte == 0x55
            
            //            if p != Character("P").asciiValue || k != Character("K").asciiValue {
            //                throw TLVDecodeError.error(message: "P or K lost!");
            //            }
            
            
            if (!withoutExpTime && !withExpTime) {
                
                throw TLVDecodeError.error(message: "Wrong first 2 bytes!");
            }
            
            if(withExpTime){
                
                
                //                if (stream.available() < Integer.BYTES) {
                //                    throw new TLVDecodeException("Data corrupted!");
                //                }
                
                // we have unsigned int here
                try reader.readBytes(count: 4)
                
                
                
                //                if (stream.available() == 0) {
                //                    throw new TLVDecodeException("Expired!");
                //                }
                
            }
        } catch TLVDecodeError.error(let message) {
            throw TLVDecodeError.error(message: "Failed to read header: " + message);
        }
        
        // fullDataLength += 2;
        fullDataLength = 0;
        
        while reader.bytesAvailable > 1 {
            do {
                let typeCode = try  reader.readUInt16BigEndian()
                
                print("tlv record type \(String(describing: typeCode))\n")
                
                guard let type = IDEncodeFieldType(rawValue: typeCode) else {
                    throw TLVDecodeError.error(message: "Invalid data type!");
                }
                
                
                let recordDataLength = try reader.readUInt16BigEndian()
                let tlvData = try reader.readBytes(count: Int(recordDataLength))
                let tlvRecord = TLVRecordExample(type: type, bytes: tlvData)
                result.append(tlvRecord)
                fullDataLength += MemoryLayout.size(ofValue: typeCode)
                    + MemoryLayout.size(ofValue: recordDataLength)
                    + Int(recordDataLength);
            } catch BufferReaderError.error(let message) {
                throw TLVDecodeError.error(message: "Data corrupted: " + message);
            }
        }
        
        // if data length is odd you need to check:
        // 1 - only 1 byte left;
        // 2 - this byte is 0.
        // if data length is even you need to check:
        // 1 - there is no data left;
        
//        if (fullDataLength % 2 == 0) {
//            if (reader.bytesAvailable != 0) {
//                throw TLVDecodeError.error(message: "Wrong alignment!");
//            }
//        }
//        else {
//            if try (reader.bytesAvailable != 1 || (try reader.readByte()) != 0x00) {
//                throw TLVDecodeError.error(message: "Wrong alignment!");
//            }
//        }
        
        return result;
    }
}

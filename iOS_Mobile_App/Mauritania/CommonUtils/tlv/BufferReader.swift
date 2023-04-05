import Foundation

public enum BufferReaderError: Error {
    case error(message: String)
}

class BufferReader
{
    init(data: [UInt8]) {
        _buffer = data;
    }

    public var bytesAvailable: Int {
        _buffer.count - _it
    }

    public func readByte() throws -> UInt8 {
        if (bytesAvailable == 0) {
            throw BufferReaderError.error(message: "Out of bounds!")
        }
        let byte = _buffer[_it]
        _it += 1
        return byte
    }

    public func readBytes(count: Int) throws -> [UInt8] {
        if (bytesAvailable < count) {
            throw BufferReaderError.error(message: "Out of bounds!") 
        }

        let bytes = _buffer[_it..<_it + count]
        _it += count
        return Array(bytes)
    }

    public func readUInt16BigEndian() throws -> UInt16 {
        let value : UInt16 = (UInt16(try readByte()) << 8) | UInt16(try readByte());
        return value
    }

    private let _buffer : [UInt8]
    private var _it : Int = 0
}

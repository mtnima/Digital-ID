import Foundation

public protocol ITLVDecoder {
    func decode(tlvEncodedData: [UInt8]) throws -> [ITLVRecord]
}

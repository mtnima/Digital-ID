import Foundation
 public class TLVRecordExample :NSObject, ITLVRecord {
    public init(type: IDEncodeFieldType, bytes: [UInt8]) {
        _type = type
        _data = bytes
    }

    public var type: IDEncodeFieldType {
        get {
            _type
        }
        set {
            _type = type
        }
    }

    public var data: [UInt8] {
        get {
            _data
        }
        set {
            _data = data
        }
    }

    private var _data: [UInt8]

    private var _type: IDEncodeFieldType
}

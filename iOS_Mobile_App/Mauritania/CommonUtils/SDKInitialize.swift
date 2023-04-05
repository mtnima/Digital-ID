//
//  SDKInitialize.swift
//  Malaysia iKad
//
//  Created by Radhika on 10/01/23.
//

import UIKit
import T5CryptographClientFramework
class SDKInitialize {//d6470670-1d30-400b-acd8-55631ecb09d6
    public static var tech5_Crypto : T5CryptographClient?
    public static var uniqueId = ""
    
    public static var _pointer: UnsafeMutablePointer<UInt8>? = nil
    public static var pointer: UnsafeMutablePointer<UInt8> { _pointer! }
    
    public static var size: Int32 { _size }
    
    public static var _size: Int32 = 0
    public static var isSuccess = false
    public static var _cryptoGraph: UnsafeMutablePointer<UInt8>? = nil
    public static var cryptoGraph: UnsafeMutablePointer<UInt8> { _cryptoGraph! }
    
    public static var isFaceDetected = false
    public static var isCryoGraphFaceDetected = false
    public static var decodedData : Data!
    public static var decodedDataSize = 0
    public static var faceImage = UIImage()
    public static var errorFailingtoDecode = 0
    public static var demographicArray:[KeyAndValue]?
    public static var decodedfaceTemplate : Data?
    public static var demogs : String?
    public static var demogsData : Data?
    public static var digitalCertificateData : Data?
    public static var digitalCertificateString : String?
    public static var demoData : NSData?
    public static func initCryptoSDK(){
        let key = "MGM1MjA0ZGY5MzFhZTNlN2U3NWI5ZmQ5OWQ4MDk4YTdhZGYyOWZjMWRmZDkzMTE1MDEzM2VhMjIyZmUwYjBlNjE2ZWNkMjMyY2IxMmE2ZjUzOTFmNmVlMjAwNjIzODZkN2UxZTEwNWQ5ZDhjZjQ5MTFkOWY4ZmU5NDljYmU5Y2Y2MzAxYjRiY2IyMDhhYmJmMjA0ZWUxMzM3N2FhMzUwOTFlOWVkYmFjOTdjNDE1MDBiOGM5MTdlNmJlZTRhNmZhMzY2NTllNjM2OWZkNmU2NThmYjUxN2U4NTE4NTc1ZjZjNDcwMzkyMjMzMmI5YmE3OWNkYTUyZWRlMmI5ZTBiZQ=="
        let urlPath = Bundle.main.url(forResource: "encryptionKey", withExtension: "txt")
        do{
            
            let keyData = try Data(contentsOf: urlPath!)
            keyData.withUnsafeBytes({ (p: UnsafePointer<UInt8>) -> Void in
                _size = Int32(keyData.count)
                _pointer = UnsafeMutablePointer<UInt8>.allocate(capacity: Int(_size))
                _pointer!.initialize(from: p, count: Int(_size))
            })
        }
        catch{
            print("catch")
        }
        print("size - ",_size)
        print("pointer - ",_pointer)
        tech5_Crypto = T5CryptographClient()
        isSuccess = tech5_Crypto!.cryptograph_Create(BlockEncryptionKey: _pointer!, ret:&_size)
        print("isSuccess - ",isSuccess)
        print("tech5_Crypto - ",tech5_Crypto as Any)
        print("_size - ",_size)
    }
    
    
    deinit {
        SDKInitialize._pointer!.deinitialize(count: Int(SDKInitialize._size))
        SDKInitialize._pointer!.deallocate()
        SDKInitialize._cryptoGraph!.deinitialize(count: Int(SDKInitialize._size))
        SDKInitialize._cryptoGraph!.deallocate()
    }
    
    public static func decodeCryptograph(barCodeData:Data){
        //Coverting cryptograph to pointer
        if isSuccess == true {
            print("which thread  - ", Thread.isMainThread)
            barCodeData.withUnsafeBytes({ (p: UnsafePointer<UInt8>) -> Void in
                _size = Int32(barCodeData.count)
                _cryptoGraph = UnsafeMutablePointer<UInt8>.allocate(capacity: Int(_size))
                _cryptoGraph!.initialize(from: p, count: Int(_size))
            })
            print("_size - ",_size)
            var decodeddatasize: Int32 = 10 * 1024
            var ErrorFailingtoDecode: Int32 = -1
            let uniqueIDPointer: UnsafePointer<Int8>? = NSString(string: uniqueId).utf8String
            _ = NSString(string: uniqueId).length
            var decodeData : UnsafeMutablePointer<UInt8>? = nil
            //var decodeData = UnsafeMutablePointer <UInt8>.allocate(capacity: Int(decodeddatasize))
//            let errorCode = m_crypto!.cryptograph_Decode(cryptoGraphPNG: _cryptoGraph!, cryptoGraphSize: _size, uniqueID: uniqueIDPointer!, data: decodeData, dataSize: &decodeddatasize, ErrorBeforeFailingToDecode: &ErrorFailingtoDecode)
//            print("ErrorFailingtoDecode - ",ErrorFailingtoDecode)
//            if errorCode == 1{
                decodeData = UnsafeMutablePointer <UInt8>.allocate(capacity: Int(decodeddatasize))
                
                defer {
                    decodeData!.deinitialize(count: Int(decodeddatasize))
                    decodeData!.deallocate()
                    
                }
            print("tech5_Crypto - ",tech5_Crypto as Any)
            print("_cryptoGraph - ",_cryptoGraph as Any)
            print("decodeddatasize - ",decodeddatasize)
            print("decodeData - ",decodeData as Any)
            //print("keyData - ",keyData)
            let newErrorCode = tech5_Crypto!.cryptograph_Decode(cryptoGraphPNG: _cryptoGraph!, cryptoGraphSize: _size, uniqueID: uniqueIDPointer!, data: decodeData!, dataSize: &decodeddatasize, ErrorBeforeFailingToDecode: &ErrorFailingtoDecode)
                print("newErrorCode - ",newErrorCode)
            print("ErrorFailingtoDecode - ",ErrorFailingtoDecode)
            print("decodeddatasize - ",decodeddatasize)
            errorFailingtoDecode = Int(ErrorFailingtoDecode)
//            var newdecodeData = UnsafeMutablePointer <UInt8>.allocate(capacity: Int(decodeddatasize))
//            defer {
//                newdecodeData.deinitialize(count: Int(decodeddatasize))
//                newdecodeData.deallocate()
//            }
//            let str = String(cString: decodeData!)
//                print("Str - ",str)
//          //  }
            if newErrorCode == 0{
                let decoded = makeDataTakeOwnership(bytes: decodeData!, size: UInt64(decodeddatasize))//Data(bytes: decodeData!, count: Int(decodeddatasize))
                decodedData = decoded as Data
                decodedDataSize = Int(decodeddatasize)
                setValues(decodedData: decoded)
            }
        }
    }
    public static func makeDataTakeOwnership(bytes: UnsafeMutablePointer<UInt8>, size: UInt64) -> NSData {
        NSData(bytesNoCopy: bytes, length: Int(size), freeWhenDone: false)
    }
    
    public static func setValues(decodedData:NSData) {

        var tlvDecoder:TLVDecoderExample?
        var bytes = [UInt8]()
        let nsdata = decodedData
        //if let data = nsdata {
            print("data length - ",nsdata.length)
            var buffer = [UInt8](repeating: 0, count: nsdata.length)
            nsdata.getBytes(&buffer, length: nsdata.length)
            bytes = buffer
            //print("bytes - ",bytes)
            tlvDecoder = TLVDecoderExample()
            do{

                let records :[ITLVRecord]   =   try tlvDecoder!.decode(tlvEncodedData: bytes)
                print("records - ",records)
                setResultsFromTlVRecords(records: records)

                //  showDemographics()
            }catch{
                print(error)
            }

        //}

    }
    
    public static func setResultsFromTlVRecords(records:[ITLVRecord]){

        print("setResultsFromTlVRecords() called")
        var compressedImage = Data()

        for record in records{

            print(record.type)

            if(record.type == IDEncodeFieldType.FaceCompressedImage){
                compressedImage = Data(record.data)
                print("compresedImage - ")

            }else if(record.type == IDEncodeFieldType.FaceTemplate){

                SDKInitialize.decodedfaceTemplate = Data(record.data)
//                faceImage = Data(record.data)
                isCryoGraphFaceDetected = true
                print("facetemplate - ")

            }else if(record.type == IDEncodeFieldType.Demog){

                let demogData =  Data(record.data)
                demogsData = Data(record.data)
                let data = NSData(bytes: record.data, length: record.data.count)
                demoData = data
                let str = String(decoding: demogData, as: UTF8.self)
                let newStr = str.replacingOccurrences(of: "\"", with: "")
                demogs = newStr.replacingOccurrences(of: "\n", with: "")
                print("demogs \(demogs!)")

                let values = str.components(separatedBy: ",")
                var mystring = ""
                for value in values {
                    if mystring.count <= 0{
                        mystring = value
                    }
                    else {
                        mystring = "\(mystring + value)"
                    }
                }
                print("Arranged String - \(mystring)")
                let keys: [String] = ["Name", "Date of Birth", "Nationality",  "Email", "Gender", "Marital Status", "Blood Group", "Date Of Issue", "Cryptograph Validity"]

                let count = min(values.count, keys.count)
                var demographicsyArray:[KeyAndValue] = [KeyAndValue]()
                for index in 0..<count{

                    var value:String = values[index]

                    if(keys[index] == "Date Of Issue"){


                        let issueDateFormatter = DateFormatter()
                        issueDateFormatter.dateFormat = "ddMMyyyy"
                        let date:Date? =  issueDateFormatter.date(from: value)

                        if(date != nil){
                            let displatDateFormatter = DateFormatter()
                            displatDateFormatter.dateFormat = "dd-MMM-yyyy"
                          value = displatDateFormatter.string(from: date!)
                        }
                    }

                    let keyAndVal :KeyAndValue = KeyAndValue(key: keys[index], value: value
                    )


                    demographicsyArray.append(keyAndVal)

                }

                print("demofraphics - ",demographicsyArray)
                demographicArray = demographicsyArray
            }
            else if(record.type==IDEncodeFieldType.Extra){
                //                fingerTemplatesDictionary[10] = Data(record.data)
                var extraData : Data? = Data(record.data)
            }
            else if(record.type==IDEncodeFieldType.DigitalCertificate){
                //                fingerTemplatesDictionary[10] = Data(record.data)
                digitalCertificateData = Data(record.data)
                digitalCertificateString = String(decoding: digitalCertificateData!, as: UTF8.self)
                print("Digital Certificate = \(digitalCertificateString!)")
            }
        }

    }
    
//    public static func decompressImage(imageData:Data){
//        let request = Tech5OmniMatchConvertImageFormatRequest()
//        let requestImage = Tech5OmniMatchImage()
//        requestImage.format = .jpeg
//        requestImage.bytes = imageData
//
//    }
    
}

struct KeyAndValue{
    var key:String
    var value:String
}

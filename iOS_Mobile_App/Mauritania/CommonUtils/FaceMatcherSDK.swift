//
//  FaceMatcherSDK.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 14/01/23.
//

import Foundation
import OmniMatch
//import T5OmniMatchBioSDK

class FaceMatcherSDK {//d6470670-1d30-400b-acd8-55631ecb09d6
    public static var uniqueId = ""
    
//    public static var _pointer: UnsafeMutablePointer<UInt8>? = nil
//    public static var pointer: UnsafeMutablePointer<UInt8> { _pointer! }
    
//    public static var size: Int32 { _size }
    
//    public static var _size: Int32 = 0
    public static var isSuccess = false
//    public static var _cryptoGraph: UnsafeMutablePointer<UInt8>? = nil
//    public static var cryptoGraph: UnsafeMutablePointer<UInt8> { _cryptoGraph! }
    public static var isFaceDetected = false
//    public static var isCryoGraphFaceDetected = false
    public static var faceDetectorNative : FaceDetectorNative!
    public static var faceDetectorInstance : FaceDetectorInstance!
    public static var templateNative : TemplateCreatorNNNative!
    public static var templateInstance : TemplateCreatorNNInstance!
    public static var authMatcherNative : AuthMatcherNative!
    public static var authMatcherInstance : AuthMatcherInstance!
    public static var decodedfaceTemplate : Data!
    public static var faceTemplate : Data!
//    public static var decodedData : Data!
//    public static var decodedDataSize = 0
    
    public static func initOmniMatchSDK(){
        let coreNative = CoreNative()
        let license = Tech5OmniMatchLicense()
        license.token = ""
        do {
            try OmniMatchException.catch {
                /* calls that might throw an NSException */
                let retCode = coreNative.setLicense(license)
                print("ret Code: ", retCode.rawValue)
                initializeAllInstances()
            }
        }
        catch{
            print("An error ocurred: \((error as NSError).domain)")
            let retCode = Int((error as NSError).domain)!
            if retCode < 0{
                    let bundleID = Bundle.main.bundleIdentifier
                    let urlString = "https://pheonix-lic.tech5.tech/license/\(bundleID!)/\(abs(retCode))"
                    
                    print("urlString - ",urlString)
                    // Create URL
                    let url = URL(string: urlString)
                    guard let requestUrl = url else { fatalError() }
                    
                    // Create URL Request
                    var request = URLRequest(url: requestUrl)
                    
                    // Specify HTTP Method to use
                    request.httpMethod = "GET"
                    
                    // Send HTTP Request
                    let task = URLSession.shared.dataTask(with: request) { (data, response, error) in
                        
                        // Convert HTTP Response Data to a simple String
                        if let data = data, let dataString = String(data: data, encoding: .utf8) {
                            print("Response data string:\n \(dataString)")
                            
                            let newLicense = Tech5OmniMatchLicense.init()
                            newLicense.token = dataString
                            let retCode = coreNative.setLicense(newLicense)
                            print("ret Code: ", retCode.rawValue)
                            
                            if(retCode.rawValue >= 0){
                                let licenseInfo = Tech5OmniMatchLicenseInfo.init()
                                print("expirationdate - ",licenseInfo.expirationDate as Any);
                                initializeAllInstances()
                            }else{
                                print("Not initialized correctly");
                            }
                        }
                        
                    }
                    task.resume()
            }
            
        }
        
    }
    
    public static func initializeAllInstances(){
        faceDetectorNative = FaceDetectorNative()
        let faceDetectorConfig = Tech5OmniMatchFaceDetectorConfiguration()
        faceDetectorConfig.algorithm = .detFace100Light
        let baseConfig = Tech5OmniMatchBaseConfiguration()
        baseConfig.debugMode = false
        let batchConfig = Tech5OmniMatchBatchConfiguration()
        batchConfig.batchSize = 1
        
        faceDetectorConfig.base = baseConfig
        faceDetectorConfig.batch = batchConfig
        faceDetectorConfig.singleFace = true
        faceDetectorConfig.confidenceThreshold = 0.2
        faceDetectorInstance = faceDetectorNative.createInstance(faceDetectorConfig)
        
        templateNative = TemplateCreatorNNNative()

        let templateConfig = Tech5OmniMatchTemplateCreatorNnConfiguration()
        let faceLightNNAlgo = Tech5OmniMatchAlgorithm()
        faceLightNNAlgo.face = .detFace100Light
        templateConfig.algorithm = faceLightNNAlgo
        templateConfig.bioType = .face
        let faceNNAssessorBase = Tech5OmniMatchBaseConfiguration()
        faceNNAssessorBase.debugMode = false
        templateConfig.base = faceNNAssessorBase
        let faceLightNNBatch = Tech5OmniMatchBatchConfiguration()
        faceLightNNBatch.batchSize = 1
        templateConfig.batch = faceLightNNBatch
        templateInstance = templateNative.createInstance(templateConfig)

        print("createInstance - ",templateInstance as Any)


        authMatcherNative = AuthMatcherNative()
        let config = Tech5OmniMatchAuthMatcherConfiguration()
        let algos = Tech5OmniMatchAlgorithms()
        algos.face = .detFace100Light
        config.algorithms = algos
        authMatcherInstance = authMatcherNative.createInstance(config)
    }
    
//    public static func initCryptoSDK(){
//        let key = "MGM1MjA0ZGY5MzFhZTNlN2U3NWI5ZmQ5OWQ4MDk4YTdhZGYyOWZjMWRmZDkzMTE1MDEzM2VhMjIyZmUwYjBlNjE2ZWNkMjMyY2IxMmE2ZjUzOTFmNmVlMjAwNjIzODZkN2UxZTEwNWQ5ZDhjZjQ5MTFkOWY4ZmU5NDljYmU5Y2Y2MzAxYjRiY2IyMDhhYmJmMjA0ZWUxMzM3N2FhMzUwOTFlOWVkYmFjOTdjNDE1MDBiOGM5MTdlNmJlZTRhNmZhMzY2NTllNjM2OWZkNmU2NThmYjUxN2U4NTE4NTc1ZjZjNDcwMzkyMjMzMmI5YmE3OWNkYTUyZWRlMmI5ZTBiZQ=="
//        let urlPath = Bundle.main.url(forResource: "encryptionKey", withExtension: "txt")
//        do{
//
//            let keyData = try Data(contentsOf: urlPath!)
//            keyData.withUnsafeBytes({ (p: UnsafePointer<UInt8>) -> Void in
//                _size = Int32(keyData.count)
//                _pointer = UnsafeMutablePointer<UInt8>.allocate(capacity: Int(_size))
//                _pointer!.initialize(from: p, count: Int(_size))
//            })
//        }
//        catch{
//            print("catch")
//        }
//        print("size - ",_size)
//        print("pointer - ",_pointer)
//        tech5_Crypto = T5CryptographClient()
//        isSuccess = tech5_Crypto!.cryptograph_Create(BlockEncryptionKey: _pointer!, ret:&_size)
//        print("isSuccess - ",isSuccess)
//        print("tech5_Crypto - ",tech5_Crypto as Any)
//        print("_size - ",_size)
//    }
    
    
//    deinit {
//        FaceMatcherSDK._pointer!.deinitialize(count: Int(FaceMatcherSDK._size))
//        FaceMatcherSDK._pointer!.deallocate()
//        FaceMatcherSDK._cryptoGraph!.deinitialize(count: Int(FaceMatcherSDK._size))
//        FaceMatcherSDK._cryptoGraph!.deallocate()
//    }
    
//    public static func decodeCryptograph(barCodeData:Data){
//        //Coverting cryptograph to pointer
//        if isSuccess == true{
////            do{
////                let urlPath = Bundle.main.url(forResource: "cryptograph_encoded", withExtension: "JPG")
////                let keyData = try Data(contentsOf: urlPath!)
////                keyData.withUnsafeBytes({ (p: UnsafePointer<UInt8>) -> Void in
////                    _size = Int32(keyData.count)
////                    _cryptoGraph = UnsafeMutablePointer<UInt8>.allocate(capacity: Int(_size))
////                    _cryptoGraph!.initialize(from: p, count: Int(_size))
////                })
////            }
////            catch{
////                print("catch")
////            }
////            print("barcodeData - ",barCodeData)
////            UIImageWriteToSavedPhotosAlbum(UIImage(data: barCodeData)!, nil, nil, nil)
//            print("which thread  - ", Thread.isMainThread)
//            barCodeData.withUnsafeBytes({ (p: UnsafePointer<UInt8>) -> Void in
//                _size = Int32(barCodeData.count)
//                _cryptoGraph = UnsafeMutablePointer<UInt8>.allocate(capacity: Int(_size))
//                _cryptoGraph!.initialize(from: p, count: Int(_size))
//            })
//            print("_size - ",_size)
//            var decodeddatasize: Int32 = 10 * 1024
//            var ErrorFailingtoDecode: Int32 = -1
//            let uniqueIDPointer: UnsafePointer<Int8>? = NSString(string: uniqueId).utf8String
//            _ = NSString(string: uniqueId).length
//            var decodeData : UnsafeMutablePointer<UInt8>? = nil
//            //var decodeData = UnsafeMutablePointer <UInt8>.allocate(capacity: Int(decodeddatasize))
////            let errorCode = m_crypto!.cryptograph_Decode(cryptoGraphPNG: _cryptoGraph!, cryptoGraphSize: _size, uniqueID: uniqueIDPointer!, data: decodeData, dataSize: &decodeddatasize, ErrorBeforeFailingToDecode: &ErrorFailingtoDecode)
////            print("ErrorFailingtoDecode - ",ErrorFailingtoDecode)
////            if errorCode == 1{
//                decodeData = UnsafeMutablePointer <UInt8>.allocate(capacity: Int(decodeddatasize))
//
//                defer {
//                    decodeData!.deinitialize(count: Int(decodeddatasize))
//                    decodeData!.deallocate()
//
//                }
//            print("tech5_Crypto - ",tech5_Crypto as Any)
//            print("_cryptoGraph - ",_cryptoGraph as Any)
//            print("decodeddatasize - ",decodeddatasize)
//            print("decodeData - ",decodeData as Any)
//            //print("keyData - ",keyData)
//            let newErrorCode = tech5_Crypto!.cryptograph_Decode(cryptoGraphPNG: _cryptoGraph!, cryptoGraphSize: _size, uniqueID: uniqueIDPointer!, data: decodeData!, dataSize: &decodeddatasize, ErrorBeforeFailingToDecode: &ErrorFailingtoDecode)
//                print("newErrorCode - ",newErrorCode)
//            print("decodeddatasize - ",decodeddatasize)
////            var newdecodeData = UnsafeMutablePointer <UInt8>.allocate(capacity: Int(decodeddatasize))
////            defer {
////                newdecodeData.deinitialize(count: Int(decodeddatasize))
////                newdecodeData.deallocate()
////            }
////            let str = String(cString: decodeData!)
////                print("Str - ",str)
////          //  }
//            if newErrorCode == 0{
//                let decoded = makeDataTakeOwnership(bytes: decodeData!, size: UInt64(decodeddatasize))//Data(bytes: decodeData!, count: Int(decodeddatasize))
//                decodedData = decoded as Data
//                decodedDataSize = Int(decodeddatasize)
//                setValues(decodedData: decoded)
//            }
//        }
//    }
    public static func makeDataTakeOwnership(bytes: UnsafeMutablePointer<UInt8>, size: UInt64) -> NSData {
        NSData(bytesNoCopy: bytes, length: Int(size), freeWhenDone: false)
    }
    
//    public static func setValues(decodedData:NSData) {
//
//        var tlvDecoder:TLVDecoderExample?
//        var bytes = [UInt8]()
//        let nsdata = decodedData
//        //if let data = nsdata {
//            print("data length - ",nsdata.length)
//            var buffer = [UInt8](repeating: 0, count: nsdata.length)
//            nsdata.getBytes(&buffer, length: nsdata.length)
//            bytes = buffer
//            //print("bytes - ",bytes)
//            tlvDecoder = TLVDecoderExample()
//            do{
//
//                let records :[ITLVRecord]   =   try tlvDecoder!.decode(tlvEncodedData: bytes)
//                print("records - ",records)
//                setResultsFromTlVRecords(records: records)
//
//                //  showDemographics()
//            }catch{
//                print(error)
//            }
//
//        //}
//
//    }
    
//    public static func setResultsFromTlVRecords(records:[ITLVRecord]){
//
//        print("setResultsFromTlVRecords() called")
//        var compressedImage = Data()
//
//        for record in records{
//
//            print(record.type)
//
//            if(record.type == IDEncodeFieldType.FaceCompressedImage){
//                compressedImage = Data(record.data)
//                print("compresedImage - ")
//
//            }else if(record.type == IDEncodeFieldType.FaceTemplate){
//
//                decodedfaceTemplate = Data(record.data)
//                isCryoGraphFaceDetected = true
//                print("facetemplate - ")
//
//            }else if(record.type == IDEncodeFieldType.Demog){
//
//                let demogData =  Data(   record.data)
//                let str = String(decoding: demogData, as: UTF8.self)
//
//                print("demogs \(str)")
//
//                let values = str.components(separatedBy: ",")
//                let keys: [String] = ["Name", "Date of Birth", "Nationality",  "Email", "Gender", "Marital Status", "Blood Group", "Date Of Issue", "Cryptograph Validity"]
//
//                let count = min(values.count, keys.count)
//                var demographicsyArray:[KeyAndValue] = [KeyAndValue]()
//                for index in 0..<count{
//
//                    var value:String = values[index]
//
//                    if(keys[index] == "Date Of Issue"){
//
//
//                        let issueDateFormatter = DateFormatter()
//                        issueDateFormatter.dateFormat = "ddMMyyyy"
//                        let date:Date? =  issueDateFormatter.date(from: value)
//
//                        if(date != nil){
//                            let displatDateFormatter = DateFormatter()
//                            displatDateFormatter.dateFormat = "dd-MMM-yyyy"
//                          value = displatDateFormatter.string(from: date!)
//                        }
//                    }
//
//                    let keyAndVal :KeyAndValue = KeyAndValue(key: keys[index], value: value
//                    )
//
//
//                    demographicsyArray.append(keyAndVal)
//
//                }
//
//                print("demofraphics - ",demographicsyArray)
//
//            }
//            else if(record.type==IDEncodeFieldType.Extra){
//                //                fingerTemplatesDictionary[10] = Data(record.data)
//                var extraData : Data? = Data(record.data)
//            }
//
//        }
//
//    }
    
//    public static func decompressImage(imageData:Data){
//        let request = Tech5OmniMatchConvertImageFormatRequest()
//        let requestImage = Tech5OmniMatchImage()
//        requestImage.format = .jpeg
//        requestImage.bytes = imageData
//
//    }
    
    public static func detectFace(faceData : Data){
        do {
            try OmniMatchException.catch {
                /* calls that might throw an NSException */
                let faceDetectRequest = Tech5OmniMatchFaceDetectRequest()
                let matchImage = Tech5OmniMatchImage()
                matchImage.format = .jpeg
                matchImage.bytes = faceData
                var imagesArr = [Tech5OmniMatchImage]()
                imagesArr.append(matchImage)
                faceDetectRequest.imagesArray = (imagesArr as NSArray).mutableCopy() as? NSMutableArray
                
                let response : Tech5OmniMatchFaceDetectResponse = faceDetectorNative.detect(faceDetectorInstance, faceDetectorRequest: faceDetectRequest)
                //print("resultArr - ",response.resultsArray as Any)
                let detected = response.resultsArray[0] as! Tech5OmniMatchFaceDetectResult
                if detected.errorCode.rawValue == 4{
                    return
                }
                for result in response.resultsArray {
                    let detectedFace = (result as! Tech5OmniMatchFaceDetectResult).detected.facesArray[0] as! Tech5OmniMatchDetectedFace
                    print("faces Count - ",detectedFace)
                    if (detectedFace.leftEye.x - detectedFace.rightEye.x) > 50{
                        
                        print("face bounds - ",detectedFace.bbox as Any)
                        let box = detectedFace.bbox
                        let cgRect = CGRect(x: CGFloat(box!.left), y: CGFloat(box!.top), width: CGFloat(box!.right - box!.left), height: CGFloat(box!.bottom - box!.top))
                        let cgimage = UIImage(data: faceData)?.cgImage?.cropping(to: cgRect)
                        let uiimage = UIImage(cgImage: cgimage!)
                        //UIImageWriteToSavedPhotosAlbum(uiimage, nil, nil, nil)
                        let template = createTemplate(imageData: uiimage.jpegData(compressionQuality: 1.0)!)
                        if template == Data(){
                            return
                        }
                        else
                        {
                            faceTemplate = template
                            isFaceDetected = true
                        }
                    }
                    
                }
            }
        }
        catch{
            print("An error ocurred: \((error as NSError).domain)")
        }
            
    }
    
    public static func createTemplate(imageData:Data) -> Data{
        print("imageData - ",imageData)
        
        var templateData = Data()
        
//        UIImage *faceimage = [UIImage imageNamed:imageStr];
//        NSData *imageData = UIImageJPEGRepresentation(faceimage, 1.0);
        
//        let faceImage = UIImage(named: "fake-face.jpeg")
//        let faceData = faceImage?.jpegData(compressionQuality: 1.0)
        
        let templateRequest = Tech5OmniMatchCreateTemplateRequest()
        let image = Tech5OmniMatchImage()
        image.format = .jpeg
        image.bytes = imageData
        var imagesArr = [Tech5OmniMatchImage]()
        imagesArr.append(image)
        templateRequest.imagesArray = (imagesArr as NSArray).mutableCopy() as? NSMutableArray
        templateRequest.doSegmentation = false
        let response : Tech5OmniMatchCreateTemplateResponse = templateNative.createTemplate(templateInstance!, templateRequest: templateRequest)
        let template = response.resultsArray[0] as! Tech5OmniMatchCreateTemplateResult
        if template.errorCode.rawValue == 4{
            return Data()
        }
        for result in response.resultsArray{
            print("template result - ",result)
            templateData = (result as! Tech5OmniMatchCreateTemplateResult).template_p.data_p

        }
        return templateData
    }
    public static func matchTemplates(faceTemplate:Data, cryptGraphFaceTemplate:Data) -> Float{
        let request = Tech5OmniMatchAuthVerifyRecordRequest()
        request.verifyMode = .nnOnly
        
        let referenceRecord = Tech5OmniMatchRecord()
        let matcherRTemplate = Tech5OmniMatchMatcherTemplate()
        let templateR = Tech5OmniMatchTemplate()
        templateR.data_p = faceTemplate
        templateR.quality = 100
        matcherRTemplate.templateData = templateR
        referenceRecord.face = matcherRTemplate
        
        let captureRecord = Tech5OmniMatchRecord()
        let matcherCTemplate = Tech5OmniMatchMatcherTemplate()
        let templateC = Tech5OmniMatchTemplate()
        templateC.data_p = cryptGraphFaceTemplate
        templateC.quality = 100
        matcherCTemplate.templateData = templateC
        captureRecord.face = matcherCTemplate
        
        request.capturedRecord = captureRecord
        request.referenceRecord = referenceRecord
        
        let result : Tech5OmniMatchRecordResult = authMatcherNative.verifyRecord(authMatcherInstance, recordRequest: request)
        print("logFar - ",result.candidate.scores.fused.logFar)
        
        return result.candidate.scores.fused.logFar
    }
    
    public static func closeAllInstances(){
        faceDetectorNative.delete(faceDetectorInstance)
        templateNative.delete(templateInstance)
        authMatcherNative.delete(authMatcherInstance)
    }
    
}

//
//  Extensions.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 18/01/23.
//

import Foundation
import UIKit
import DocumentReader
import CommonCrypto

extension String {
    func getSteringValueWithSpace()->[String]{
        return self.components(separatedBy: " ")
    }
    func getIDNumber()->String{
        
        let result = self//.replacingOccurrences( of:"[^0-9]", with: "", options: .regularExpression)

        if result.count >= 10 {
            return String(result.prefix(10))
        }
        else{
            var updated = result
            while updated.count<10{
                updated = updated + "0"
            }
            return updated
        }
    }
    func truncate(_ length: Int, trailing: String = "") -> String {
            let updatedString = (self.count > length) ? self.prefix(max(0, length - trailing.count)) + trailing : self
            print(updatedString)
        return updatedString
    }
}

extension Data{
    func getString()->String {
        return String(data: self, encoding: .utf8) ?? ""
    }
    func getEncodedString()->String {
        return self.base64EncodedString(options: Data.Base64EncodingOptions.endLineWithLineFeed)
    }
}

extension Encodable {

    /// Encode into JSON and return `Data`
    func jsonData() throws -> Data {
        let encoder = JSONEncoder()
        encoder.outputFormatting = .prettyPrinted
        encoder.dateEncodingStrategy = .iso8601
        return try encoder.encode(self)
    }
}
extension String {
    func toImage() -> UIImage? {
        if let data = Data(base64Encoded: self, options: .ignoreUnknownCharacters){
            return UIImage(data: data)
        }
        return nil
    }
}

extension DocumentReaderResults{
    func firstName()-> String? {
        return (self.getTextFieldValueByType(fieldType: .ft_Given_Names) ?? givenName())?.truncate(15)
    }
    
    func lastName() -> String? {
        return (self.getTextFieldValueByType(fieldType: .ft_Surname) ?? getLastName())?.truncate(10)
    }
    
    private func getLastName()-> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Last_Name) ?? getFamilyName()
    }
    private func getFamilyName() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Family_Name) ?? getSecondName()
    }
    private func getSecondName()->String? {
        return self.getTextFieldValueByType(fieldType: .ft_Second_Name) ?? fullName().lastName
    }
    
    func documentNumber() -> String? {
        let number = self.getTextFieldValueByType(fieldType: .ft_Personal_Summary)
        return ((number?.count ?? 0) > 0 ? number : getOptionalData())?.getIDNumber()
    }
    func genderType() -> String? {
        let gender = self.getTextFieldValueByType(fieldType: .ft_Sex)
        return gender
    }
    func getOptionalData() -> String? {
        let number = self.getTextFieldValueByType(fieldType: .ft_Optional_Data)
        return (number?.count ?? 0) > 0 ? number : getPersonalNumber()
    }
    func getPersonalNumber() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Document_Number)
    }
    
    func placeOfBirth() -> String? {
         return self.getTextFieldValueByType(fieldType: .ft_Place_of_Birth)
    }
    func birthDate()->String? {
        return self.getTextFieldValueByType(fieldType: .ft_Date_of_Birth)
    }
    func documentExpiryDate() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Date_of_Expiry)
    }
    func documentIssueDate() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Date_of_Issue) ?? firstIssueDate()
    }
    func firstIssueDate() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_First_Issue_Date)
    }
    func phoneNumber() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Phone)
    }
    func nationality() -> String? {
        return self.getTextFieldValueByType(fieldType: .ft_Nationality)
    }
    
    func givenName() -> String?{
        return self.getTextFieldValueByType(fieldType: .ft_First_Name) ?? fullName().firstName
        
    }
    private func fullName() -> (fullName:String?, firstName:String?, lastName:String?){
        let fullName = self.getTextFieldValueByType(fieldType: .ft_Surname_And_Given_Names)
        let separatedNames = fullName?.getSteringValueWithSpace()
        let firstName = separatedNames?[0]
        let lastName = separatedNames?[1]
        return(fullName,firstName,lastName)
    }
    func getAllRequiredDetail()->[String:String]?{
        var allFields : [String:String]? = [:]
        allFields?["Name"] = (firstName() ?? "") + " \(lastName() ?? "")"
        if let birthDate = birthDate() {
            allFields?["Birth Date"] = birthDate
        }
        if let number = documentNumber() {
            allFields?["ID"] = number.getIDNumber()
        }
        if let expiry = documentExpiryDate() {
            allFields?["Expiry Date"] = expiry
        }
        if let issue = documentIssueDate() {
            allFields?["Issue Date"] = issue
        }
        if let phone = phoneNumber() {
            allFields?["Phone"] = phone
        }
        if let nationality = nationality() {
            allFields?["Nationality"] = nationality
        }
        if let gender = genderType() {
            allFields?["Gender"] = gender
        }
        return allFields
    }
    func getDocumentDetail()->DocumentRequestModel?{
        let doument = DocumentRequestModel(firstName: self.firstName(),lastName: self.lastName(),pin: self.documentNumber(),birthDate: self.birthDate(),placeOfBirth: self.placeOfBirth() ?? "",phoneNumber: self.phoneNumber(),documentExpiryDate: self.documentExpiryDate(),dateIssueName: self.documentIssueDate(),nationality: self.nationality(),gender: self.genderType())
        return doument
    }
    
}
extension UIColor {
    func appcolor() -> UIColor{
        return UIColor(red: 7.0/255.0, green: 168.0/255.0, blue: 84.0/255.0, alpha: 1)
    }
    func viewBackgroundColor() -> UIColor {
        return UIColor(named: "appcolor") ?? UIColor.white
    }
    func labelCOlor() -> UIColor {
        return UIColor(named: "labelcolor") ?? UIColor.white
    }
}
extension UserDefaults{
    func storescannerResult(result:DocumentRequestModel?){
        do {
            if let resultData = result{
                let data = try JSONEncoder().encode(resultData)
                set(data, forKey: USERDEFAULTS().ocrresult)
                synchronize()
            }
        } catch let error {
            print("Error encoding: \(error)")
        }
    }
    func getDocumentScannerResult()->DocumentRequestModel?{
        do {
            if let data = UserDefaults.standard.data(forKey: USERDEFAULTS().ocrresult) {
                let registerResponse = try JSONDecoder().decode(DocumentRequestModel.self, from: data)
                return registerResponse
            }
        } catch let error {
            print("Error decoding: \(error)")
        }
        return nil
    }
    func storePortraitImage(portraiImage: UIImage?){
        if let image = portraiImage{
            let data = image.pngData()
            let encoded = try! PropertyListEncoder().encode(data)
            set(encoded, forKey: USERDEFAULTS().portraiData)
            synchronize()
        }
    }
    func getPortraitImage()->Data?{
        guard let data = UserDefaults.standard.data(forKey: USERDEFAULTS().portraiData) else { return nil }
        let decoded = try! PropertyListDecoder().decode(Data.self, from: data)
        return decoded
    }
    func storeLivenessData(liveness:Data?){
        if let data = liveness{
            let encoded = try! PropertyListEncoder().encode(data)
            set(encoded, forKey: USERDEFAULTS().livenessdata)
            synchronize()
        }
    }
    func getLivenessData()->Data?{
        guard let data = UserDefaults.standard.data(forKey: USERDEFAULTS().livenessdata) else { return nil }
        let decoded = try! PropertyListDecoder().decode(Data.self, from: data)

        return decoded
    }
    func storeRegiterResponse(result:UserRegisterResponse?){
        do {
            if let resultData = result{
                let data = try JSONEncoder().encode(resultData)
                set(data, forKey: USERDEFAULTS().registerresponse)
                synchronize()
            }
        } catch let error {
            print("Error encoding: \(error)")
        }
    }
    func getRegisterResponseData()->UserRegisterResponse?{
        do {
            if let data = UserDefaults.standard.data(forKey: USERDEFAULTS().registerresponse) {
                let registerResponse = try JSONDecoder().decode(UserRegisterResponse.self, from: data)
                return registerResponse
            }
        } catch let error {
            print("Error decoding: \(error)")
        }
        return nil
    }
    func storeCryptoResponse(result:CryptographyResponse?){
        do {
            if let resultData = result{
                let data = try JSONEncoder().encode(resultData)
                set(data, forKey: USERDEFAULTS().cryptoresponse)
                synchronize()
            }
        } catch let error {
            print("Error encoding: \(error)")
        }
    }
    func getCryptoResponseData()->CryptographyResponse?{
        do {
            if let data = UserDefaults.standard.data(forKey: USERDEFAULTS().cryptoresponse) {
                let registerResponse = try JSONDecoder().decode(CryptographyResponse.self, from: data)
                return registerResponse
            }
        } catch let error {
            print("Error decoding: \(error)")
        }
        return nil
    }
    func getAppLanguage() -> String{
        let language = value(forKey: USERDEFAULTS().applanguage) as? String
        return language ?? "DeviceLanguage"
    }
    func setAppLanguage(withLang lang:String){
        UserDefaults.standard.set(lang, forKey: USERDEFAULTS().applanguage)
        UserDefaults.standard.synchronize()
    }
    func storeFaceTemplate(with template:String){
        set(template, forKey: USERDEFAULTS().facetemplate)
        synchronize()
    }
    func getFaceTemplate()->String{
        let template = value(forKey: USERDEFAULTS().facetemplate) as? String
        return template ?? ""
    }
    
    func clearSession() {
//        let lang = (UserDefaults.standard.value(forKey: "kSaveLanguageDefaultKey") as? String)
//        let domain = Bundle.main.bundleIdentifier!
//        self.removePersistentDomain(forName: domain)
//        self.synchronize()
//        self.set(lang, forKey: "kSaveLanguageDefaultKey")
//        self.synchronize()
        print("Hello you are done")
        self.removeObject(forKey: USERDEFAULTS().islogin)
        self.synchronize()
    }
}
extension String {
    
    func localizedLanguage(comment: String = "") -> String {
        let userDflts = UserDefaults.standard
        let defaultLanguage = userDflts.getAppLanguage()
        let value = NSLocalizedString(self, comment: comment)
        if NSLocale.preferredLanguages.first == defaultLanguage {
            return value // String localization was found
        }
        
        // Load resource for default language to be used as
        // the fallback language
        guard let path = Bundle.main.path(forResource: defaultLanguage, ofType: "lproj"), let bundle = Bundle(path: path) else {
            return value
        }
        
        return NSLocalizedString(self, bundle: bundle, comment: "")
    }
    func localized(withComment comment: String = "") -> String {
           return Bundle.main.localizedString(forKey: self,
                                              value: "\(self)",
                                              table: nil)
       }
    
    func localize(withComment comment: String = "")->String{
        let defualtLanguage = UserDefaults.standard.getAppLanguage()
        return NSLocalizedString(self,tableName: defualtLanguage, comment: "")
    }
    func random(digits:Int) -> String {
        var number = String()
        for _ in 1...digits {
           number += "\(Int.random(in: 1...9))"
        }
        return number
    }

}
extension Int {
    init(_ range: Range<Int> ) {
        let delta = range.startIndex < 0 ? abs(range.startIndex) : 0
        let min = UInt32(range.startIndex + delta)
        let max = UInt32(range.endIndex   + delta)
        self.init(Int(min + arc4random_uniform(max - min)) - delta)
    }
}


extension Data{
    public func sha256() -> String{
        return hexStringFromData(input: digest(input: self as NSData))
    }
    public func getsha256() -> NSData {
        return digest(input: self as NSData)
    }
    private func digest(input : NSData) -> NSData {
        let digestLength = Int(CC_SHA256_DIGEST_LENGTH)
        var hash = [UInt8](repeating: 0, count: digestLength)
        CC_SHA256(input.bytes, UInt32(input.length), &hash)
        return NSData(bytes: hash, length: digestLength)
    }
    
    private  func hexStringFromData(input: NSData) -> String {
        var bytes = [UInt8](repeating: 0, count: input.length)
        input.getBytes(&bytes, length: input.length)
        
        var hexString = ""
        for byte in bytes {
            hexString += String(format:"%02x", UInt8(byte))
        }
        
        return hexString
    }
}

public extension String {
    var hexadecimalStringToData: NSData? {
            // Convert a hexstring to data
            var data = Data(capacity: self.count / 2)
            
            let regex = try! NSRegularExpression(pattern: "[0-9a-f]{1,2}", options: .caseInsensitive)
            regex.enumerateMatches(in: self, range: NSRange(startIndex..., in: self)) { match, _, _ in
                let byteString = (self as NSString).substring(with: match!.range)
                let num = UInt8(byteString, radix: 16)!
                data.append(num)
            }
            
            guard data.count > 0 else { return nil }
            
            return data as NSData
        }
    func sha256() -> String{
        if let stringData = self.data(using: String.Encoding.utf8) {
            return stringData.sha256()
        }
        return ""
    }
    func base64Data() -> NSData? {
        return Data(base64Encoded: self) as? NSData
    }
    func getUTF() -> NSData? {
        return Data(self.utf8) as NSData
    }
}
extension NSError {
    func getErrorWithMessage(withError error:String) -> NSError{
        let updatedError = NSError(domain: "", code: 415, userInfo: [ NSLocalizedDescriptionKey: error])
        return updatedError
    }
}

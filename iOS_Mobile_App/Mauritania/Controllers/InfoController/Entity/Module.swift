//
//  Module.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 18/01/23.
//

import Foundation


public struct CryptographyResponse : Codable {
 
    public var uuid: String?
    public var  image:String?

    public var error:String?;
    public var timestamp:String?
}
public struct CryptographRequest : Encodable {
    public var pin : String?
    public var firstName : String?
    public var lastName : String?
    public var birthDate : String?
    public var faceTemplate : String?
    var dictionary: [String: Any] {
        return ["pin": pin ?? "",
                    "firstName": firstName ?? "",
                    "lastName": lastName ?? "",
                    "birthDate":birthDate ?? "",
                    "faceTemplate":faceTemplate ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}

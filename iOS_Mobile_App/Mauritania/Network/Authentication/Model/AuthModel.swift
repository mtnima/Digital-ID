//
//  AuthModel.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation


public struct AuthenticationResponse : Codable {
    public var tokenId: String?
    public var successUrl:String?;
    public var realm:String?
    public var code:Int?
    public var reason:String?
    public var message:String?
}

public struct TokenAuthRequest : Encodable {
    public var tokenId: String?
    var dictionary: [String: Any] {
        return ["tokenId": tokenId ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}
public struct EstablishConnectionRequest : Encodable {
    public var username: String?
    public var qrAuth: String?
    var dictionary: [String:Any] {
        return ["username":username ?? "",
                "qrAuth":qrAuth ?? ""]
    }
    var nsDictionary: NSDictionary {
        return dictionary as NSDictionary
    }
}
public struct enstablishConnectionResponse : Codable {
    public var username : String?
    public var qrAuth : String?
    public var createdAt : String?
}
public struct TokenAuthResponse : Codable {
    public var authId: String?
    public var template: String?
    public var stage: String?
    public var header: String?
    public var infoText: [String]?
    public var callbacks: [callback]?
    public var token: String?
    public var code: Int?
    public var reason: String?
    public var message: String?
    enum CodingKeys: String, CodingKey {
            case authId = "authId"
            case template = "template"
            case stage = "stage"
            case header = "header"
            case infoText = "infoText"
            case callbacks = "callbacks"
        }
    var dictionary: [String: Any] {
        return ["authId": authId ?? "",
                "template": template ?? "",
                "stage": stage ?? "",
                "header": header ?? "",
                "infoText": infoText ?? "",
                "callbacks": callbacks?[0].nsDictionary ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}
public struct callback : Codable {
    public var type: String?
    public var output: [in_output]?
    public var input: [in_output]?
    enum CodingKeys: String, CodingKey {
            case type = "type"
            case output = "output"
            case input = "input"
        }
    var dictionary: [String: Any] {
        return ["type": "\(type ?? "")" ,
                "output": output?[0].nsDictionary ?? "",
                "input": input?[0].nsDictionary ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}
public struct in_output : Codable {
    public var name: String?
    public var value: String?
    enum CodingKeys: String, CodingKey {
            case value = "value"
            case name = "name"
        }
    var dictionary: [String: String] {
        return ["name": "\(name ?? "")",
                "value": "\(value ?? "")"]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}



public struct QRRequest : Encodable {
    public var authId: String?
    public var template: String?
    public var stage: String?
    public var header: String?
    public var infoText: [String]?
    public var callbacks: [callbackRequest]?
    public var token: String?
    enum CodingKeys: String, CodingKey {
            case authId = "authId"
            case template = "template"
            case stage = "stage"
            case header = "header"
            case infoText = "infoText"
            case callbacks = "callbacks"
        }
    var dictionary: [String: Any] {
        return ["authId": authId ?? "",
                "template": template ?? "",
                "stage": stage ?? "",
                "header": header ?? "",
                "infoText": infoText ?? "",
                "callbacks": callbacks?[0].nsDictionary ?? "",
                "token": token ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}
public struct callbackRequest : Encodable {
    public var type: String?
    public var output: [in_outputRequest]?
    public var input: [in_outputRequest]?
    enum CodingKeys: String, CodingKey {
            case type = "type"
            case output = "output"
            case input = "input"
        }
    var dictionary: [String: Any] {
        return ["type": "\(type ?? "")" ,
                "output": output?[0].nsDictionary ?? "",
                "input": input?[0].nsDictionary ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}
public struct in_outputRequest : Encodable {
    public var name: String?
    public var value: String?
    enum CodingKeys: String, CodingKey {
            case value = "value"
            case name = "name"
        }
    var dictionary: [String: String] {
        return ["name": "\(name ?? "")",
                "value": "\(value ?? "")"]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
    
}



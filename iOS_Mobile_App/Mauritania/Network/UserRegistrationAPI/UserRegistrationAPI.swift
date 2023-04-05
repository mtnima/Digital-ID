//
//  UserRegistrationAPI.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation

public struct UserRegisterResponse : Codable {
    public var value: String?
    public var error:String?;
    public var timestamp:String?
    public var pin : String?
    var dictionary: [String: Any] {
        return ["pin": pin ?? "","value": value ?? "",
                    "error": error ?? "",
                    "timestamp": timestamp ?? ""]
        }
    var nsDictionary: NSDictionary {
        return dictionary as NSDictionary
    }
}

public struct UserRegisterRequest : Encodable {
    public var pin : String?
    public var firstName : String?
    public var lastName : String?
    public var error:String?;
    public var timestamp:String?
    public var birthDate : String?
    var dictionary: [String: Any] {
        return ["pin": pin ?? "",
                    "firstName": firstName ?? "",
                    "lastName": lastName ?? "",
                    "birthDate":birthDate ?? ""]
        }
        var nsDictionary: NSDictionary {
            return dictionary as NSDictionary
        }
}

enum UserRegistrationAPI {
    case registerUser(UserRegisterRequest)
}

extension UserRegistrationAPI: APIProtocol {
    func httpMthodType() -> HTTPMethodType {
        var methodType = HTTPMethodType.get
        switch self {
        case .registerUser(_):
            methodType = .post
        }
        return methodType
    }

    func apiEndPath() -> String {
        var apiEndPath = ""
        switch self {
        case .registerUser(_):
            apiEndPath += WebserviceConstants.userRegistration
        }
        return apiEndPath
    }

    func apiBasePath() -> String {
        switch self {
        case .registerUser(_):
            return WebserviceConstants.baseURL
        }
    }
}

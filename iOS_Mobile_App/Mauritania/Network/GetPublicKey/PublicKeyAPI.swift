//
//  PublicKeyAPI.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 24/02/23.
//

import Foundation

public struct PublicKeyResponse : Codable {
    public var publicKey: String?
    public var timestamp:String?;
    public var error:String?;
    var dictionary: [String: Any] {
        return ["publicKey": publicKey ?? "",
                "error": error ?? "",
                    "timestamp": timestamp ?? ""]
        }
    var nsDictionary: NSDictionary {
        return dictionary as NSDictionary
    }
}
enum getPublicKeyAPI {
    case getPublicKey
}

extension getPublicKeyAPI : APIProtocol {
    func httpMthodType() -> HTTPMethodType {
        var methodType = HTTPMethodType.get
        switch self {
        case .getPublicKey:
            methodType = .get
        }
        return methodType
    }

    func apiEndPath() -> String {
        var apiEndPath = ""
        switch self {
        case .getPublicKey:
            apiEndPath += WebserviceConstants.getPublicKey
        }
        return apiEndPath
    }

    func apiBasePath() -> String {
        switch self {
        case .getPublicKey:
            return WebserviceConstants.baseURL
        }
    }
}

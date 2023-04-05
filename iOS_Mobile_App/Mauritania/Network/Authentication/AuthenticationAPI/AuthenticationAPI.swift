//
//  AuthenticationAPI.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation
enum AuthenticationAPI {
    case authentication(UserRegisterResponse)
    case tokenAuth(TokenAuthRequest)
    case qrRegistration(TokenAuthResponse)
    case establishConnection(EstablishConnectionRequest)
}

extension AuthenticationAPI: APIProtocol {
    func httpMthodType() -> HTTPMethodType {
        var methodType = HTTPMethodType.get
        switch self {
        case .authentication(_):
            methodType = .post
        case .tokenAuth(_):
            methodType = .post
        case .qrRegistration(_):
            methodType = .post
        case .establishConnection(_):
            methodType = .post
        }
        return methodType
    }

    func apiEndPath() -> String {
        var apiEndPath = ""
        switch self {
        case .authentication(_):
            apiEndPath += WebserviceConstants.authenticate
        case .tokenAuth(_):
            return ""
            
        case .qrRegistration(_):
            apiEndPath += WebserviceConstants.authenticate
        case .establishConnection(_):
            apiEndPath += WebserviceConstants.establishConnection
        }
        return apiEndPath
    }

    func apiBasePath() -> String {
        switch self {
        case .authentication(_):
            return WebserviceConstants.authenticationBaseURL
        case .tokenAuth(_):
//            print("")
            return ""
        case .qrRegistration(_):
           return WebserviceConstants.authenticationBaseURL
        case .establishConnection(_):
            return WebserviceConstants.baseURL
        }
        
    }
    
    func apiURL(withToken token1:String) -> String {
        switch self {
        case .authentication(_):
            return ""
        case .tokenAuth(_):
            var components = URLComponents()
            components.scheme = "https"
            components.host = "di-apis.smartdev.ai"
            components.path = "/openam/json/authenticate"

//            components.query = WebserviceConstants.authenticationBaseURL
            components.queryItems = [URLQueryItem(name: "authIndexType", value: "service"),
                                     URLQueryItem(name: "authIndexValue", value: "qr"),
                                     URLQueryItem(name: "ForceAuth", value: "true"),
                                     URLQueryItem(name: "sessionUpgradeSSOTokenId", value: token1)]
            return components.string!
        case .qrRegistration(_):
            var components = URLComponents()
            components.scheme = "https"
            components.host = "di-apis.smartdev.ai"
            components.path = "/openam/json/authenticate"

//            components.query = WebserviceConstants.authenticationBaseURL
            components.queryItems = [URLQueryItem(name: "authIndexType", value: "service"),
                                     URLQueryItem(name: "authIndexValue", value: "qr"),
                                     URLQueryItem(name: "ForceAuth", value: "true"),
                                     URLQueryItem(name: "sessionUpgradeSSOTokenId", value: token1)]
            return components.string!
        case .establishConnection(_):
            return ""
        }
        
    }
}

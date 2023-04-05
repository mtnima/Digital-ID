//
//  WebserviceConfig.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 18/01/23.
//

import Foundation

/// HTTPMethodTypes
public enum HTTPMethodType: String {
    case get     = "GET"
    case post    = "POST"
    case put     = "PUT"
}

/// Protocol to which every API should confirm to.
protocol APIProtocol {
    func httpMthodType() -> HTTPMethodType
    func apiEndPath() -> String
    func apiBasePath() -> String
    func apiURL(withToken token1:String) -> String
}
extension APIProtocol {
    func apiURL(withToken token1:String) -> String {
        return ""
    }
}

/// Request Model type that the APIRequestModel confirms to.
protocol APIModelType {
    var api: APIProtocol { get set }
    var parameters: [String: Any]? { get set }
}

protocol APIModelTypeNew {
    var api: APIProtocol { get set }
    var parameters: TokenAuthResponse? { get set }
}
/// Request Model that holds every api calls parameters, headers and other api details.
struct APIRequestModel: APIModelType {
    var api: APIProtocol
    var parameters: [String: Any]?

    init(api: APIProtocol, parameters: [String: Any]? = nil) {
        self.api = api
        self.parameters = parameters
    }
}
struct APIQRRequestModel: APIModelTypeNew {    
    var api: APIProtocol
    var parameters: TokenAuthResponse?

    init(api: APIProtocol, parameters: TokenAuthResponse? = nil) {
        self.api = api
        self.parameters = parameters
    }
}

/// Responsible for generating common headers for requests.
struct WebserviceConfig {
    /// Generates common headers specific to APIs. Can also accept additional headers if demanded by specific APIs.
    ///
    /// - Returns: A configured header JSON dictionary which includes both common and additional params.\
    ///
    func generateHeaderForToken() -> [String: String] {
        var headerDict = [String: String]()
        headerDict["Content-Type"] = "application/json"
//        headerDict["Authorization"] = "Basic dXNlcjoxdmEzellhJiUzI1E0UkRy"
        return headerDict
    }
    func generateHeader() -> [String: String] {
        var headerDict = [String: String]()
        let user = "user"
        let password = "1va3zYa&%3#Q4RDr"
        let credentialData = "\(user):\(password)".data(using: String.Encoding.utf8)!
        let base64Credentials = credentialData.base64EncodedString(options: [])

        headerDict["Content-Type"] = "application/json"
        headerDict["Authorization"] = "Basic \(base64Credentials)"
        return headerDict
    }
    
    func generateHeader(withId id:String, andWithPassword password:String) -> [String: String] {
        var headerDict = [String: String]()
//        headerDict["Content-Type"] = "application/json"
//        headerDict["Authorization"] = "Basic dXNlcjoxdmEzellhJiUzI1E0UkRy"
//        headerDict["Content-Type"] = "application/json"
        headerDict["X-OpenAM-Username"] = id
        headerDict["X-OpenAm-Password"] = password
        return headerDict
    }
}

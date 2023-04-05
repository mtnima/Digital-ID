//
//  WebserviceHelper.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 18/01/23.
//

import Foundation

enum NetworkError: Error {
    case incorrectData(Data)
    case incorrectURL
    case unknown
}

typealias WebServiceCompletionBlock = (Result<Data, Error>) -> Void

/// Helper class to prepare request(adding headers & clubbing base URL) & perform API request.
struct WebserviceHelper {
    
    /// Performs a API request which is called by any service request class.
    /// It also performs an additional task of validating the auth token and refreshing if necessary
    ///
    /// - Parameters:
    ///   - apiModel: APIModelType which contains the info about api endpath, header & http method type.
    ///   - completion: Request completion handler.
    /// - Returns: Returns a URLSessionDataTask instance.
    @discardableResult public static func requestAPI(apiModel: APIModelType, completion: @escaping WebServiceCompletionBlock) -> URLSessionDataTask? {
        var request : URLRequest!
        if apiModel.api.httpMthodType().rawValue == "GET"{
            var escapedAddress = (apiModel.api.apiBasePath()+apiModel.api.apiEndPath()).addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)!
            request = URLRequest(url: URL(string: escapedAddress)!)
            request.httpMethod = apiModel.api.httpMthodType().rawValue
            request.allHTTPHeaderFields = WebserviceConfig().generateHeader()
        }
        else {
            var escapedAddress = ""
            let token = apiModel.parameters?["tokenId"] as? String ?? ""
            let authId = apiModel.parameters?["authId"] as? String ?? ""
            if apiModel.api.apiURL(withToken: token) == "" && authId == ""{
                escapedAddress = (apiModel.api.apiBasePath()+apiModel.api.apiEndPath()).addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)!
            }
            else {
                if authId == ""{
                    escapedAddress = apiModel.api.apiURL(withToken: apiModel.parameters?["tokenId"] as? String ?? "")
                }
                else{
                    escapedAddress = apiModel.api.apiURL(withToken: apiModel.parameters?["token"] as? String ?? "")
                }
            }
            request = URLRequest(url: URL(string: escapedAddress)!)
            request.httpMethod = apiModel.api.httpMthodType().rawValue
            if apiModel.api.apiEndPath() == WebserviceConstants.authenticate && token == "" && authId == ""{
                request.allHTTPHeaderFields = WebserviceConfig().generateHeader(withId: apiModel.parameters!["pin"] as! String, andWithPassword: apiModel.parameters!["value"] as! String)
            }
            else if token == ""{
                if apiModel.api.apiEndPath() == WebserviceConstants.authenticate{
                    request.allHTTPHeaderFields = WebserviceConfig().generateHeaderForToken()
                }
                else{
                    request.allHTTPHeaderFields = WebserviceConfig().generateHeader()
                }
                if let params = apiModel.parameters {
                    do {
                        var tempPara = params
                        tempPara["token"] = nil
                        request.httpBody = try JSONSerialization.data(withJSONObject: tempPara as Any, options: .prettyPrinted)
                    } catch let error {
                        print(error.localizedDescription)
                    }
                }
            }
            else{
            }
        }
        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data, error == nil else {
                completion(.failure(error ?? NetworkError.unknown))
                return
            }

            if let httpStatus = response as? HTTPURLResponse,  ![200, 201].contains(httpStatus.statusCode) {
                completion(.failure(NetworkError.incorrectData(data)))
                return
            }
            completion(.success(data))

        }
        
        task.resume()
        return task
    }
    
    @discardableResult public static func requestQR(apiModel: APIQRRequestModel, completion: @escaping WebServiceCompletionBlock) -> URLSessionDataTask? {
        var escapedAddress = ""
        escapedAddress = apiModel.api.apiURL(withToken: apiModel.parameters?.token as? String ?? "")
        var request = URLRequest(url: URL(string: escapedAddress)!)
        request.httpMethod = apiModel.api.httpMthodType().rawValue
        request.allHTTPHeaderFields = WebserviceConfig().generateHeaderForToken()
            
            if let params = apiModel.parameters {
                do {
                    var tempPara = params
                    tempPara.token = nil
                    request.httpBody = try JSONEncoder().encode(tempPara)

//                    request.httpBody = try JSONSerialization.data(withJSONObject: tempPara as Any, options: .prettyPrinted)
                } catch let error {
                    print(error.localizedDescription)
                }
            }

        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data, error == nil else {
                completion(.failure(error ?? NetworkError.unknown))
                return
            }

            if let httpStatus = response as? HTTPURLResponse,  ![200, 201].contains(httpStatus.statusCode) {
                completion(.failure(NetworkError.incorrectData(data)))
                return
            }
            completion(.success(data))

        }
        
        task.resume()
        return task
    }

}
class DictionaryEncoder {

    private let encoder = JSONEncoder()

    var dateEncodingStrategy: JSONEncoder.DateEncodingStrategy {
        set { encoder.dateEncodingStrategy = newValue }
        get { return encoder.dateEncodingStrategy }
    }

    var dataEncodingStrategy: JSONEncoder.DataEncodingStrategy {
        set { encoder.dataEncodingStrategy = newValue }
        get { return encoder.dataEncodingStrategy }
    }

    var nonConformingFloatEncodingStrategy: JSONEncoder.NonConformingFloatEncodingStrategy {
        set { encoder.nonConformingFloatEncodingStrategy = newValue }
        get { return encoder.nonConformingFloatEncodingStrategy }
    }

    var keyEncodingStrategy: JSONEncoder.KeyEncodingStrategy {
        set { encoder.keyEncodingStrategy = newValue }
        get { return encoder.keyEncodingStrategy }
    }

    func encode<T>(_ value: T) throws -> [String: Any] where T : Encodable {
        let data = try encoder.encode(value)
        return try JSONSerialization.jsonObject(with: data, options: .allowFragments) as! [String: Any]
    }
}

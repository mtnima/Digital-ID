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
        let escapedAddress = (apiModel.api.apiBasePath()+apiModel.api.apiEndPath()).addingPercentEncoding(withAllowedCharacters: CharacterSet.urlQueryAllowed)
        var request = URLRequest(url: URL(string: escapedAddress!)!)
        request.httpMethod = apiModel.api.httpMthodType().rawValue
        if apiModel.api.apiEndPath() == WebserviceConstants.authenticate{
            request.allHTTPHeaderFields = WebserviceConfig().generateHeader(withId: apiModel.parameters["pin"] as! String, andWithPassword: apiModel.parameters["value"] as! String)
        }
        else {
            request.allHTTPHeaderFields = WebserviceConfig().generateHeader()
            if let params = apiModel.parameters {
                do {
                    request.httpBody = try JSONSerialization.data(withJSONObject: params as Any, options: .prettyPrinted)
                } catch let error {
                    print(error.localizedDescription)
                }
            }
        }

       

        let task = URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data, error == nil else {
                completion(.failure(error ?? NetworkError.unknown))
                return
            }

            if let httpStatus = response as? HTTPURLResponse,  ![200, 201].contains(httpStatus.statusCode) {
                completion(.failure(NetworkError.incorrectData(data)))
            }
            completion(.success(data))

        }
        
        task.resume()
        return task
    }

}

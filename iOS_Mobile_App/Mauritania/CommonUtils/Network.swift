//
//  Network.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 17/01/23.
//

import Foundation


// 1
enum HTTPMethod: String {
    case get = "GET"
    case post = "POST"
    case put = "PUT"
    case patch = "PATCH"
    case delete = "DELETE"
}

// 2
protocol DataRequest {
    associatedtype Response
    
    var url: String { get }
    var method: HTTPMethod { get }
    var headers: [String : String] { get }
    var queryItems: [String : String] { get }
    
    func decode(_ data: Data) throws -> Response
}

// 3
extension DataRequest where Response: Decodable {
    func decode(_ data: Data) throws -> Response {
        let decoder = JSONDecoder()
        return try decoder.decode(Response.self, from: data)
    }
}

// 4
extension DataRequest {
    var headers: [String : String] {
        [:]
    }
    
    var queryItems: [String : String] {
        [:]
    }
}

// 1
protocol NetworkService {
    func request<Request: DataRequest>(_ request: Request, completion: @escaping (Result<Request.Response, Error>) -> Void)
}
enum ErrorResponse: String {
    case invalidEndpoint = "Invalid endpoint"
    case invalidResponse = "Invalid Response"
    case invalidParsing = "Invalid Parsing"
    case patch = "PATCH"
    case delete = "DELETE"
}
// 2
final class DefaultNetworkService: NetworkService {
    
    func request<Request: DataRequest>(_ request: Request, completion: @escaping (Result<Request.Response, Error>) -> Void) {
    
        // 3
        guard var urlComponent = URLComponents(string: request.url) else {
            let error = NSError(
                domain: ErrorResponse.invalidEndpoint.rawValue,
                code: 404,
                userInfo: nil
            )
            
            return completion(.failure(error))
        }
        
        // 4
        var queryItems: [URLQueryItem] = []
        
        request.queryItems.forEach {
            let urlQueryItem = URLQueryItem(name: $0.key, value: $0.value)
            urlComponent.queryItems?.append(urlQueryItem)
            queryItems.append(urlQueryItem)
        }
        
        urlComponent.queryItems = queryItems
        
        // 5
        guard let url = urlComponent.url else {
            let error = NSError(
                domain: ErrorResponse.invalidEndpoint.rawValue,
                code: 404,
                userInfo: nil
            )
            
            return completion(.failure(error))
        }
        
        // 6
        var urlRequest = URLRequest(url: url)
        urlRequest.httpMethod = request.method.rawValue
        urlRequest.allHTTPHeaderFields = request.headers
        
        // 7
        URLSession.shared.dataTask(with: urlRequest) { (data, response, error) in
            if let error = error {
                return completion(.failure(error))
            }
            
            guard let response = response as? HTTPURLResponse, 200..<300 ~= response.statusCode else {
                return completion(.failure(NSError()))
            }
            
            guard let data = data else {
                return completion(.failure(NSError()))
            }
            
            do {
                try completion(.success(request.decode(data)))
            } catch let error as NSError {
                completion(.failure(error))
            }
        }
        .resume()
    }
}

class Network:NSObject {
//    func apiCall(completion:@escaping())
}

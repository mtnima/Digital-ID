//
//  AuthenticationRequest.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation
typealias AuthResponse = (Result<AuthenticationResponse, Error>) -> Void
typealias TokenAuthoResponse = (Result<TokenAuthResponse, Error>) -> Void
typealias qrResponse = (Result<QRRequest, Error>) -> Void
typealias establishResponse = (Result<enstablishConnectionResponse, Error>) -> Void

protocol AuthenticationRequestType {
    @discardableResult func Authentication(apiQueryModel: UserRegisterResponse, _ completion: @escaping AuthResponse) -> URLSessionDataTask?
    @discardableResult func TokenAuthentication(apiQueryModel: TokenAuthRequest, _ completion: @escaping TokenAuthoResponse) -> URLSessionDataTask?
    @discardableResult func qrAuthentication(apiQueryModel: TokenAuthResponse, _ completion: @escaping TokenAuthoResponse) -> URLSessionDataTask?
    @discardableResult func EstablishConnectionWith(apiQueryModel: EstablishConnectionRequest, _ completion: @escaping establishResponse) -> URLSessionDataTask?

}

struct AuthenticationRequest: AuthenticationRequestType {
    func qrAuthentication(apiQueryModel: TokenAuthResponse, _ completion: @escaping TokenAuthoResponse) -> URLSessionDataTask? {
        let authenticateRequestModel = APIQRRequestModel(api: AuthenticationAPI.qrRegistration(apiQueryModel), parameters: apiQueryModel)
        return WebserviceHelper.requestQR(apiModel: authenticateRequestModel, completion: { response in
            switch response {
            case .success(let serverData):
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: TokenAuthResponse.self, completion: { (allRestaurantResponse, error) in
                    if let parserError = error {
                        completion(.failure(parserError))
                        return
                    }

                    if let restaurantResponse = allRestaurantResponse {
                        completion(.success(restaurantResponse))
                        return
                    }
                })
            case .failure(let error):
                completion(.failure(error))
            }
        })
    }
    func EstablishConnectionWith(apiQueryModel: EstablishConnectionRequest, _ completion: @escaping establishResponse) -> URLSessionDataTask? {
        let apimodel = APIRequestModel(api: AuthenticationAPI.establishConnection(apiQueryModel), parameters: apiQueryModel.dictionary)
        return WebserviceHelper.requestAPI(apiModel: apimodel) { response in
            switch response {
            case .success(let serverData):
                
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: enstablishConnectionResponse.self, completion: { (allRestaurantResponse, error) in
//                    if let parserError = error {
//                        completion(.failure(parserError))
//                        return
//                    }
                    let response = enstablishConnectionResponse(username: "dummy")
                    completion(.success(allRestaurantResponse ?? response))
//                    if let restaurantResponse = allRestaurantResponse {
//                        completion(.success(restaurantResponse))
//                        return
//                    }
                })
                print("Success")
            case .failure(let error):
                completion(.failure(error))
                print("Error")
                return 
            }
        }
    }
    func TokenAuthentication(apiQueryModel: TokenAuthRequest, _ completion: @escaping TokenAuthoResponse) -> URLSessionDataTask? {
        let authenticateRequestModel = APIRequestModel(api: AuthenticationAPI.tokenAuth(apiQueryModel),parameters: apiQueryModel.dictionary)
        return WebserviceHelper.requestAPI(apiModel: authenticateRequestModel) { response in
            switch response {
            case .success(let serverData):
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: TokenAuthResponse.self, completion: { (allRestaurantResponse, error) in
                    if let parserError = error {
                        completion(.failure(parserError))
                        return
                    }

                    if let restaurantResponse = allRestaurantResponse {
                        completion(.success(restaurantResponse))
                        return
                    }
                })
            case .failure(let error):
                completion(.failure(error))
                return
            }
        }
    }
    
    func Authentication(apiQueryModel: UserRegisterResponse, _ completion: @escaping AuthResponse) -> URLSessionDataTask? {
        let authenticateRequestModel = APIRequestModel(api: AuthenticationAPI.authentication(apiQueryModel),parameters: apiQueryModel.dictionary)
        return WebserviceHelper.requestAPI(apiModel: authenticateRequestModel) { response in
            switch response {
            case .success(let serverData):
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: AuthenticationResponse.self, completion: { (allRestaurantResponse, error) in
                    if let parserError = error {
                        completion(.failure(parserError))
                        return
                    }

                    if let restaurantResponse = allRestaurantResponse {
                        completion(.success(restaurantResponse))
                        return
                    }
                })
            case .failure(let error):
                completion(.failure(error))
            }
        }
    }
}

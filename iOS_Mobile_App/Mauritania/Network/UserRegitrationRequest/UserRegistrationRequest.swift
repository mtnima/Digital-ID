//
//  UserRegistrationRequest.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation
typealias RegisterResponse = (Result<UserRegisterResponse, Error>) -> Void

protocol UserRegisterRequestType {
    @discardableResult func UserRegister(apiQueryModel: UserRegisterRequest, completion: @escaping RegisterResponse) -> URLSessionDataTask?
}

struct UserRegisterRequests: UserRegisterRequestType {
    
    @discardableResult func UserRegister(apiQueryModel: UserRegisterRequest, completion: @escaping RegisterResponse) -> URLSessionDataTask? {
        
        let contactRequestModel = APIRequestModel(api: UserRegistrationAPI.registerUser(apiQueryModel),parameters: apiQueryModel.dictionary)
        return WebserviceHelper.requestAPI(apiModel: contactRequestModel) { response in
            switch response {
            case .success(let serverData):
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: UserRegisterResponse.self, completion: { (allRestaurantResponse, error) in
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

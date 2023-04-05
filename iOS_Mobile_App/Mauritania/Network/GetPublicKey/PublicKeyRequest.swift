//
//  PublicKeyRequest.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 24/02/23.
//

import Foundation
typealias publicKeyResponse = (Result<PublicKeyResponse, Error>) -> Void

protocol PublicKeyRequestType {
    @discardableResult func getPublicKey(completion: @escaping publicKeyResponse) -> URLSessionDataTask?
}
struct PublicKeyRequests: PublicKeyRequestType {
    
    @discardableResult func getPublicKey(completion: @escaping publicKeyResponse) -> URLSessionDataTask? {
        
        let publicKeyModel = APIRequestModel(api: getPublicKeyAPI.getPublicKey)
        return WebserviceHelper.requestAPI(apiModel: publicKeyModel) { response in
            switch response {
            case .success(let serverData):
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: PublicKeyResponse.self, completion: { (allRestaurantResponse, error) in
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

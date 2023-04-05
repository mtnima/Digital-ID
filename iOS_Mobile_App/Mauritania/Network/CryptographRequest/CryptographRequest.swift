//
//  CryptographRequest.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 18/01/23.
//

import Foundation


typealias GetCryptographResponse = (Result<CryptographyResponse, Error>) -> Void

protocol CryptographServiceRequestType {
    @discardableResult func createCryptograph(apiQueryModel: CryptographRequest, completion: @escaping GetCryptographResponse) -> URLSessionDataTask?
}

struct CryptographServiceRequests: CryptographServiceRequestType {
    
    @discardableResult func createCryptograph(apiQueryModel: CryptographRequest, completion: @escaping GetCryptographResponse) -> URLSessionDataTask? {
        
        let contactRequestModel = APIRequestModel(api: CryptographAPI.createCryptograph(apiQueryModel),parameters: apiQueryModel.dictionary)
        return WebserviceHelper.requestAPI(apiModel: contactRequestModel) { response in
            switch response {
            case .success(let serverData):
                JSONResponseDecoder.decodeFrom(serverData, returningModelType: CryptographyResponse.self, completion: { (allRestaurantResponse, error) in
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

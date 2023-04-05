//
//  CryptographAPI.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 18/01/23.
//

import Foundation

//struct RestaurantAPIQueryParamModel {
////    let coordinate: CLLocationCoordinate2D
////    let lookupRadius: Int
//}

///  This API will hold all APIs related to restaurant
enum CryptographAPI {
    case createCryptograph(CryptographRequest)
}

extension CryptographAPI: APIProtocol {
    func httpMthodType() -> HTTPMethodType {
        var methodType = HTTPMethodType.get
        switch self {
        case .createCryptograph(_):
            methodType = .post
        }
        return methodType
    }

    func apiEndPath() -> String {
        var apiEndPath = ""
        switch self {
        case .createCryptograph(_):
            apiEndPath += WebserviceConstants.getCryptography
        }
        return apiEndPath
    }

    func apiBasePath() -> String {
        switch self {
        case .createCryptograph(_):
            return WebserviceConstants.baseURL
        }
    }
}


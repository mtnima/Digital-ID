//
//  PostScannerInteractor.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 01/03/23.
//

import Foundation
class PostScannerInteractor:PostScannerPresenterToInteractorProtocol{
    var presenter: PostScannerInteractorToPresenter?
    
    func authenticateUserWith(demographic: UserRegisterResponse, andWith barcode: String) {
        let request = EstablishConnectionRequest(username: demographic.pin, qrAuth: barcode)
        AuthenticationRequest().EstablishConnectionWith(apiQueryModel: request) { [weak self] apiResult in
            DispatchQueue.main.async {
                switch apiResult {
                case .success(_):
                    self?.presenter?.qrRegisterWithResponse(response: nil, andWithSuccess: true)
                    print("Success")
                case .failure(_):
                    self?.presenter?.qrRegisterWithResponse(response: nil, andWithSuccess: false)
                    print("Failure")
                }
            }
        }
    }
}

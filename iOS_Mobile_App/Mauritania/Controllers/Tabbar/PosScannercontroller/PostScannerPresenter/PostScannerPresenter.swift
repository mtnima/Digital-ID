//
//  PostScannerPresenter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 01/03/23.
//

import Foundation
class PostScannerPresenter:PostScannerViewtoPresenterProtocol{
    var interactor: PostScannerPresenterToInteractorProtocol?
    
    var view: PostScannerPresenterToViewProtocol?
    
    func moveToNextController() {
        
    }
    
    func authenticateUserWith(demographic: UserRegisterResponse, andWith barcode: String) {
        interactor?.authenticateUserWith(demographic: demographic, andWith: barcode)
    }
    
    
}
extension PostScannerPresenter:PostScannerInteractorToPresenter{
    func qrRegisterWithResponse(response: TokenAuthResponse?, andWithSuccess success: Bool) {
        view?.qrRegisterWithResponse(response: response, andWithSuccess: success)
    }
    
    
}

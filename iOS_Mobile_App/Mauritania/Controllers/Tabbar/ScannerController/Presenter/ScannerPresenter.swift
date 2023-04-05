//
//  ScannerPresenter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation
import UIKit



class ScannerPresenter:ScannerViewtoPresenterProtocol{
    func verifyUserWithLivenessData(demographic: UserRegisterResponse, andWith barcode: String, withLivenessData livenessData: Data?) {
        interactor?.verifyUserWithLivenessData(demographic: demographic, andWith: barcode, withLivenessData: livenessData)
    }
    
    
    
    var interactor: ScannerPresenterToInteractorProtocol?
    
    var view: ScannerPresenterToViewProtocol?
    
    var rouer: ScannerPresenterToRouterProtocol?
    
    func openScanner(withController controller: ScannerViewController?){
        interactor?.openScanner(withController: controller)
    }
    
    func moveToNextController() {
        rouer?.moveToNextController()
    }
//    func authenticateUserWith(demographic: UserRegisterResponse, andWith barcode: String) {
//        interactor?.authenticateUserWith(demographic: demographic, andWith: barcode)
//    }
//    func authenticationWith(token: String, andwithScanCode scanner: String) {
//        interactor?.authenticationWith(token: token, andwithScanCode: scanner)
//    }
//    func registerQRCodeWith(request: TokenAuthResponse) {
//        interactor?.registerQRCodeWith(request: request)
//    }
}
extension ScannerPresenter:ScannerInteractorToPresenterProtocol{
//    func authenticationResponse(withResponse response: AuthenticationResponse?, withError error: String?) {
////        view?.authenticationResponse(withResponse: response, withError: error)
//    }
    
    func userAuthorized() {
        view?.userAuthorized()
    }    
    func codeFromScanner(withCode code: String) {
        view?.codeFromScanner(withCode: code)
    }
//    func tokenAutherizedWithResponse(response: TokenAuthResponse?, andWithSuccess success: Bool) {
////        view?.tokenAutherizedWithResponse(response: response, andWithSuccess: success)
//    }
//    func qrRegisterWithResponse(response: TokenAuthResponse?, andWithSuccess success: Bool) {
////        view?.qrRegisterWithResponse(response: response, andWithSuccess: success)
//    }
    
}

//
//  SplashPresenter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import Foundation
import UIKit

class SplashPresenter: splashViewToPresenterProtocol {
    var view: presenterToSplashViewProtocol?
    
    var interactor: presenterToSplashInteractoreProtocol?
    
    var router: presentorToRouterProtocol?

    func getLiscense() {
        interactor?.ValidateDocumentReader(withName: "regula.license")
    }
    func moveToHomeViewController(navigationConroller navigationController:UINavigationController){
        router?.pushToHomeViewController(navigationConroller: navigationController)
    }
}
extension SplashPresenter:interactoreToPresenterProtocol {
    func documentReaderValidationResult(with status: Bool, andWith error: Error?) {
        self.view?.documentReaderValidationResult(with: status, andWith: error)
    }
}


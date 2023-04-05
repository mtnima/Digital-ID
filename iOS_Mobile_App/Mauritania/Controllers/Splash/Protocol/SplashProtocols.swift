//
//  Protocols.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import Foundation
import UIKit

protocol splashViewToPresenterProtocol: AnyObject {
    var view: presenterToSplashViewProtocol? {get set}
    var interactor: presenterToSplashInteractoreProtocol? {get set}
    var router: presentorToRouterProtocol? {get set}

    func getLiscense()
    func moveToHomeViewController(navigationConroller navigationController:UINavigationController)
}
protocol presenterToSplashInteractoreProtocol: AnyObject {

    var presentor : interactoreToPresenterProtocol? {get set}
    func ValidateDocumentReader(withName fileName:String?)
}
protocol interactoreToPresenterProtocol: AnyObject {
    func documentReaderValidationResult(with status:Bool, andWith error:Error?)
}
protocol presenterToSplashViewProtocol: AnyObject {
    func documentReaderValidationResult(with status:Bool, andWith error:Error?)
}
protocol presentorToRouterProtocol: AnyObject{
    static func createModule()->SplashViewController
    func pushToHomeViewController(navigationConroller:UINavigationController)
}


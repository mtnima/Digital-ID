//
//  ScannerProtocol.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation
import UIKit
protocol ScannerPresenterToViewProtocol:AnyObject {
    func codeFromScanner(withCode code:String)
//    func authenticationResponse(withResponse response:AuthenticationResponse?, withError error:String?)
//    func tokenAutherizedWithResponse(response:TokenAuthResponse?, andWithSuccess success:Bool)
//    func qrRegisterWithResponse(response:TokenAuthResponse?, andWithSuccess success:Bool)
    func userAuthorized()
}

protocol ScannerPresenterToInteractorProtocol:AnyObject {
    var presenter:ScannerInteractorToPresenterProtocol?{get set}
    func openScanner(withController controller:ScannerViewController?)
//    func authenticateUserWith(demographic:UserRegisterResponse, andWith barcode:String)
//    func authenticationWith(token:String, andwithScanCode scanner:String)
//    func registerQRCodeWith(request:TokenAuthResponse)
    func verifyUserWithLivenessData(demographic:UserRegisterResponse, andWith barcode:String, withLivenessData livenessData:Data?)
}
protocol ScannerPresenterToRouterProtocol:AnyObject {
    func moveToNextController()
}
protocol ScannerViewtoPresenterProtocol:AnyObject{
    var interactor: ScannerPresenterToInteractorProtocol?{get set}
    var view: ScannerPresenterToViewProtocol?{get set}
    var rouer: ScannerPresenterToRouterProtocol?{get set}
    func openScanner(withController controller:ScannerViewController?)
    func moveToNextController()
//    func authenticateUserWith(demographic:UserRegisterResponse, andWith barcode:String)
//    func authenticationWith(token:String, andwithScanCode scanner:String)
//    func registerQRCodeWith(request:TokenAuthResponse)
    func verifyUserWithLivenessData(demographic:UserRegisterResponse, andWith barcode:String, withLivenessData livenessData:Data?)
}
protocol ScannerInteractorToPresenterProtocol:AnyObject {
    func codeFromScanner(withCode code:String)
//    func authenticationResponse(withResponse response:AuthenticationResponse?, withError error:String?)
//    func tokenAutherizedWithResponse(response:TokenAuthResponse?, andWithSuccess success:Bool)
//    func qrRegisterWithResponse(response:TokenAuthResponse?, andWithSuccess success:Bool)
    func userAuthorized()
}

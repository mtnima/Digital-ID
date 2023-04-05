//
//  PostScannerProtocol.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 01/03/23.
//

import Foundation



protocol PostScannerViewtoPresenterProtocol:AnyObject {
    var interactor: PostScannerPresenterToInteractorProtocol?{get set}
    var view: PostScannerPresenterToViewProtocol?{get set}
//    var rouer: ScannerPresenterToRouterProtocol?{get set}
    func moveToNextController()
    func authenticateUserWith(demographic:UserRegisterResponse, andWith barcode:String)
}
protocol PostScannerPresenterToInteractorProtocol:AnyObject {
    var presenter:PostScannerInteractorToPresenter?{get set}
    func authenticateUserWith(demographic:UserRegisterResponse, andWith barcode:String)
}
protocol PostScannerInteractorToPresenter:AnyObject {
    func qrRegisterWithResponse(response:TokenAuthResponse?, andWithSuccess success:Bool)
}
protocol PostScannerPresenterToViewProtocol:AnyObject {
    func qrRegisterWithResponse(response:TokenAuthResponse?, andWithSuccess success:Bool)
}
protocol PostScannerPresenterToRouterProtocol:AnyObject {
    func moveToNextController()
}

//
//  PostScannerRouter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 01/03/23.
//

import Foundation

class PostScannerRouter:PostScannerPresenterToRouterProtocol {
    static func createModule() -> PostScannerViewController {
        let postScannerVC = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "postscannercontroller") as! PostScannerViewController
        let splashPresentor: PostScannerViewtoPresenterProtocol & PostScannerInteractorToPresenter = PostScannerPresenter()
        let interactor: PostScannerPresenterToInteractorProtocol = PostScannerInteractor()
//        let router: PostScannerPresenterToRouterProtocol = PostScannerRouter()
        
        postScannerVC.presenter = splashPresentor
        splashPresentor.view = postScannerVC
//        splashPresentor.router = router
        splashPresentor.interactor = interactor
        
        interactor.presenter = splashPresentor
        return postScannerVC
    }
    func moveToNextController() {
        
    }
}

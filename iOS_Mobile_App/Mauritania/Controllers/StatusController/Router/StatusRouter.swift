//
//  StatusRouter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 13/01/23.
//

import Foundation
import UIKit

class StatusRouter{
    static func createModule() -> StatusViewController {
        let view = mainstoryboard.instantiateViewController(withIdentifier: "Statuscontroller") as! StatusViewController
        
//        let infoPresenter: ViewToPresenterInfoProtocol & InteractorToPresenterInfoProtocol = InfoPresenter()
//        let interactor: PresenterToInteractorInfoProtocol = InfoInterActor()
//        let router: PresenterToRouterInfoProtocol = InfoRouter()
////
//        view.presenter = infoPresenter
//        infoPresenter.view = view
//
//        infoPresenter.router = router
//        infoPresenter.interactor = interactor
////
//        interactor.presenter = infoPresenter
        
        return view
    }
    
    static var mainstoryboard: UIStoryboard {
        return UIStoryboard(name:"Main",bundle: Bundle.main)
    }
    func pushToHomeViewController(navigationConroller navigationController:UINavigationController){
//        let homeModule = HomeRouter.createMovieModule()
//        navigationController.pushViewController(homeModule,animated: true)

    }
}

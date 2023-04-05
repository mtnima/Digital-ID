//
//  SplashRouter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import Foundation
import UIKit


class SplashRouter:presentorToRouterProtocol{
    
    static func createModule() -> SplashViewController {
        
        let view = mainstoryboard.instantiateViewController(withIdentifier: "Splashcontroller") as! SplashViewController
        
        let splashPresentor: splashViewToPresenterProtocol & interactoreToPresenterProtocol = SplashPresenter()
        let interactor: presenterToSplashInteractoreProtocol = SplashInteractor()
        let router: presentorToRouterProtocol = SplashRouter()
        
        view.presentorDelegate = splashPresentor
        splashPresentor.view = view
        splashPresentor.router = router
        splashPresentor.interactor = interactor
        
        interactor.presentor = splashPresentor
        return view
    }
    
    
    
    static var mainstoryboard: UIStoryboard {
        return UIStoryboard(name:"Main",bundle: Bundle.main)
    }
    func pushToHomeViewController(navigationConroller navigationController:UINavigationController){
//        let homeModule = HomeRouter.createMovieModule()
        
        let userdefaults = UserDefaults.standard
        if let isLogged = userdefaults.value(forKey: USERDEFAULTS().islogin) as? Bool, isLogged == true{
            let homeModule = HomeRouter.createTabView()
            homeModule.selectedIndex = 1
            
            let hometabbarcontroller = homeModule.viewControllers![1] as! HomeTabViewController
            hometabbarcontroller.documentResult = userdefaults.getDocumentScannerResult()
            hometabbarcontroller.livenessData = userdefaults.getLivenessData()
            hometabbarcontroller.response = userdefaults.getCryptoResponseData()
            hometabbarcontroller.registerResponse = userdefaults.getRegisterResponseData()

            let scannerController = homeModule.viewControllers![0] as! ScannerViewController
            scannerController.documentResult = userdefaults.getDocumentScannerResult()
            scannerController.livenessData = userdefaults.getLivenessData()
            scannerController.response = userdefaults.getCryptoResponseData()
            scannerController.registerResponse = userdefaults.getRegisterResponseData()
            navigationController.pushViewController(homeModule,animated: true)
            
//            let navigationController = UINavigationController()
//            navigationController.viewControllers = [homeModule]
//            navigationController.navigationBar.isHidden = true
//            if let windowScene = scene as? UIWindowScene {
//                let window = UIWindow(windowScene: windowScene)
//                window.rootViewController = navigationController
//                self.window = window
//                window.makeKeyAndVisible()
//            }
        }
        else{
            let homeModule = HomeRouter.createTutorialModule()
            navigationController.pushViewController(homeModule,animated: true)

        }

    }
}

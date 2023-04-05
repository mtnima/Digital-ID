//
//  HomeRouter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import DocumentReader

class HomeRouter:HomePresenterToRouterProtocol{
    
    static func createTabView() -> TabViewController {
        
        let view = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "tabbarcontroller") as! TabViewController
        view.selectedIndex = 1
        
        let scannerVC = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "scannercontroller") as! ScannerViewController
        let infoPresenter: ScannerViewtoPresenterProtocol & ScannerInteractorToPresenterProtocol = ScannerPresenter()
        let interactor: ScannerPresenterToInteractorProtocol = ScannerInteractor()
        let router: ScannerPresenterToRouterProtocol = ScannerRouter()
        ////
        scannerVC.presenter = infoPresenter
        infoPresenter.view = scannerVC

        infoPresenter.rouer = router
        infoPresenter.interactor = interactor
//
        interactor.presenter = infoPresenter

        let homeVC = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "hometabbar") as! HomeTabViewController
        let settingVC = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "settingcontroller") as! SettingViewController
        view.viewControllers = [scannerVC,homeVC,settingVC]
       
        
//        let presenter: HomeViewtoPresenterProtocol & HomeInteractorToPresenterProtocol = HomePresnter()
//        let interactor: HomePresenterToInteractorProtocol = HomeInteractor()
//        let router:HomePresenterToRouterProtocol = HomeRouter()
////
//        view.presenter = presenter
//        presenter.view = view
//
//        presenter.rouer = router
////        presenter.router = router
//        presenter.interactor = interactor
//        interactor.presenter = presenter
        
        return view
        
    }
    static func createTutorialModule() -> TutorialViewController {
        
        let view = HomeRouter.mainstoryboard.instantiateViewController(withIdentifier: "tutorialcontroller") as! TutorialViewController
        return view
        
    }
    
    static func createHomeModele() -> ViewController {
        
        let view = HomeRouter.mainstoryboard.instantiateViewController(withIdentifier: "Homecontroller") as! ViewController

        
        let presenter: HomeViewtoPresenterProtocol & HomeInteractorToPresenterProtocol = HomePresnter()
        let interactor: HomePresenterToInteractorProtocol = HomeInteractor()
        let router:HomePresenterToRouterProtocol = HomeRouter()
//
        view.presenter = presenter
        presenter.view = view
        
        presenter.rouer = router
//        presenter.router = router
        presenter.interactor = interactor
        interactor.presenter = presenter
        
        return view
        
    }
    static var mainstoryboard: UIStoryboard {
        return UIStoryboard(name:"Main",bundle: Bundle.main)
    }
    static var tabstoryboard: UIStoryboard {
        return UIStoryboard(name:"Tabbar",bundle: Bundle.main)
    }
    func moveToInfoController(withController controller: UINavigationController, withDocumentResult result: DocumentReaderResults?, andTemplateData template: Data) {
        
//        let infoModule = InfoRouter.createModule(withDocument: result, andWithFaceTemplate: template)
//        controller.pushViewController(infoModule,animated: true)

        let stepModeul = StepRouter.createStepModele(withDocument: result, andWithFaceTemplate: template)
        controller.pushViewController(stepModeul,animated: true)

    }
}

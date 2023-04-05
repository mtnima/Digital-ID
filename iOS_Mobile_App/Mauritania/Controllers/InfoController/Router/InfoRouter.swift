//
//  InfoRouter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import DocumentReader
class InfoRouter:PresenterToRouterInfoProtocol{
    
    static func createModule(withDocument result:DocumentReaderResults?, andWithFaceTemplate faceTemplate:Data?) -> InformationViewController {
        let view = mainstoryboard.instantiateViewController(withIdentifier: "InformationController") as! InformationViewController
        view.idCardFaceTemplate = faceTemplate
        view.documentRreaderResult = result
        let infoPresenter: ViewToPresenterInfoProtocol & InteractorToPresenterInfoProtocol = InfoPresenter()
        let interactor: PresenterToInteractorInfoProtocol = InfoInterActor()
        let router: PresenterToRouterInfoProtocol = InfoRouter()
//
        view.presenter = infoPresenter
        infoPresenter.view = view
        
        infoPresenter.router = router
        infoPresenter.interactor = interactor
//
        interactor.presenter = infoPresenter
        return view
    }
    static var mainstoryboard: UIStoryboard {
        return UIStoryboard(name:"Main",bundle: Bundle.main)
    }
    func pushToHomeViewController(navigationConroller navigationController: UINavigationController, scanndDocumentResult documentRreaderResult: DocumentReaderResults?, livenessFaceData liveness: Data, withResponse response:CryptographyResponse?, withRegisterResponse registerResponse: UserRegisterResponse?) {
        let statusController = StatusRouter.createModule()
        statusController.livenessData = liveness
        statusController.documentResult = documentRreaderResult
        statusController.response = response
        statusController.registerResponse = registerResponse
        navigationController.pushViewController(statusController,animated: true)
    }
}

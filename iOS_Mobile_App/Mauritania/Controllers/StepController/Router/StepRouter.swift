//
//  StepRouter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 24/01/23.
//

import Foundation
import Foundation
import UIKit
import DocumentReader


class StepRouter:StepPresenterToRouterProtocol{

    static func createStepModele(withDocument result:DocumentReaderResults?, andWithFaceTemplate faceTemplate:Data?) -> StepsViewController {
        let view = mainstoryboard.instantiateViewController(withIdentifier: "stepsviewcontroller") as! StepsViewController
        let infoPresenter: StepViewtoPresenterProtocol & StepInteractorToPresenterProtocol = StepPresenter()
        let interactor : StepPresenterToInteractorProtocol = StepInteractor()
        let router: StepPresenterToRouterProtocol = StepRouter()
        view.documentRreaderResult = result
        view.idCardFaceTemplate = faceTemplate
        view.presenter = infoPresenter
        infoPresenter.view = view
        
        infoPresenter.interactor = interactor
        infoPresenter.rouer = router
        
        interactor.presenter = infoPresenter

        return view
    }
    static var mainstoryboard: UIStoryboard {
        return UIStoryboard(name:"Main",bundle: Bundle.main)
    }
    func moveToInfoController(withController controller: UINavigationController, withDocumentResult result: DocumentReaderResults?, andTemplateData template: Data) {
        let infoModule = InfoRouter.createModule(withDocument: result, andWithFaceTemplate: template)
        controller.pushViewController(infoModule,animated: true)
    }
}



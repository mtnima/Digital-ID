//
//  StepPresenter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 25/01/23.
//

import Foundation
import DocumentReader

class StepPresenter:StepViewtoPresenterProtocol{
    var interactor: StepPresenterToInteractorProtocol?
    
    var view: StepPresenterToViewProtocol?
    
    var rouer: StepPresenterToRouterProtocol?
    
    func openRFID(withController controller: StepsViewController) {
        interactor?.openRFIDReader(withController: controller)
    }
    
    func moveToInfoViewController(navigationController controller: UINavigationController, withDocumentResult result: DocumentReaderResults?, andTemplateData template: Data) {
        rouer?.moveToInfoController(withController: controller, withDocumentResult: result, andTemplateData: template)
    }
    
    
}
extension StepPresenter:StepInteractorToPresenterProtocol{
    func readStatus(docReaderAction action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
        view?.readStatus(docReaderAction: action, withResult: result, andWithError: error)
    }
    
    func getDocumentDataWith(successStatus success: Bool, templateData template: Data, withDocReader action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
        view?.getDocumentDataWith(successStatus: success, templateData: template, withDocReader: action, withResult: result, andWithError: error)
    }
    
    
}

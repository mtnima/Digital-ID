//
//  HomePresenter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import DocumentReader

class HomePresnter:HomeViewtoPresenterProtocol{
    
    var interactor: HomePresenterToInteractorProtocol?
    var view: HomePresenterToViewProtocol?
    var rouer: HomePresenterToRouterProtocol?
    
    func openDocumentReader(with controller:ViewController) {
        interactor?.openDocumentReader(withController: controller)
    }
    func moveToInfoViewController(navigationController controller: UINavigationController, withDocumentResult result: DocumentReaderResults?, andTemplateData template: Data) {
        rouer?.moveToInfoController(withController: controller, withDocumentResult: result, andTemplateData: template)
    }
}
extension HomePresnter:HomeInteractorToPresenterProtocol{
    func getDocumentDataWith(successStatus success: Bool, templateData template: Data, withDocReader action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
//        DocReader.shared.stopRFIDReader(errorMessage: "Custom error message") {
//            print("Stopped")
//        }
            view?.getDocumentDataWith(successStatus: success, templateData: template, withDocReader: action, withResult: result, andWithError: error)
    }
}

//
//  StepProtocols.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 25/01/23.
//

import Foundation
import UIKit
import DocumentReader

protocol StepPresenterToViewProtocol:AnyObject {
    func getDocumentDataWith(successStatus success:Bool, templateData template:Data, withDocReader action:DocReaderAction, withResult result:DocumentReaderResults?, andWithError error:Error?)
    func readStatus(docReaderAction action:DocReaderAction, withResult result:DocumentReaderResults?, andWithError error:Error?)

}

protocol StepPresenterToInteractorProtocol:AnyObject {
    var presenter:StepInteractorToPresenterProtocol?{get set}
    func openRFIDReader(withController controller:StepsViewController)
}

protocol StepPresenterToRouterProtocol:AnyObject {
    static func createStepModele(withDocument result:DocumentReaderResults?, andWithFaceTemplate faceTemplate:Data?) -> StepsViewController
    func moveToInfoController(withController controller:UINavigationController, withDocumentResult result:DocumentReaderResults?, andTemplateData template:Data)
}

protocol StepViewtoPresenterProtocol:AnyObject{
    var interactor: StepPresenterToInteractorProtocol?{get set}
    var view: StepPresenterToViewProtocol?{get set}
    var rouer: StepPresenterToRouterProtocol?{get set}
    func openRFID(withController controller:StepsViewController)
    func moveToInfoViewController(navigationController controller:UINavigationController, withDocumentResult result:DocumentReaderResults?, andTemplateData template:Data)
}

protocol StepInteractorToPresenterProtocol:AnyObject {
    func getDocumentDataWith(successStatus success:Bool, templateData template:Data, withDocReader action:DocReaderAction, withResult result:DocumentReaderResults?, andWithError error:Error?)
    func readStatus(docReaderAction action:DocReaderAction, withResult result:DocumentReaderResults?, andWithError error:Error?)
}

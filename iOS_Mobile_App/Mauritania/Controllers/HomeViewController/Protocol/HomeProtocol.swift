//
//  HomeProtocol.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import DocumentReader
protocol HomePresenterToViewProtocol:AnyObject {
    func getDocumentDataWith(successStatus success:Bool, templateData template:Data, withDocReader action:DocReaderAction, withResult result:DocumentReaderResults?, andWithError error:Error?)
}

protocol HomePresenterToInteractorProtocol:AnyObject {
    var presenter:HomeInteractorToPresenterProtocol?{get set}
    func openDocumentReader(withController controller:ViewController)
}
protocol HomePresenterToRouterProtocol:AnyObject {
    static func createHomeModele() -> ViewController
    func moveToInfoController(withController controller:UINavigationController, withDocumentResult result:DocumentReaderResults?, andTemplateData template:Data)
}
protocol HomeViewtoPresenterProtocol:AnyObject{
    var interactor: HomePresenterToInteractorProtocol?{get set}
    var view: HomePresenterToViewProtocol?{get set}
    var rouer: HomePresenterToRouterProtocol?{get set}

    func openDocumentReader(with controller:ViewController)
    func moveToInfoViewController(navigationController controller:UINavigationController, withDocumentResult result:DocumentReaderResults?, andTemplateData template:Data)
}
protocol HomeInteractorToPresenterProtocol:AnyObject {
    func getDocumentDataWith(successStatus success:Bool, templateData template:Data, withDocReader action:DocReaderAction, withResult result:DocumentReaderResults?, andWithError error:Error?)
}

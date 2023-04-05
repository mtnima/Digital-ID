//
//  HomeInteractorTest.swift
//  MauritaniaTests
//
//  Created by Yuvraj Bharat Kale on 09/03/23.
//

import XCTest
@testable import Mauritania
import DocumentReader

final class HomeInteractorTest: XCTestCase,HomeInteractorToPresenterProtocol {
    
    

    var presenter : HomePresnter?
    var interactor : HomeInteractor?
    private var homeEexpectation : XCTestExpectation?
    var status : Bool = false
    var view : ViewController?
    override func setUp() {
        view = HomeRouter.mainstoryboard.instantiateViewController(withIdentifier: "Homecontroller") as! ViewController

        
        presenter = HomePresnter()
        interactor = HomeInteractor()
//        let router:HomePresenterToRouterProtocol = HomeRouter()
//
//        view.presenter = presenter
//        presenter.view = view
//
//        presenter.rouer = router
////        presenter.router = router
//        presenter.interactor = interactor
//        interactor.presenter = presenter

    }
    
    func testI_home_Interactor_Return_failure() {
        homeEexpectation = self.expectation(description: "Home.expectation")
        interactor?.presenter = self
        interactor?.openDocumentReader(withController: view!)
        waitForExpectations(timeout: 50)
        XCTAssertFalse(status)
    }
    
    func getDocumentDataWith(successStatus success: Bool, templateData template: Data, withDocReader action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
        status = success
        homeEexpectation?.fulfill()
    }

}

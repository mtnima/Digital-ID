//
//  SplashInteractorTest.swift
//  MauritaniaTests
//
//  Created by Yuvraj Bharat Kale on 09/03/23.
//

import XCTest
@testable import Mauritania
final class SplashInteractorTest: XCTestCase, interactoreToPresenterProtocol,presenterToSplashViewProtocol {
    
    

    var splashPresentor : SplashPresenter?
    var interactor : SplashInteractor?
    var router : SplashRouter?
    var view : SplashViewController?
    var data : Data?
    var status : Bool = false
    var error : Error?
    private var delegateExpectation: XCTestExpectation!
    override func setUp() {
        view = UIStoryboard(name:"Main",bundle: Bundle.main).instantiateViewController(withIdentifier: "Splashcontroller") as? SplashViewController
        splashPresentor = SplashPresenter()
        interactor = SplashInteractor()
        router = SplashRouter()
        data = interactor!.checkLicensing(withName: "regula.license")
    }
    func testALicense_With_EmptyPath_returns_Failure(){
        let data = interactor!.checkLicensing(withName: "")
        XCTAssertNil(data)
    }
   
    func testBLicense_With_WrongFileName_returns_Failure() {
        let data = interactor!.checkLicensing(withName: "License.regula")
        XCTAssertNil(data)
    }
    func testCLicense_with_licenseFile_returns_Success(){
        let data = interactor!.checkLicensing(withName: "regula.license")
        XCTAssertNotNil(data)
    }

    func testD_initialization_with_Data_return_success(){
        let my_expectation = self.expectation(description: "Empty_data_return_error")
        interactor!.initializeDocReader(withData: data!) { success, error in
            XCTAssertNil(error)
            XCTAssertTrue(success)
            my_expectation.fulfill()
        }
        waitForExpectations(timeout: 5,handler: nil)
    }
    func testE_initialization_with_data_success() {
        delegateExpectation = self.expectation(description: "delegate_expectation")
        interactor?.presentor = self
        interactor!.ValidateDocumentReader(withName: "regula.license")
        waitForExpectations(timeout: 15)
        XCTAssertTrue(self.status)
    }
    func testF_initialization_with_emptyname_return_failure() {
        delegateExpectation = self.expectation(description: "delegate_expectation")
        interactor?.presentor = self
        interactor!.ValidateDocumentReader(withName: "")
        waitForExpectations(timeout: 15)
        XCTAssertFalse(self.status)
        XCTAssertNotNil(error!)
    }
    func testG_initialization_with_wrongname_return_failure() {
        delegateExpectation = self.expectation(description: "delegate_expectation")
        interactor?.presentor = self
        interactor!.ValidateDocumentReader(withName: "aksjd")
        waitForExpectations(timeout: 15)
        XCTAssertFalse(self.status)
        XCTAssertNotNil(error!)
    }
    func documentReaderValidationResult(with status: Bool, andWith error: Error?) {
        self.status = status
        self.error = error
        delegateExpectation.fulfill()
    }
//    func test_SplashPreseter_with_Success(){
//        delegateExpectation = self.expectation(description: "delegate_expectation1")
//        interactor?.presentor = self
//        splashPresentor?.view = self
//        splashPresentor!.getLiscense()
//        waitForExpectations(timeout: 100)
//        XCTAssertTrue(self.status)
//    }
}

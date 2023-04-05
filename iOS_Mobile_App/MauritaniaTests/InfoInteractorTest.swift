//
//  InfoInteractorTest.swift
//  MauritaniaTests
//
//  Created by Yuvraj Bharat Kale on 10/03/23.
//

import XCTest
@testable import Mauritania
import DocumentReader
import AirsnapFaceUI
import AirsnapFaceCore

final class InfoInteractorTest: XCTestCase,InteractorToPresenterInfoProtocol {
    
    
   
    var view : InformationViewController?
    var infoPresenter : InfoPresenter?
    var interactor : InfoInterActor?
    var expextation : XCTestExpectation?
    var requestStatus = false
    override func setUp() {
         view = UIStoryboard(name:"Main",bundle: Bundle.main).instantiateViewController(withIdentifier: "InformationController") as? InformationViewController
//        view.idCardFaceTemplate = faceTemplate
//        view.documentRreaderResult = result
        infoPresenter = InfoPresenter()
        interactor = InfoInterActor()
//        let router: PresenterToRouterInfoProtocol = InfoRouter()
    }

    func test_create_cryptograph_return_Success(){
        expextation = self.expectation(description: "creat_request")
        let cryptoRequest = CryptographRequest(pin: "1212121212", firstName: "test", lastName: "test2", birthDate: "1986-12-25", faceTemplate: "ACAfwACAHEBXgc9fnTNawYuJb67PuFz4c4Ga9U12n56Ng6tAill3/5KFmYq8sWx7kJ17VKieTKZtryiuZ6eMWmOOoaMfGF/NgDBiAJicd4U7sT90gruiX5M++IrNKVmee4VMSUkwsFF3iORisytbr0FiXo5hQaSqoLN5KM5bd7dUnKR/q2h+jw==")
        interactor?.presenter = self
        interactor?.sendRequest(faceData: cryptoRequest)
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertTrue(requestStatus)
    }
    
    func test_create_cryptograph_withEmpty_pin_return_failure(){
        expextation = self.expectation(description: "creat_request")
        let cryptoRequest = CryptographRequest(pin: "", firstName: "test", lastName: "test2", birthDate: "1986-12-25", faceTemplate: "ACAfwACAHEBXgc9fnTNawYuJb67PuFz4c4Ga9U12n56Ng6tAill3/5KFmYq8sWx7kJ17VKieTKZtryiuZ6eMWmOOoaMfGF/NgDBiAJicd4U7sT90gruiX5M++IrNKVmee4VMSUkwsFF3iORisytbr0FiXo5hQaSqoLN5KM5bd7dUnKR/q2h+jw==")
        interactor?.presenter = self
        interactor?.sendRequest(faceData: cryptoRequest)
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertFalse(requestStatus)
    }
    
    func test_create_cryptograph_withEmpty_firstname_return_failure(){
        expextation = self.expectation(description: "creat_request")
        let cryptoRequest = CryptographRequest(pin: "1212121212", firstName: "", lastName: "test2", birthDate: "1986-12-25", faceTemplate: "ACAfwACAHEBXgc9fnTNawYuJb67PuFz4c4Ga9U12n56Ng6tAill3/5KFmYq8sWx7kJ17VKieTKZtryiuZ6eMWmOOoaMfGF/NgDBiAJicd4U7sT90gruiX5M++IrNKVmee4VMSUkwsFF3iORisytbr0FiXo5hQaSqoLN5KM5bd7dUnKR/q2h+jw==")
        interactor?.presenter = self
        interactor?.sendRequest(faceData: cryptoRequest)
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertFalse(requestStatus)
    }
    
    func test_create_cryptograph_withEmpty_lastname_return_failure(){
        expextation = self.expectation(description: "creat_request")
        let cryptoRequest = CryptographRequest(pin: "1212121212", firstName: "test", lastName: "", birthDate: "1986-12-25", faceTemplate: "ACAfwACAHEBXgc9fnTNawYuJb67PuFz4c4Ga9U12n56Ng6tAill3/5KFmYq8sWx7kJ17VKieTKZtryiuZ6eMWmOOoaMfGF/NgDBiAJicd4U7sT90gruiX5M++IrNKVmee4VMSUkwsFF3iORisytbr0FiXo5hQaSqoLN5KM5bd7dUnKR/q2h+jw==")
        interactor?.presenter = self
        interactor?.sendRequest(faceData: cryptoRequest)
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertFalse(requestStatus)
    }
    
    func test_create_cryptograph_withEmpty_birthdate_return_failure(){
        expextation = self.expectation(description: "creat_request")
        let cryptoRequest = CryptographRequest(pin: "1212121212", firstName: "test", lastName: "test2", birthDate: "", faceTemplate: "ACAfwACAHEBXgc9fnTNawYuJb67PuFz4c4Ga9U12n56Ng6tAill3/5KFmYq8sWx7kJ17VKieTKZtryiuZ6eMWmOOoaMfGF/NgDBiAJicd4U7sT90gruiX5M++IrNKVmee4VMSUkwsFF3iORisytbr0FiXo5hQaSqoLN5KM5bd7dUnKR/q2h+jw==")
        interactor?.presenter = self
        interactor?.sendRequest(faceData: cryptoRequest)
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertFalse(requestStatus)
    }
    
    func test_create_cryptograph_withEmpty_face_return_failure(){
        expextation = self.expectation(description: "creat_request")
        let cryptoRequest = CryptographRequest(pin: "1212121212", firstName: "test", lastName: "test2", birthDate: "1986-12-25", faceTemplate: "")
        interactor?.presenter = self
        interactor?.sendRequest(faceData: cryptoRequest)
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertFalse(requestStatus)
    }
    
    
    
    func test_public_key_return_success() {
        expextation = self.expectation(description: "creat_request")
        interactor?.presenter = self
        interactor?.getPublicKey()
        waitForExpectations(timeout: 40, handler: nil)
        XCTAssertTrue(requestStatus)

    }
    
    func test_register_user_with_success_return() {
        expextation = self.expectation(description: "creat_request")
        let userRequest = UserRegisterRequest(pin: "1212121213",firstName: "test",lastName: "test2",birthDate: "1986-12-25")
        interactor?.presenter = self
        interactor?.registerUser(withRequest: userRequest)
        waitForExpectations(timeout: 30, handler: nil)
        XCTAssertTrue(requestStatus)
    }
    func test_register_user_with_Fail_return() {
        expextation = self.expectation(description: "creat_request")
        let userRequest = UserRegisterRequest(pin: "1212121213",firstName: "test",lastName: "test2",birthDate: "1986-12-25")
        interactor?.presenter = self
        interactor?.registerUser(withRequest: userRequest)
        waitForExpectations(timeout: 30, handler: nil)
        XCTAssertFalse(requestStatus)
    }
    
    func faceResult(withSuccessStatus status: Bool, faceData data: NSData?, faceBoxValues facebox: FaceBox?, andWithError: String?) {
        requestStatus = status
        expextation?.fulfill()
    }
    
    func cryptoCreated(with status: Bool, andWith response: Mauritania.CryptographyResponse?, failure error: Error?) {
        requestStatus = status
        expextation?.fulfill()
    }
    
    func userRegisted(with status: Bool, andWith response: Mauritania.UserRegisterResponse?, failure error: Error?) {
        requestStatus = status
        expextation?.fulfill()
    }
    
    func processStatus(withMessage message: String) {
    }
    
    func publicKey(with status: Bool, andWith response: Mauritania.PublicKeyResponse?, failure error: String?) {
        requestStatus = status
        expextation?.fulfill()
    }
     
}

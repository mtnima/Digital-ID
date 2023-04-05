//
//  ScannerInteractorTest.swift
//  MauritaniaTests
//
//  Created by Yuvraj Bharat Kale on 10/03/23.
//

import XCTest
@testable import Mauritania
import DocumentReader
import AirsnapFaceUI
import AirsnapFaceCore

final class ScannerInteractorTest: XCTestCase, PostScannerInteractorToPresenter {
    var postPresenter : PostScannerPresenter?
    var postinteractor : PostScannerInteractor?
    var successStatus = false
    var scannerExpectation : XCTestExpectation?
    override func setUp() {
        postPresenter = PostScannerPresenter()
        postinteractor = PostScannerInteractor()
    }
    
    func test_authentitcation_with_success_return() {
        scannerExpectation = self.expectation(description: "user.register")
        postinteractor?.presenter = self
        let userResponse = UserRegisterResponse(value: "",error: "", timestamp: "2023-03-10T09:17:46.233846759Z", pin: "Z526471000")
        postinteractor?.authenticateUserWith(demographic: userResponse, andWith: "gzeuwxjpnf696z12frgbvezgrdtxvhx2dbhjyotksubedshfabvyy16w9dn6s9ep5cwkeet1aw8sztiobmzavjmlpr3euparlrglx0azmvpbizeqxmpblscvdz38izpz9ffta15vrqv7")
        waitForExpectations(timeout: 30)
        XCTAssertTrue(successStatus)
    }
    func test_authentitcation_with_empty_pin_failure_return() {
        scannerExpectation = self.expectation(description: "user.register")
        postinteractor?.presenter = self
        let userResponse = UserRegisterResponse(value: "",error: "", timestamp: "2023-03-10T09:17:46.233846759Z", pin: "")
        postinteractor?.authenticateUserWith(demographic: userResponse, andWith: "gzeuwxjpnf696z12frgbvezgrdtxvhx2dbhjyotksubedshfabvyy16w9dn6s9ep5cwkeet1aw8sztiobmzavjmlpr3euparlrglx0azmvpbizeqxmpblscvdz38izpz9ffta15vrqv7")
        waitForExpectations(timeout: 30)
        XCTAssertFalse(successStatus)
    }
    func test_authentitcation_with_empty_barcode_failure_return() {
        scannerExpectation = self.expectation(description: "user.register")
        postinteractor?.presenter = self
        let userResponse = UserRegisterResponse(value: "",error: "", timestamp: "2023-03-10T09:17:46.233846759Z", pin: "1212121212")
        postinteractor?.authenticateUserWith(demographic: userResponse, andWith: "")
        waitForExpectations(timeout: 30)
        XCTAssertFalse(successStatus)
    }
    func qrRegisterWithResponse(response: Mauritania.TokenAuthResponse?, andWithSuccess success: Bool) {
        successStatus = success
        scannerExpectation?.fulfill()
    }
}

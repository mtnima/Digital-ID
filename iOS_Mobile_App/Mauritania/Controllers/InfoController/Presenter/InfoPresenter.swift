//
//  InfoPresenter.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import AirsnapFaceUI
import AirsnapFaceCore
import DocumentReader

class InfoPresenter:ViewToPresenterInfoProtocol{
    func moveToNextViewController(navigationController controller: UINavigationController, scanndDocumentResult documentRreaderResult: DocumentReaderResults?, livenessFaceData liveness: Data, withResponse response: CryptographyResponse?, withRegisterResponse registerResponse: UserRegisterResponse?) {
        router?.pushToHomeViewController(navigationConroller: controller, scanndDocumentResult: documentRreaderResult, livenessFaceData: liveness, withResponse: response, withRegisterResponse: registerResponse)
    }
    

    var view: PresenterToViewInfoProtocol?
    var interactor: PresenterToInteractorInfoProtocol?
    var router: PresenterToRouterInfoProtocol?
    
    func initializeFaceSDK(with viewcontroller: InformationViewController) {
        interactor?.initializeFaceSDK(with: viewcontroller)
    }
//    func moveToNextViewController(navigationController controller: UINavigationController, scanndDocumentResult documentRreaderResult: DocumentReaderResults?, livenessFaceData liveness: Data, withResponse response:CryptographyResponse?) {
//        router?.pushToHomeViewController(navigationConroller: controller, scanndDocumentResult: documentRreaderResult, livenessFaceData: liveness, withResponse: response, withRegisterResponse: <#UserRegisterResponse?#>)
//    }
    func verifyIdentification(withLivenssFaceData livenessFaceData:Data, andWithScannedDocumentFace scannedFaceData:Data, scanndDocumentResult documentRreaderResult:DocumentReaderResults?) {
        interactor?.verifyIdentification(withLivenssFaceData: livenessFaceData, andWithScannedDocumentFace: scannedFaceData, scanndDocumentResult: documentRreaderResult)
    }
    func registerUser(withDemographics demographics: DocumentReaderResults?) {
        interactor?.registerUser(withDemographics: demographics)
    }
    func getPublicKey() {
        interactor?.getPublicKey()
    }
}
extension InfoPresenter:InteractorToPresenterInfoProtocol{
    func publicKey(with status: Bool, andWith response: PublicKeyResponse?, failure error: String?) {
        view?.publicKey(with: status, andWith: response, failure: error)
    }
    
    func processStatus(withMessage message: String) {
        view?.processStatus(withMessage: message)
    }
    
    func faceResult(withSuccessStatus status: Bool, faceData data: NSData?, faceBoxValues facebox: FaceBox?, andWithError: String?) {
        view?.faceResult(withSuccessStatus: status, faceData: data, faceBoxValues: facebox, andWithError: andWithError)
    }
    func cryptoCreated(with status: Bool, andWith response: CryptographyResponse?, failure error: Error?) {
        view?.cryptoCreated(with: status, andWith: response, failure: error)
    }
    func userRegisted(with status: Bool, andWith response: UserRegisterResponse?, failure error: Error?) {
        view?.userRegisted(with: status, andWith: response, failure: error)
    }
}

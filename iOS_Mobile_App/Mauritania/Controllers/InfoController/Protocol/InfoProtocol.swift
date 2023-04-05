//
//  InfoProtocol.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import AirsnapFaceUI
import AirsnapFaceCore
import DocumentReader

protocol ViewToPresenterInfoProtocol:AnyObject{
    var view: PresenterToViewInfoProtocol?{get set}
    var interactor: PresenterToInteractorInfoProtocol?{get set}
    var router: PresenterToRouterInfoProtocol?{get set}

    func getPublicKey()
    func initializeFaceSDK(with viewcontroller:InformationViewController)
    func moveToNextViewController(navigationController controller:UINavigationController, scanndDocumentResult documentRreaderResult:DocumentReaderResults?, livenessFaceData liveness:Data, withResponse response:CryptographyResponse?, withRegisterResponse registerResponse:UserRegisterResponse?)
//    func sendRequest(faceData:CryptographRequest)
    func verifyIdentification(withLivenssFaceData livenessFaceData:Data, andWithScannedDocumentFace scannedFaceData:Data, scanndDocumentResult documentRreaderResult:DocumentReaderResults?)
    func registerUser(withDemographics demographics:DocumentReaderResults?)
}
protocol InteractorToPresenterInfoProtocol:AnyObject{
    
    func faceResult(withSuccessStatus status:Bool, faceData data: NSData?, faceBoxValues facebox: FaceBox?, andWithError:String?)
    func cryptoCreated(with status:Bool, andWith response:CryptographyResponse?, failure error:Error?)
    func userRegisted(with status:Bool, andWith response:UserRegisterResponse?, failure error:Error?)
    func processStatus(withMessage message:String)
    func publicKey(with status:Bool, andWith response:PublicKeyResponse?, failure error:String?)
}
protocol PresenterToInteractorInfoProtocol:AnyObject{
    var presenter:InteractorToPresenterInfoProtocol?{get set}
    func initializeFaceSDK(with viewcontroller:InformationViewController)
    func sendRequest(faceData:CryptographRequest)
    func verifyIdentification(withLivenssFaceData livenessFaceData:Data, andWithScannedDocumentFace scannedFaceData:Data, scanndDocumentResult documentRreaderResult:DocumentReaderResults?)
    func registerUser(withDemographics demographics: DocumentReaderResults?)
    func getPublicKey()
}
protocol PresenterToViewInfoProtocol:AnyObject{
    func faceResult(withSuccessStatus status: Bool, faceData data: NSData?, faceBoxValues facebox: FaceBox?, andWithError: String?)
    func cryptoCreated(with status: Bool, andWith response: CryptographyResponse?, failure error: Error?)
    func userRegisted(with status: Bool, andWith response: UserRegisterResponse?, failure error: Error?)
    func processStatus(withMessage message: String)
    func publicKey(with status:Bool, andWith response:PublicKeyResponse?, failure error:String?)
}
protocol PresenterToRouterInfoProtocol:AnyObject{
    static func createModule(withDocument result:DocumentReaderResults?, andWithFaceTemplate:Data?) -> InformationViewController
    func pushToHomeViewController(navigationConroller navigationController:UINavigationController, scanndDocumentResult documentRreaderResult:DocumentReaderResults?, livenessFaceData liveness:Data, withResponse response:CryptographyResponse?, withRegisterResponse registerResponse: UserRegisterResponse?)
}


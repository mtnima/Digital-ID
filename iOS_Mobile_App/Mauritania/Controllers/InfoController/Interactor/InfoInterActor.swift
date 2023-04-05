//
//  InfoInterActor.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
//import AirsnapFaceUI
//import AirsnapFaceCore
import DocumentReader


class InfoInterActor:PresenterToInteractorInfoProtocol{
    
    var presenter:InteractorToPresenterInfoProtocol?

    func initializeFaceSDK(with viewcontroller:InformationViewController) {
//        let controller: FaceCaptureController = FaceCaptureController()
//
//        controller.setAutoCapture(autoCapture: true)
//        controller.setUseBackCamera(useBackCamera: false)
//        controller.setFrameCapture(frameCapture: true)
//        let lang = (UserDefaults.standard.value(forKey: "kSaveLanguageDefaultKey") as? String) ?? "DeviceLanguage"
//        controller.setAppLanguage(lang: lang)
//        //controller.setPFCMThresholds(thresholds: PFCMThresholds)
//
//
//        controller.setOcclusionEnabled(occlusionEnabled: UserDefaultsHelper.shared.getIsOcculusionEnabled())
//        controller.setEyeClosedEnabled(eyeClosedEnabled: UserDefaultsHelper.shared.getIsEyeClosedEnabled())
//
////        controller.setIsISOEnabled(isoEnabled: chkBoxICAO.isSelected)
//
//        controller.setEnableCaptureAfter(enableCaptureAfter: UserDefaultsHelper.shared.getEnableCaptureAfter());
//
//
//        controller.setMessagesFrequency(frequency: UserDefaultsHelper.shared.getDelayBetweenFrames())
//
//        controller.setCaptureTimeoutInSecs(timeout: 30)
//
//
//        let thresholds:AirsnapFaceThresholds = AirsnapFaceThresholds();
//
//        thresholds.setMASK_THRESHOLD(MASK_THRESHOLD: UserDefaultsHelper.shared.getMaskThreshold())
//        thresholds.setEYE_CLOSE_THRESHOLD(EYE_CLOSE_THRESHOLD: UserDefaultsHelper.shared.getEyeCloseThreshold())
//        thresholds.setSUNGLASS_THRESHOLD(SUNGLASS_THRESHOLD: UserDefaultsHelper.shared.getSunglassThreshold())
//
//
//        print("YAW_THRESHOLD \(UserDefaultsHelper.shared.getYawThreshold())")
//
//        thresholds.setYawThreshold(threshold: UserDefaultsHelper.shared.getYawThreshold())
//        thresholds.setPITCH_THRESHOLD(PITCH_THRESHOLD: UserDefaultsHelper.shared.getPitchThreshold())
//        thresholds.setRollThreshold(threshold: UserDefaultsHelper.shared.getRollThreshold())
//        thresholds.setBRISQUE_THRESHOLD(BRISQUE_THRESHOLD: UserDefaultsHelper.shared.getBrisqueThreshold())
//        thresholds.setFaceWidthToImageWidthRatioTolerance(tolerance: UserDefaultsHelper.shared.getFaceWidthTolerance())
//        thresholds.setFaceCentreToImageCentreTolerance(tolerance: Int(UserDefaultsHelper.shared.getImageCentreToFaceCentreTolerance()))
//
//       controller.setAirsnapFaceThresholds(thresholds: thresholds)
//
//        //range 0 to 100
////        if(chkBoxCompression.isSelected){
////            controller.setCompressionQuality(quality: UserDefaultsHelper.shared.getCompressionQuality())
////        }else{
////            controller.setCompressionQuality(quality: 100)
////        }
//        controller.setLivenessEnabled(livenessEnabled: true)
//
//        controller.startFaceCapture(license: "", viewController: viewcontroller, delegate: self)
//
    }
    
    func sendRequest(faceData:CryptographRequest) {
        CryptographServiceRequests().createCryptograph(apiQueryModel: faceData) { [weak self] apiResult in
            DispatchQueue.main.async {
                switch apiResult {
                case .success(let cryptograph):
                    print("")
                    if cryptograph.error == nil{
                        if let cryptoImage = cryptograph.image {
                            UserDefaults.standard.storeFaceTemplate(with: cryptoImage)
                            self?.presenter?.cryptoCreated(with: true, andWith: cryptograph, failure: nil)
                        }
                        else{
                            let updatedError = NSError(domain: "", code: 415, userInfo: [ NSLocalizedDescriptionKey: "Failed to create cryptograph face template"])

                            self?.presenter?.cryptoCreated(with: false, andWith: cryptograph, failure: updatedError)
                        }
                    }
                    else{
                        self?.presenter?.cryptoCreated(with: false, andWith: cryptograph, failure: nil)
                    }
                case .failure(let error):
                    self?.presenter?.cryptoCreated(with: false, andWith: nil, failure: error)
                    print(error.localizedDescription)
                }
            }
        }
        
    }
    func getPublicKey() {
        presenter?.processStatus(withMessage: Localization(TranslationConstants.PUBLIC_KEY))
        PublicKeyRequests().getPublicKey { [weak self] apiResult in
            DispatchQueue.main.async {
                switch apiResult {
                case .success(let registerResponse):
                    print("")
                    if let respose = registerResponse.error {
                        self?.presenter?.publicKey(with: false, andWith: registerResponse, failure: respose)
                    }
                    else{
                        self?.presenter?.publicKey(with: true, andWith: registerResponse, failure: nil)
                    }
                case .failure(let error):
                    self?.presenter?.publicKey(with: true, andWith: nil, failure: nil)
                    print(error.localizedDescription)
                }
            }
        }
    }
    
    
    func registerUser(withRequest requset:UserRegisterRequest){
        UserRegisterRequests().UserRegister(apiQueryModel: requset) { [weak self] apiResult in
            DispatchQueue.main.async {
                switch apiResult {
                case .success(let registerResponse):
                    print("")
                    if let respose = registerResponse.error{
                        self?.presenter?.userRegisted(with: false, andWith: registerResponse, failure: nil)
                    }
                    else{
                        self?.presenter?.userRegisted(with: true, andWith: registerResponse, failure: nil)
                    }
                case .failure(let error):
                    self?.presenter?.userRegisted(with: false, andWith: nil, failure: error)
                    print(error.localizedDescription)
                }
            }
        }
    }
    
    func verifyIdentification(withLivenssFaceData livenessFaceData: Data, andWithScannedDocumentFace scannedFaceData: Data, scanndDocumentResult documentRreaderResult: DocumentReaderResults?) {
        FaceMatcherSDK.detectFace(faceData: livenessFaceData)
        
            let score = FaceMatcherSDK.matchTemplates(faceTemplate: FaceMatcherSDK.faceTemplate, cryptGraphFaceTemplate: scannedFaceData)
            if score > 5.0 {
                presenter?.processStatus(withMessage: Localization(TranslationConstants.FACE_MATCHED))
                var request = CryptographRequest()
                request.faceTemplate = scannedFaceData.getEncodedString()
                request.firstName = documentRreaderResult?.firstName()
                request.lastName = documentRreaderResult?.lastName()
                request.pin = (documentRreaderResult?.documentNumber() ?? "").getIDNumber()
                request.birthDate = documentRreaderResult?.birthDate()
                self.sendRequest(faceData: request)
            }
            else {
             print("Failed to match score: \(score)")
                let updatedError = NSError(domain: "", code: 401, userInfo: [ NSLocalizedDescriptionKey: Localization(TranslationConstants.FACE_MATCHING_FAILED)])

                self.presenter?.cryptoCreated(with: false, andWith: nil, failure: updatedError)
            }
        }
    
    func registerUser(withDemographics demographics: DocumentReaderResults?) {
        presenter?.processStatus(withMessage: Localization(TranslationConstants.REGISTER_USER))
        var request = UserRegisterRequest()
        request.firstName = demographics?.firstName() ?? ""
        request.lastName = demographics?.lastName() ?? ""
        request.pin = (demographics?.documentNumber() ?? "").getIDNumber()
        request.birthDate = demographics?.birthDate()

        self.registerUser(withRequest: request)

    }
}
//extension InfoInterActor:FaceCapturedProtocol{
//    func onFaceCaptured(data: NSData?, facebox: FaceBox) {
//        presenter?.faceResult(withSuccessStatus: true, faceData: data, faceBoxValues: facebox, andWithError: nil)
//    }
//    
//    func onFaceCaptureFailed(errorMsg: String) {
//        presenter?.faceResult(withSuccessStatus: false, faceData: nil, faceBoxValues: nil, andWithError: errorMsg)
//    }
//    
//    func onTimedout(data: NSData?) {
//        presenter?.faceResult(withSuccessStatus: false, faceData: data, faceBoxValues: nil, andWithError: "Time Out")
//    }
//    
//    func onCancelled() {
//        presenter?.faceResult(withSuccessStatus: false, faceData: nil, faceBoxValues: nil, andWithError: "Action Cancelled")
//    }
//}

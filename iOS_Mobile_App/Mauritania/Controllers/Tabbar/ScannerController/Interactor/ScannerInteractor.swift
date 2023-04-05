//
//  ScannerInteractor.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 27/01/23.
//

import Foundation
import MercariQRScanner
import AVFoundation
import AirsnapFaceUI
import AirsnapFaceCore


class ScannerInteractor:ScannerPresenterToInteractorProtocol{
   
    
    var presenter: ScannerInteractorToPresenterProtocol?
    var scanController: ScannerViewController?
    var scannedCode: String?
    var qrScannerView : QRScannerView?
    func openScanner(withController controller: ScannerViewController?) {
        scanController = controller
            switch AVCaptureDevice.authorizationStatus(for: .video) {
            case .authorized:
                setupQRScannerView(withController: controller)
            case .notDetermined:
                AVCaptureDevice.requestAccess(for: .video) { [weak self] granted in
                    if granted {
                        DispatchQueue.main.async { [weak self] in
                            self?.setupQRScannerView(withController: controller)
                        }
                    }
                }
            default:
                showAlert(withController: controller)
            }
        }
    
    
    
    private func showAlert(withController controller: ScannerViewController?) {
            DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) { [weak self] in
                let alert = UIAlertController(title: "Error", message: "Camera is required to use in this application", preferredStyle: .alert)
                alert.addAction(.init(title: "OK", style: .default))
                controller?.present(alert, animated: true)
            }
        }
    private func setupQRScannerView(withController controller: ScannerViewController?) {
        qrScannerView = QRScannerView(frame: controller?.view.bounds ?? UIScreen.main.bounds)
        controller?.view.addSubview(qrScannerView!)
            qrScannerView?.configure(delegate: self, input: .init(isBlurEffectEnabled: true))
            qrScannerView?.startRunning()
        }
//    func authenticateUserWith(demographic: UserRegisterResponse, andWith barcode: String) {
//        let request = EstablishConnectionRequest(username: demographic.pin, qrAuth: barcode)
//        AuthenticationRequest().EstablishConnectionWith(apiQueryModel: request) { [weak self] apiResult in
//            DispatchQueue.main.async {
//                switch apiResult {
//                case .success(_):
//                    self?.presenter?.qrRegisterWithResponse(response: nil, andWithSuccess: true)
//                    print("Success")
//                case .failure(_):
//                    self?.presenter?.qrRegisterWithResponse(response: nil, andWithSuccess: false)
//                    print("Failure")
//                }
//            }
//        }
////        AuthenticationRequest().Authentication(apiQueryModel: demographic) { [weak self] apiResult in
////            DispatchQueue.main.async {
////                switch apiResult {
////                case .success(let authResponse):
////                    print("")
////                    if authResponse.code != nil{
////                        print("Error of authenitcation - \(authResponse.reason)")
////                        self?.presenter?.authenticationResponse(withResponse: authResponse, withError: authResponse.reason)
////                    }
////                    else{
////                        self?.presenter?.authenticationResponse(withResponse: authResponse, withError: authResponse.reason)
////                    }
////                case .failure(let error):
////                    self?.presenter?.authenticationResponse(withResponse: nil, withError: error.localizedDescription)
////                    print(error.localizedDescription)
////                }
////            }
////        }
//    }
//    func authenticationWith(token: String, andwithScanCode scanner: String) {
//        let authToken = TokenAuthRequest(tokenId: token)
//        AuthenticationRequest().TokenAuthentication(apiQueryModel: authToken) { [weak self] apiResult in
//            DispatchQueue.main.async {
//                switch apiResult {
//                case .success(let authResponse):
//                    print("")
//                    self?.presenter?.tokenAutherizedWithResponse(response: authResponse, andWithSuccess: true)
//
//                case .failure(let error):
//                    self?.presenter?.tokenAutherizedWithResponse(response: nil, andWithSuccess: false)
//                    print(error.localizedDescription)
//                }
//            }
//        }
//    }
//    func registerQRCodeWith(request: TokenAuthResponse) {
//
//        let inputRequest = in_outputRequest(name: "\(request.callbacks![0].input![0].name ?? "")",value: "\(request.callbacks![0].input![0].value ?? "")")
//        let outputRequest = in_outputRequest(name: "\(request.callbacks![0].output![0].name ?? "")",value: "\(request.callbacks![0].output![0].value ?? "")")
//        let callbackRequest = callbackRequest(type: "\(request.callbacks![0].type ?? "")", output: [outputRequest], input: [inputRequest])
//        let qrrequest = QRRequest(authId: request.authId,template: request.template,stage: request.stage, header: request.header, infoText: request.infoText, callbacks: [callbackRequest],token: request.token)
//        AuthenticationRequest().qrAuthentication(apiQueryModel: request) { [weak self] apiResult in
//            DispatchQueue.main.async {
//                switch apiResult {
//                case .success(let authResponse):
//                    print("")
//                    self?.presenter?.qrRegisterWithResponse(response: authResponse, andWithSuccess: true)
//
//                case .failure(let error):
//                    self?.presenter?.qrRegisterWithResponse(response: nil, andWithSuccess: false)
//                    print(error.localizedDescription)
//                }
//            }
//        }
//    }
    
    //MARK: Open Face Detection
    func initializeFaceSDK(with viewcontroller:ScannerViewController) {
        let controller: FaceCaptureController = FaceCaptureController()
        
        controller.setAutoCapture(autoCapture: true)
        controller.setUseBackCamera(useBackCamera: false)
        controller.setFrameCapture(frameCapture: true)
        
        controller.setOcclusionEnabled(occlusionEnabled: UserDefaultsHelper.shared.getIsOcculusionEnabled())
        controller.setEyeClosedEnabled(eyeClosedEnabled: UserDefaultsHelper.shared.getIsEyeClosedEnabled())
        
        
        controller.setEnableCaptureAfter(enableCaptureAfter: UserDefaultsHelper.shared.getEnableCaptureAfter());

        
        controller.setMessagesFrequency(frequency: UserDefaultsHelper.shared.getDelayBetweenFrames())

        let thresholds:AirsnapFaceThresholds = AirsnapFaceThresholds();
        
        thresholds.setMASK_THRESHOLD(MASK_THRESHOLD: UserDefaultsHelper.shared.getMaskThreshold())
        thresholds.setEYE_CLOSE_THRESHOLD(EYE_CLOSE_THRESHOLD: UserDefaultsHelper.shared.getEyeCloseThreshold())
        thresholds.setSUNGLASS_THRESHOLD(SUNGLASS_THRESHOLD: UserDefaultsHelper.shared.getSunglassThreshold())
       
        
        print("YAW_THRESHOLD \(UserDefaultsHelper.shared.getYawThreshold())")
        
        thresholds.setYawThreshold(threshold: UserDefaultsHelper.shared.getYawThreshold())
        thresholds.setPITCH_THRESHOLD(PITCH_THRESHOLD: UserDefaultsHelper.shared.getPitchThreshold())
        thresholds.setRollThreshold(threshold: UserDefaultsHelper.shared.getRollThreshold())
        thresholds.setBRISQUE_THRESHOLD(BRISQUE_THRESHOLD: UserDefaultsHelper.shared.getBrisqueThreshold())
        thresholds.setFaceWidthToImageWidthRatioTolerance(tolerance: UserDefaultsHelper.shared.getFaceWidthTolerance())
        thresholds.setFaceCentreToImageCentreTolerance(tolerance: Int(UserDefaultsHelper.shared.getImageCentreToFaceCentreTolerance()))
        controller.setAirsnapFaceThresholds(thresholds: thresholds)

        controller.setCaptureTimeoutInSecs(timeout: 30)
        controller.setLivenessEnabled(livenessEnabled: true)
        
        controller.startFaceCapture(license: "", viewController: scanController!, delegate: self)

    }
    
    func verifyUserWithLivenessData(demographic: UserRegisterResponse, andWith barcode: String, withLivenessData livenessData: Data?) {
        if let faceData = livenessData {
            FaceMatcherSDK.detectFace(faceData: faceData as Data)
            if let cryptoImage = UserDefaults.standard.getFaceTemplate().toImage(){
//                UIPasteboard.general.string = UserDefaults.standard.getFaceTemplate() + "Test"
                let pixelData = cryptoImage.jpegData(compressionQuality: 1.0)
                SDKInitialize.decodeCryptograph(barCodeData: pixelData!)
                if let decodedData = SDKInitialize.decodedfaceTemplate {
                    let score = FaceMatcherSDK.matchTemplates(faceTemplate: FaceMatcherSDK.faceTemplate, cryptGraphFaceTemplate: decodedData)
                    print(score)
                    if score > 5 {
                        presenter?.userAuthorized()
                    }
                }
                else{
                    scanController?.alert(message: "Failed to retrive face image from saved face template")
                }
            }
            else {
                scanController?.alert(message: Localization(TranslationConstants.FACE_NOT_FOUND))
            }
        }
        else{
            scanController?.alert(message: Localization(TranslationConstants.FACE_NOT_FOUND))
        }
    }
}
extension ScannerInteractor:QRScannerViewDelegate{
    func qrScannerView(_ qrScannerView: QRScannerView, didFailure error: QRScannerError) {
            print(error)
        }

        func qrScannerView(_ qrScannerView: QRScannerView, didSuccess code: String) {
            print(code)
            scannedCode = code
//            self.initializeFaceSDK(with: self.scanController!)
            qrScannerView.stopRunning()
            qrScannerView.removeFromSuperview()
            presenter?.codeFromScanner(withCode: scannedCode!)
        }
}

extension ScannerInteractor:FaceCapturedProtocol{
    func onFaceCaptured(data: NSData?, facebox: FaceBox) {
        if let faceData = data {
            FaceMatcherSDK.detectFace(faceData: faceData as Data)
            if let cryptoImage = UserDefaults.standard.getFaceTemplate().toImage(){
//                UIPasteboard.general.string = UserDefaults.standard.getFaceTemplate() + "Test"
                let pixelData = cryptoImage.jpegData(compressionQuality: 1.0)
                SDKInitialize.decodeCryptograph(barCodeData: pixelData!)
                if let decodedData = SDKInitialize.decodedfaceTemplate {
                    let score = FaceMatcherSDK.matchTemplates(faceTemplate: FaceMatcherSDK.faceTemplate, cryptGraphFaceTemplate: decodedData)
                    print(score)
                    if score > 3 {
                        presenter?.codeFromScanner(withCode: scannedCode!)
                    }
                }
                else{
                    scanController?.alert(message: "Failed to retrive face image from saved face template")
                }
            }
            else{
                scanController?.alert(message: Localization(TranslationConstants.FACE_NOT_FOUND))
            }
        }
        else{
            scanController?.alert(message: Localization(TranslationConstants.FACE_NOT_FOUND))
        }
    }
    
    func onFaceCaptureFailed(errorMsg: String) {
    }
    
    func onTimedout(data: NSData?) {
    }
    
    func onCancelled() {
    }
    
}

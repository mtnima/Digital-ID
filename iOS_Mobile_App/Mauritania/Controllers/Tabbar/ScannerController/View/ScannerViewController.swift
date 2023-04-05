//
//  ScannerViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 19/01/23.
//

import UIKit
import MercariQRScanner
import DocumentReader

class ScannerViewController: BaseViewController {

    var presenter : ScannerViewtoPresenterProtocol?
    var livenessData : Data?
    var documentResult : DocumentRequestModel?
    var response : CryptographyResponse?
    var registerResponse : UserRegisterResponse?
    var scannerCode : String?
    var generatedToken : String?
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        presenter?.openScanner(withController: self)
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false
        registerResponse?.pin = documentResult?.pin

    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
extension ScannerViewController:ScannerPresenterToViewProtocol{
//    func authenticationResponse(withResponse response: AuthenticationResponse?, withError error: String?) {
//        self.hideProgress()
//        if let _ = error {
////            self.showPreogress(title: "Token Creation failed")
//            navigateToFailureScreen()
//            return
//        }
//        print("Token - \(response?.tokenId ?? "No Token to show")")
//        if let token = response?.tokenId,let scanner = scannerCode{
//            generatedToken = token
//            self.updatedMessage(title: Localization(TranslationConstants.TOKEN_AUTHENTICATION))
////            self.showPreogress(title: "Token Created, Authenticating Token")
//            presenter?.authenticationWith(token: token, andwithScanCode: scanner)
//        }
//        else{
//        }
//    }
    
    func userAuthorized() {
//        self.hideProgress()
        if let response = registerResponse {
//            self.showPreogress(title: Localization(TranslationConstants.TOKEN_CREATION))
            
//            let postScannerVC = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "postscannercontroller") as! PostScannerViewController
            let postScannerVC = PostScannerRouter.createModule()
            postScannerVC.response = response
            postScannerVC.scannerCode = scannerCode
            self.navigationController?.pushViewController(postScannerVC, animated: true)

//            self.presenter?.authenticateUserWith(demographic: response, andWith: scannerCode!)
        }
    }
    
    func codeFromScanner(withCode code: String) {
        scannerCode = code
        let InfoModule = InfoRouter.createModule(withDocument: nil, andWithFaceTemplate: nil)
        InfoModule.qrCode = scannerCode
        InfoModule.faceCollecterDelegate = self
        self.navigationController?.pushViewController(InfoModule, animated: true)
//        print("Scanner value - \(code)")
//        if let response = registerResponse {
//            self.showPreogress(title: Localization(TranslationConstants.TOKEN_CREATION))
//            self.presenter?.authenticateUserWith(demographic: response, andWith: code)
//        }
    }
   
//    func tokenAutherizedWithResponse(response: TokenAuthResponse?, andWithSuccess success: Bool) {
//
//        if success {
//            self.updatedMessage(title: Localization(TranslationConstants.TOKEN_REGISTER))
//            var updateResponse = response
//            updateResponse?.header = scannerCode
//            updateResponse?.callbacks?[0].input?[0].value = scannerCode
//            updateResponse?.token = generatedToken
//            presenter?.registerQRCodeWith(request: updateResponse!)
//        }
//        else{
//            self.hideProgress()
//            navigateToFailureScreen()
//        }
//    }
//    func qrRegisterWithResponse(response: TokenAuthResponse?, andWithSuccess success: Bool) {
//            self.hideProgress()
//        DispatchQueue.main.asyncAfter(deadline: .now() + 0.4, execute: {
//                DispatchQueue.main.async {
//                    if success{
////                        let storyboard = UIStoryboard(name:"Tabbar",bundle: Bundle.main)
//                        let postScannerVC = HomeRouter.tabstoryboard.instantiateViewController(withIdentifier: "postscannercontroller") as! PostScannerViewController
//                        self.navigationController?.pushViewController(postScannerVC, animated: true)
//                    }
//                    else{
//                        self.navigateToFailureScreen()
//                    }
//                }
//            })
//    }
    func navigateToFailureScreen(){
        let status = StatusRouter.createModule()
        status.navString = Localization(TranslationConstants.THIRD_PARTY_LOGIN)
        status.imageName = "error"
        status.statusHeader = Localization(TranslationConstants.LOGIN_ERROR)
        status.statusSubHeader = Localization(TranslationConstants.LOGIN_ERROR_NOTE)
        self.navigationController?.pushViewController(status, animated: true)
    }
}
extension ScannerViewController:FaceDataCollecter{
    func getLivenessData(livenessData: Data?) {
        //From data collected
        if let response = registerResponse {
//            self.showPreogress(title: "Verifying")
            presenter?.verifyUserWithLivenessData(demographic: response, andWith: scannerCode!, withLivenessData: livenessData)
        }
    }
}

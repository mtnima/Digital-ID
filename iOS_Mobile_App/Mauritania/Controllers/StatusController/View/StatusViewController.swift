//
//  StatusViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import UIKit
import DocumentReader

class StatusViewController: BaseViewController {

    @IBOutlet weak var continueButton: UIButton!
    @IBOutlet weak var successSubtitle: UILabel!
    @IBOutlet weak var successTitle: UILabel!
    @IBOutlet weak var navTitle: UILabel!
    var navString : String?
    
    var livenessData : Data?
    var documentResult : DocumentReaderResults?
    var response : CryptographyResponse?
    var registerResponse : UserRegisterResponse?
    var imageName = "Done"
    var statusHeader : String? = Localization(TranslationConstants.SUCCESS)
    var statusSubHeader : String? = Localization(TranslationConstants.SUCCESS_NOTE)
    @IBOutlet weak var statusImage: UIImageView!
    override func viewDidLoad() {
        super.viewDidLoad()
        statusImage.image = UIImage(named: imageName)
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        // Do any additional setup after loading the view.
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false
        if imageName == "Done"{
            statusImage.layer.borderColor = UIColor().appcolor().cgColor
            statusImage.layer.borderWidth = 8
        }
        
        updateLanguage()
    }
    @IBAction func continueAction(_ sender: Any) {
        if navString == Localization(TranslationConstants.THIRD_PARTY_LOGIN){
            if let navigtion = self.navigationController{
                for controller in navigtion.viewControllers {
                    if controller is TabViewController{
                        if let tab = controller as? TabViewController{
                            tab.selectedIndex = 1
                            self.navigationController?.popToViewController(controller, animated: true)
                        }
                    }
                }
            }
        }
        else{
            let homeModule = HomeRouter.createTabView()
            homeModule.selectedIndex = 1
            manageSession()
            let hometabbarcontroller = homeModule.viewControllers![1] as! HomeTabViewController
            hometabbarcontroller.documentResult = documentResult?.getDocumentDetail()
            hometabbarcontroller.livenessData = livenessData
            hometabbarcontroller.response = response
            hometabbarcontroller.registerResponse = registerResponse
            
            let scannerController = homeModule.viewControllers![0] as! ScannerViewController
            scannerController.documentResult = documentResult?.getDocumentDetail()
            scannerController.livenessData = livenessData
            scannerController.response = response
            scannerController.registerResponse = registerResponse
            self.navigationController!.pushViewController(homeModule,animated: true)
        }
    }
    
    func manageSession(){
        let sessionuserdefaults = UserDefaults.standard
        
        sessionuserdefaults.setValue(true, forKey: USERDEFAULTS().islogin)
        
        sessionuserdefaults.storescannerResult(result: documentResult?.getDocumentDetail())
        sessionuserdefaults.storeLivenessData(liveness: livenessData)
        sessionuserdefaults.storeCryptoResponse(result: response)
        sessionuserdefaults.storeRegiterResponse(result: registerResponse)
        let portraitImage = documentResult?.getGraphicFieldImageByType(fieldType: .gf_Portrait, source: .rfidImageData)
    }
    
    
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateLanguage()
        }
    }
    func updateLanguage(){
        if navTitle.text == Localization(TranslationConstants.THIRD_PARTY_LOGIN){
            
        }
        else{
            continueButton.setTitle(Localization(TranslationConstants.CONTINUE), for: .normal)
            successSubtitle.text = statusSubHeader ?? Localization(TranslationConstants.SUCCESS_NOTE)
            successTitle.text = statusHeader ?? Localization(TranslationConstants.SUCCESS)
            navTitle.text = navString ?? Localization(TranslationConstants.IDENTITY_TITLE)
        }

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

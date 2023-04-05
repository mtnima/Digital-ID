//
//  PostScannerViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 30/01/23.
//

import UIKit

class PostScannerViewController: BaseViewController {

    @IBOutlet weak var navTitle: UILabel!
    @IBOutlet weak var lastNameKey: CustomLabel!
    @IBOutlet weak var mobileNumberKey: CustomLabel!
    @IBOutlet weak var nameKey: CustomLabel!
    @IBOutlet weak var nniKey: CustomLabel!
    @IBOutlet weak var requestedDataKey: CustomLabel!
    @IBOutlet weak var dataRecipientKey: CustomLabel!
    
    @IBOutlet weak var backButton: CustomButton!
    @IBOutlet weak var nextButton: CustomButton!
    var response: UserRegisterResponse?
    var scannerCode: String?
    var presenter : PostScannerViewtoPresenterProtocol?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        updateWithLanguage()
        // Do any additional setup after loading the view.
    }
    

    @IBAction func nextAction(_ sender: Any) {
        
        registerUser()
//        let status = StatusRouter.createModule()
//        status.navString = Localization(TranslationConstants.THIRD_PARTY_LOGIN)
//        status.imageName = "Done"
//        status.statusHeader = Localization(TranslationConstants.LOGIN_SUCCESS)
//        status.statusSubHeader = Localization(TranslationConstants.LOGIN_SUCCESS_NOTE)
//        self.navigationController?.pushViewController(status, animated: true)
    }
    
    func registerUser(){
        self.showPreogress(title: Localization(TranslationConstants.TOKEN_CREATION))
        self.presenter?.authenticateUserWith(demographic: response!, andWith: scannerCode!)
    }
    
    @IBAction func backAction(_ sender: Any) {
        var isMoved = false
        if let navigtion = self.navigationController{
            for controller in navigtion.viewControllers {
                if controller is TabViewController{
                    if let tab = controller as? TabViewController{
                        isMoved = true
                        tab.selectedIndex = 1
                        self.navigationController?.popToViewController(controller, animated: true)
                    }
                }
            }
        }
        if !isMoved {
            self.navigationController?.popViewController(animated: true)
        }
    }
    
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateWithLanguage()
        }
    }
    func updateWithLanguage(){
        lastNameKey.text = Localization(TranslationConstants.LAST_NAME)
        mobileNumberKey.text = Localization(TranslationConstants.BIRTH_DATE)
        nniKey.text = Localization(TranslationConstants.NNI)
        nameKey.text = Localization(TranslationConstants.FIRST_NAME)
        requestedDataKey.text = Localization(TranslationConstants.REQUESTED_DATA)
        dataRecipientKey.text = Localization(TranslationConstants.RECIEPIENT_DATA)
        navTitle.text = Localization(TranslationConstants.THIRD_PARTY_LOGIN)
        backButton.setTitle(Localization(TranslationConstants.BACK), for: .normal)
        nextButton.setTitle(Localization(TranslationConstants.NEXT), for: .normal)
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
extension PostScannerViewController:PostScannerPresenterToViewProtocol{
    func qrRegisterWithResponse(response: TokenAuthResponse?, andWithSuccess success: Bool) {
            self.hideProgress()
            let status = StatusRouter.createModule()
            status.navString = Localization(TranslationConstants.THIRD_PARTY_LOGIN)
            status.imageName =  success ? "Done" : "error"
            status.statusHeader = success ? Localization(TranslationConstants.LOGIN_SUCCESS) : Localization(TranslationConstants.LOGIN_ERROR)
            status.statusSubHeader = success ? Localization(TranslationConstants.LOGIN_SUCCESS_NOTE) : Localization(TranslationConstants.LOGIN_ERROR_NOTE)
            self.navigationController?.pushViewController(status, animated: true)
    }
}

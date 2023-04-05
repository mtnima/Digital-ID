//
//  HomeTabViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 19/01/23.
//

import UIKit
import DocumentReader

class HomeTabViewController: BaseViewController {
    var livenessData : Data?
    var documentResult : DocumentRequestModel?
    var response: CryptographyResponse?
    var registerResponse : UserRegisterResponse?

    @IBOutlet weak var usefulKey: CustomLabel!
    @IBOutlet weak var verifiedIdentityKey: CustomLabel!
    @IBOutlet weak var newsKey: CustomLabel!
    @IBOutlet weak var documentKey: CustomLabel!
    @IBOutlet weak var availableServiceKey: CustomLabel!
    @IBOutlet weak var nationalityKey: CustomLabel!
    @IBOutlet weak var issueDateKey: CustomLabel!
    @IBOutlet weak var expiryDateKey: CustomLabel!
    @IBOutlet weak var birthDateKey: CustomLabel!
    @IBOutlet weak var phoneNumberKey: CustomLabel!
    @IBOutlet weak var genderKey: CustomLabel!
    @IBOutlet weak var birthPlaceKey: CustomLabel!
    
    @IBOutlet weak var profileImage: UIImageView!
    @IBOutlet weak var documentNumber: UILabel!
    
    @IBOutlet weak var birthPlaceName: UILabel!
    @IBOutlet weak var birthData: UILabel!
    @IBOutlet weak var profileName: UILabel!
    @IBOutlet weak var nationality: UILabel!
    
    @IBOutlet weak var phoneNumber: UILabel!
    @IBOutlet weak var genderName: UILabel!
    @IBOutlet weak var documentExpiryDate: UILabel!
    
    @IBOutlet weak var dateIssueName: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        profileImage.layer.borderColor = UIColor().appcolor().cgColor
        profileImage.layer.borderWidth = 2
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        // Do any additional setup after loading the view.
    }
    override func viewWillAppear(_ animated: Bool) {
        NotificationCenter.default.removeObserver(self, name: kNotificationLanguageChanged, object: nil)
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        self.reloadInputViews()
        if let porfileImageData = UserDefaults.standard.getPortraitImage() {
            profileImage.image = UIImage(data: porfileImageData)
        }
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false
        showProfileDetails()
        updateWithLanguage()
    }
    func showProfileDetails() {
        let firstName = documentResult?.firstName ?? "----"
        let lastName = documentResult?.lastName ?? "----"
        profileName.text = firstName + " \(lastName)"
        documentNumber.text = documentResult?.pin ?? Localization(TranslationConstants.NOT_MENTION)
        birthData.text = documentResult?.birthDate ?? Localization(TranslationConstants.NOT_MENTION)
        phoneNumber.text = documentResult?.phoneNumber ?? Localization(TranslationConstants.NOT_MENTION)
        birthPlaceName.text = documentResult?.placeOfBirth ?? Localization(TranslationConstants.NOT_MENTION)
        documentExpiryDate.text = documentResult?.documentExpiryDate ?? Localization(TranslationConstants.NOT_MENTION)
        dateIssueName.text = documentResult?.dateIssueName ?? Localization(TranslationConstants.NOT_MENTION)
        nationality.text = documentResult?.nationality ?? Localization(TranslationConstants.NOT_MENTION)
        genderName.text = documentResult?.gender ?? Localization(TranslationConstants.NOT_MENTION)
    }

    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateWithLanguage()
        }
    }
    func updateWithLanguage(){
        availableServiceKey.text = Localization(TranslationConstants.AVAILABLE_SERVICE)
        nationalityKey.text = Localization(TranslationConstants.NATIONALITY)
        issueDateKey.text = Localization(TranslationConstants.ISSUE_DATE)
        expiryDateKey.text = Localization(TranslationConstants.EXPIRY_DATE)
        birthDateKey.text = Localization(TranslationConstants.BIRTH_DATE)
        phoneNumberKey.text = Localization(TranslationConstants.PHONE_NUMBER)
        genderKey.text = Localization(TranslationConstants.GENDER)
        birthPlaceKey.text = Localization(TranslationConstants.BIRTH_PLACE)
        usefulKey.text = Localization(TranslationConstants.LINKS)
        newsKey.text = Localization(TranslationConstants.NEWS)
        documentKey.text = Localization(TranslationConstants.DOCUMENT)
        verifiedIdentityKey.text = Localization(TranslationConstants.VERIFIED_IDENTITY)
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

//
//  ViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 09/01/23.
//

import UIKit
import DocumentReader

class ViewController: BaseViewController {
    
    @IBOutlet weak var startVerificationSubheader: CustomLabel!
    @IBOutlet weak var continueButton: UIButton!
    @IBOutlet weak var startVerificationHeader: CustomLabel!
    @IBOutlet weak var eIDTitle: UILabel!
    @IBOutlet weak var skipAction: UIButton!
    var presenter: HomeViewtoPresenterProtocol?
    override func viewDidLoad() {
        super.viewDidLoad()
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        updateLanguage()
        // Do any additional setup after loading the view.
    }

    @IBAction func continueAction(_ sender: Any) {
        presenter?.openDocumentReader(with: self)
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false

    }
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateLanguage()
        }
    }
    func updateLanguage(){
        continueButton.setTitle(Localization(TranslationConstants.CONTINUE), for: .normal)
        startVerificationSubheader.text = Localization(TranslationConstants.START_VERIFY_IDENTITY_NOTE)
        startVerificationHeader.text = Localization(TranslationConstants.START_VERIFICATION)
        eIDTitle.text = Localization(TranslationConstants.IDENTITY_TITLE)
    }
}
extension ViewController:HomePresenterToViewProtocol{
    func getDocumentDataWith(successStatus success: Bool, templateData template: Data, withDocReader action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
        self.hideProgress()
        if success{
            DispatchQueue.main.async {
                self.presenter?.moveToInfoViewController(navigationController: self.navigationController!, withDocumentResult: result, andTemplateData: template)
            }
        }
        else{
            self.alert(message: error?.localizedDescription ?? Localization(TranslationConstants.TRY_AGAIN))
        }
    }
}


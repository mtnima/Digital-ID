//
//  InformationViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import UIKit
import AirsnapFaceUI
import AirsnapFaceCore
import ALProgressView
import DocumentReader
import Alamofire

class InformationViewController: BaseViewController {
//    let loadingAlerxxtController: UIAlertController = UIAlertController(title: "Loading", message: nil, preferredStyle: .alert)
    
    @IBOutlet weak var header: CustomLabel!
    
    @IBOutlet weak var scanButton: UIButton!
    @IBOutlet weak var subHeader: CustomLabel!
    @IBOutlet weak var navTitle: CustomLabel!
    @IBOutlet weak var progressView: UIView!
    
    @IBOutlet weak var infoSubtitle: UILabel!
    @IBOutlet weak var infoTitle: UILabel!
    var documentRreaderResult:DocumentReaderResults?
    var idCardFaceTemplate:Data?
    var livenessfaceData : Data?
    var cryptoSuccessResponse : CryptographyResponse?
    var faceCollecterDelegate : FaceDataCollecter?
    var progressRing = ALProgressRing()
    var stepsLabel = UILabel()
    var totalSteps = 3
    var qrCode : String?
    @IBOutlet weak var infoTableView: UITableView!
    var presenter:ViewToPresenterInfoProtocol?
    let inforamtions : [String] = [TranslationConstants.VERIFY_STEP_1, TranslationConstants.VERIFY_STEP_2,TranslationConstants.VERIFY_STEP_3, TranslationConstants.VERIFY_STEP_4, TranslationConstants.VERIFY_STEP_5]
    let icons : [String] = ["glasses","Sun_light","happy","sunglasses","hat"]
    override func viewDidLoad() {
        super.viewDidLoad()
        if let _ = qrCode {
            self.navigationController?.navigationItem.hidesBackButton = false
            self.infoTitle.isHidden = true
            self.infoSubtitle.isHidden = true
            self.infoTitle.isHidden = true
            self.stepsLabel.isHidden = true
        }
        else{
            self.navigationController?.navigationItem.hidesBackButton = true
            self.infoTitle.text = Localization(TranslationConstants.FACE_MATCH)
            self.infoSubtitle.text = Localization(TranslationConstants.NEXT_3)
            totalSteps = (documentRreaderResult!.chipPage > 0) ? 3 : 2
            stepsLabel.text = "\(totalSteps) / \(totalSteps)"
            stepsLabel.textAlignment = .center
            self.setupRingProgress()

        }
        infoTableView.reloadData()
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)
        updateLanguage()
        // Do any additional setup after loading the view.
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false

    }
    
    @IBAction func startFaceScanning(_ sender: Any) {
        
        presenter?.initializeFaceSDK(with: self)
    }

    func setupRingProgress(){
        progressView.addSubview(progressRing)
        progressRing.addSubview(stepsLabel)
        stepsLabel.translatesAutoresizingMaskIntoConstraints = false
        stepsLabel.centerXAnchor.constraint(equalTo: progressRing.centerXAnchor).isActive = true
        stepsLabel.centerYAnchor.constraint(equalTo: progressRing.centerYAnchor).isActive = true
          // Make sure to set the view size
        stepsLabel.widthAnchor.constraint(equalToConstant: 45).isActive = true
        stepsLabel.heightAnchor.constraint(equalToConstant: 25).isActive = true

        progressRing.translatesAutoresizingMaskIntoConstraints = false
        progressRing.centerXAnchor.constraint(equalTo: progressView.centerXAnchor).isActive = true
        progressRing.centerYAnchor.constraint(equalTo: progressView.centerYAnchor).isActive = true
          // Make sure to set the view size
        progressRing.widthAnchor.constraint(equalToConstant: 90).isActive = true
        progressRing.heightAnchor.constraint(equalToConstant: 90).isActive = true
        progressRing.duration = 2 // Duration of the ring's fill animation.
//        progressRing.timingFunction = .easeOutExpo // Timing function of the ring's fill animation.
        progressRing.setProgress(Float(totalSteps/totalSteps), animated: true)
        progressRing.startColor = UIColor().appcolor()
        progressRing.endColor = UIColor().appcolor()
        // Sets the line width for progress ring and "groove" ring
        progressRing.lineWidth = 2
        // Or, if you need to separate these parameters, use
        progressRing.ringWidth = 2
        progressRing.grooveWidth = 2

    }
    
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateLanguage()
        }
    }
    func updateLanguage(){
        scanButton.setTitle(Localization(TranslationConstants.CONTINUE), for: .normal)
        header.text = Localization(TranslationConstants.VERIFY_STEP)
        subHeader.text = Localization(TranslationConstants.VERIFY_STEP_NOTE)
        navTitle.text = Localization(TranslationConstants.IDENTITY_TITLE)
        infoSubtitle.text = Localization(TranslationConstants.NEXT_3)
        infoTitle.text = Localization(TranslationConstants.FACE_MATCH)
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

extension InformationViewController: UITableViewDelegate, UITableViewDataSource {
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return icons.count
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = self.infoTableView.dequeueReusableCell(withIdentifier: "labelcell", for: indexPath) as? InfoTableViewCell
        cell?.infoIcon.image = UIImage(named: icons[indexPath.row])
        cell?.inforamationLable.text = Localization(inforamtions[indexPath.row])
        cell?.infoIcon.contentMode = .scaleAspectFit
        cell?.infoIcon.layer.borderWidth = 1
        if indexPath.row > 2 {
            cell?.infoIcon.layer.borderColor = UIColor.red.cgColor
        }
        return cell!
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 70
    }
}
extension InformationViewController:PresenterToViewInfoProtocol{
    func publicKey(with status: Bool, andWith response: PublicKeyResponse?, failure error: String?) {
        if status {
            self.validateCetificate(using: response?.publicKey)
        }
        else {
            self.hideProgress()
            if let error = response?.error{
                DispatchQueue.main.async {
                    self.alert(message: error)
                }
            }
            else{
                DispatchQueue.main.async {
                    self.alert(message: error ?? TranslationConstants.WENT_WRONG.localize())
                }
            }
        }
    }
    
    func validateRSASignature(signedData: NSData, signature: Data, publicKeyData: Data) -> Bool {

        // Create a SecKey instance from the public key data.
        var error1: Unmanaged<CFError>? = nil

        let publicKey: SecKey! = SecKeyCreateWithData(publicKeyData as NSData, [
            kSecAttrKeyType: kSecAttrKeyTypeRSA,
            kSecAttrKeyClass: kSecAttrKeyClassPublic
        ] as NSDictionary, &error1)
//        NSLog("%@", "\(key)")
       NSLog(error1.debugDescription)
        let hashString = SDKInitialize.demogs!.sha256()
        print("Generated Hash -\(hashString)")
        let shaData = hashString.getUTF()
        // Verify the RSA signature.
        var error2: Unmanaged<CFError>? = nil
         let status = SecKeyVerifySignature(publicKey,
                                     .rsaSignatureMessagePKCS1v15SHA256,
                                            shaData!,
                                            signature as NSData,
                                     &error2)
        NSLog(error2.debugDescription)
        return status
    }
    
    func validateCetificate(using publicKey:String?){
        if let cryptoImage = UserDefaults.standard.getFaceTemplate().toImage() {
            let pixelData = cryptoImage.jpegData(compressionQuality: 1.0)
            SDKInitialize.decodeCryptograph(barCodeData: pixelData!)
            let demoData = SDKInitialize.demogsData
            let pubKeyData = publicKey?.data(using: .ascii)
            guard let pubKeyData1 = Data(base64Encoded: publicKey!) else {
                    return
                }
            let result = validateRSASignature(signedData: SDKInitialize.demoData!, signature: SDKInitialize.digitalCertificateData!, publicKeyData: pubKeyData1)
            if result {
                self.presenter?.registerUser(withDemographics: documentRreaderResult)
            }
        }
    }
    
    func cryptoCreated(with status: Bool, andWith response: CryptographyResponse?, failure error: Error?) {
        if status{
            cryptoSuccessResponse = response
            self.presenter?.getPublicKey()
        }
        else{
            self.hideProgress()
            if let error = response?.error{
                DispatchQueue.main.async {
                    self.alert(message: error)
                }
            }
            else{
                DispatchQueue.main.async {
                    self.alert(message: error?.localizedDescription ?? TranslationConstants.WENT_WRONG.localize())
                }
            }
        }
    }
    
    func userRegisted(with status: Bool, andWith response: UserRegisterResponse?, failure error: Error?) {
        self.hideProgress()
        if status{
            DispatchQueue.main.async {
                self.presenter?.moveToNextViewController(navigationController: self.navigationController!, scanndDocumentResult: self.documentRreaderResult, livenessFaceData: self.livenessfaceData!, withResponse: self.cryptoSuccessResponse, withRegisterResponse: response)
            }
            
        }
        else{
            if let message = response?.error{
                DispatchQueue.main.async {
                    self.alert(message: message)
                }
                
            }
            else{
                DispatchQueue.main.async {
                    self.alert(message: error?.localizedDescription ?? TranslationConstants.WENT_WRONG.localize())
                }
            }
        }
    }
    
    func faceResult(withSuccessStatus status: Bool, faceData data: NSData?, faceBoxValues facebox: FaceBox?, andWithError: String?) {
        self.hideProgress()
        if let _ = qrCode{
            faceCollecterDelegate?.getLivenessData(livenessData: data as Data?)
//            self.navigationController?.popViewController(animated: true)
            return
        }
        if let faceData = data {
            
            self.showPreogress(title: Localization(TranslationConstants.CREATING_CRYPTO))
            livenessfaceData = faceData as Data
        }
        else {
            self.alert(message: andWithError!)
            return
        }
        if status == false || idCardFaceTemplate!.isEmpty {
            
            self.alert(message: Localization(TranslationConstants.CREATING_CRYPTO))
            return
        }
        presenter?.verifyIdentification(withLivenssFaceData: data! as Data, andWithScannedDocumentFace: idCardFaceTemplate!, scanndDocumentResult: documentRreaderResult)
    }
    func processStatus(withMessage message: String) {
        self.updatedMessage(title: message)
    }
}



//
//  StepsViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 23/01/23.
//

import UIKit
import GradientCircularProgress
import ALProgressView
import DocumentReader

class StepsViewController: BaseViewController {
    @IBOutlet weak var navTitle: CustomLabel!
    
    @IBOutlet weak var backButton: UIButton!
    @IBOutlet weak var nextButton: UIButton!
    @IBOutlet weak var stepTableView: UITableView!
    @IBOutlet weak var progressSubheader: UILabel!
    @IBOutlet weak var progressHeader: UILabel!
    @IBOutlet weak var infoSubTitlLabl: UILabel!
    @IBOutlet weak var progressView1: UIView!
    var presenter : StepViewtoPresenterProtocol?
    var stepsLabel = UILabel()
    var totalSteps = 3.0
    @IBOutlet weak var infoTitle: UILabel!
    var documentRreaderResult:DocumentReaderResults?
    var details : [String:String]?
    var idCardFaceTemplate:Data?
    var livenessfaceData : Data?
    var numberofItems : [String]?
    var progress = GradientCircularProgress()
    var progressRing = ALProgressRing()
    var progressBar = ALProgressBar()
    var isNextScreenShown = false
    var isReadingStarted = false
    @IBOutlet weak var progressBarSuperView: UIView!
    let transferDataSteps = [TranslationConstants.STEP_1,TranslationConstants.STEP_2,TranslationConstants.STEP_3,TranslationConstants.STEP_1]
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.progressBarSuperView.isHidden = true
        isNextScreenShown = false
        totalSteps = (documentRreaderResult!.chipPage > 0) ? 3.0 : 2.0
        infoTitle.text = Localization(TranslationConstants.VERIFY_SCANNED_DATA)
        stepsLabel.text = "1 / \(Int(totalSteps))"
        stepsLabel.textAlignment = .center
        setupRingProgress()
        stepTableView.reloadData()
        updateLanguage()
        NotificationCenter.default.addObserver(self, selector: #selector(receiveLanguageChangedNotification(notification: )), name: kNotificationLanguageChanged, object: nil)

//        navTitle.text = TranslationConstants.IDENTITY_TITLE
        // Do any additional setup after loading the view.
    }
    
    
    func setupRingProgress(){
        progressView1.addSubview(progressRing)
        progressRing.addSubview(stepsLabel)
        stepsLabel.translatesAutoresizingMaskIntoConstraints = false
        stepsLabel.centerXAnchor.constraint(equalTo: progressRing.centerXAnchor).isActive = true
        stepsLabel.centerYAnchor.constraint(equalTo: progressRing.centerYAnchor).isActive = true
          // Make sure to set the view size
        stepsLabel.widthAnchor.constraint(equalToConstant: 45).isActive = true
        stepsLabel.heightAnchor.constraint(equalToConstant: 25).isActive = true

        progressRing.translatesAutoresizingMaskIntoConstraints = false
        progressRing.centerXAnchor.constraint(equalTo: progressView1.centerXAnchor).isActive = true
        progressRing.centerYAnchor.constraint(equalTo: progressView1.centerYAnchor).isActive = true
          // Make sure to set the view size
        progressRing.widthAnchor.constraint(equalToConstant: 90).isActive = true
        progressRing.heightAnchor.constraint(equalToConstant: 90).isActive = true
        progressRing.duration = 2 // Duration of the ring's fill animation.
//        progressRing.timingFunction = .easeOutExpo // Timing function of the ring's fill animation.
        progressRing.setProgress(Float(1/totalSteps), animated: true)
        progressRing.startColor = UIColor().appcolor()
        progressRing.endColor = UIColor().appcolor()
        // Sets the line width for progress ring and "groove" ring
        progressRing.lineWidth = 2
        // Or, if you need to separate these parameters, use
        progressRing.ringWidth = 2
        progressRing.grooveWidth = 2
        

    }
    func setupBarProgress(){
        if progressBarSuperView.subviews.contains(progressBar) {
            progressBarSuperView.addSubview(progressBar)
            progressBar.translatesAutoresizingMaskIntoConstraints = false
            progressBar.centerXAnchor.constraint(equalTo: progressBarSuperView.centerXAnchor).isActive = true
            progressBar.centerYAnchor.constraint(equalTo: progressBarSuperView.centerYAnchor).isActive = true
            // Make sure to set the view size
            progressBar.widthAnchor.constraint(equalToConstant: 200).isActive = true
            progressBar.heightAnchor.constraint(equalToConstant: 30).isActive = true
            progressBar.duration = 2 // Duration of the ring's fill animation.
            //        progressRing.timingFunction = .easeOutExpo // Timing function of the ring's fill animation.
            progressBar.setProgress(35.0, animated: true)
            progressBar.startColor = UIColor().appcolor()
            progressBar.endColor = UIColor().appcolor()
        }
        // Sets the line width for progress ring and "groove" ring
        // Or, if you need to separate these parameters, use
    }

    
    override func viewWillAppear(_ animated: Bool) {
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false
        details = documentRreaderResult?.getAllRequiredDetail()
        
        if documentRreaderResult?.chipPage ?? 0 > 0{
            infoSubTitlLabl.text = Localization(TranslationConstants.NEXT_1)
            
        }
        else{
            infoSubTitlLabl.text = Localization(TranslationConstants.NEXT_2)
        }
        if !(details?.isEmpty ?? true){
            numberofItems = Array(details!.keys)
            stepTableView.reloadData()
        }
    }

    @IBAction func bakcAction(_ sender: Any) {
        if isNextScreenShown{
            self.viewDidLoad()
        }
        else{
            self.navigationController?.popViewController(animated: true)
        }
    }
    @IBAction func nextAction(_ sender: Any) {
        self.progressBarSuperView.isHidden = true
        if !isNextScreenShown && documentRreaderResult?.chipPage ?? 0 > 0{
            isNextScreenShown = true
            stepTableView.reloadData()
            infoTitle.text = Localization(TranslationConstants.NEXT_1)
            infoSubTitlLabl.text = Localization(TranslationConstants.NEXT_2)
            progressHeader.text = Localization(TranslationConstants.START_DATA_TRANSFER)
            progressSubheader.text = Localization(TranslationConstants.STEP_NOTE)
            stepsLabel.text = "2 / 3"
            progressRing.setProgress(Float(2/totalSteps), animated: true)
            stepTableView.reloadData()
        }
        else if !isReadingStarted && isNextScreenShown{
            isReadingStarted = true
            //show progress
//            self.progressBarSuperView.isHidden = false
            self.setupBarProgress()
            presenter?.openRFID(withController: self)
        }
        else{
            //move to info screen
            presenter?.moveToInfoViewController(navigationController: self.navigationController!, withDocumentResult: documentRreaderResult, andTemplateData: idCardFaceTemplate!)
        }
    }
    
    @objc func receiveLanguageChangedNotification(notification:NSNotification) {
        if notification.name == kNotificationLanguageChanged {
            updateLanguage()
        }
    }
    func updateLanguage(){
        backButton.setTitle(Localization(TranslationConstants.BACK), for: .normal)
        nextButton.setTitle(Localization(TranslationConstants.NEXT), for: .normal)
        progressSubheader.text = Localization(TranslationConstants.IS_DATA_CORRECT_NOTE)
        progressHeader.text = Localization(TranslationConstants.IS_DATA_CORRECT)
        infoSubTitlLabl.text = Localization(TranslationConstants.NEXT_2)
        infoTitle.text = Localization(TranslationConstants.VERIFY_SCANNED_DATA)
        navTitle.text = Localization(TranslationConstants.IDENTITY_TITLE)

    }
}
extension StepsViewController:UITableViewDataSource,UITableViewDelegate{
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if isNextScreenShown{
            return transferDataSteps.count
        }
        return numberofItems?.count ?? 0
    }
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if !isNextScreenShown{
            let cell = tableView.dequeueReusableCell(withIdentifier: "step1", for: indexPath) as! Step1TableViewCell
            let key = numberofItems![indexPath.row]
            cell.fieldName.text = Localization(key)
            cell.fieldValue.text = details![key]
            return cell
        }
        else{
            let cell = tableView.dequeueReusableCell(withIdentifier: "step2", for: indexPath) as! SteptwoTableViewCell
            cell.number.text = "\(indexPath.row + 1)"
            cell.InfoLabel.text = Localization(transferDataSteps[indexPath.row])
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if isNextScreenShown{
            return 90
        }
        return 50
    }
    
    
}

extension StepsViewController:StepPresenterToViewProtocol{
    //Return value of completiong status
    func readStatus(docReaderAction action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
        self.progressBar.setProgress(Float(action.rawValue), animated: true)
    }
    
    func getDocumentDataWith(successStatus success: Bool, templateData template: Data, withDocReader action: DocReaderAction, withResult result: DocumentReaderResults?, andWithError error: Error?) {
        if let _ = result{
            
            presenter?.moveToInfoViewController(navigationController: self.navigationController!, withDocumentResult: result, andTemplateData: template)
        }
        else{
            isReadingStarted = false
            self.alert(message: error?.localizedDescription ?? "Something went wrong")
            self.stepTableView.reloadData()
        }
    }
    
    
}


import GradientCircularProgress
import ALProgressView

public struct MyStyle : StyleProperty {
    /*** style properties **********************************************************************************/
    
    // Progress Size
    public var progressSize: CGFloat = 80
    
    // Gradient Circular
    public var arcLineWidth: CGFloat = 2.0
    public var startArcColor: UIColor = UIColor.clear
    public var endArcColor: UIColor = UIColor.green
    
    // Base Circular
    public var baseLineWidth: CGFloat? = 2.0
    public var baseArcColor: UIColor? = UIColor.darkGray
    
    // Ratio
    public var ratioLabelFont: UIFont? = UIFont(name: "Poppins-Bold", size: 16.0)
    public var ratioLabelFontColor: UIColor? = UIColor.white
    
    // Message
    public var messageLabelFont: UIFont? = UIFont.systemFont(ofSize: 16.0)
    public var messageLabelFontColor: UIColor? = UIColor.white
    
    // Background
    public var backgroundStyle: BackgroundStyles = .transparent
    
    // Dismiss
    public var dismissTimeInterval: Double? = 0.0 // 'nil' for default setting.
    
    /*** style properties **********************************************************************************/
    
    public init() {}
}

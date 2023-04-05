//
//  SplashViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import UIKit
import AirsnapFaceUI
import Lottie

class SplashViewController: BaseViewController {

    @IBOutlet weak var indicator: UIActivityIndicatorView!
    @IBOutlet weak var indicatorLable: UILabel!
    var presentorDelegate: splashViewToPresenterProtocol?
    var animationView : LottieAnimationView?
    var moveToNextScreen : Bool? = false
    var isPushed : Bool = false
    var demoLabel : UILabel?
    override func viewDidLoad() {
        
        super.viewDidLoad()
        self.indicator.isHidden = true
        self.indicatorLable.isHidden = true
        demoLabel = UILabel(frame: CGRect(x: 0, y: 0, width: self.view.frame.size.width * 0.80, height: 21))
        demoLabel?.center = CGPoint(x: self.view.center.x, y: 64)
        demoLabel?.textAlignment = .center
        demoLabel?.text = Localization(TranslationConstants.DEMO)
        demoLabel?.font = UIFont(name: "abel", size: 17)

        self.view.addSubview(demoLabel!)
        self.view.bringSubviewToFront(demoLabel!)

//        self.presentorDelegate?.getLiscense()
        FaceCaptureController().initSDK(licenseString: "") { status in
            if status {
                self.presentorDelegate?.getLiscense()
            }
            else {
                DispatchQueue.main.async {
                    self.indicator.isHidden = false
                    self.indicatorLable.isHidden = false
                    self.indicator.startAnimating()
                    self.indicatorLable.text = Localization(TranslationConstants.TRY_AGAIN)
                }
            }
        }
        DispatchQueue.main.asyncAfter(deadline: .now() + 3) { [self] in
            self.indicator.isHidden = false
            self.indicatorLable.isHidden = false
            self.indicator.startAnimating()
            self.indicatorLable.text = Localization(TranslationConstants.INIT_OCR)
        }
        
        animationView = LottieAnimationView(name: "final")
        animationView?.frame = self.view.bounds
        animationView?.loopMode = .playOnce
        animationView?.animationSpeed = 0.5
        animationView?.play(completion: { status in
            DispatchQueue.main.async {
                if self.moveToNextScreen! {
                    if !self.isPushed {
                        self.indicatorLable.text = Localization(TranslationConstants.INTIALIZED)
                        self.indicator.stopAnimating()
                        self.indicator.isHidden = true
                        self.isPushed = true
                        DispatchQueue.main.async {
                            self.presentorDelegate?.moveToHomeViewController(navigationConroller: self.navigationController!)
                        }
                    }
                }
                self.moveToNextScreen = true
            }
        })
        self.view.addSubview(animationView!)
        view.sendSubviewToBack(animationView!)
        
//        presentorDelegate?.getLiscense()
        // Do any additional setup after loading the view.
    }
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.navigationController?.interactivePopGestureRecognizer?.isEnabled = false

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
extension SplashViewController: presenterToSplashViewProtocol {

    
    func documentReaderValidationResult(with status: Bool, andWith error: Error?) {
        DispatchQueue.main.async {
            if status {
                
                if self.moveToNextScreen! {
                    if !self.isPushed {
                        self.indicatorLable.text = Localization(TranslationConstants.INTIALIZED)
                        self.indicator.stopAnimating()
                        self.indicator.isHidden = true
                        self.indicatorLable.text = Localization(TranslationConstants.INTIALIZED)
                        self.isPushed = true
                            self.presentorDelegate?.moveToHomeViewController(navigationConroller: self.navigationController!)
                    }
                }
                self.moveToNextScreen = true
            }
            else{
                self.indicatorLable.text = error?.localizedDescription
            }

        }
    }
}

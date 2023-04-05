//
//  BaseViewController.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 19/01/23.
//

import UIKit

class BaseViewController: UIViewController {
    let loadingAlertController: UIAlertController = UIAlertController(title: "Loading", message: nil, preferredStyle: .alert)

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    
    func updatedMessage(title:String){
        DispatchQueue.main.async {
            self.loadingAlertController.title = title
        }
        
    }
    func showPreogress(title:String){
        
        DispatchQueue.main.async { [self] in
            // add the spinner view controller
            
            do{
                
                let activityIndicator: UIActivityIndicatorView = UIActivityIndicatorView(style: .gray)
                activityIndicator.translatesAutoresizingMaskIntoConstraints = false
                loadingAlertController.title = title
                
                loadingAlertController.view.addSubview(activityIndicator)
                
                let xConstraint: NSLayoutConstraint = NSLayoutConstraint(item: activityIndicator, attribute: .centerX, relatedBy: .equal, toItem: loadingAlertController.view, attribute: .centerX, multiplier: 1, constant: 0)
                let yConstraint: NSLayoutConstraint = NSLayoutConstraint(item: activityIndicator, attribute: .centerY, relatedBy: .equal, toItem: loadingAlertController.view, attribute: .centerY, multiplier: 1.4, constant: 0)
                
                NSLayoutConstraint.activate([ xConstraint, yConstraint])
                activityIndicator.isUserInteractionEnabled = false
                activityIndicator.startAnimating()
                
                let height: NSLayoutConstraint = NSLayoutConstraint(item: loadingAlertController.view as Any, attribute: NSLayoutConstraint.Attribute.height, relatedBy: NSLayoutConstraint.Relation.equal, toItem: nil, attribute: NSLayoutConstraint.Attribute.notAnAttribute, multiplier: 1, constant: 110)
                loadingAlertController.view.addConstraint(height)
                
                self.present(loadingAlertController, animated: true, completion: nil)
                //                viewController.addChild(indicator)
                //                indicator.view.frame = viewController.view.frame
                //                viewController.view.addSubview(indicator.view)
                //                indicator.didMove(toParent: viewController)
            }catch{
                
            }
        }
    }
    
    func hideProgress(){
        DispatchQueue.main.async { [self] in
            do{
                loadingAlertController.dismiss(animated: true)
            }catch{
            }
            
        }
    }

    func alert(message: String, title: String = "") {
        self.hideProgress()
      let alertController = UIAlertController(title: title, message: message, preferredStyle: .alert)
      let OKAction = UIAlertAction(title: "OK", style: .default, handler: nil)
      alertController.addAction(OKAction)
        DispatchQueue.main.async {
            self.present(alertController, animated: true, completion: nil)
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

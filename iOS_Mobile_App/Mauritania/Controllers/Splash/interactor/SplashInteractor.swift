//
//  SplashInteractor.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 11/01/23.
//

import UIKit
import DocumentReader

class SplashInteractor: presenterToSplashInteractoreProtocol {
    var presentor: interactoreToPresenterProtocol?
        
    func ValidateDocumentReader(withName fileName: String?) {
       let licenseData = self.checkLicensing(withName: fileName)
        if licenseData != nil {
            initializeDocReader(withData: licenseData!) { success, error in
                if success {
                    DocReader.shared.rfidScenario.ePassportDataGroups.dG14 = false
                    DocReader.shared.processParams.scenario = RGL_SCENARIO_FULL_PROCESS
                }
                self.presentor?.documentReaderValidationResult(with: success, andWith: error)
            }
        }
        else {
            self.presentor?.documentReaderValidationResult(with: false, andWith: NSError().getErrorWithMessage(withError: "No License found"))
        }
        
    }
    
    func checkLicensing(withName fileName:String?) -> Data? {
        guard let licensePath = Bundle.main.path(forResource: fileName, ofType: nil) else {
            return nil
        }
        do {
            guard let licenseData = try? Data(contentsOf: URL(fileURLWithPath: licensePath)) else {
                return nil
            }
            return licenseData
        } 
    }
    
    func initializeDocReader(withData licenseData:Data, completion:@escaping ((Bool,Error?)->Void)) {
        let config = DocReader.Config(license: licenseData)
        config.licenseUpdateCheck = true
        DocReader.shared.initializeReader(config: config) { (success, error) in
            completion(success,error)
        }
    }
    
    
}

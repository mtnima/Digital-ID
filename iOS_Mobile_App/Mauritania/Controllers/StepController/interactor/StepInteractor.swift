//
//  StepInteractor.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 25/01/23.
//

import Foundation
import UIKit
import DocumentReader

class StepInteractor:StepPresenterToInteractorProtocol{
    var presenter: StepInteractorToPresenterProtocol?
    
    func openRFIDReader(withController controller: StepsViewController) {
        var template:Data = Data()
        DocReader.shared.startRFIDReader(fromPresenter: controller, completion: { (action, results, error) in
            self.presenter?.readStatus(docReaderAction: action, withResult: results, andWithError: error)
            switch action {
            case .complete:
                if results != nil{
                    let portraitImage = results?.getGraphicFieldImageByType(fieldType: .gf_Portrait, source: .rfidImageData)
                    if let image = portraitImage{
                        UserDefaults.standard.storePortraitImage(portraiImage: image)
                        FaceMatcherSDK.detectFace(faceData: image.jpegData(compressionQuality: 1.0)!)
                        if FaceMatcherSDK.faceTemplate != nil {
                            template = FaceMatcherSDK.faceTemplate
                        }
                    }
                    self.presenter?.getDocumentDataWith(successStatus: true, templateData: template, withDocReader: action, withResult: results, andWithError: error)
                    return
                    
                }
                let updatedError = NSError(domain: "", code: 401, userInfo: [ NSLocalizedDescriptionKey: Localization(TranslationConstants.NO_SCAN_RESULT)])
                self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: results, andWithError: error)
                
                print("Completed")
            case .cancel:
                self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: results, andWithError: error)
                
                print("Cancelled by user")
            case .error:
                self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: results, andWithError: error)
                print("Error: \(error)")
            default:
                self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: results, andWithError: error)
                break;
            }
            
        })
        
    }
   
}

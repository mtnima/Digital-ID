//
//  HomeInteractor.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 12/01/23.
//

import Foundation
import UIKit
import DocumentReader

class HomeInteractor:HomePresenterToInteractorProtocol{
    var presenter:HomeInteractorToPresenterProtocol?
    
     func openDocumentReader(withController controller: ViewController) {
        var template:Data = Data()
//         DocReader.shared.processParams.scenario = RGL_SCENARIO_FULL_PROCESS
         DocReader.shared.processParams.multipageProcessing = true
        DocReader.shared.showScanner(controller) { (action, result, error) in
            if action == .complete || action == .processTimeout {
                if result != nil{
//                    if (result?.chipPage ?? 0) > 0 {
//                        self.startRFIDScanning(withController: controller)
//                        return
//                    }
                    let portrait = result!.getGraphicFieldImageByType(fieldType: .gf_Portrait)
                    if let image = portrait{
                        UserDefaults.standard.storePortraitImage(portraiImage: portrait)
                        FaceMatcherSDK.detectFace(faceData: image.jpegData(compressionQuality: 1.0)!)
                        if FaceMatcherSDK.faceTemplate != nil {
                            template = FaceMatcherSDK.faceTemplate
                        }
                        else{
                            let updatedError = NSError(domain: "", code: 401, userInfo: [ NSLocalizedDescriptionKey: Localization(TranslationConstants.FACE_TEMPLATE_FAILED)])
                            DispatchQueue.main.async {
                                self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: result, andWithError: updatedError)
                            }
                            
                            return
                        }
                    }
                    else{
                        let updatedError = NSError(domain: "", code: 401, userInfo: [ NSLocalizedDescriptionKey: Localization(TranslationConstants.FACE_NOT_FOUND)])
                        DispatchQueue.main.async {
                            self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: result, andWithError: updatedError)
                        }
                        return
                    }
//                    result?.getTextFieldByType(fieldType: .ft_First_Name, lcid: .hindiIndia)
                    for textField in result!.textResult.fields {
                        guard let value = result!.getTextFieldValueByType(fieldType: textField.fieldType, lcid: textField.lcid) else { continue }
                        print("fieldName: \(textField.fieldName), value: \(value)")
                    }
                    self.presenter?.getDocumentDataWith(successStatus: true, templateData: template, withDocReader: action, withResult: result, andWithError: error)
                    return
                }
                let updatedError = NSError(domain: "", code: 401, userInfo: [ NSLocalizedDescriptionKey: Localization(TranslationConstants.NO_SCAN_RESULT)])
                self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: result, andWithError: error)
            }
            else {
                if error != nil {
                    self.presenter?.getDocumentDataWith(successStatus: false, templateData: template, withDocReader: action, withResult: result, andWithError: error)
                }
            }
        }
    }
}

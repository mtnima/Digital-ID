//
//  CustomView.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 03/02/23.
//

import Foundation
import UIKit

@IBDesignable
class CustomButton:UIButton{
    @IBInspectable var languageKye:String?{
        didSet{
            updateUI()
        }
    }
    func updateUI(){
        if let string = languageKye{
            setTitle(string.localize(), for: .normal)
        }
    }
}

@IBDesignable
class CustomLabel:UILabel{
    @IBInspectable var languageKye:String?{
        didSet{
            updateUI()
        }
    }
    func updateUI(){
        if let string = languageKye{
            text = string.localize()
        }
    }
}

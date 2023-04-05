//
//  documentRequestModel.swift
//  Mauritania
//
//  Created by Yuvraj Bharat Kale on 02/02/23.
//

import Foundation
import UIKit

public struct DocumentRequestModel : Codable {
    public var firstName: String?
    public var lastName:String?;
    public var pin:String?
    public var birthDate:String?
    public var placeOfBirth:String
    public var phoneNumber:String?
    public var documentExpiryDate:String?
    public var dateIssueName:String?
    public var nationality:String?
    public var gender:String?
}

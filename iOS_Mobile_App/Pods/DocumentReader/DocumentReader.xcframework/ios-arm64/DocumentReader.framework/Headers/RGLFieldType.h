//
//  RGLFieldType.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 18/02/2022.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Enum contains identifiers that determine the logical type of text data obtained while reading MRZ, document filling fields, and barcodes
typedef NS_ENUM(NSInteger, RGLFieldType) {
    /// Document class code
    RGLFieldTypeFt_Document_Class_Code = 0,
    /// Issuing state code in compliance with 3166-1 standard (ICAO doc 9303)
    RGLFieldTypeFt_Issuing_State_Code = 1,
    /// Document number
    RGLFieldTypeFt_Document_Number = 2,
    /// Expiry date of the document
    RGLFieldTypeFt_Date_of_Expiry = 3,
    /// Issue date of the document
    RGLFieldTypeFt_Date_of_Issue = 4,
    /// Date of birth
    RGLFieldTypeFt_Date_of_Birth = 5,
    /// Place of birth
    RGLFieldTypeFt_Place_of_Birth = 6,
    /// Personal number
    RGLFieldTypeFt_Personal_Number = 7,
    /// Surname
    RGLFieldTypeFt_Surname = 8,
    /// Given name(s)
    RGLFieldTypeFt_Given_Names = 9,
    /// Mother's name
    RGLFieldTypeFt_Mothers_Name = 10,
    /// Nationality
    RGLFieldTypeFt_Nationality = 11,
    /// Sex
    RGLFieldTypeFt_Sex = 12,
    /// Height
    RGLFieldTypeFt_Height = 13,
    /// Weight
    RGLFieldTypeFt_Weight = 14,
    /// Eye color
    RGLFieldTypeFt_Eyes_Color = 15,
    /// Hair color
    RGLFieldTypeFt_Hair_Color = 16,
    /// Address
    RGLFieldTypeFt_Address = 17,
    /// Organ donor indicator
    RGLFieldTypeFt_Donor = 18,
    /// Social security number
    RGLFieldTypeFt_Social_Security_Number = 19,
    /// Driving licence classification code
    RGLFieldTypeFt_DL_Class = 20,
    /// Driving licenсe endorsement code
    RGLFieldTypeFt_DL_Endorsed = 21,
    /// Driving licence restriction code
    RGLFieldTypeFt_DL_Restriction_Code = 22,
    /// Date of 21st birthday
    RGLFieldTypeFt_DL_Under_21_Date = 23,
    /// Issuing authority
    RGLFieldTypeFt_Authority = 24,
    /// Surname and given name(s)
    RGLFieldTypeFt_Surname_And_Given_Names = 25,
    /// Nationality code in compliance with ISO3166-1 standard (ICAO doc 9303)
    RGLFieldTypeFt_Nationality_Code = 26,
    /// Passport number
    RGLFieldTypeFt_Passport_Number = 27,
    /// Invitation number
    RGLFieldTypeFt_Invitation_Number = 28,
    /// Visa identification number
    RGLFieldTypeFt_Visa_ID = 29,
    /// Visa class
    RGLFieldTypeFt_Visa_Class = 30,
    /// Visa subclass
    RGLFieldTypeFt_Visa_SubClass = 31,
    /// Not used
    RGLFieldTypeFt_MRZ_String1 = 32,
    /// Not used
    RGLFieldTypeFt_MRZ_String2 = 33,
    /// Not used
    RGLFieldTypeFt_MRZ_String3 = 34,
    /// MRZ type (ID-1 – 0, ID-2 – 1, ID-3 – 2)
    RGLFieldTypeFt_MRZ_Type = 35,
    /// Optional data
    RGLFieldTypeFt_Optional_Data = 36,
    /// Document class name
    RGLFieldTypeFt_Document_Class_Name = 37,
    /// Issuing state name
    RGLFieldTypeFt_Issuing_State_Name = 38,
    /// Place of issue
    RGLFieldTypeFt_Place_of_Issue = 39,
    /// Checksum for document number
    RGLFieldTypeFt_Document_Number_Checksum = 40,
    /// Checksum for date of birth
    RGLFieldTypeFt_Date_of_Birth_Checksum = 41,
    /// Checksum for date of expiry
    RGLFieldTypeFt_Date_of_Expiry_Checksum = 42,
    /// Checksum for personal number
    RGLFieldTypeFt_Personal_Number_Checksum = 43,
    /// Final checksum (for the whole MRZ)
    RGLFieldTypeFt_FinalChecksum = 44,
    /// Checksum for passport number (for visas)
    RGLFieldTypeFt_Passport_Number_Checksum = 45,
    /// Checksum for invitation number (for visas)
    RGLFieldTypeFt_Invitation_Number_Checksum = 46,
    /// Checksum for visa identification number
    RGLFieldTypeFt_Visa_ID_Checksum = 47,
    /// Checksum for surname + given name(s)
    RGLFieldTypeFt_Surname_And_Given_Names_Checksum = 48,
    /// Checksum for visa expiry date
    RGLFieldTypeFt_Visa_Valid_Until_Checksum = 49,
    /// Other information
    RGLFieldTypeFt_Other = 50,
    /// MRZ lines
    RGLFieldTypeFt_MRZ_Strings = 51,
    /// Name suffix
    RGLFieldTypeFt_Name_Suffix = 52,
    /// Name prefix
    RGLFieldTypeFt_Name_Prefix = 53,
    /// Checksum for date of issue
    RGLFieldTypeFt_Date_of_Issue_Checksum = 54,
    /// Check digit for date of issue
    RGLFieldTypeFt_Date_of_Issue_CheckDigit = 55,
    /// Document series
    RGLFieldTypeFt_Document_Series = 56,
    /// Serial number of registration certificate
    RGLFieldTypeFt_RegCert_RegNumber = 57,
    /// Vehicle model
    RGLFieldTypeFt_RegCert_CarModel = 58,
    /// Vehicle color
    RGLFieldTypeFt_RegCert_CarColor = 59,
    /// Vehicle identification number (VIN)
    RGLFieldTypeFt_RegCert_BodyNumber = 60,
    /// Vehicle type
    RGLFieldTypeFt_RegCert_CarType = 61,
    /// Permissible maximum weight
    RGLFieldTypeFt_RegCert_MaxWeight = 62,
    /// Vehicle weight
    RGLFieldTypeFt_Reg_Cert_Weight = 63,
    /// Address (area)
    RGLFieldTypeFt_Address_Area = 64,
    /// Address (state)
    RGLFieldTypeFt_Address_State = 65,
    /// Address (building number)
    RGLFieldTypeFt_Address_Building = 66,
    /// Address (house number)
    RGLFieldTypeFt_Address_House = 67,
    /// Address (flat number)
    RGLFieldTypeFt_Address_Flat = 68,
    /// Place of registration
    RGLFieldTypeFt_Place_of_Registration = 69,
    /// Date of registration
    RGLFieldTypeFt_Date_of_Registration = 70,
    /// Resident from (date)
    RGLFieldTypeFt_Resident_From = 71,
    /// Resident until (date)
    RGLFieldTypeFt_Resident_Until = 72,
    /// Issuing authority code (for the passport of the Russian Federation)
    RGLFieldTypeFt_Authority_Code = 73,
    /// Place of birth (area)
    RGLFieldTypeFt_Place_of_Birth_Area = 74,
    /// Place of birth (state code)
    RGLFieldTypeFt_Place_of_Birth_StateCode = 75,
    /// Address (street)
    RGLFieldTypeFt_Address_Street = 76,
    /// Address (city)
    RGLFieldTypeFt_Address_City = 77,
    /// Address (jurisdiction code)
    RGLFieldTypeFt_Address_Jurisdiction_Code = 78,
    /// Address (postal code)
    RGLFieldTypeFt_Address_Postal_Code = 79,
    /// Check digit for document number
    RGLFieldTypeFt_Document_Number_CheckDigit = 80,
    /// Check digit for date of birth
    RGLFieldTypeFt_Date_of_Birth_CheckDigit = 81,
    /// Check digit for document expiry date
    RGLFieldTypeFt_Date_of_Expiry_CheckDigit = 82,
    /// Check digit for personal number
    RGLFieldTypeFt_Personal_Number_CheckDigit = 83,
    /// Final check digit (for the whole MRZ)
    RGLFieldTypeFt_FinalCheckDigit = 84,
    /// Check digit for passport number (for visas)
    RGLFieldTypeFt_Passport_Number_CheckDigit = 85,
    /// Check digit for invitation number (for visas)
    RGLFieldTypeFt_Invitation_Number_CheckDigit = 86,
    /// Check digit for visa number
    RGLFieldTypeFt_Visa_ID_CheckDigit = 87,
    /// Check digit for surname and given name(s)
    RGLFieldTypeFt_Surname_And_Given_Names_CheckDigit = 88,
    /// Check digit for visa expiry date
    RGLFieldTypeFt_Visa_Valid_Until_CheckDigit = 89,
    /// Permit type
    RGLFieldTypeFt_Permit_DL_Class = 90,
    /// Permit expiry date
    RGLFieldTypeFt_Permit_Date_of_Expiry = 91,
    /// Permit identifier
    RGLFieldTypeFt_Permit_Identifier = 92,
    /// Permit issue date
    RGLFieldTypeFt_Permit_Date_of_Issue = 93,
    /// Driving permit restriction code
    RGLFieldTypeFt_Permit_Restriction_Code = 94,
    /// Driving permit endorsement code
    RGLFieldTypeFt_Permit_Endorsed = 95,
    /// A line used for document validation in accordance with the database
    RGLFieldTypeFt_Issue_Timestamp = 96,
    /// Number of duplicates
    RGLFieldTypeFt_Number_of_Duplicates = 97,
    /// Medical indicator/code
    RGLFieldTypeFt_Medical_Indicator_Codes = 98,
    /// Indicator showing that the document holder is a non-resident
    RGLFieldTypeFt_Non_Resident_Indicator = 99,
    /// Visa type
    RGLFieldTypeFt_Visa_Type = 100,
    /// The earliest date from which the visa is valid
    RGLFieldTypeFt_Visa_Valid_From = 101,
    /// The date until which the visa is valid
    RGLFieldTypeFt_Visa_Valid_Until = 102,
    /// Duration of stay (in days) granted by the visa
    RGLFieldTypeFt_Duration_of_Stay = 103,
    /// Number of entries granted by the visa
    RGLFieldTypeFt_Number_of_Entries = 104,
    /// Day in the date
    RGLFieldTypeFt_Day = 105,
    /// Month in the date
    RGLFieldTypeFt_Month = 106,
    /// Year in the date
    RGLFieldTypeFt_Year = 107,
    /// Identification number
    RGLFieldTypeFt_Unique_Customer_Identifier = 108,
    /// Commercial vehicle code
    RGLFieldTypeFt_Commercial_Vehicle_Codes = 109,
    /// Also known as (date of birth)
    RGLFieldTypeFt_AKA_Date_of_Birth = 110,
    /// Also known as (social security number)
    RGLFieldTypeFt_AKA_Social_Security_Number = 111,
    /// Also known as (surname)
    RGLFieldTypeFt_AKA_Surname = 112,
    /// Also known as (given names)
    RGLFieldTypeFt_AKA_Given_Names = 113,
    /// Also known as (suffix name)
    RGLFieldTypeFt_AKA_Name_Suffix = 114,
    /// Also known as (prefix name)
    RGLFieldTypeFt_AKA_Name_Prefix = 115,
    /// Mailing address (street)
    RGLFieldTypeFt_Mailing_Address_Street = 116,
    /// Mailing address (city)
    RGLFieldTypeFt_Mailing_Address_City = 117,
    /// Mailing address (jurisdiction code)
    RGLFieldTypeFt_Mailing_Address_Jurisdiction_Code = 118,
    /// Mailing address (postal code)
    RGLFieldTypeFt_Mailing_Address_Postal_Code = 119,
    /// A number which is used for driving licence validation
    RGLFieldTypeFt_Audit_Information = 120,
    /// Inventory control number
    RGLFieldTypeFt_Inventory_Number = 121,
    /// Race/ethnicity
    RGLFieldTypeFt_Race_Ethnicity = 122,
    /// Jurisdiction vehicle class
    RGLFieldTypeFt_Jurisdiction_Vehicle_Class = 123,
    /// Jurisdiction endorsement code
    RGLFieldTypeFt_Jurisdiction_Endorsement_Code = 124,
    /// Jurisdiction restriction code
    RGLFieldTypeFt_Jurisdiction_Restriction_Code = 125,
    /// Surname and (or) given name(s) at birth
    RGLFieldTypeFt_Family_Name = 126,
    /// Given name(s) (Russian transcription)
    RGLFieldTypeFt_Given_Names_RUS = 127,
    /// Visa ID (Russian transcription)
    RGLFieldTypeFt_Visa_ID_RUS = 128,
    /// Father’s name/patronymic
    RGLFieldTypeFt_Fathers_Name = 129,
    /// Father’s name/patronymic (Russian transcription)
    RGLFieldTypeFt_Fathers_Name_RUS = 130,
    /// Surname and given name(s) (Russian transcription)
    RGLFieldTypeFt_Surname_And_Given_Names_RUS = 131,
    /// Place of birth (Russian transcription)
    RGLFieldTypeFt_Place_Of_Birth_RUS = 132,
    /// Document issuing authority (Russian transcription)
    RGLFieldTypeFt_Authority_RUS = 133,
    /// Numeric issuing state code in compliance with ISO 3166-1 standard
    RGLFieldTypeFt_Issuing_State_Code_Numeric = 134,
    /// Numeric nationality code in compliance with ISO 3166-1 standard
    RGLFieldTypeFt_Nationality_Code_Numeric = 135,
    /// Engine power
    RGLFieldTypeFt_Engine_Power = 136,
    /// Engine capacity
    RGLFieldTypeFt_Engine_Volume = 137,
    /// Chassis number
    RGLFieldTypeFt_Chassis_Number = 138,
    /// Engine number
    RGLFieldTypeFt_Engine_Number = 139,
    /// Engine model
    RGLFieldTypeFt_Engine_Model = 140,
    /// Vehicle category
    RGLFieldTypeFt_Vehicle_Category = 141,
    /// Identity card number
    RGLFieldTypeFt_Identity_Card_Number = 142,
    /// Control number
    RGLFieldTypeFt_Control_No = 143,
    /// Parents' given names
    RGLFieldTypeFt_Parrent_s_Given_Names = 144,
    /// Second surname
    RGLFieldTypeFt_Second_Surname = 145,
    /// Second name
    RGLFieldTypeFt_Middle_Name = 146,
    /// Vehicle identification number
    RGLFieldTypeFt_RegCert_VIN = 147,
    /// Check digit for vehicle identification number
    RGLFieldTypeFt_RegCert_VIN_CheckDigit = 148,
    /// Checksum for vehicle identification number
    RGLFieldTypeFt_RegCert_VIN_Checksum = 149,
    /// Check digit for the first MRZ line
    RGLFieldTypeFt_Line1_CheckDigit = 150,
    /// Check digit for the second MRZ line
    RGLFieldTypeFt_Line2_CheckDigit = 151,
    /// Check digit for the third MRZ line
    RGLFieldTypeFt_Line3_CheckDigit = 152,
    /// Checksum for the first MRZ line
    RGLFieldTypeFt_Line1_Checksum = 153,
    /// Checksum for the second MRZ line
    RGLFieldTypeFt_Line2_Checksum = 154,
    /// Checksum for the third MRZ line
    RGLFieldTypeFt_Line3_Checksum = 155,
    /// Check digit for vehicle registration number
    RGLFieldTypeFt_RegCert_RegNumber_CheckDigit = 156,
    /// Check sum for vehicle registration number
    RGLFieldTypeFt_RegCert_RegNumber_Checksum = 157,
    /// Vehicle code according to ITS (IntelligentTransportation Systems )
    RGLFieldTypeFt_RegCert_Vehicle_ITS_Code = 158,
    /// Access number for RFID chip
    RGLFieldTypeFt_Card_Access_Number = 159,
    /// Marital status
    RGLFieldTypeFt_Marital_Status = 160,
    /// Company name
    RGLFieldTypeFt_Company_Name = 161,
    /// Special notes
    RGLFieldTypeFt_Special_Notes = 162,
    /// Surname of spouse
    RGLFieldTypeFt_Surname_of_Spose = 163,
    /// Number for checking document status
    RGLFieldTypeFt_Tracking_Number = 164,
    /// Booklet number
    RGLFieldTypeFt_Booklet_Number = 165,
    /// Children
    RGLFieldTypeFt_Children = 166,
    /// Copy number
    RGLFieldTypeFt_Copy = 167,
    /// Serial number
    RGLFieldTypeFt_Serial_Number = 168,
    /// Dossier number
    RGLFieldTypeFt_Dossier_Number = 169,
    /// Also known as (surname and given names)
    RGLFieldTypeFt_AKA_Surname_And_Given_Names = 170,
    /// Territorial validity
    RGLFieldTypeFt_Territorial_Validity = 171,
    /// MRZ with correct checksums
    RGLFieldTypeFt_MRZ_Strings_With_Correct_CheckSums = 172,
    /// Commercial driving license restriction code
    RGLFieldTypeFt_DL_CDL_Restriction_Code = 173,
    /// Date of 18th birthday
    RGLFieldTypeFt_DL_Under_18_Date = 174,
    /// Date of record creation
    RGLFieldTypeFt_DL_Record_Created = 175,
    /// Date of duplicate creation
    RGLFieldTypeFt_DL_Duplicate_Date = 176,
    /// Type of issued driving license
    RGLFieldTypeFt_DL_Iss_Type = 177,
    /// Military card number
    RGLFieldTypeFt_Military_Book_Number = 178,
    /// Destination
    RGLFieldTypeFt_Destination = 179,
    /// Blood group
    RGLFieldTypeFt_Blood_Group = 180,
    /// Sequence number
    RGLFieldTypeFt_Sequence_Number = 181,
    /// Car body type
    RGLFieldTypeFt_RegCert_BodyType = 182,
    /// Car make
    RGLFieldTypeFt_RegCert_CarMark = 183,
    /// Transaction number
    RGLFieldTypeFt_Transaction_Number = 184,
    /// Age
    RGLFieldTypeFt_Age = 185,
    /// Folio number
    RGLFieldTypeFt_Folio_Number = 186,
    /// Voter's identification number
    RGLFieldTypeFt_Voter_Key = 187,
    /// Address (municipality)
    RGLFieldTypeFt_Address_Municipality = 188,
    /// Address (location)
    RGLFieldTypeFt_Address_Location = 189,
    /// Section/sector
    RGLFieldTypeFt_Section = 190,
    /// OCR number
    RGLFieldTypeFt_OCR_Number = 191,
    /// Federal elections
    RGLFieldTypeFt_Federal_Elections = 192,
    /// Unique number
    RGLFieldTypeFt_Reference_Number = 193,
    /// Checksum for optional data
    RGLFieldTypeFt_Optional_Data_Checksum = 194,
    /// Check digit for optional data
    RGLFieldTypeFt_Optional_Data_CheckDigit = 195,
    /// Visa number
    RGLFieldTypeFt_Visa_Number = 196,
    /// Checksum for visa
    RGLFieldTypeFt_Visa_Number_Checksum = 197,
    /// Checkdigit for visa
    RGLFieldTypeFt_Visa_Number_CheckDigit = 198,
    /// Voter
    RGLFieldTypeFt_Voter = 199,
    /// Type/number of the previous document
    RGLFieldTypeFt_Previous_Type = 200,
    /// Reserved for internal use
    RGLFieldTypeFt_FieldFromMRZ = 220,
    /// Reserved for internal use
    RGLFieldTypeFt_CurrentDate = 221,
    /// Status expiry date
    RGLFieldTypeFt_Status_Date_of_Expiry = 251,
    /// Banknote number
    RGLFieldTypeFt_Banknote_Number = 252,
    /// Customer Service Centre code
    RGLFieldTypeFt_CSC_Code = 253,
    /// Pseudonym
    RGLFieldTypeFt_Artistic_Name = 254,
    /// Academic title
    RGLFieldTypeFt_Academic_Title = 255,
    /// Address (country)
    RGLFieldTypeFt_Address_Country = 256,
    /// Address (zip code)
    RGLFieldTypeFt_Address_Zipcode = 257,
    /// Data on permanent residence permit 1(eID field)
    RGLFieldTypeFt_EID_Residence_Permit1 = 258,
    /// Data on permanent residence permit 2(eID field)
    RGLFieldTypeFt_EID_Residence_Permit2 = 259,
    /// Place of birth: street (eID field)
    RGLFieldTypeFt_EID_PlaceOfBirth_Street = 260,
    /// Place of birth: city (eID field)
    RGLFieldTypeFt_EID_PlaceOfBirth_City = 261,
    /// Place of birth: state (eID field)
    RGLFieldTypeFt_EID_PlaceOfBirth_State = 262,
    /// Place of birth: country (eID field)
    RGLFieldTypeFt_EID_PlaceOfBirth_Country = 263,
    /// Place of birth: zip code (eID field)
    RGLFieldTypeFt_EID_PlaceOfBirth_Zipcode = 264,
    /// Commercial driving license class
    RGLFieldTypeFt_CDL_Class = 265,
    /// Date of 19th birthday
    RGLFieldTypeFt_DL_Under_19_Date = 266,
    /// Weight (pounds)
    RGLFieldTypeFt_Weight_pounds = 267,
    /// Indicator of document limited duration
    RGLFieldTypeFt_Limited_Duration_Document_Indicator = 268,
    /// Endorsement expiry date
    RGLFieldTypeFt_Endorsement_Expiration_Date = 269,
    /// Date of revision
    RGLFieldTypeFt_Revision_Date = 270,
    /// Type of compliance
    RGLFieldTypeFt_Compliance_Type = 271,
    /// Family name truncation
    RGLFieldTypeFt_Family_name_truncation = 272,
    /// First name truncation
    RGLFieldTypeFt_First_name_truncation = 273,
    /// Middle name truncation
    RGLFieldTypeFt_Middle_name_truncation = 274,
    /// Examination date
    RGLFieldTypeFt_Exam_Date = 275,
    /// Organization
    RGLFieldTypeFt_Organization = 276,
    /// Department
    RGLFieldTypeFt_Department = 277,
    /// Pay grade
    RGLFieldTypeFt_Pay_Grade = 278,
    /// Rank/status/title
    RGLFieldTypeFt_Rank = 279,
    /// Number that relates to benefit eligibility
    RGLFieldTypeFt_Benefits_Number = 280,
    /// Sponsor's service
    RGLFieldTypeFt_Sponsor_Service = 281,
    /// Sponsor's status
    RGLFieldTypeFt_Sponsor_Status = 282,
    /// Sponsor
    RGLFieldTypeFt_Sponsor = 283,
    /// Relationship
    RGLFieldTypeFt_Relationship = 284,
    /// Alien registration number issued by theU.S. Citizenship and Immigration Service
    RGLFieldTypeFt_USCIS = 285,
    /// Category
    RGLFieldTypeFt_Category = 286,
    /// Conditions
    RGLFieldTypeFt_Conditions = 287,
    /// Identifier
    RGLFieldTypeFt_Identifier = 288,
    /// Configuration
    RGLFieldTypeFt_Configuration = 289,
    /// Discretionary data
    RGLFieldTypeFt_Discretionary_data = 290,
    /// Optional data from MRZ Line 1
    RGLFieldTypeFt_Line1_Optional_Data = 291,
    /// Optional data from MRZ Line 2
    RGLFieldTypeFt_Line2_Optional_Data = 292,
    /// Optional data from MRZ Line 3
    RGLFieldTypeFt_Line3_Optional_Data = 293,
    /// Equivalence value (security code)
    RGLFieldTypeFt_EQV_Code = 294,
    /// ALT сode
    RGLFieldTypeFt_ALT_Code = 295,
    /// Binary сode
    RGLFieldTypeFt_Binary_Code = 296,
    /// Pseudo-code
    RGLFieldTypeFt_Pseudo_Code = 297,
    /// Fee
    RGLFieldTypeFt_Fee = 298,
    /// Stamp number
    RGLFieldTypeFt_Stamp_Number = 299,
    /// Parameters of biometric data protection
    RGLFieldTypeFt_SBH_SecurityOptions = 300,
    /// Parameters of biometric data integrity
    RGLFieldTypeFt_SBH_IntegrityOptions = 301,
    /// Date of creation of biometric data record
    RGLFieldTypeFt_Date_of_Creation = 302,
    /// Term of validity of biometric data record
    RGLFieldTypeFt_Validity_Period = 303,
    /// Version of header of biometric data format owner
    RGLFieldTypeFt_Patron_Header_Version = 304,
    /// Type of biometric data record
    RGLFieldTypeFt_BDB_Type = 305,
    /// Type of biometric data
    RGLFieldTypeFt_Biometric_Type = 306,
    /// Subtype of biometric data
    RGLFieldTypeFt_Biometric_Subtype = 307,
    /// Identifier of biometric data
    RGLFieldTypeFt_Biometric_ProductID = 308,
    /// Identifier of biometric data format owner
    RGLFieldTypeFt_Biometric_Format_Owner = 309,
    /// Biometric data format
    RGLFieldTypeFt_Biometric_Format_Type = 310,
    /// DO's phone number
    RGLFieldTypeFt_Phone = 311,
    /// DO's profession
    RGLFieldTypeFt_Profession = 312,
    /// DO's title
    RGLFieldTypeFt_Title = 313,
    /// DO's personal summary data
    RGLFieldTypeFt_Personal_Summary = 314,
    /// Other valid identifier
    RGLFieldTypeFt_Other_Valid_ID = 315,
    /// Custody information
    RGLFieldTypeFt_Custody_Info = 316,
    /// Other name
    RGLFieldTypeFt_Other_Name = 317,
    /// Observations
    RGLFieldTypeFt_Observations = 318,
    /// Tax information
    RGLFieldTypeFt_Tax = 319,
    /// Date of document personalization
    RGLFieldTypeFt_Date_of_Personalization = 320,
    /// Serial number of personalization
    RGLFieldTypeFt_Personalization_SN = 321,
    /// Other person's name
    RGLFieldTypeFt_OtherPerson_Name = 322,
    /// Date of record entry on persons to notify in case of emergency
    RGLFieldTypeFt_PersonToNotify_Date_of_Record = 323,
    /// Name of person to notify in case of emergency
    RGLFieldTypeFt_PersonToNotify_Name = 324,
    /// Phone number of person to notify in case of emergency
    RGLFieldTypeFt_PersonToNotify_Phone = 325,
    /// Address of person to notify in case of emergency
    RGLFieldTypeFt_PersonToNotify_Address = 326,
    /// Textual information about the DS-certificate issuer
    RGLFieldTypeFt_DS_Certificate_Issuer = 327,
    /// Textual information about the document issuer
    RGLFieldTypeFt_DS_Certificate_Subject = 328,
    /// Start date of the DS-certificate validity
    RGLFieldTypeFt_DS_Certificate_ValidFrom = 329,
    /// Expiration date of the DS-certificate
    RGLFieldTypeFt_DS_Certificate_ValidTo = 330,
    /// Vehicle category/restrictions/conditions from DG1 data group of eDL application
    RGLFieldTypeFt_VRC_DataObject_Entry = 331,
    /// Type approval number
    RGLFieldTypeFt_TypeApprovalNumber = 332,
    /// Administrative number
    RGLFieldTypeFt_AdministrativeNumber = 333,
    /// Document discriminator
    RGLFieldTypeFt_DocumentDiscriminator = 334,
    /// Data discriminator
    RGLFieldTypeFt_DataDiscriminator = 335,
    /// ISO issuer ID number
    RGLFieldTypeFt_ISO_Issuer_ID_Number = 336,
    /// Registration number issued by GardaNational Immigration Bureau
    RGLFieldTypeFt_GNIB_Number = 340,
    /// Department number
    RGLFieldTypeFt_Dept_Number = 341,
    /// Telegraph code
    RGLFieldTypeFt_Telex_Code = 342,
    /// Allergies
    RGLFieldTypeFt_Allergies = 343,
    /// Sp. code
    RGLFieldTypeFt_Sp_Code = 344,
    /// Code of restriction imposed by court
    RGLFieldTypeFt_Court_Code = 345,
    /// County code
    RGLFieldTypeFt_Cty = 346,
    /// Sponsor's social security number
    RGLFieldTypeFt_Sponsor_SSN = 347,
    /// Department of Defense identification number
    RGLFieldTypeFt_DoD_Number = 348,
    /// Expiry date of Motorcycle status
    RGLFieldTypeFt_MC_Novice_Date = 349,
    /// DUF Number (a number that is assigned to everyone who applies for residence inNorway)
    RGLFieldTypeFt_DUF_Number = 350,
    /// Code of Philippine Land TransportationOffice Agency
    RGLFieldTypeFt_AGY = 351,
    /// Passenger name record (reservation code)
    RGLFieldTypeFt_PNR_Code = 352,
    /// Code of the airport of departure
    RGLFieldTypeFt_From_Airport_Code = 353,
    /// Code of the airport of arrival
    RGLFieldTypeFt_To_Airport_Code = 354,
    /// Flight number
    RGLFieldTypeFt_Flight_Number = 355,
    /// Date of flight
    RGLFieldTypeFt_Date_of_Flight = 356,
    /// Seat number
    RGLFieldTypeFt_Seat_Number = 357,
    /// Date of boarding pass issue
    RGLFieldTypeFt_Date_of_Issue_Boarding_Pass = 358,
    /// Expiration date of Concealed CarryWeapon Permit
    RGLFieldTypeFt_CCW_Until = 359,
    /// Checksum for reference number
    RGLFieldTypeFt_Reference_Number_Checksum = 360,
    /// Check digit for reference number
    RGLFieldTypeFt_Reference_Number_CheckDigit = 361,
    /// Room number
    RGLFieldTypeFt_Room_Number = 362,
    /// Religion
    RGLFieldTypeFt_Religion = 363,
    /// Months to expire
    RGLFieldTypeFt_RemainderTerm = 364,
    /// Electronic ticket indicator
    RGLFieldTypeFt_Electronic_Ticket_Indicator = 365,
    /// Compartment сode
    RGLFieldTypeFt_Compartment_Code = 366,
    /// Check-in sequence number on a boarding pass
    RGLFieldTypeFt_CheckIn_Sequence_Number = 367,
    /// Code of the airline which issued the boarding pass
    RGLFieldTypeFt_Airline_Designator_of_boarding_pass_issuer = 368,
    /// Numeric airline code
    RGLFieldTypeFt_Airline_Numeric_Code = 369,
    /// Ticket number
    RGLFieldTypeFt_Ticket_Number = 370,
    /// Frequent flyer indicator
    RGLFieldTypeFt_Frequent_Flyer_Airline_Designator = 371,
    /// Frequent flyer number
    RGLFieldTypeFt_Frequent_Flyer_Number = 372,
    /// Free baggage allowance
    RGLFieldTypeFt_Free_Baggage_Allowance = 373,
    /// Codec for PDF417
    RGLFieldTypeFt_PDF417Codec = 374,
    /// Checksum for identity card number
    RGLFieldTypeFt_Identity_Card_Number_Checksum = 375,
    /// Check digit for identity card number
    RGLFieldTypeFt_Identity_Card_Number_CheckDigit = 376,
    /// Veteran
    RGLFieldTypeFt_Veteran = 377,
    /// DL class code A1 valid from
    RGLFieldTypeFt_DLClassCode_A1_From = 378,
    /// DL class code A1 valid to
    RGLFieldTypeFt_DLClassCode_A1_To = 379,
    /// DL class code A1 valid notes
    RGLFieldTypeFt_DLClassCode_A1_Notes = 380,
    /// DL class code A1 valid from
    RGLFieldTypeFt_DLClassCode_A_From = 381,
    /// DL class code A1 valid to
    RGLFieldTypeFt_DLClassCode_A_To = 382,
    /// DL class code A1 valid notes
    RGLFieldTypeFt_DLClassCode_A_Notes = 383,
    /// DL class code B valid from
    RGLFieldTypeFt_DLClassCode_B_From = 384,
    /// DL class code B valid to
    RGLFieldTypeFt_DLClassCode_B_To = 385,
    /// DL class code B valid notes
    RGLFieldTypeFt_DLClassCode_B_Notes = 386,
    /// DL class code C1 valid from
    RGLFieldTypeFt_DLClassCode_C1_From = 387,
    /// DL class code C1 valid to
    RGLFieldTypeFt_DLClassCode_C1_To = 388,
    /// DL class code C1 valid notes
    RGLFieldTypeFt_DLClassCode_C1_Notes = 389,
    /// DL class code C valid from
    RGLFieldTypeFt_DLClassCode_C_From = 390,
    /// DL class code C valid to
    RGLFieldTypeFt_DLClassCode_C_To = 391,
    /// DL class code C valid notes
    RGLFieldTypeFt_DLClassCode_C_Notes = 392,
    /// DL class code D1 valid from
    RGLFieldTypeFt_DLClassCode_D1_From = 393,
    /// DL class code D1 valid to
    RGLFieldTypeFt_DLClassCode_D1_To = 394,
    /// DL class code D1 valid notes
    RGLFieldTypeFt_DLClassCode_D1_Notes = 395,
    /// DL class code D valid from
    RGLFieldTypeFt_DLClassCode_D_From = 396,
    /// DL class code D valid to
    RGLFieldTypeFt_DLClassCode_D_To = 397,
    /// DL class code D valid notes
    RGLFieldTypeFt_DLClassCode_D_Notes = 398,
    /// DL class code BE valid from
    RGLFieldTypeFt_DLClassCode_BE_From = 399,
    /// DL class code BE valid to
    RGLFieldTypeFt_DLClassCode_BE_To = 400,
    /// DL class code BE valid notes
    RGLFieldTypeFt_DLClassCode_BE_Notes = 401,
    /// DL class code C1E valid from
    RGLFieldTypeFt_DLClassCode_C1E_From = 402,
    /// DL class code C1E valid to
    RGLFieldTypeFt_DLClassCode_C1E_To = 403,
    /// DL class code C1E valid notes
    RGLFieldTypeFt_DLClassCode_C1E_Notes = 404,
    /// DL class code CE valid from
    RGLFieldTypeFt_DLClassCode_CE_From = 405,
    /// DL class code CE valid to
    RGLFieldTypeFt_DLClassCode_CE_To = 406,
    /// DL class code CE valid notes
    RGLFieldTypeFt_DLClassCode_CE_Notes = 407,
    /// DL class code D1E valid from
    RGLFieldTypeFt_DLClassCode_D1E_From = 408,
    /// DL class code D1E valid to
    RGLFieldTypeFt_DLClassCode_D1E_To = 409,
    /// DL class code D1E valid notes
    RGLFieldTypeFt_DLClassCode_D1E_Notes = 410,
    /// DL class code DE valid from
    RGLFieldTypeFt_DLClassCode_DE_From = 411,
    /// DL class code DE valid to
    RGLFieldTypeFt_DLClassCode_DE_To = 412,
    /// DL class code DE valid notes
    RGLFieldTypeFt_DLClassCode_DE_Notes = 413,
    /// DL class code M valid from
    RGLFieldTypeFt_DLClassCode_M_From = 414,
    /// DL class code M valid to
    RGLFieldTypeFt_DLClassCode_M_To = 415,
    /// DL class code M valid notes
    RGLFieldTypeFt_DLClassCode_M_Notes = 416,
    /// DL class code L valid from
    RGLFieldTypeFt_DLClassCode_L_From = 417,
    /// DL class code L valid to
    RGLFieldTypeFt_DLClassCode_L_To = 418,
    /// DL class code L valid notes
    RGLFieldTypeFt_DLClassCode_L_Notes = 419,
    /// DL class code T valid from
    RGLFieldTypeFt_DLClassCode_T_From = 420,
    /// DL class code T valid to
    RGLFieldTypeFt_DLClassCode_T_To = 421,
    /// DL class code T valid notes
    RGLFieldTypeFt_DLClassCode_T_Notes = 422,
    /// DL class code AM valid from
    RGLFieldTypeFt_DLClassCode_AM_From = 423,
    /// DL class code AM valid to
    RGLFieldTypeFt_DLClassCode_AM_To = 424,
    /// DL class code AM valid notes
    RGLFieldTypeFt_DLClassCode_AM_Notes = 425,
    /// DL class code A2 valid from
    RGLFieldTypeFt_DLClassCode_A2_From = 426,
    /// DL class code A2 valid to
    RGLFieldTypeFt_DLClassCode_A2_To = 427,
    /// DL class code A2 valid notes
    RGLFieldTypeFt_DLClassCode_A2_Notes = 428,
    /// DL class code B1 valid from
    RGLFieldTypeFt_DLClassCode_B1_From = 429,
    /// DL class code B1 valid to
    RGLFieldTypeFt_DLClassCode_B1_To = 430,
    /// DL class code B1 valid notes
    RGLFieldTypeFt_DLClassCode_B1_Notes = 431,
    /// Surname at birth
    RGLFieldTypeFt_Surname_at_Birth = 432,
    /// Civil status
    RGLFieldTypeFt_Civil_Status = 433,
    /// Number of seats
    RGLFieldTypeFt_Number_of_Seats = 434,
    /// Number of standing places
    RGLFieldTypeFt_Number_of_Standing_Places = 435,
    /// Maximum speed
    RGLFieldTypeFt_Max_Speed = 436,
    /// Fuel type
    RGLFieldTypeFt_Fuel_Type = 437,
    /// Vehicle environmental type
    RGLFieldTypeFt_EC_Environmental_Type = 438,
    /// Power–to–weight ratio
    RGLFieldTypeFt_Power_Weight_Ratio = 439,
    /// Maximum weight of the trailer without brakes
    RGLFieldTypeFt_Max_Mass_of_Trailer_Braked = 440,
    /// Maximum weight of the trailer without brakes
    RGLFieldTypeFt_Max_Mass_of_Trailer_Unbraked = 441,
    /// Transmission type
    RGLFieldTypeFt_Transmission_Type = 442,
    /// Trailer hitch
    RGLFieldTypeFt_Trailer_Hitch = 443,
    /// Accompanying person
    RGLFieldTypeFt_Accompanied_by = 444,
    /// Police district
    RGLFieldTypeFt_Police_District = 445,
    /// Date of first issue
    RGLFieldTypeFt_First_Issue_Date = 446,
    /// Payload capacity
    RGLFieldTypeFt_Payload_Capacity = 447,
    /// Number of axels
    RGLFieldTypeFt_Number_of_Axels = 448,
    /// Permissible axle load
    RGLFieldTypeFt_Permissible_Axle_Load = 449,
    /// Precinct
    RGLFieldTypeFt_Precinct = 450,
    /// Invited by
    RGLFieldTypeFt_Invited_by = 451,
    /// Purpose of entry
    RGLFieldTypeFt_Purpose_of_Entry = 452,
    /// Skin color
    RGLFieldTypeFt_Skin_Color = 453,
    /// Complexion
    RGLFieldTypeFt_Complexion = 454,
    /// Airport of departure
    RGLFieldTypeFt_Airport_From = 455,
    /// Airport of arrival
    RGLFieldTypeFt_Airport_To = 456,
    /// Airline name
    RGLFieldTypeFt_Airline_Name = 457,
    /// A loyalty program offered by the airline to its customers who fly frequently
    RGLFieldTypeFt_Airline_Name_Frequent_Flyer = 458,
    /// Licenсe number
    RGLFieldTypeFt_License_Number = 459,
    /// In tanks
    RGLFieldTypeFt_In_Tanks = 460,
    /// Except in tanks
    RGLFieldTypeFt_Exept_In_Tanks = 461,
    /// Passenger using the Fast Track service in the airport
    RGLFieldTypeFt_Fast_Track = 462,
    /// Owner
    RGLFieldTypeFt_Owner = 463,
    /// MRZ strings from ICAO RFID
    RGLFieldTypeFt_MRZ_Strings_ICAO_RFID = 464,
    /// The number of times a card with this number has been issued
    RGLFieldTypeFt_Number_of_Card_Issuance = 465,
    /// Number of card issuance checksum
    RGLFieldTypeFt_Number_of_Card_Issuance_Checksum = 466,
    /// Number of card issuance check digit
    RGLFieldTypeFt_Number_of_Card_Issuance_CheckDigit = 467,
    /// Century of birth
    RGLFieldTypeFt_Century_Date_of_Birth = 468,
    /// DL class code A3 valid from
    RGLFieldTypeFt_DLClassCode_A3_From = 469,
    /// DL class code A3 valid to
    RGLFieldTypeFt_DLClassCode_A3_To = 470,
    /// DL class code A3 valid notes
    RGLFieldTypeFt_DLClassCode_A3_Notes = 471,
    /// DL class code C2 valid from
    RGLFieldTypeFt_DLClassCode_C2_From = 472,
    /// DL class code C2 valid to
    RGLFieldTypeFt_DLClassCode_C2_To = 473,
    /// DL class code C2 valid notes
    RGLFieldTypeFt_DLClassCode_C2_Notes = 474,
    /// DL class code B2 valid from
    RGLFieldTypeFt_DLClassCode_B2_From = 475,
    /// DL class code B2 valid to
    RGLFieldTypeFt_DLClassCode_B2_To = 476,
    /// DL class code B2 valid notes
    RGLFieldTypeFt_DLClassCode_B2_Notes = 477,
    /// DL class code D2 valid from
    RGLFieldTypeFt_DLClassCode_D2_From = 478,
    /// DL class code B2 valid to
    RGLFieldTypeFt_DLClassCode_D2_To = 479,
    /// DL class code B2 valid notes
    RGLFieldTypeFt_DLClassCode_D2_Notes = 480,
    /// DL class code B2E valid from
    RGLFieldTypeFt_DLClassCode_B2E_From = 481,
    /// DL class code B2E valid to
    RGLFieldTypeFt_DLClassCode_B2E_To = 482,
    /// DL class code B2E valid notes
    RGLFieldTypeFt_DLClassCode_B2E_Notes = 483,
    /// DL class code G valid from
    RGLFieldTypeFt_DLClassCode_G_From = 484,
    /// DL class code G valid to
    RGLFieldTypeFt_DLClassCode_G_To = 485,
    /// DL class code G valid notes
    RGLFieldTypeFt_DLClassCode_G_Notes = 486,
    /// DL class code J valid from
    RGLFieldTypeFt_DLClassCode_J_From = 487,
    /// DL class code J valid to
    RGLFieldTypeFt_DLClassCode_J_To = 488,
    /// DL class code J valid notes
    RGLFieldTypeFt_DLClassCode_J_Notes = 489,
    /// DL class code LC valid from
    RGLFieldTypeFt_DLClassCode_LC_From = 490,
    /// DL class code LC valid to
    RGLFieldTypeFt_DLClassCode_LC_To = 491,
    /// DL class code LC valid notes
    RGLFieldTypeFt_DLClassCode_LC_Notes = 492,
    /// Bank card number
    RGLFieldTypeFt_BankCardNumber = 493,
    /// Bank card validity
    RGLFieldTypeFt_BankCardValidThru = 494,
    /// Tax number
    RGLFieldTypeFt_TaxNumber = 495,
    /// Health insurance number
    RGLFieldTypeFt_HealthNumber = 496,
    /// Grandfather's name
    RGLFieldTypeFt_GrandfatherName = 497,
    /// Selectee indicator
    RGLFieldTypeFt_Selectee_Indicator = 498,
    /// Mother's surname
    RGLFieldTypeFt_Mother_Surname = 499,
    /// Mother's given name
    RGLFieldTypeFt_Mother_GivenName = 500,
    /// Father's surname
    RGLFieldTypeFt_Father_Surname = 501,
    /// Father's given name
    RGLFieldTypeFt_Father_GivenName = 502,
    /// Mother's date of birth
    RGLFieldTypeFt_Mother_DateOfBirth = 503,
    /// Father's date of birth
    RGLFieldTypeFt_Father_DateOfBirth = 504,
    /// Mother's personal number
    RGLFieldTypeFt_Mother_PersonalNumber = 505,
    /// Father's personal number
    RGLFieldTypeFt_Father_PersonalNumber = 506,
    /// Mother's place of birth
    RGLFieldTypeFt_Mother_PlaceOfBirth = 507,
    /// Father's place of birth
    RGLFieldTypeFt_Father_PlaceOfBirth = 508,
    /// Mother's country of birth
    RGLFieldTypeFt_Mother_CountryOfBirth = 509,
    /// Father's country of birth
    RGLFieldTypeFt_Father_CountryOfBirth = 510,
    /// Date of first renewal
    RGLFieldTypeFt_Date_First_Renewal = 511,
    /// Date of second renewal
    RGLFieldTypeFt_Date_Second_Renewal = 512,
    /// Place of examination
    RGLFieldTypeFt_PlaceOfExamination = 513,
    /// Application number
    RGLFieldTypeFt_ApplicationNumber = 514,
    /// Voucher number
    RGLFieldTypeFt_VoucherNumber = 515,
    /// Authorization number
    RGLFieldTypeFt_AuthorizationNumber = 516,
    /// Faculty
    RGLFieldTypeFt_Faculty = 517,
    /// Form of education
    RGLFieldTypeFt_FormOfEducation = 518,
    /// DNI number
    RGLFieldTypeFt_DNINumber = 519,
    /// Retirement number
    RGLFieldTypeFt_RetirementNumber = 520,
    /// Professional Id number
    RGLFieldTypeFt_ProfessionalIdNumber = 521,
    /// Age at issue
    RGLFieldTypeFt_Age_at_Issue = 522,
    /// Years since issue
    RGLFieldTypeFt_Years_Since_Issue = 523,
    /// DL class code BTP valid from
    RGLFieldTypeFt_DLClassCode_BTP_From = 524,
    /// DL class code BTP valid notes
    RGLFieldTypeFt_DLClassCode_BTP_Notes = 525,
    /// DL class code BTP valid to
    RGLFieldTypeFt_DLClassCode_BTP_To = 526,
    /// DL class code C3 valid from
    RGLFieldTypeFt_DLClassCode_C3_From = 527,
    /// DL class code C3 valid notes
    RGLFieldTypeFt_DLClassCode_C3_Notes = 528,
    /// DL class code C3 valid to
    RGLFieldTypeFt_DLClassCode_C3_To = 529,
    /// DL class code E valid from
    RGLFieldTypeFt_DLClassCode_E_From = 530,
    /// DL class code E valid notes
    RGLFieldTypeFt_DLClassCode_E_Notes = 531,
    /// DL class code E valid to
    RGLFieldTypeFt_DLClassCode_E_To = 532,
    /// DL class code F valid from
    RGLFieldTypeFt_DLClassCode_F_From = 533,
    /// DL class code F valid notes
    RGLFieldTypeFt_DLClassCode_F_Notes = 534,
    /// DL class code F valid to
    RGLFieldTypeFt_DLClassCode_F_To = 535,
    /// DL class code FA valid from
    RGLFieldTypeFt_DLClassCode_FA_From = 536,
    /// DL class code FA valid notes
    RGLFieldTypeFt_DLClassCode_FA_Notes = 537,
    /// DL class code FA valid to
    RGLFieldTypeFt_DLClassCode_FA_To = 538,
    /// DL class code FA1 valid from
    RGLFieldTypeFt_DLClassCode_FA1_From = 539,
    /// DL class code FA1 valid notes
    RGLFieldTypeFt_DLClassCode_FA1_Notes = 540,
    /// DL class code FA1 valid to
    RGLFieldTypeFt_DLClassCode_FA1_To = 541,
    /// DL class code FB valid from
    RGLFieldTypeFt_DLClassCode_FB_From = 542,
    /// DL class code FB valid notes
    RGLFieldTypeFt_DLClassCode_FB_Notes = 543,
    /// DL class code FB valid to
    RGLFieldTypeFt_DLClassCode_FB_To = 544,
    /// DL class code G1 valid from
    RGLFieldTypeFt_DLClassCode_G1_From = 545,
    /// DL class code G1 valid notes
    RGLFieldTypeFt_DLClassCode_G1_Notes = 546,
    /// DL class code G1 valid to
    RGLFieldTypeFt_DLClassCode_G1_To = 547,
    /// DL class code H valid from
    RGLFieldTypeFt_DLClassCode_H_From = 548,
    /// DL class code H valid notes
    RGLFieldTypeFt_DLClassCode_H_Notes = 549,
    /// DL class code H valid to
    RGLFieldTypeFt_DLClassCode_H_To = 550,
    /// DL class code I valid from
    RGLFieldTypeFt_DLClassCode_I_From = 551,
    /// DL class code I valid notes
    RGLFieldTypeFt_DLClassCode_I_Notes = 552,
    /// DL class code I valid to
    RGLFieldTypeFt_DLClassCode_I_To = 553,
    /// DL class code K valid from
    RGLFieldTypeFt_DLClassCode_K_From = 554,
    /// DL class code K valid notes
    RGLFieldTypeFt_DLClassCode_K_Notes = 555,
    /// DL class code K valid to
    RGLFieldTypeFt_DLClassCode_K_To = 556,
    /// DL class code LK valid from
    RGLFieldTypeFt_DLClassCode_LK_From = 557,
    /// DL class code LK valid notes
    RGLFieldTypeFt_DLClassCode_LK_Notes = 558,
    /// DL class code LK valid to
    RGLFieldTypeFt_DLClassCode_LK_To = 559,
    /// DL class code N valid from
    RGLFieldTypeFt_DLClassCode_N_From = 560,
    /// DL class code N valid notes
    RGLFieldTypeFt_DLClassCode_N_Notes = 561,
    /// DL class code N valid to
    RGLFieldTypeFt_DLClassCode_N_To = 562,
    /// DL class code S valid from
    RGLFieldTypeFt_DLClassCode_S_From = 563,
    /// DL class code S valid notes
    RGLFieldTypeFt_DLClassCode_S_Notes = 564,
    /// DL class code S valid to
    RGLFieldTypeFt_DLClassCode_S_To = 565,
    /// DL class code TB valid from
    RGLFieldTypeFt_DLClassCode_TB_From = 566,
    /// DL class code TB valid notes
    RGLFieldTypeFt_DLClassCode_TB_Notes = 567,
    /// DL class code TB valid to
    RGLFieldTypeFt_DLClassCode_TB_To = 568,
    /// DL class code TM valid from
    RGLFieldTypeFt_DLClassCode_TM_From = 569,
    /// DL class code TM valid notes
    RGLFieldTypeFt_DLClassCode_TM_Notes = 570,
    /// DL class code TM valid to
    RGLFieldTypeFt_DLClassCode_TM_To = 571,
    /// DL class code TR valid from
    RGLFieldTypeFt_DLClassCode_TR_From = 572,
    /// DL class code TR valid notes
    RGLFieldTypeFt_DLClassCode_TR_Notes = 573,
    /// DL class code TR valid to
    RGLFieldTypeFt_DLClassCode_TR_To = 574,
    /// DL class code TV valid from
    RGLFieldTypeFt_DLClassCode_TV_From = 575,
    /// DL class code TV valid notes
    RGLFieldTypeFt_DLClassCode_TV_Notes = 576,
    /// DL class code TV valid to
    RGLFieldTypeFt_DLClassCode_TV_To = 577,
    /// DL class code V valid from
    RGLFieldTypeFt_DLClassCode_V_From = 578,
    /// DL class code V valid notes
    RGLFieldTypeFt_DLClassCode_V_Notes = 579,
    /// DL class code V valid to
    RGLFieldTypeFt_DLClassCode_V_To = 580,
    /// DL class code W valid from
    RGLFieldTypeFt_DLClassCode_W_From = 581,
    /// DL class code W valid notes
    RGLFieldTypeFt_DLClassCode_W_Notes = 582,
    /// DL class code W valid to
    RGLFieldTypeFt_DLClassCode_W_To = 583,
    /// Uniform Resource Locator
    RGLFieldTypeFt_URL = 584,
    /// Caliber
    RGLFieldTypeFt_Caliber = 585,
    /// Model
    RGLFieldTypeFt_Model = 586,
    /// Make
    RGLFieldTypeFt_Make = 587,
    /// Number of cylinders
    RGLFieldTypeFt_NumberOfCylinders = 588,
    /// Surname of husband after registration
    RGLFieldTypeFt_SurnameOfHusbandAfterRegistration = 589,
    /// Surname of wife after registration
    RGLFieldTypeFt_SurnameOfWifeAfterRegistration = 590,
    /// Wife's date of birth
    RGLFieldTypeFt_DateOfBirthOfWife = 591,
    /// Husband's date of birth
    RGLFieldTypeFt_DateOfBirthOfHusband = 592,
    /// Citizenship of the first person
    RGLFieldTypeFt_CitizenshipOfFirstPerson = 593,
    /// Citizenship of the second person
    RGLFieldTypeFt_CitizenshipOfSecondPerson = 594,
    /// Card Security Code
    RGLFieldTypeFt_CVV = 595,
    /// Date of insurance expiry
    RGLFieldTypeFt_Date_of_Insurance_Expiry = 596,
    /// Mortgage by
    RGLFieldTypeFt_Mortgage_by = 597,
    /// Old document number
    RGLFieldTypeFt_Old_Document_Number = 598,
    /// Old date of issue
    RGLFieldTypeFt_Old_Date_of_Issue = 599,
    /// Old place of issue
    RGLFieldTypeFt_Old_Place_of_Issue = 600,
    /// DL category LR valid from
    RGLFieldTypeFt_DLClassCode_LR_From = 601,
    /// DL category LR valid to
    RGLFieldTypeFt_DLClassCode_LR_To = 602,
    /// DL category LR valid notes
    RGLFieldTypeFt_DLClassCode_LR_Notes = 603,
    /// DL category MR valid from
    RGLFieldTypeFt_DLClassCode_MR_From = 604,
    /// DL category MR valid to
    RGLFieldTypeFt_DLClassCode_MR_To = 605,
    /// DL category MR valid notes
    RGLFieldTypeFt_DLClassCode_MR_Notes = 606,
    /// DL category HR valid from
    RGLFieldTypeFt_DLClassCode_HR_From = 607,
    /// DL category HR valid to
    RGLFieldTypeFt_DLClassCode_HR_To = 608,
    /// DL category HR valid notes
    RGLFieldTypeFt_DLClassCode_HR_Notes = 609,
    /// DL category HC valid from
    RGLFieldTypeFt_DLClassCode_HC_From = 610,
    /// DL category HC valid to
    RGLFieldTypeFt_DLClassCode_HC_To = 611,
    /// DL category HC valid notes
    RGLFieldTypeFt_DLClassCode_HC_Notes = 612,
    /// DL category MC valid from
    RGLFieldTypeFt_DLClassCode_MC_From = 613,
    /// DL category MC valid to
    RGLFieldTypeFt_DLClassCode_MC_To = 614,
    /// DL category MC valid notes
    RGLFieldTypeFt_DLClassCode_MC_Notes = 615,
    /// DL category RE valid from
    RGLFieldTypeFt_DLClassCode_RE_From = 616,
    /// DL category RE valid to
    RGLFieldTypeFt_DLClassCode_RE_To = 617,
    /// DL category RE valid notes
    RGLFieldTypeFt_DLClassCode_RE_Notes = 618,
    /// DL category R valid from
    RGLFieldTypeFt_DLClassCode_R_From = 619,
    /// DL category R valid to
    RGLFieldTypeFt_DLClassCode_R_To = 620,
    /// DL category R valid notes
    RGLFieldTypeFt_DLClassCode_R_Notes = 621,
    /// DL category CA valid from
    RGLFieldTypeFt_DLClassCode_CA_From = 622,
    /// DL category CA valid to
    RGLFieldTypeFt_DLClassCode_CA_To = 623,
    /// DL category CA valid notes
    RGLFieldTypeFt_DLClassCode_CA_Notes = 624,
    /// Citizenship status
    RGLFieldTypeFt_Citizenship_Status = 625,
    /// Start date of military service
    RGLFieldTypeFt_Military_Service_From = 626,
    /// End date of military service
    RGLFieldTypeFt_Military_Service_To = 627,
    /// DL category NT valid notes
    RGLFieldTypeFt_DLClassCode_NT_From = 628,
    /// DL category NT valid to
    RGLFieldTypeFt_DLClassCode_NT_To = 629,
    /// DL category NT valid notes
    RGLFieldTypeFt_DLClassCode_NT_Notes = 630,
    /// DL category TN valid from
    RGLFieldTypeFt_DLClassCode_TN_From = 631,
    /// DL category TN valid to
    RGLFieldTypeFt_DLClassCode_TN_To = 632,
    /// DL category TN valid notes
    RGLFieldTypeFt_DLClassCode_TN_Notes = 633,
    /// DL category D3 valid from
    RGLFieldTypeFt_DLClassCode_D3_From = 634,
    /// DL category D3 valid to
    RGLFieldTypeFt_DLClassCode_D3_To = 635,
    /// DL category D3 valid notes
    RGLFieldTypeFt_DLClassCode_D3_Notes = 636,
    /// Alternative date of expiry
    RGLFieldTypeFt_Alt_Date_Of_Expiry = 637,
    /// DL category CD valid from
    RGLFieldTypeFt_DLClassCode_CD_From = 638,
    /// DL category CD valid to
    RGLFieldTypeFt_DLClassCode_CD_To = 639,
    /// DL category CD valid notes
    RGLFieldTypeFt_DLClassCode_CD_Notes = 640,
    /// End date of payment period
    RGLFieldTypeFt_Payment_Period_To = 643,
    /// Start date of payment period
    RGLFieldTypeFt_Payment_Period_From = 642,
    /// Issuer identification number (IIN)
    RGLFieldTypeFt_Issuer_Identification_Number = 641,
    /// Vaccination certificate identifier
    RGLFieldTypeFt_VaccinationCertificateIdentifier = 644,
    /// First name
    RGLFieldTypeFt_First_Name = 645,
    /// Date of arrival
    RGLFieldTypeFt_Date_of_Arrival = 646,
    /// Second name
    RGLFieldTypeFt_Second_Name = 647,
    /// Third name
    RGLFieldTypeFt_Third_Name = 648,
    /// Fourth name
    RGLFieldTypeFt_Fourth_Name = 649,
    /// Last name
    RGLFieldTypeFt_Last_Name = 650
} NS_SWIFT_NAME(FieldType);

FOUNDATION_EXPORT NSString *RGLFieldTypeGetStringValue(RGLFieldType type) CF_SWIFT_NAME(getter:FieldType.stringValue(self:));

NS_ASSUME_NONNULL_END

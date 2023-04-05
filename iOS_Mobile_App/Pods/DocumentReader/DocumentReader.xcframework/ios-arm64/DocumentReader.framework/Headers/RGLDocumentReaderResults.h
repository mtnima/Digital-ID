#import <Foundation/Foundation.h>

#import "RGLMacros.h"
#import "RGLCheckResult.h"
#import "RGLFieldType.h"

@class UIImage;

/// Enumeration contains a pool of constants that determine the type of resulting data formed during the data scanning and processing cycle and passed to the user application
typedef NS_ENUM(NSInteger, RGLResultType) {
    /**
     No result
     */
    RGLResultTypeEmpty                          =   0,
    /**
     Stores a graphic image
     */
    RGLResultTypeRawImage                       =   1,
    /**
     Represented as binary array which contains image of the image graphic file
     */
    RGLResultTypeFileImage                      =   2,
    /**
     Serves for storing text results of MRZ, document filling and bar-codes reading
     */
    RGLResultTypeMrzOCRExtended                 =   3,
    /**
     Serves for storing and passing to the user application of results of bar-codes areas search on the scanned document page and their reading in binary non-formatted code
     */
    RGLResultTypeBarCodes                       =   5,
    /**
     Serves for storing graphic results of document filling area and bar-codes reading
     */
    RGLResultTypeGraphics                       =   6,
    /**
     Serves for storing the information on document MRZ printing quality check results
     */
    RGLResultTypeMrzTestQuality                 =   7,
    /**
     Serves for storing information on candidate documents and passing it to the user application when performing the recognition of the document type
     */
    RGLResultTypeDocumentTypesCandidates        =   8,
    /**
     Contains information on one candidate document when determining the document type
     */
    RGLResultTypeChosenDocumentTypeCandidate    =   9,
    /**
     Not used. Serves for storing the full list of documents stored in the current document database and passing it to the user application
     */
    RGLResultTypeDocumentsInfoList              =  10,
    /**
     Serves for storing the results of comparing the MRZ text data, document filling area data, bar-codes data and data retrieved from RFID-chip memory and passing it to the user application
     */
    RGLResultTypeOcrLexicalAnalyze              =  15,
    /**
     Result stores a graphic image without compression
     */
    RGLResultTypeRawUncroppedImage              =  16,
    /**
     Result serves for storing text results of MRZ, document filling and bar-codes reading
     */
    RGLResultTypeVisualOCRExtended              =  17,
    /**
     Result serves for storing text results of MRZ, document filling and bar-codes reading
     */
    RGLResultTypeBarCodesTextData               =  18,
    /**
     Serves for storing graphic results of document filling area and bar-codes reading
     */
    RGLResultTypeBarCodesImageData              =  19,
    /**
     Serves for storing the result of document authenticity check using the images for different lighting schemes and passing it to the user application
     */
    RGLResultTypeAuthenticity                   =  20,
    /**
     Not used
     */
    RGLResultTypeExpertAnalyze                  =  21,
    /**
     Not used
     */
    RGLResultTypeOcrLexicalAnalyzeEx            =  22,
    /**
     Stores a graphic image in without compression and passing it to the user application
     */
    RGLResultTypeEosImage                       =  23,
    /**
     Stores a graphic image in without compression and passing it to the user application
     */
    RGLResultTypeBayer                          =  24,
    /**
     Represented as binary array which contains array if data erade from magnetic stripe
     */
    RGLResultTypeMagneticStripe                 =  25,
    /**
     Serves for storing text results of MRZ, document filling and bar-codes reading
     */
    RGLResultTypeMagneticStripeTextData         =  26,
    /**
     Represented as binary array which contains image of the graphic field image graphic file
     */
    RGLResultTypeFieldFileImage                 =  27,
    /**
     Serves for storing the result of documents database check
     */
    RGLResultTypeDatabaseCheck                  =  28,
    /**
     Represented as binary array which contains ISO fingerprint template
     */
    RGLResultTypeFingerprintTemplateISO         =  29,
    /**
     Used for storing input image quality check results list
     */
    RGLResultTypeInputImageQuality              =  30,

    /// Stores information about operations status
    RGLResultTypeStatus                         =  33,
    /**
     Used for storing text results list
     */
    RGLResultTypeText                           =  36,
    /**
     Used for storing images results list
     */
    RGLResultTypeImages                         =  37,
    /**
     Serves to store RFID session as binary data
     */
    RGLResultTypeRFIDSession                    = 48,
    /**
     Serves to store the encrypted data object
     */
    RGLResultTypeEncryptedRCL                   = 49,
    /**
     Serves to store the encrypted license key
     */
    RGLResultTypeLicense                        = 50,
    /**
     Used for storing MRZ position
     */
    RGLResultTypeMrzPosition                    =  61,
    /**
     Used for storing barcode position
     */
    RGLResultTypeBarcodePosition                =  62,
    /**
     Used for storing document position
     */
    RGLResultTypeDocumentPosition               =  85,
    /**
     Not used
     */
    RGLResultTypeCustom                         = 100,
    /**
     Servers for storing the data reading results from the RFID-chip in a form of a list of the logically separated data groups
     */
    RGLResultTypeRfidRawData                    = 101,
    /**
     Servers for storing the results of data reading from the RFID-chip in a form of a list of logically separated text data (text fields)
     */
    RGLResultTypeRfidTextData                   = 102,
    /**
     Servers for storing the results of data reading from the RFID- chip in a form of a list of logically separated graphic data (images, graphic fields)
     */
    RGLResultTypeRfidImageData                  = 103,
    /**
     Servers for storing the data reading results from the RFID-chip in a form of a list of the logically separated data groups
     */
    RGLResultTypeRfidBinaryData                 = 104,
    /**
     Servers for storing the results of data reading in a form of a list of objects of the original binary representation of the graphics in memory of the RFID-chip
     */
    RGLResultTypeRfidOriginalGraphics           = 105
} NS_SWIFT_NAME(ResultType);

/// Enumeration contains identifiers that determine the verification and comparison of text fields
typedef NS_ENUM(NSInteger, RGLFieldVerificationResult) {
    /**
     Comparison was not done, result undefined
     */
    RGLFieldVerificationResultDisabled          =   0,
    /**
     Verification passed
     */
    RGLFieldVerificationResultVerified          =   1,
    /**
     Verification failed
     */
    RGLFieldVerificationResultNotVerified       =   2,
    /**
     Positive comparison result
     */
    RGLFieldVerificationResultCompareTrue       =   3,
    /**
     Negative comparison result
     */
    RGLFieldVerificationResultCompareFalse      =   4
} NS_SWIFT_NAME(FieldVerificationResult);

/// Enumeration contains identifiers that determine the possibility of performing different authenticity control procedures using images for definite lighting schemes
typedef NS_ENUM(NSInteger, RGLAuthenticity) {
    /// No authenticity control procedure provided for this document.
    RGLAuthenticityNone                           =   0,
    /// Document material UV fluorescence control (check for presence of UV dull paper) is provided for this document.
    RGLAuthenticityUvLuminescence                 =   1,
    /// Control of MRZ contrast using the image for IR lighting scheme is provided for this document.
    RGLAuthenticityIRB900                         =   2,
    /// Control of the presence of an image pattern with a specified color, shape and brightness on a document page under white, UV and IR light.
    RGLAuthenticityImagePattern                   =   4,
    /// UV fluorescence of protection fibers control is provided for this document.
    RGLAuthenticityAxialProtection                =   8,
    /// Blank elements visibility control using the images for IR lighting scheme is provided for this document.
    RGLAuthenticityUVFibers                       =   16,
    /// Authenticity control using the images for white coaxial light scheme is provided for this document.
    RGLAuthenticityIRVisibility                   =   32,
    /// Make OCR for the text field in UV and compare it with other text sources.
    RGLAuthenticityOCRSecurityText                =   64,
    /// Find invisible personal information images.
    RGLAuthenticityIpi                            =   128,
    /// Check photo is printed or sticked.
    RGLAuthenticityPhotoEmbedType                 =   512,
    /// Reserved for internal use.
    RGLAuthenticityHolograms                      =   4096,
    /// Reserved for internal use.
    RGLAuthenticityPhotoArea                      =   8192,
    /// Portrait comparison.
    RGLAuthenticityPortraitComparison             =   32768,
    /// Barcode format check.
    RGLAuthenticityBarcodeFormatCheck             =   65536,
    /// Kinegram.
    RGLAuthenticityKinegram                       =   131027,
    /// Reserved for internal use.
    RGLAuthenticityHologramsDetection             =   524288,
    /// Checks the correctness of the size of the MRZ lines, their relative position, absence of signs that the image was edited
    RGLAuthenticityMRZ                            =   8388608,
} NS_SWIFT_NAME(Authenticity);

/// Enumeration contains identifiers that determine the types of elements for the document authenticity check
typedef NS_ENUM(NSInteger, RGLSecurityFeatureType) {
    RGLSecurityFeatureTypeNone                               =   -1,
    /**
     Blank element
     */
    RGLSecurityFeatureTypeBlank                              =   0,
    /**
     Personalization element
     */
    RGLSecurityFeatureTypeFill                               =   1,
    /**
     Photo
     */
    RGLSecurityFeatureTypePhoto                              =   2,
    /**
     MRZ
     */
    RGLSecurityFeatureTypeMrz                                =   3,
    /**
     Photo surrounding area
     */
    RGLSecurityFeatureTypeFalseLuminescence                  =   4,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypeHoloSimple                         =   5,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypeHoloVerifyStatic                   =   6,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypeHoloVerifyMultiStatic              =   7,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypeHoloVerifyDinamic                  =   8,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypePatternNotInterrupted              =   9,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypePatternNotShifted                  =  10,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypePatternSameColors                  =  11,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypePatternIRInvisible                 =  12,
    /**
     Reserved for internal use
     */
    RGLSecurityFeatureTypePhotoSizeCheck                     =  13,
    /**
     Main portrait and ghost portrait comparison
     */
    RGLSecurityFeatureTypePortraitComparisonVsGhost          =  14,
    /**
     Main portrait and RFID portrait comparison
     */
    RGLSecurityFeatureTypePortraitComparisonVsRFID           =  15,
    /**
     Main portrait and other page portrait comparison
     */
    RGLSecurityFeatureTypePortraitComparisonVsVisual         =  16,
    /**
     Barcode format check
     */
    RGLSecurityFeatureTypeBarcode                            =  17,
    /**
     Different lines thickness
     */
    RGLSecurityFeatureTypePatternDifferentLinesThickness     =  18,
    /**
     Portrait comparison with image from camera
     */
    RGLSecurityFeatureTypePortraitComparisonVsCamera         =  19,
    /**
     Portrait comparison with image from RFID
     */
    RGLSecurityFeatureTypePortraitComparisonRFIDvsCamera     =  20,
    /**
     Ghost photo
     */
    RGLSecurityFeatureTypeGhostPhoto                         =  21,
    /**
     Clear ghost photo
     */
    RGLSecurityFeatureTypeClearGhostPhoto                    =  22,
    /**
     Invisible object
     */
    RGLSecurityFeatureTypeInvisibleObject                    =  23,
    /**
     Low contrast object
     */
    RGLSecurityFeatureTypeLowContrastObject                  =  24,
    /**
     Photo color type
     */
    RGLSecurityFeatureTypePhotoColor                         =  25,
    /**
     Photo squareness check
     */
    RGLSecurityFeatureTypePhotoShape                         =  26,
    /**
     Photo corners shape
     */
    RGLSecurityFeatureTypePhotoCorners                       =  27,
    /**
     Document canceled
     */
    RGLSecurityFeatureTypeDocumentCancellingDetector         =  28
} NS_SWIFT_NAME(SecurityFeatureType);

/// Enumeration contains a language ID that identifies a particular language
typedef NS_ENUM(NSInteger, RGLLCID) {
  RGLLCIDLatin = 0,
  RGLLCIDAbkhazianCyrillic = 10011,
  RGLLCIDAfrikaans = 1078,
  RGLLCIDAlbanian = 1052,
  RGLLCIDAmharic = 1118,
  RGLLCIDArabicAlgeria = 5121,
  RGLLCIDArabicBahrain = 15361,
  RGLLCIDArabicEgypt = 3073,
  RGLLCIDArabicIraq = 2049,
  RGLLCIDArabicJordan = 11265,
  RGLLCIDArabicKuwait = 13313,
  RGLLCIDArabicLebanon = 12289,
  RGLLCIDArabicLibya = 4097,
  RGLLCIDArabicMorocco = 6145,
  RGLLCIDArabicOman = 8193,
  RGLLCIDArabicQatar = 16385,
  RGLLCIDArabicSaudiArabia = 1025,
  RGLLCIDArabicSyria = 10241,
  RGLLCIDArabicTunisia = 7169,
  RGLLCIDArabicUAE = 14337,
  RGLLCIDArabicYemen = 9217,
  RGLLCIDArabicArmenian = 1067,
  RGLLCIDArabicWorld = 4096,
  RGLLCIDAzeriCyrillic = 2092,
  RGLLCIDAzeriLatin = 1068,
  RGLLCIDBasque = 1069,
  RGLLCIDBankCard = 10003,
  RGLLCIDBankCardCVV2 = 10004,
  RGLLCIDBankCardName = 10002,
  RGLLCIDBankCardNumber = 10000,
  RGLLCIDBankCardValidThru = 10001,
  RGLLCIDBelarusian = 1059,
  RGLLCIDBengali = 2117,
  RGLLCIDBulgarian = 1026,
  RGLLCIDCatalan = 1027,
  RGLLCIDChineseHongKongSAR = 3076,
  RGLLCIDChineseMacaoSAR = 5124,
  RGLLCIDChinese = 2052,
  RGLLCIDChineseSingapore = 4100,
  RGLLCIDChineseTaiwan = 1028,
  RGLLCIDCroatian = 1050,
  RGLLCIDCzech = 1029,
  RGLLCIDDanish = 1030,
  RGLLCIDDivehi = 1125,
  RGLLCIDDutchBelgium = 2067,
  RGLLCIDDutchNetherlands = 1043,
  RGLLCIDEnglishAustralia = 3081,
  RGLLCIDEnglishBelize = 10249,
  RGLLCIDEnglishCanada = 4105,
  RGLLCIDEnglishCaribbean = 9225,
  RGLLCIDEnglishIreland = 6153,
  RGLLCIDEnglishJamaica = 8201,
  RGLLCIDEnglishNewZealand = 5129,
  RGLLCIDEnglishPhilippines = 13321,
  RGLLCIDEnglishSouthAfrica = 7177,
  RGLLCIDEnglishTrinidad = 11273,
  RGLLCIDEnglishUnitedKingdom = 2057,
  RGLLCIDEnglishUnitedStates = 1033,
  RGLLCIDEnglishZimbabwe = 12297,
  RGLLCIDEstonian = 1061,
  RGLLCIDFaroese = 1080,
  RGLLCIDFarsi = 1065,
  RGLLCIDFinnish = 1035,
  RGLLCIDFrenchBelgium = 2060,
  RGLLCIDFrenchCanada = 3084,
  RGLLCIDFrenchFrance = 1036,
  RGLLCIDFrenchLuxembourg = 5132,
  RGLLCIDFrenchMonaco = 6156,
  RGLLCIDFrenchSwitzerland = 4108,
  RGLLCIDFyroMacedonian = 1071,
  RGLLCIDGalician = 1110,
  RGLLCIDGeorgian = 1079,
  RGLLCIDGermanAustria = 3079,
  RGLLCIDGermanGermany = 1031,
  RGLLCIDGermanLiechtenstein = 5127,
  RGLLCIDGermanLuxembourg = 4103,
  RGLLCIDGermanSwitzerland = 2055,
  RGLLCIDGreek = 1032,
  RGLLCIDGujarati = 1095,
  RGLLCIDHebrew = 1037,
  RGLLCIDHindiIndia = 1081,
  RGLLCIDHungarian = 1038,
  RGLLCIDIcelandic = 1039,
  RGLLCIDIndonesian = 1057,
  RGLLCIDItalianItaly = 1040,
  RGLLCIDItalianSwitzerland = 2064,
  RGLLCIDJapanese = 1041,
  RGLLCIDKashmiri = 1120,
  RGLLCIDKannada = 1099,
  RGLLCIDKazakh = 1087,
  RGLLCIDKonkani = 1111,
  RGLLCIDKorean = 1042,
  RGLLCIDKyrgyzCyrillic = 1088,
  RGLLCIDLao = 1108,
  RGLLCIDLatvian = 1062,
  RGLLCIDLithuanian = 1063,
  RGLLCIDMalayBruneiDarussalam = 2110,
  RGLLCIDMarathi = 1102,
  RGLLCIDMalayMalaysia = 1086,
  RGLLCIDMongolianCyrillic = 1104,
  RGLLCIDNorwegianBokmal = 1044,
  RGLLCIDNorwegianNynorsk = 2068,
  RGLLCIDPashto = 1123,
  RGLLCIDPolish = 1045,
  RGLLCIDPortugueseBrazil = 1046,
  RGLLCIDPortuguesePortugal = 2070,
  RGLLCIDPunjabi = 1094,
  RGLLCIDRhaetoRomanic = 1047,
  RGLLCIDRomanian = 1048,
  RGLLCIDRussian = 1049,
  RGLLCIDSanskrit = 1103,
  RGLLCIDSerbianCyrillic = 3098,
  RGLLCIDSerbianLatin = 2074,
  RGLLCIDSindhi = 2137,
  RGLLCIDSindhiIndia =  1113,
  RGLLCIDSinhala = 1115,
  RGLLCIDSlovak = 1051,
  RGLLCIDSlovenian = 1060,
  RGLLCIDSpanishArgentina = 11274,
  RGLLCIDSpanishBolivia = 16394,
  RGLLCIDSpanishChile = 13322,
  RGLLCIDSpanishColombia = 9226,
  RGLLCIDSpanishCostaRica = 5130,
  RGLLCIDSpanishDominicanRepublic = 7178,
  RGLLCIDSpanishEcuador = 12298,
  RGLLCIDSpanishElSalvador = 17418,
  RGLLCIDSpanishGuatemala = 4106,
  RGLLCIDSpanishHonduras = 18442,
  RGLLCIDSpanishInternationalSort = 3082,
  RGLLCIDSpanishMexico = 2058,
  RGLLCIDSpanishNicaragua = 19466,
  RGLLCIDSpanishPanama = 6154,
  RGLLCIDSpanishParaguay = 15370,
  RGLLCIDSpanishPeru = 10250,
  RGLLCIDSpanishPuertoRico = 20490,
  RGLLCIDSpanishTraditionalSort = 1034,
  RGLLCIDSpanishUruguay = 14346,
  RGLLCIDSpanishVenezuela = 8202,
  RGLLCIDSwahili = 1089,
  RGLLCIDSwedish = 1053,
  RGLLCIDSwedishFinland = 2077,
  RGLLCIDSyriac = 1114,
  RGLLCIDTamil = 1097,
  RGLLCIDTatar = 1092,
  RGLLCIDTelugu = 1098,
  RGLLCIDThaiThailand = 1054,
  RGLLCIDTurkish = 1055,
  RGLLCIDUkrainian = 1058,
  RGLLCIDUrdu = 1056,
  RGLLCIDUzbekCyrillic = 2115,
  RGLLCIDUzbekLatin = 1091,
  RGLLCIDVietnamese = 1066,
  RGLLCIDTajikCyrillic = 1064,
  RGLLCIDTurkmen = 1090,
  RGLLCIDCtcSimplified = 50001,
  RGLLCIDCtcTraditional = 50002,
  RGLLCIDCustom = 9999
} NS_SWIFT_NAME(LCID);

/// Enumeration contains identifiers that determine the logical type of the graphic data obtained while reading the document filling fields or barcodes
typedef NS_ENUM(NSInteger, RGLGraphicFieldType) {
    /**
     Photo of the document owner
     */
    RGLGraphicFieldTypeGf_Portrait           = 201,
    /**
     Fingerprint of the document owner
     */
    RGLGraphicFieldTypeGf_Fingerprint        = 202,
    /**
     Iris of the document owner
     */
    RGLGraphicFieldTypeGf_Eye                = 203,
    /**
     Signature of the document owner
     */
    RGLGraphicFieldTypeGf_Signature          = 204,
    /**
     Barcode image
     */
    RGLGraphicFieldTypeGf_BarCode            = 205,
    /**
     Image of the citizenship proving document
     */
    RGLGraphicFieldTypeGf_ProofOfCitizenship = 206,
    /**
     Document image
     */
    RGLGraphicFieldTypeGf_DocumentImage      = 207,
    /**
     Color dynamic area in the document
     */
    RGLGraphicFieldTypeGf_ColorDynamic       = 209,
    /**
     Ghost portrait
     */
    RGLGraphicFieldTypeGf_GhostPortrait      = 210,
    /**
     Stamp
     */
    RGLGraphicFieldTypeGf_Stamp              = 211,
    /**
     Portrait of child
     */
    RGLGraphicFieldTypeGf_Portrait_Of_Child  = 212,
    /**
     Other image type
     */
    RGLGraphicFieldTypeGf_Other              = 250,
    /**
     Fingerprint, left thumb
     */
    RGLGraphicFieldTypeGf_FingerLeftThumb    = 300,
    /**
     Fingerprint, left index
     */
    RGLGraphicFieldTypeGf_FingerLeftIndex    = 301,
    /**
     Fingerprint, left middle
     */
    RGLGraphicFieldTypeGf_FingerLeftMiddle   = 302,
    /**
     Fingerprint, left ring
     */
    RGLGraphicFieldTypeGf_FingerLeftRing     = 303,
    /**
     Fingerprint, left little
     */
    RGLGraphicFieldTypeGf_FingerLeftLittle   = 304,
    /**
     Fingerprint, right thumb
     */
    RGLGraphicFieldTypeGf_FingerRightThumb   = 305,
    /**
     Fingerprint, right index
     */
    RGLGraphicFieldTypeGf_FingerRightIndex   = 306,
    /**
     Fingerprint, right middle
     */
    RGLGraphicFieldTypeGf_FingerRightMiddle  = 307,
    /**
     Fingerprint, right ring
     */
    RGLGraphicFieldTypeGf_FingerRightRing    = 308,
    /**
     Fingerprint, right little
     */
    RGLGraphicFieldTypeGf_FingerRightLittle  = 309
} NS_SWIFT_NAME(GraphicFieldType);

/// Enumeration contains a set of identifiers used for identifying the document reader possibilities, specifying lighting schemes for scanning, etc.
typedef NS_ENUM(NSInteger, RGLGraphicFieldLight) {
    /**
     Light off
    */
    RGLGraphicFieldLightOff              = 0,
    /**
     General white light scheme
     */
    RGLGraphicFieldLightWhite            = 6,
    /**
     General infrared light scheme
     */
    RGLGraphicFieldLightInfrared         = 24,
    /**
     General UV light scheme
     */
    RGLGraphicFieldLightUV               = 128,
    /**
     OVD light for hologram visualization
     */
    RGLGraphicFieldLightOVD              = 67108864,
} NS_SWIFT_NAME(GraphicFieldLight);

/// Enumeration contains identificators that determine the result of the text field comparison from different sources
typedef NS_ENUM(NSInteger, RGLCheckDiagnose) {
    /**
     Check was not performed
     */
    RGLCheckDiagnoseUnknown = 0,
    /**
     Check was ok
     */
    RGLCheckDiagnosePass = 1,
    /**
     Invalid input data
     */
    RGLCheckDiagnoseInvalidInputData = 2,
    /**
     Internal error in module
     */
    RGLCheckDiagnoseInternalError = 3,
    /**
     Exception caught
     */
    RGLCheckDiagnoseExceptionInModule = 4,
    /**
     Can't make reliable decision
     */
    RGLCheckDiagnoseUncertainVerification = 5,
    /**
     Image in necessary light is not found
     */
    RGLCheckDiagnoseNecessaryImageNotFound = 7,
    /**
     Necessary side of photo not found
     */
    RGLCheckDiagnosePhotoSidesNotFound = 8,
    /**
     Invalid checksum
     */
    RGLCheckDiagnoseInvalidChecksum = 10,
    /**
     Syntactical error
     */
    RGLCheckDiagnoseSyntaxError = 11,
    /**
     Logical error
     */
    RGLCheckDiagnoseLogicError = 12,
    /**
     Comparison was incorrect
     */
    RGLCheckDiagnoseSourcesComparisonError = 13,
    /**
     Logical error, e.g. the current date is less than issue date
     */
    RGLCheckDiagnoseFieldsComparisonLogicError = 14,
    /**
     Wrong field format
     */
    RGLCheckDiagnoseInvalidFieldFormat = 15,
    /**
     Element of the luminescense in the UV does not meet the standard
     */
    RGLCheckDiagnoseTrueLuminiscenceError = 20,
    /**
     The presence of excess luminescence in UV
     */
    RGLCheckDiagnoseFalseLuminiscenceError = 21,
    /**
     Pattern does not match the standard
     */
    RGLCheckDiagnoseFixedPatternError = 22,
    /**
     Low contrast of object in transmitted IR light
     */
    RGLCheckDiagnoseLowContrastInIRLight = 23,
    /**
     Background of page is too light or has invalid color
     */
    RGLCheckDiagnoseIncorrectBackgroundLight = 24,
    /**
     Background lightness of two pages is different
     */
    RGLCheckDiagnoseBackgroundComparisonError = 25,
    /**
     Text has incorrect color of luminescence in UV light
     */
    RGLCheckDiagnoseIncorrectTextColor = 26,
    /**
     Invalid luminescence in photo area
     */
    RGLCheckDiagnosePhotoFalseLuminiscence = 27,
    /**
     Object is too shifted from standard coordinates
     */
    RGLCheckDiagnoseTooMuchShift = 28,
    /**
     No protective fibers were found in UV
     */
    RGLCheckDiagnoseFibersNotFound = 30,
    /**
    Error finding fibers, too many objects
     */
    RGLCheckDiagnoseTooManyObjects = 31,
    /**
     Speck or exposure in UV image
     */
    RGLCheckDiagnoseSpecksInUV = 33,
    /**
     Resolution too low for fibers search
     */
    RGLCheckDiagnoseTooLowResolution = 34,
    /**
     Erroneous visibility of the element in IR
     */
    RGLCheckDiagnoseInvisibleElementPresent = 40,
    /**
     Element is absent in IR
     */
    RGLCheckDiagnoseVisibleElementAbsent = 41,
    /**
     Element should be in color
     */
    RGLCheckDiagnoseElementShouldBeColored = 42,
    /**
     Element should be in grayscale
     */
    RGLCheckDiagnoseElementShouldBeGrayscale = 43,
    RGLCheckDiagnosePhotoWhiteIRDontMatch = 44,
    /**
     Glow paper in MRZ
     */
    RGLCheckDiagnoseUVDullPaper_MRZ = 50,
    /**
     Luminescence characters in MRZ
     */
    RGLCheckDiagnoseFalseLuminiscenceInMRZ = 51,
    /**
     Glow in the field of photo paper
     */
    RGLCheckDiagnoseUVDullPaper_Photo = 52,
    /**
     Glow of the whole paper form
     */
    RGLCheckDiagnoseUVDullPaper_Blank = 53,
    /**
     Glow of the document in UV
     */
    RGLCheckDiagnoseUVDullPaperError = 54,
    /**
     Element of blank has luminescence
     */
    RGLCheckDiagnoseFalseLuminiscenceInBlank = 55,
    /**
     Violation of the retro-reflective protection
     */
    RGLCheckDiagnoseBadAreaInAxial = 60,
    /**
     Invalid params for IPI check
     */
    RGLCheckDiagnoseFalseIPIParameters = 65,
    /**
     IR image too bright
     */
    RGLCheckDiagnoseFieldPosCorrector_Highlight_IR = 80,
    /**
     Glares in photo area
     */
    RGLCheckDiagnoseFieldPosCorrector_GlaresInPhotoArea = 81,
    /**
     * Photo replaced
     */
    RGLCheckDiagnoseFieldPosCorrector_PhotoReplaced = 82,
    /**
     OVI object is not visible in IR
     */
    RGLCheckDiagnoseOVIIRInvisible = 90,
    /**
     Insufficient area of the object OVI
     */
    RGLCheckDiagnoseOVIInsufficientArea = 91,
    /**
     OVI color of an object does not change
     */
    RGLCheckDiagnoseOVIColorInvariable = 92,
    /**
     Impossible to determine the color of the AXIAL image
     */
    RGLCheckDiagnoseOVIBadColorFront = 93,
    /**
     Impossible to determine the color of the WHITE image
     */
    RGLCheckDiagnoseOVIBadColorSide = 94,
    /**
     Wide color spread
     */
    RGLCheckDiagnoseOVIWideColorSpread = 95,
    /**
     Not enough color information
     */
    RGLCheckDiagnoseOVIBadColorPercent = 96,
    /**
     Hologram element absent
     */
    RGLCheckDiagnoseHologramElementAbsent = 100,
    /**
     There are no side or top images. Check cancelled
     */
    RGLCheckDiagnoseHologramSideTopImagesAbsent = 101,
    /**
     Hologram element present
     */
    RGLCheckDiagnoseHologramElementPresent = 102,
    RGLCheckDiagnoseHologramFramesIsAbsent = 103,
    RGLCheckDiagnoseHologramHoloFieldIsAbsent = 104,
    /**
     Pattern is interrupted
     */
    RGLCheckDiagnosePhotoPatternInterrupted = 110,
    /**
     Some of the patterns are shifted relative to each other
     */
    RGLCheckDiagnosePhotoPatternShifted = 111,
    /**
     Some parts of the pattern have different color
     */
    RGLCheckDiagnosePhotoPatternDifferentColors = 112,
    /**
     Pattern visible in the infrared
     */
    RGLCheckDiagnosePhotoPatternIRVisible = 113,
    /**
     Edge of the photo does not intersect with the pattern. Check cancelled
     */
    RGLCheckDiagnosePhotoPatternNotIntersect = 114,
    /**
     Size of the photo does not correspond to requirements
     */
    RGLCheckDiagnosePhotoSizeIsWrong = 115,
    /**
     Some parts of the pattern have invalid color
     */
    RGLCheckDiagnosePhotoPatternInvalidColor = 116,
    /**
     Some patterns are relatively shifted
     */
    RGLCheckDiagnosePhotoPatternShiftedVert = 117,
    /**
     Not found Pattern. Check cancelled
     */
    RGLCheckDiagnosePhotoPatternPatternNotFound = 118,
    /**
     Different lines thickness
     */
    RGLCheckDiagnosePhotoPatternDifferentLinesThickness = 119,
    /**
     Photo shape is not rectangular
     */
    RGLCheckDiagnosePhotoIsNotRectangle = 120,
    /**
     Photo corners don't meet the requirements
     */
    RGLCheckDiagnosePhotoCornersIsWrong = 121,
    /**
     For internal use only
     */
    RGLCheckDiagnoseDocumentIsCancelling = 122,
    /**
     Text color should be blue
     */
    RGLCheckDiagnoseTextColorShouldBeBlue = 130,
    /**
     Text color should be green
     */
    RGLCheckDiagnoseTextColorShouldBeGreen = 131,
    /**
     Text color should be red
     */
    RGLCheckDiagnoseTextColorShouldBeRed = 132,
    /**
     Text should be black
     */
    RGLCheckDiagnoseTextShouldBeBlack = 133,
    /**
     Barcode read with errors
     */
    RGLCheckDiagnoseBarcodeWasReadWithErrors = 140,
    /**
     Barcode data format error
     */
    RGLCheckDiagnoseBarcodeDataFormatError = 141,
    /**
     Barcode size parameters error
     */
    RGLCheckDiagnoseBarcodeSizeParamsError = 142,
    /**
     Not all barcodes read
     */
    RGLCheckDiagnoseNotAllBarcodesRead = 143,
    /**
     Portraits differ
     */
    RGLCheckDiagnosePortraitComparisonPortraitsDiffer = 150,
    /**
     No reply from portrait comparison service
     */
    RGLCheckDiagnosePortraitComparisonNoServiceReply = 151,
    /**
     Portrait comparison service error
     */
    RGLCheckDiagnosePortraitComparisonServiceError = 152,
    /**
     Not enough images
     */
    RGLCheckDiagnosePortraitComparisonNotEnoughImages = 153,
    /**
     No image from camera
     */
    RGLCheckDiagnosePortraitComparisonNoLivePhoto = 154,
    /**
     No license on portrait comparison service
     */
    RGLCheckDiagnosePortraitComparisonNoServiceLicense = 155,
    /**
     No portraits detected
     */
    RGLCheckDiagnosePortraitComparisonNoPortraitDetected = 156,
    /**
     Unsuitable light conditions
     */
    RGLCheckDiagnoseMobileImagesUnsuitableLightConditions = 160,
    /**
     No difference in visible and UV mobile images. Possible UV torch malfunction
     */
    RGLCheckDiagnoseMobileImagesWhiteUVNoDifference = 161,
    /**
     Fingerprints comparison mismatch
     */
    RGLCheckDiagnoseFingerprintsComparisonMismatch = 170,
    /**
     Face isn’t detected
     */
    RGLCheckDiagnoseHoloPhotoFaceNotDetected = 180,
    /**
     Face comparison failed
     */
    RGLCheckDiagnoseHoloPhotoFaceComparisonFailed = 181,
    /**
     Glare in center absent
     */
    RGLCheckDiagnoseHoloPhotoFaceGlareInCenterAbsent = 182,
    /**
     Hologram element shape error
     */
    RGLCheckDiagnoseHoloElementShapeError = 183,
    /**
     Algorithm steps error
     */
    RGLCheckDiagnoseAlgorithmStepsError = 184,
    /**
     Hologram areas not loaded
     */
    RGLCheckDiagnoseHoloAreasNotLoaded = 185,
    /**
     Hologram check finished by time out
     */
    RGLCheckDiagnoseFinishedByTimeout = 186,

    RGLCheckDiagnoseHoloPhotoDocumentOutsideFrame = 187,

    RGLCheckDiagnoseLivenessDepthCheckFailed = 190,
  
    /**
     Hologram check finished by time out
     */
    RGLCheckDiagnoseMRZQualityWrongDPI = 200,
    /**
     * Wrong background
     */
    RGLCheckDiagnoseMRZQualityWrongBackground = 201,
    /**
     For internal use
     */
    RGLCheckDiagnoseLastDiagnoseValue = 210,
} NS_SWIFT_NAME(CheckDiagnose);

/// Enumeration contains identifiers that determine the processing finish status
typedef NS_ENUM(NSInteger, RGLProcessingFinishedStatus) {
    /**
     Processing is not finished
     */
    RGLProcessingFinishedStatusNotReady           = 0,
    /**
     Processing is finished
     */
    RGLProcessingFinishedStatusReady              = 1,
    /**
     Processing is finished by timeout
     */
    RGLProcessingFinishedStatusTimeout            = 2
} NS_SWIFT_NAME(ProcessingFinishedStatus);

@class RGLDocumentReaderDocumentType;
@class RGLDocumentReaderTextResult;
@class RGLDocumentReaderGraphicResult;
@class RGLDocumentPosition;
@class RGLBarcodePosition;
@class RGLMrzPosition;
@class RGLImageQualityGroup;
@class RGLDocumentReaderAuthenticityResult;
@class RGLRFIDSessionData;
@class RGLDocumentReaderTextField;
@class RGLDocumentReaderGraphicField;
@class RGLDocumentReaderBarcodeResult;
@class RGLVDSNCData;
@class RGLDocumentReaderResultsStatus;

NS_SWIFT_NAME(DocumentReaderResults)
@interface RGLDocumentReaderResults : NSObject

/// Document type results
@property(nonatomic, strong, readonly, nullable) NSArray <RGLDocumentReaderDocumentType *> *documentType;

/// Textual results
@property(nonatomic, strong, readonly, nonnull) RGLDocumentReaderTextResult *textResult;

/// Graphic results
@property(nonatomic, strong, readonly, nonnull) RGLDocumentReaderGraphicResult *graphicResult;

/// Position of a document
@property(nonatomic, strong, readonly, nullable) NSArray <RGLDocumentPosition *> *documentPosition;

/// Position of a barcode
@property(nonatomic, strong, readonly, nullable) NSArray <RGLBarcodePosition *> *barcodePosition;

/// Position of MRZ
@property(nonatomic, strong, readonly, nullable) NSArray <RGLMrzPosition *> *mrzPosition;

/// Image quality results
@property(nonatomic, strong, readonly, nullable) NSArray <RGLImageQualityGroup *> *imageQualityGroup;

/// Overall check result based on checks of textual, authenticity and RFID results, one of RGLCheckResult values.
@property(nonatomic, assign, readonly) RGLCheckResult overallResult RGL_DEPRECATED(6.1, "Use `status.overallStatus` instead.");

/// Status information for each operation.
@property(nonatomic, strong, readonly, nonnull) RGLDocumentReaderResultsStatus *status;

/// Authenticity results
@property(nonatomic, strong, readonly, nullable) RGLDocumentReaderAuthenticityResult *authenticityResults;

/// RFID session data
@property(nonatomic, strong, readonly, nullable) RGLRFIDSessionData *rfidSessionData;

/// Indicates which page of the document contains an RFID chip (0 if there's no page containing it).
/// Requires document type recognition, otherwise 1 by default
@property(nonatomic, assign, readonly) NSInteger chipPage;

/// Barcode results
@property(nonatomic, strong, readonly, nonnull) RGLDocumentReaderBarcodeResult *barcodeResult;

/// Visible Digital Seal data.
@property(nonatomic, strong, readonly, nullable) RGLVDSNCData *vdsncData;

/// Document processing finish status, one of RGLProcessingFinishedStatus values
@property(nonatomic, assign, readonly) RGLProcessingFinishedStatus processingFinishedStatus;

/// Indicates how many pages of a document remains to process. Requires Document Type recognition, otherwise 0 by default
@property(nonatomic, assign, readonly) NSInteger morePagesAvailable;

/// Indicates how much time has been required for document processing, milliseconds
@property(nonatomic, assign, readonly) NSInteger elapsedTime;

/// Indicates how much time has been required for RFID chip processing, milliseconds
@property(nonatomic, assign, readonly) NSInteger elapsedTimeRFID;

/// Raw results, i.e. in their initial view
@property(nonatomic, strong, readonly, nonnull) NSString *rawResult;

- (nonnull instancetype)initWithDocumentTypes:(nullable NSArray<RGLDocumentReaderDocumentType *> *)documentType
                                   textResult:(nullable RGLDocumentReaderTextResult *)textResult
                                graphicResult:(nonnull RGLDocumentReaderGraphicResult *)graphicResult
                                    rawResult:(nullable NSString *)rawResult
                             documentPosition:(nullable NSArray<RGLDocumentPosition *> *)documentPosition
                              barcodePosition:(nullable NSArray<RGLBarcodePosition *> *)barcodePosition
                                  mrzPosition:(nullable NSArray<RGLMrzPosition *> *)mrzPosition
                            imageQualityGroup:(nullable NSArray<RGLImageQualityGroup *> *)imageQualityGroup
                          authenticityResults:(nullable RGLDocumentReaderAuthenticityResult *)authenticityResults
                              rfidSessionData:(nullable RGLRFIDSessionData *)rfidSessionData
                                     chipPage:(NSInteger)chipPage
                                barcodeResult:(nullable RGLDocumentReaderBarcodeResult *)barcodeResult
                                    vdsncData:(nullable RGLVDSNCData *)vdsncData
                                       status:(nonnull RGLDocumentReaderResultsStatus *)status
                           processingFinished:(NSInteger)processingFinished
                           morePagesAvailable:(NSInteger)morePagesAvailable
                                  elapsedTime:(NSInteger)elapsedTime
                              elapsedTimeRFID:(NSInteger)elapsedTimeRFID;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
- (instancetype _Nonnull)initWithRawJSON:(NSString *_Nonnull)rawString;
- (nonnull NSDictionary *)jsonDictionary;
- (BOOL)isResultsEmpty;

/**
 Allows you to get a value of a text field based on LCID, a source type and its originality
 @param fieldType Field type, one of RGLFieldType values
 @param lcid LCID, one of RGLLCID values
 @param source Source type, one of RGLResultType values
 @param original Originality
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType lcid:(RGLLCID)lcid source:(RGLResultType)source original:(BOOL)original NS_SWIFT_NAME(getTextFieldValueByType(fieldType:lcid:source:original:));
/**
 Allows you to get a value of a text field based on LCID and a source type
 @param fieldType Field type, one of RGLFieldType values
 @param lcid LCID, one of RGLLCID values
 @param source Source type, one of RGLResultType values
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType lcid:(RGLLCID)lcid source:(RGLResultType)source NS_SWIFT_NAME(getTextFieldValueByType(fieldType:lcid:source:));
/**
 Allows you to get a value of a text field based on LCID
 @param fieldType Field type, one of RGLFieldType values
 @param lcid LCID, one of RGLLCID values
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType lcid:(RGLLCID)lcid NS_SWIFT_NAME(getTextFieldValueByType(fieldType:lcid:));
/**
 Allows you to get a value of a text field
 @param fieldType Field type, one of RGLFieldType values
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType NS_SWIFT_NAME(getTextFieldValueByType(fieldType:));
/**
 Allows you to get a value of a text field based on a source type
 @param fieldType Field type, one of RGLFieldType values
 @param source Source type, one of RGLResultType values
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType source:(RGLResultType)source NS_SWIFT_NAME(getTextFieldValueByType(fieldType:source:));
/**
 Allows you to get a value of a text field based on a source type and its originality
 @param fieldType Field type, one of RGLFieldType values
 @param source Source type, one of RGLResultType values
 @param original Originality
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType source:(RGLResultType)source original:(BOOL)original NS_SWIFT_NAME(getTextFieldValueByType(fieldType:source:original:));
/**
 Allows you to get a value of a text field based on its originality
 @param fieldType Field type, one of RGLFieldType values
 @param original Originality
 */
- (NSString *_Nullable)getTextFieldValueByType:(RGLFieldType)fieldType original:(BOOL)original NS_SWIFT_NAME(getTextFieldValueByType(fieldType:original:));
/**
 Allows you to get an instance of a text field
 @param fieldType Field type, one of RGLFieldType values
 */
- (RGLDocumentReaderTextField *_Nullable)getTextFieldByType:(RGLFieldType)fieldType NS_SWIFT_NAME(getTextFieldByType(fieldType:));
/**
 Allows you to get an instance of a text field based on LCID
 @param fieldType Field type, one of RGLFieldType values
 @param lcid LCID, one of RGLLCID values
 */
- (RGLDocumentReaderTextField *_Nullable)getTextFieldByType:(RGLFieldType)fieldType lcid:(RGLLCID)lcid NS_SWIFT_NAME(getTextFieldByType(fieldType:lcid:));

/**
 Allows you to get an image of a graphic field based on a source type, page index and light type
 @param fieldType Field type, one of RGLGraphicFieldType values
 @param source Source type, one of RGLResultType values
 @param pageIndex An index of the document page
 @param light Light type, one of RGLGraphicFieldLight values
 */
- (UIImage *_Nullable)getGraphicFieldImageByType:(RGLGraphicFieldType)fieldType source:(RGLResultType)source pageIndex:(NSInteger)pageIndex light:(RGLGraphicFieldLight)light NS_SWIFT_NAME(getGraphicFieldImageByType(fieldType:source:pageIndex:light:));
/**
 Allows you to get an image of a graphic field based on a source type and page index
 @param fieldType Field type, one of RGLGraphicFieldType values
 @param source Source type, one of RGLResultType values
 @param pageIndex An index of the document page
 */
- (UIImage *_Nullable)getGraphicFieldImageByType:(RGLGraphicFieldType)fieldType source:(RGLResultType)source pageIndex:(NSInteger)pageIndex NS_SWIFT_NAME(getGraphicFieldImageByType(fieldType:source:pageIndex:));
/**
 Allows you to get an image of a graphic field based on a source type and page index
 @param fieldType Field type, one of RGLGraphicFieldType values
 @param source Source type, one of RGLResultType values
 */
- (UIImage *_Nullable)getGraphicFieldImageByType:(RGLGraphicFieldType)fieldType source:(RGLResultType)source NS_SWIFT_NAME(getGraphicFieldImageByType(fieldType:source:));
/**
 Allows you to get an image of a graphic field
 @param fieldType Field type, one of RGLGraphicFieldType values
 */
- (UIImage *_Nullable)getGraphicFieldImageByType:(RGLGraphicFieldType)fieldType NS_SWIFT_NAME(getGraphicFieldImageByType(fieldType:));
/**
 Allows you to get an instance of a graphic field based on a source type, page index and light type
 @param fieldType Field type, one of RGLGraphicFieldType values
 @param source Source type, one of RGLResultType values
 @param pageIndex An index of the document page
 @param light Light type, one of RGLGraphicFieldLight values
 */
- (RGLDocumentReaderGraphicField *_Nullable)getGraphicFieldByType:(RGLGraphicFieldType)fieldType source:(RGLResultType)source pageIndex:(NSInteger)pageIndex light:(RGLGraphicFieldLight)light NS_SWIFT_NAME(getGraphicFieldByType(fieldType:source:pageIndex:light:));
/**
 Allows you to get an instance of a graphic field based on a source type and page index
 @param fieldType Field type, one of RGLGraphicFieldType values
 @param source Source type, one of RGLResultType values
 @param pageIndex An index of the document page
 */
- (RGLDocumentReaderGraphicField *_Nullable)getGraphicFieldByType:(RGLGraphicFieldType)fieldType source:(RGLResultType)source pageIndex:(NSInteger)pageIndex NS_SWIFT_NAME(getGraphicFieldByType(fieldType:source:pageIndex:));
/**
 Allows you to get an instance of a graphic field based on a source type
 @param fieldType Field type, one of RGLGraphicFieldType values
 @param source Source type, one of RGLResultType values
 */
- (RGLDocumentReaderGraphicField *_Nullable)getGraphicFieldByType:(RGLGraphicFieldType)fieldType source:(RGLResultType)source NS_SWIFT_NAME(getGraphicFieldByType(fieldType:source:));
/**
 Allows you to get an instance of a graphic field
 @param fieldType Field type, one of RGLGraphicFieldType values
 */
- (RGLDocumentReaderGraphicField *_Nullable)getGraphicFieldByType:(RGLGraphicFieldType)fieldType NS_SWIFT_NAME(getGraphicFieldByType(fieldType:));
/**
 Method returns containers by result type. If result type doesn't exist, the result of the search will be null.
 @param resultTypes array of result type specified in  `RGLResultType` raw values.
 @return get original containers from rawResult value in NSString format including information about the transaction.
 */
- (NSString *_Nullable)getContainersByResultTypes:(NSArray<NSNumber *> *_Nonnull)resultTypes NS_SWIFT_NAME(getContainers(byResultTypes:));
/**
 Method returns only containers for `RGLResultTypeRFIDSession`, `RGLResultTypeEncryptedRCL` and `RGLResultTypeLicense` values
 from `RGLResultType` enum. For more details, see `getContainersByResultTypes` method.
 @return Get all encrypted containers from rawResult to reprocess data on the server side.
 */
- (NSString *_Nullable)getEncryptedContainers NS_SWIFT_NAME(getEncryptedContainers());

+ (nonnull instancetype)initWithJSON:(nonnull NSDictionary *)json;
+ (nonnull instancetype)initWithRawString:(nonnull NSString *)rawString;

@end

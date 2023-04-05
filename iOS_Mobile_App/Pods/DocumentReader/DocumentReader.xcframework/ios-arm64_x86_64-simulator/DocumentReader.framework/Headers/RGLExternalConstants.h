#import <Foundation/Foundation.h>

/// Processing scenario for obtaining MRZ data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_MRZ;
/// Processing scenario for obtaining barcode data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_BARCODE;
/// Processing scenario for detecting document boundaries
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_LOCATE;
/// Processing scenario for obtaining visual zone OCR results
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_OCR;
/// Processing scenario for document type recognition
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_DOCTYPE;
/// Processing scenario for obtaining MRZ and/or barcode data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_MRZ_OR_BARCODE;
/// Processing scenario for detecting document boundaries and/or obtaining MRZ data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_MRZ_OR_LOCATE;
/// Processing scenario for detecting document boundaries and obtaining MRZ data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_MRZ_AND_LOCATE;
/// Processing scenario for obtaining MRZ data or visual zone OCR results
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_MRZ_OR_OCR;
/// Processing scenario for obtaining MRZ or barcode or visual zone OCR results
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_MRZ_OR_BARCODE_OR_OCR;
/// Processing scenario for detecting document boundaries and obtaining MRZ data or visual zone OCR results
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_LOCATE_VISUAL_AND_MRZ_OR_OCR;
/// Processing scenario for obtaining all document data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_FULL_PROCESS;
/// Processing scenario for obtaining all document data and document authentication
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_FULL_AUTH;
/// Processing scenario for obtaining visual zone OCR results from Russian National Passport and MRZ data from any document
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_ID3RUS;
/// Processing scenario for obtaining data from registration stamps in Russian passports
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_RUS_STAMP;
/// Processing scenario for obtaining OCR results of any image
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_OCR_FREE;
/// Processing scenario for obtaining bank card data
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_CREDIT_CARD;
/// Scenario for obtaining an original image without any processing
FOUNDATION_EXPORT NSString *const RGL_SCENARIO_CAPTURE;

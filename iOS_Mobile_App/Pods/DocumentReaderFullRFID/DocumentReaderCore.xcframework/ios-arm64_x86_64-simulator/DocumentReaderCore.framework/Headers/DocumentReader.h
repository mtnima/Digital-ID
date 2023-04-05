//
//  DocumentReader.h
//  DocumentReader
//
//  Created by Игорь Клещёв on 15.04.17.
//  Copyright © 2017 Regula Forensics. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

//! Project version number for DocumentReader.
FOUNDATION_EXPORT double DocumentReaderVersionNumber;

//! Project version string for DocumentReader.
FOUNDATION_EXPORT const unsigned char DocumentReaderVersionString[];

/// Sourced from `passpr_internal.h`. Copied `eProcessCommandsResult` and added a suffix `_`.
/// This enum represents known result codes from `process` operation.
///
/// Knowning exact values and names of enum cases makes the integration with a platform much easier.
/// The wrapper layer can return correct errors in case it is required and the platform layer may match agains exact errore code instead of
/// doing something like `code  == 5`.
typedef NS_ENUM(NSInteger, DocumentReaderErrorCode) {
    ePC_Result_OK_ = 0,                   // command executed successfully
    ePC_Result_UnsupportedCommand_ = 1,   // command not supported
    ePC_Result_BadInputData_ = 2,         // bad input data
    ePC_Result_Finished_ = 3,             // already done
    ePC_Result_CurrentlyUnavailable_ = 4, // command can not be processed at this moment, bad initial state
    ePC_Result_BadLicense_ = 5,           // license not available or for another system,
    ePC_Result_AlreadyDone_ = 6           // The command has already been executed (as an example, in the case of SetLicense)
};

/// Sourced from `passpr_internal.h`. Copied `eProcessGlCommands` and added a suffix `_`.
///
/// This enum may be used as a reference for a platform layer to implement command constants on its side.
typedef NS_ENUM(NSInteger, DocumentReaderCommand) {
    ePC_ProcMgr_SetLicense_ = 12100,                          // initialize ProcMgr
    ePC_ProcMgr_Process_ = 12101,                             // process images and return result
    ePC_ProcMgr_ProcessImage_ = 12104,                        // process image/images and return result
    ePC_ProcMgr_StartNewDocument_ = 12105,
    ePC_ProcMgr_StartNewPage_ = 12106,
    ePC_ProcMgr_Unload_ = 12107,                              // unload ProcMgr
    ePC_ProcMgr_ReadRfid_ = 12108,                            // read RFID
    ePC_ProcMgr_CheckDatabase_ = 12109,                       // check database need for update
    ePC_ProcMgr_ComparePortraits_ = 12111,                     // compare available portraits in current document
    ePC_RFID_SetTCCParams_ = 12522,
    ePC_Irs_Init_ = 3100,                                      // initialize IRS core. provide license and path to local/remote IRS DB
    ePC_Irs_Get_ = 3101,                                       // get data from IRS
    ePC_Irs_Unpack_ = 3102,                                    // unpack image data
};

typedef NS_ENUM(NSInteger, DocumentReaderLight) {
    DocumentReaderLight_OFF               = 0x00000000, // Light Off
    DocumentReaderLight_OVI               = 0x00000001, // Light for OVI
    DocumentReaderLight_White_Top         = 0x00000002, // Light White Top
    DocumentReaderLight_White_Side        = 0x00000004, // Light White Side
    DocumentReaderLight_White_Front       = 0x00800000, // Light White (single light source)
    DocumentReaderLight_IR_Top            = 0x00000008, // Light IR Top
    DocumentReaderLight_IR_Side           = 0x00000010, // Light IR Side
    DocumentReaderLight_IR_Front          = 0x01000000, // Light IR (single light source)
    DocumentReaderLight_IR_870            = 0x01000000, // Light IR 870 (mod. 8803)
    DocumentReaderLight_White_Gray        = 0x02000000, // Light GRAY (grayscale made from WHITE)
    DocumentReaderLight_OVD               = 0x04000000, // Light OVD (hologram visualization)
    
    DocumentReaderLight_UV                = 0x00000080, // Light UV
    DocumentReaderLight_IR_Luminescence   = 0x00000100, // Light Green Front
    DocumentReaderLight_AXIAL_White_Front = 0x00000200, // Light Axial (3M) White
    DocumentReaderLight_AXIAL_White_Left  = 0x00000400, // Light Axial (3M) White Left
    DocumentReaderLight_AXIAL_White_Right = 0x00000800, // Light Axial (3M) White Right
    
    DocumentReaderLight_IR_700            = 0x00001000, // Light IR 700 (mod. 8803)
    DocumentReaderLight_IR_720            = 0x00001000, // Light IR 720 (mod. 8850)
    DocumentReaderLight_IR_940            = 0x00002000, // Light IR 940 (mod. 8803, 8850)
    
    DocumentReaderLight_White_Full        = (DocumentReaderLight_White_Top | DocumentReaderLight_White_Side),
    DocumentReaderLight_IR_Full           = (DocumentReaderLight_IR_Top    | DocumentReaderLight_IR_Side),
    DocumentReaderLight_AXIAL_White_Full  = (DocumentReaderLight_AXIAL_White_Left | DocumentReaderLight_AXIAL_White_Right),
    
    DocumentReaderLight_Transmitted       = 0x00000020, // transmitted light
    DocumentReaderLight_Transmitted_IR    = 0x00000040, // transmitted IR light
    DocumentReaderLight_AntiStokes        = 0x00010000, // Anti Stokes light
};

@interface ImageResult: NSObject

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, assign) NSInteger pageIndex;
@property (nonatomic, assign) DocumentReaderLight light;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, assign) NSInteger exposure;

@end

@interface CertificateWrapper: NSObject

@property (nonatomic, strong) NSData *binaryData;
@property (nonatomic, assign) NSInteger type;
@property (nonatomic, strong) NSData *privateKey;

@end

@interface DocumentReader: NSObject

+ (DocumentReaderErrorCode)process:(DocumentReaderCommand) p_cmd
                       inputImages:(NSArray<ImageResult *> *)p_inputImages
                         inputJSON:(NSString *)p_inputJSON
                      outputImages:(NSArray * _Nonnull * _Nonnull)p_outputImages
                        outputJSON:(NSString * _Nonnull * _Nonnull)p_outputJSON;

+ (DocumentReaderErrorCode)process:(DocumentReaderCommand) p_cmd
                         inputData:(NSData *)p_inputData
                         inputJSON:(NSString *)p_inputJSON
                        outputJSON:(NSString * _Nonnull * _Nonnull)p_outputJSON;

+ (DocumentReaderErrorCode)addPKDCertificates:(NSArray *)certificates;
+ (DocumentReaderErrorCode)clearPKDCertificatesStore;

+ (void)prepareCallback:(id)pointer;
+ (void)resetCallback;

@end

@interface RegulaDocumentReaderCore: NSObject

+ (void)prepareCallback:(id)pointer;
+ (void)resetCallback;
+ (NSNumber *)processWithImage:(NSArray *)params;
+ (NSNumber *)process:(NSArray *)params;
+ (NSNumber *)addPKDCertificates:(NSArray *)certificates;
+ (NSNumber *)clearPKDCertificatesStore;

@end

NS_ASSUME_NONNULL_END

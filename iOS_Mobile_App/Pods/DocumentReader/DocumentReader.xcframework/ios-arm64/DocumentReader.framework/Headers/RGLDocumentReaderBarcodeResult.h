#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLBarcodeResult) {
    /**
     No error
     */
    RGLBarcodeResultNoErr                                 = 0,
    /**
     Null pointer of input arg/param error
     */
    RGLBarcodeResultNullPtrErr                            = -6001,
    /**
     Function arg/param is bad
     */
    RGLBarcodeResultBadArgErr                             = -6002,
    /**
     Wrong value of data size
     */
    RGLBarcodeResultSizeErr                               = -6003,
    /**
     Bad values of any parameter range
     */
    RGLBarcodeResultRangeErr                              = -6004,
    /**
     Internal program error
     */
    RGLBarcodeResultInternalErr                           = -6005,
    /**
     try-except process
     */
    RGLBarcodeResultTryExceptErr                          = -6006,
    /**
     Barcode detection error
     */
    RGLBarcodeResultBarCodeNotFound                       = -6008,
    /**
     Barcode decoding error
     */
    RGLBarcodeResultBarCodeDecodeErr                      = -6010,
    /**
     "ImageProcess.dll" connection error
     */
    RGLBarcodeResultNoUserDLLFound                        = -6019,
    /**
     IPP Dll connection error
     */
    RGLBarcodeResultNoIPPDLLFound                         = -6020,
    /**
     Run-time error in IPP-function
     */
    RGLBarcodeResultIppExecErr                            = -6024,
    /**
     try-except execution in IPP-function
     */
    RGLBarcodeResultIppTryExceptErr                       = -6025,
    /**
     Input data error
     */
    RGLBarcodeResultBARCODE_ERROR_Inputparam              = -11001,
    /**
     Initialization error
     */
    RGLBarcodeResultBARCODE_ERROR_FInit                   = -11006,
    /**
     "IpDecode.dll" connection error
     */
    RGLBarcodeResultBARCODE_ERROR_NotLoadIpDecodedll      = -11012,
    /**
     Internal program error
     */
    RGLBarcodeResultBARCODE_ERROR_InnerProblem            = -11100,
    /**
     1D-barcode decoding error
     */
    RGLBarcodeResultBARCODE_ERROR_Decode_1D_BadDecode     = -11200,
    /**
     Row or Column count computational error (PDF417)
     */
    RGLBarcodeResultBARCODE_ERROR_FindRowOrColumn         = -11201,
    /**
     MinX computational error (PDF417)
     */
    RGLBarcodeResultBARCODE_ERROR_Find3X8_2D_X            = -11202,
    /**
     MinY computational error (PDF417)
     */
    RGLBarcodeResultBARCODE_ERROR_Find3X8_2D_Y            = -11203,
    /**
     Invalid barcode angle (> 3 degree)
     */
    RGLBarcodeResultBARCODE_ERROR_2D_UgolMax              = -11204,
    /**
     The result may contain decoding errors
     */
    RGLBarcodeResultBARCODE_ERROR_INDEFINITELY_DECODED    = -11210,
    /**
     Dll initialization error
     */
    RGLBarcodeResultBARCODE_ERROR_Dllnotinit              = -11300,
    /**
     try-except in IPDECODE-function
     */
    RGLBarcodeResultBARCODE_ERROR_IPDECODE_DLL_Try_Except = -11400,
    /**
     Too many invalid code words
     */
    RGLBarcodeResultIPDECODE_ERROR_LARGEERRORS            = -4503,
    /**
     Invalid number of columns
     */
    RGLBarcodeResultIPDECODE_ERROR_FAULTCOLUMNS           = -4504,
    /**
     Invalid number of rows
     */
    RGLBarcodeResultIPDECODE_ERROR_FAULTROWS              = -4505,
    /**
     Correction Level error
     */
    RGLBarcodeResultIPDECODE_ERROR_INCORRECT_ERROR_LEVEL  = -4511,
    /**
     Loading "DevTable.bin" error
     */
    RGLBarcodeResultIPDECODE_ERROR_LOADING_DEV_TABLE      = -4512
} NS_SWIFT_NAME(BarcodeResult);

@class RGLDocumentReaderBarcodeField;

NS_SWIFT_NAME(DocumentReaderBarcodeResult)
@interface RGLDocumentReaderBarcodeResult : NSObject

/**
 Barcode fields
 */
@property(nonatomic, strong, readonly, nullable) NSArray <RGLDocumentReaderBarcodeField *> *fields;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithFields:(NSArray <RGLDocumentReaderBarcodeField *> *_Nonnull)fields;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

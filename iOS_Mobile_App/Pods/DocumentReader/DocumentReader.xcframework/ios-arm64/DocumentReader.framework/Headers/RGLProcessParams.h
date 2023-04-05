#import <Foundation/Foundation.h>

@class RGLImageQA;

/// Enumeration contains the types of barcodes that can be processed
typedef NS_ENUM(NSInteger, RGLBarcodeType) {
    /// Unknown.
    RGLBarcodeTypeUnknown = 0,
    /// One-dimensional barcode, ISO 15417 (ANSI/AIM BC4-1999 Code 128).
    RGLBarcodeTypeCode128 = 1,
    /// One-dimensional barcode, ISO 16388 (ANSI/AIM BC1-1995 Code 39).
    RGLBarcodeTypeCode39 = 2,
    /// One-dimensional barcode, EAN8, ISO 15418.
    RGLBarcodeTypeEAN8 = 3,
    /// One-dimensional barcode, Interleaved 2 of 5, ISO 16390 (ANSI/AIM BC2-1995 Interleaved 2 of 5).
    RGLBarcodeTypeITF = 4,
    /// Two-dimensional barcode, ISO 15438 (AIM USS PDF417).
    RGLBarcodeTypePDF417 = 5,
    /// One-dimensional barcode, Standard 2 of 5 (Industrial).
    RGLBarcodeTypeSTF = 6,
    /// One-dimensional barcode, Matrix 2 of 5.
    RGLBarcodeTypeMTF = 7,
    /// One-dimensional barcode, IATA 2 of 5 (Airline).
    RGLBarcodeTypeIATA = 8,
    /// One-dimensional barcode, (ANSI/AIM BC3-1995, USS - Codabar).
    RGLBarcodeTypeCODABAR = 9,
    /// One-dimensional barcode, UPC-A.
    RGLBarcodeTypeUPCA = 10,
    /// One-dimensional barcode, (ANSI/AIM BC5-1995, USS - Code 93).
    RGLBarcodeTypeCODE93 = 11,
    /// One-dimensional barcode, UPC-E.
    RGLBarcodeTypeUPCE = 12,
    /// One-dimensional barcode, EAN13, ISO 15418.
    RGLBarcodeTypeEAN13 = 13,
    /// Two-dimensional QR barcode.
    RGLBarcodeTypeQRCODE = 14,
    /// Two-dimensional AZTEC barcode.
    RGLBarcodeTypeAZTEC = 15,
    /// Two-dimensional DATAMATRIX barcode.
    RGLBarcodeTypeDATAMATRIX = 16,
    /// One-dimensional barcodes.
    RGLBarcodeTypeALL_1D = 17,
    /// One-dimensional barcode, Code 11.
    RGLBarcodeTypeCode11 = 18
} NS_SWIFT_NAME(BarcodeType);

/// The constants of the enumeration identify the system for measuring distances and weight
typedef NS_ENUM(NSInteger, RGLMeasureSystem) {
    /// The Metric System of Measurement, which uses the measuring units such as meters and grams and adds prefixes like kilo, milli and centi to count orders of magnitude.
    RGLMeasureSystemMetric = 0,
    /// The Imperial System of Measurement, where things are measured in feet, inches and pounds.
    RGLMeasureSystemImperial = 1
} NS_SWIFT_NAME(MeasureSystem);

@class RGLPosition;

NS_SWIFT_NAME(ProcessParams)
@interface RGLProcessParams : NSObject

/// Documents processing scenario.
@property (nonatomic, strong, nullable) NSString *scenario;

/// Documents processing scenario for the Capture button.
@property (nonatomic, strong, nullable) NSString *captureButtonScenario;

/// If set to `true`, the DocumentReader logs will be shown in the console.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *logs;

/// If set to `true`, processing of more than one page of the document (if they exist) will be triggered, otherwise, only one page will be processed.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *multipageProcessing;

/// If set to `true`, document focus check will be omitted.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *disableFocusingCheck;

/// Change the format string of displayed dates in the results. Mask examples: `dd/mm/yyyy`, `mm/dd/yyyy`, `dd-mm-yyyy`, `mm-dd-yyyy`, `dd/mm/yy`.
/// Set to `nil` to revert default value.
/// Default: depends on the device's locale.
@property (nonatomic, strong, null_resettable) NSString *dateFormat;

/// Takes the list of the document IDs to process. All documents will be processed if it's empty.
/// Type: Array of Integer.
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *documentIDList;

/// The path to the logs folder of the last session.
@property (readonly, nonatomic, strong, nullable) NSString *sessionLogFolder;

/// If you recognize the MRZ of documents, all fields will be extracted.
/// If you recognize the Visual zone of documents, you can set the list of field types that you wish to extract, other fields will be skipped during processing.
/// All fields will be extracted if it is empty.
/// Type: Array of `RGLFieldType` enum.
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *fieldTypesFilter;

/// Set types of barcodes that you wish to recognize. All barcodes will be recognized if it's empty.
/// Type: Array of `RGLBarcodeType` enum.
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *barcodeTypes;

/// Measure system of fields' values that are presented in results.
/// Default: If the country code is `US` or `LR` or `MM`, the `Imperial` system of measurement, otherwise, the `Metric`.
@property (nonatomic, assign) RGLMeasureSystem measureSystem;

/// If set to `true`, an original (uncropped) image will be received, which is sent for recognition.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *returnUncroppedImage;

/// If set to `true`, an image with cropped barcode will be returned.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *returnCroppedBarcode;

/// If set to `true`, allows to process up to two pages of the document (so-called "a double-page spread")
/// for one-shot if they are presented on the frame (image).
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *doublePageSpread;

/// There are documents that contain barcodes which data can be parsed only if document type verification is performed.
/// The following property allows setting the barcode parser type which should be used during recognition.
/// It allows parsing barcode data without performing document type verification.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *barcodeParserType;

/// Allows you to set the time limit for document recognition (in seconds), beyond which the recognition does not continue regardless of its result.
/// The countdown starts from the moment the scenario starts.
/// Setting value to `0` means infinity.
/// Type: `NSTimeInterval`.
@property (nonatomic, strong, nullable) NSNumber *timeout;

/// Allows you to set the time limit for document recognition (in seconds), beyond which the recognition does not continue regardless of its result.
/// The countdown starts from the moment the document is detected.
/// Setting value to `0` means infinity.
/// Type: `NSTimeInterval`.
@property (nonatomic, strong, nullable) NSNumber *timeoutFromFirstDetect;

/// Allows you to set the time limit for document recognition (in seconds), beyond which the recognition does not continue regardless of its result.
/// The countdown starts from the moment the document type is recognized.
/// Setting value to `0` means infinity.
/// Type: `NSTimeInterval`.
@property (nonatomic, strong, nullable) NSNumber *timeoutFromFirstDocType;

/// Allows to build an integral image, taking into account the quality of fixation of each of the individual images.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *integralImage;

/// Allows you to set the minimum acceptable DPI value of the camera frame that is passed for recognition.
/// Camera frames the DPI of which are less than you set won't be passed for recognition.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *minDPI;

/// Allows you to set the maximum value of the deviation of the corners of the document from the value of `90` degrees.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *perspectiveAngle;

/// If set to `true`, allows you to manually set the document's bounds after it is detected.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *manualCrop;

/// If set to `true`, a document's holograms presence will be checked.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *checkHologram;

/// If set to `true`, personal information will be removed from logs.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *depersonalizeLog;

/// If set to `true`, in case required fields are not read, their values will be empty.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *checkRequiredTextFields;

/// Types of results to return in response. See 'RGLResultType' enum for available options.
/// Type: Array of `RGLResultType` enum.
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *resultTypeOutput;

/// When enabled together with `doublePageSpread` and there is a passport with two pages spread in the image,
/// pages will be cropped, straightened and aligned together, as if the document was captured on a flatbed scanner.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *generateDoublePageSpreadImage;

/// This option controls maximum resolution in dpi of output images.
/// Resolution will remain original in case `0` is set.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *imageDpiOutMax;

/// This option can be set to `true` if you know for sure that the image you provide contains
/// already cropped document by its edges. This was designed to process on the
/// server side images captured and cropped on mobile.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *alreadyCropped;

/// Force use of specific template ID and skip document type identification step.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *forceDocID;

/// When disabled, text field OCR will be done as is and then the recognized value will be
/// matched to the field mask for validity. If enabled, we are trying to read a field value with maximum efforts
/// to match the mask and provide a correctly formatted value, making assumptions based on the provided field mask
/// in the template.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *matchTextFieldMask;

/// When enabled, shorten the list of candidates to process during document detection in
/// single image process mode. Reduces processing time for specific
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *fastDocDetect;

/// When enabled, fail OCR field validity, if there is a glare over the text field on the image.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *updateOCRValidityByGlare;

/// When enabled no graphic fields will be cropped from document image.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *noGraphics;

/// Controls properties of ImageQA checks. See `RGLImageQA` for more information.
@property (nonatomic, strong, nonnull) RGLImageQA *imageQA;

/// Force use of specified document format when locating and recognizing document to reduce the number of candidates.
/// Type: `RGLDocFormat` enum.
@property (nonatomic, strong, nullable) NSNumber *forceDocFormat;

/// Specifies minimal area of the image that document should cover to be treated as candidate when locating.
/// Value should be in range from `0` to `1`, where `1` is when document should fully cover the image.
/// Type: Float.
@property (nonatomic, strong, nullable) NSNumber *documentAreaMin;

/// This option allows locating and cropping multiple documents from one image if enabled.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *multiDocOnImage;

/// This option allows shifting the date of expiry into the future or past for number of months specified.
/// This is useful, for example, in some cases when document might be still valid for some period after original expiration date
/// to prevent negative validity status for such documents.
/// Or by shifting the date to the past will set negative validity for the documents that is about to expire in a specified number of months.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *shiftExpiryDate;

/// This options allows specifying the minimal age in years of the document holder for the document to be considered valid.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *minimalHolderAge;

/// This option allows limiting MRZ formats to be recognized by specifying them in array.
/// Type: Array of `RGLMRZFormat` enum.
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *mrzFormatsFilter;

/// This option can be set to `true` to make sure that in series processing MRZ is located fully inside the result document image, if present on the document.
/// Enabling this option may add extra processing time, by disabling optimizations, but allows more stability in output image quality.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *forceReadMrzBeforeLocate;

/// Takes JSON with parameters that are not presented in the DocumentReader.
@property (nonatomic, strong, nullable) NSDictionary *customParams;

/// When set to `false`, the Barcode code parsing will be skipped and the raw information from the code will be returned instead.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *parseBarcodes;

/// When set to `true`, the `rawResults` property of the `RGLDocumentReaderResults` will contain the encrypted containers
/// of scanning results that may be used for later reprocessing.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *shouldReturnPackageForReprocess;

/// When enabled, OCR of perforated fields in the document template will not be performed.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *disablePerforationOCR;

/// Array of specific eligible document types from `RGLDiDocType` enum to recognize from.
/// You may, for example, specify only passports to be recognized by setting this property.
@property (nonatomic, strong, nullable) NSArray<NSNumber *> *documentGroupFilter;

/// When enabled, image quality checks status affects document optical and overall status.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *respectImageQuality;

/// When enabled, the Surname and GivenNames field (`RGLDocumentReaderTextField`) will be divided into fields with fieldTypes `RGLFieldTypeFt_First_Name, RGLFieldTypeFt_Second_Name, RGLFieldTypeFt_Third_Name, RGLFieldTypeFt_Fourth_Name, RGLFieldTypeFt_Last_Name`.
@property (nonatomic, strong, nullable) NSNumber *splitNames;

/// Allowed `RGLAuthenticity`s.
/// Accepts sum of `RGLAuthenticity` values.
@property (nonatomic, strong, nullable) NSNumber *processAuth;


/// Maximum width of output images. In pixels.
@property (nonatomic, strong, nullable) NSNumber *imageOutputMaxWidth;

/// Maximum height of output images. In pixels.
@property (nonatomic, strong, nullable) NSNumber *imageOutputMaxHeight;

/// If set to `true`, images will be saved to the application's directory.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *debugSaveImages;

/// If set to `true`, cropped images will be saved to the application's directory.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *debugSaveCroppedImages;

/// If set to `true`, RFID sessions will be saved to the application's directory.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *debugSaveRFIDSession;

/// If set to `true`, text logs will be saved to the application's directory.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *debugSaveLogs;

@end

#import "RGLProcessParams.h"
#import "RGLDocReaderRFIDDelegate.h"
#import "RGLRFIDNotify.h"
#import "RGLMacros.h"

@class UIViewController;
@class UIImage;
@class RGLDocReaderVersion;
@class RGLScenario;
@class RGLDocumentReaderResults;
@class RGLFunctionality;
@class RGLCustomization;
@class RGLInitializationResponse;
@class RGLDocumentReaderCameraViewController;
@class RGLLicense;
@class RGLPKDCertificate;
@class RGLRFIDNotify;
@class RGLRFIDScenario;
@class RGLConfig;
@class RGLTCCParams;
@class RGLImageInput;
@class RGLDocReaderDocumentsDatabase;

/// Enum contains all possible notification codes about reading process
typedef NS_ENUM(NSInteger, RGLDocReaderAction) {
    /**
     Processing finished, the results were received
     */
    RGLDocReaderActionComplete = 0,
    /**
     Processing didn't finish, intermediate results may be obtained
     */
    RGLDocReaderActionProcess = 1,
    /**
     Processing of a page is completed, the next one can be processed
     */
    RGLDocReaderActionMorePagesAvailable = 2,
    /**
     Processing was cancelled, incomplete results may be obtained
     */
    RGLDocReaderActionCancel = 3,
    /**
     An error occurred during processing, incomplete results may be obtained
     */
    RGLDocReaderActionError = 4,
    /**
     Processing of a hologram is started
     */
    RGLDocReaderActionProcessWhiteFlashLight = 5,
    /**
     Processing is finished by timeout, intermediate results can be received
     */
    RGLDocReaderActionProcessTimeout = 6,
    /**
     Online processing is started
     */
    RGLDocReaderActionProcessOnServer = 7
} NS_SWIFT_NAME(DocReaderAction);

typedef NS_ENUM(NSInteger, RGLCommand) {
    RGLCommandUnknown = 0,
    RGLCommandRfidSendData = 100,
    RGLCommandRfidNotify = 101,
    RGLCommandRfidGetDataForScenario = 102,
    RGLCommandTorchGetUVFoto = 200,
    RGLCommandCommandInternetSend = 300
} NS_SWIFT_NAME(Command);

/// Enum contains all possible RFID notification actions
typedef NS_ENUM(NSInteger, RGLRFIDNotificationAction) {
    /**
     An RFID tag is found
     */
    RGLRFIDNotificationActionConnecting = 0,
    /**
     An RFID tag is being searched
     */
    RGLRFIDNotificationActionSearchingTag = 1,
    /**
     An RFID tag is being read
     */
    RGLRFIDNotificationActionStartReading = 2,
    /**
     RGLRFIDNotify notifications of current RFID chip reading events
     */
    RGLRFIDNotificationActionNotification = 3
} NS_SWIFT_NAME(RFIDNotificationAction);

/// Enum contains all possible RFID completion actions
typedef NS_ENUM(NSInteger, RGLRFIDCompleteAction) {
    /// RFID chip reading is finished
    RGLRFIDCompleteActionComplete = 0,
    /// RFID chip reading is finished with an error
    RGLRFIDCompleteActionError = 1,
    /// RFID chip reading is canceled
    RGLRFIDCompleteActionCancel = 2,
    /// RFID chip reading is restarted
    RGLRFIDCompleteActionSessionRestarted = 3
} NS_SWIFT_NAME(RFIDCompleteAction);

extern _Nonnull NSErrorDomain const RGLDocumentReaderDomain;
/// Enum contains all possible error codes
typedef NS_ERROR_ENUM(RGLDocumentReaderDomain, RGLDocumentReaderErrorCode) {
  ///  A Core framework is absent.
  RGLDocumentReaderErrorCodeInitializationCoreAbsent = 0,

  /// The reader is not initialized or an unknown initialization error occured.
  RGLDocumentReaderErrorCodeInitializationFailed = 1,

  /// This scenario is not supported based on your license and Core framework capabilities.
  RGLDocumentReaderErrorCodeIncorrectScenario = 2,

  /// There are no results after recognition of camera frames.
  RGLDocumentReaderErrorCodeNoResult = 3,

  /// An error is encountered during database removal.
  RGLDocumentReaderErrorCodeRemoveDatabase = 4,

  /// An error is encountered during database download.
  RGLDocumentReaderErrorCodeFetchingDatabase = 5,

  /// An incorrect database ID.
  RGLDocumentReaderErrorCodeDbIdNotFound = 6,

  /// An incorrect database ID.
  RGLDocumentReaderErrorCodeDbDescriptionNotFound = 7,

  /// An error is encountered during database save on your device.
  RGLDocumentReaderErrorCodeSaveDb = 8,

  /// A database is corrupted.
  RGLDocumentReaderErrorCodeDownloadDbIncorrectChecksum = 9,

  /// A database is corrupted.
  RGLDocumentReaderErrorCodeDownloadDb = 10,

  /// Deprecated.
  RGLDocumentReaderErrorCodeCreationDb = 11,

  /// An RFID error.
  RGLDocumentReaderErrorCodeRfidError = 12,

  /// A license is absent or corrupted.
  RGLDocumentReaderErrorCodeLicenseAbsentOrCorrupted = 13,

  /// An invalid date, i.e. the license may be expired, or the date and time of set on the device doesn't correspond to reality.
  RGLDocumentReaderErrorCodeLicenseInvalidDate = 14,

  /// An invalid version.
  RGLDocumentReaderErrorCodeLicenseInvalidVersion = 15,

  /// An invalid device ID.
  RGLDocumentReaderErrorCodeLicenseInvalidDeviceID = 16,

  /// An invalid OS or application ID.
  RGLDocumentReaderErrorCodeLicenseInvalidSystemOrAppID = 17,

  /// There are no capabilities for this functionality in your license.
  RGLDocumentReaderErrorCodeLicenseNoCapabilities = 18,

  /// There are no authenticity capabilities in your license.
  RGLDocumentReaderErrorCodeLicenseNoAuthenticity = 19,

  /// An invalid URL of the video during its generating.
  RGLDocumentReaderErrorCodeRecordProcessInvalidOutputURL = 20,

  /// Something went wrong with online license processing.
  RGLDocumentReaderErrorCodeLicenseOnlineError = 21,

  /// db.dat is absent.
  RGLDocumentReaderErrorCodeNoNoDatabase = 22,

  /// db.dat is incorrect.
  RGLDocumentReaderErrorCodeDatabaseIncorrect = 23,

  /// Failed to set TCC params.
  RGLDocumentReaderErrorCodeSetTCCParamsFailed = 24,

  /// The operation failed due to RFID reading has already started.
  RGLDocumentReaderErrorCodeRFIDInProgress = 25,
};

typedef void (^RGLDocumentReaderInitializationCompletion)(BOOL success,
                                                          NSError * _Nullable error) NS_SWIFT_NAME(DocumentReaderInitializationCompletion);
typedef void (^RGLDocumentReaderCheckUpdateCompletion)(RGLDocReaderDocumentsDatabase * _Nullable database) NS_SWIFT_NAME(DocumentReaderCheckUpdateCompletion);
typedef void (^RGLDocumentReaderPrepareCompletion)(BOOL success, NSError * _Nullable error) NS_SWIFT_NAME(DocumentReaderPrepareCompletion);
typedef void (^RGLDocumentReaderCompletion)(RGLDocReaderAction action,
                                            RGLDocumentReaderResults * _Nullable results,
                                            NSError * _Nullable error) NS_SWIFT_NAME(DocumentReaderCompletion);
typedef void (^RGLCallbackCompletionBlock)(NSInteger command, NSData * _Nonnull data, NSString * _Nonnull string) NS_SWIFT_NAME(CallbackCompletionBlock);
typedef void (^RGLRFIDCallbackCompletionBlock)(RGLCommand command, NSData * _Nonnull data, NSString * _Nonnull json, RGLCallbackCompletionBlock _Nonnull completionBlock) NS_SWIFT_NAME(RFIDCallbackCompletionBlock);
typedef void (^RGLRFIDProcessCompletion)(RGLRFIDCompleteAction action,
                                         RGLDocumentReaderResults * _Nullable results,
                                         NSError * _Nullable error, RGLRFIDErrorCodes errorCode) NS_SWIFT_NAME(RFIDProcessCompletion);
typedef void (^RGLRFIDNotificationCallback)(RGLRFIDNotificationAction notificationAction, RGLRFIDNotify* _Nullable notification) NS_SWIFT_NAME(RFIDNotificationCallback);
typedef NSString * _Nullable (^RGLLocalizationHandler)(NSString * _Nonnull localizationKey);

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DocReader)
@interface RGLDocReader : NSObject

RGL_EMPTY_INIT_UNAVAILABLE

@property(readonly, class, nonatomic, strong, nonnull) RGLDocReader *shared;

/**
 Params that influence the scanning process
 */
@property(nonatomic, strong, nonnull) RGLProcessParams *processParams;
/**
 Information about the SDK
 */
@property(nonatomic, strong, readonly, nullable) RGLDocReaderVersion *version;
/**
 A list of scenarios that can be used for documents recognition based on your license and Core framework capabilities
 */
@property(nonatomic, strong, readonly, nonnull) NSArray<RGLScenario *> *availableScenarios;
/**
 Allows you to check if Document Reader is ready for use
 */
@property(nonatomic, assign, readonly, getter=isDocumentReaderIsReady) BOOL documentReaderIsReady;
/**
 Allows you to check if RFID chip reading can be performed based on your license and Core framework capabilities
 */
@property(nonatomic, assign, readonly, getter=isRFIDAvailableForUse) BOOL rfidAvailable;
/**
 Allows you to check if you can use external Regula Bluetooth devices based on your license and Core framework capabilities
 */
@property(nonatomic, assign, readonly, getter=isAuthenticatorAvailableForUse) BOOL useAuthenticatorAvailable;
/**
 Allows you to pause the scanning process and resume it when it's needed
 */
@property(nonatomic, assign, readwrite, getter=isCameraSessionIsPaused) BOOL cameraSessionIsPaused;
/**
 Allows you to get a status of Document Reader
 */
@property(nonatomic, strong, readonly, nonnull) NSString *documentReaderStatus;
/**
 Allows you to get a status of the RFID chip reading process
 */
@property(nonatomic, strong, nullable) NSString *rfidSessionStatus;

/**
 Information about your license
 */
@property(nonatomic, strong, nullable) RGLLicense *license;
@property(nonatomic, weak, nullable) id <RGLDocReaderRFIDDelegate> rfidDelegate;

/**
 Params that influence the scanning process, camera view controller customization and etc.
 */
@property(nonatomic, strong, nonnull) RGLFunctionality *functionality;
/**
 Params that relate to the camera view controller customization and etc.
 */
@property(nonatomic, strong, nonnull) RGLCustomization *customization;
/**
 Params that influence the RFID chip processing
 */
@property(nonatomic, strong, nonnull) RGLRFIDScenario *rfidScenario;
/**
 Current Session identifier
 */
@property(nonatomic, strong, nullable) NSString *tag;
/**
 It should be used when you add Document Reader SDK inside yours and do localization
 */
@property(nonatomic, strong) _Nullable Class localizationClassName;

/// A localization hook to override default localization search logic.
/// If this block is not set or the implementation of the block returns `nil` the default localization will be used.
@property(readwrite, nonatomic, copy, nullable) RGLLocalizationHandler localizationHandler;


/**
 Allows you to initialize Document Reader
 @param config A configuration file for DocumentReader initialization
 @param completion The block to execute after the initialization finishes
 */
- (void)initializeReaderWithConfig:(nonnull RGLConfig *)config
                        completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion NS_SWIFT_NAME(initializeReader(config:completion:));

/**
 Allows you to initialize Document Reader
 @param license A license as NSData
 @param completion The block to execute after the initialization finishes
 */
- (void)initializeReader:(nonnull NSData *)license
              completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion NS_SWIFT_NAME(initializeReader(license:completion:)) RGL_DEPRECATED(5.8, "Use `-[initializeReaderWithConfig:completion:]` instead.");
/**
 Allows you to initialize Document Reader
 @param license A license as NSData
 @param databasePath A path to the database
 @param completion The block to execute after the initialization finishes
 */
- (void)initializeReader:(nonnull NSData *)license
            databasePath:(nonnull NSString *)databasePath
              completion:(RGLDocumentReaderInitializationCompletion _Nonnull)completion NS_SWIFT_NAME(initializeReader(license:databasePath:completion:)) RGL_DEPRECATED(5.8, "Use `-[initializeReaderWithConfig:completion:]` instead.");

/**
 Allows you to to check database update
 @param databaseID An identifier of the database
 @param completion The block to execute after the check database update finishes
 */
- (void)checkDatabaseUpdate:(nonnull NSString *)databaseID
                 completion:(RGLDocumentReaderCheckUpdateCompletion _Nonnull)completion NS_SWIFT_NAME(checkDatabaseUpdate(databaseID:completion:));

/**
 Allows you to download a database from the Regula server. If it exists in your app and compatible with the SDK, it won't be downloaded
 @param databaseID An identifier of the database
 @param progress Downloading progress
 @param completion The block to execute after the download finishes
 */
- (void)prepareDatabase:(nonnull NSString *)databaseID
        progressHandler:(void (^_Nullable)(NSProgress * _Nonnull progress))progress
             completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(prepareDatabase(databaseID:progressHandler:completion:));
/**
 Allows you to download a database from the Regula server. If it exists in your app and compatible with the SDK, it won't be downloaded
 @param databaseID An identifier of the database
 @param completion The block to execute after the download finishes
 */
- (void)prepareDatabase:(nonnull NSString *)databaseID
             completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(prepareDatabase(databaseID:completion:));
/**
 Allows you to download a database from the Regula server. Each new update of the database will be downloaded
 @param databaseID An identifier of the database
 @param progress Downloading progress
 @param completion The block to execute after the download finishes
 */
- (void)runAutoUpdate:(nonnull NSString *)databaseID
      progressHandler:(void (^_Nullable)(NSProgress * _Nonnull progress))progress
           completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(runAutoUpdate(databaseID:progressHandler:completion:));
/**
 Allows you to download a database from the Regula server. Each new update of the database will be downloaded
 @param databaseID An identifier of the database
 @param completion The block to execute after the download finishes
 */
- (void)runAutoUpdate:(nonnull NSString *)databaseID
           completion:(RGLDocumentReaderPrepareCompletion _Nonnull)completion NS_SWIFT_NAME(runAutoUpdate(databaseID:completion:));
- (UIViewController * _Nullable)prepareCameraViewController:(RGLDocumentReaderCameraViewController *_Nullable)controller cameraHandler:(RGLDocumentReaderCompletion _Nonnull)completion NS_SWIFT_NAME(prepareCameraViewController(cameraViewController:cameraHandler:));
- (UIViewController * _Nullable)prepareCameraViewController:(RGLDocumentReaderCompletion _Nonnull)completion NS_SWIFT_NAME(prepareCameraViewController(cameraHandler:));
/**
 Allows you to remove the database from your app
 @param completion The block to execute after the removal finishes
 */
- (void)removeDatabase:(RGLDocumentReaderPrepareCompletion _Nullable)completion NS_SWIFT_NAME(removeDatabase(completion:));
/**
 Allows you to cancel the database update
 */
- (void)cancelDBUpdate;

/**
 It's used to start the processing of the next page of the document once the current one is processed
 */
- (void)startNewPage;
/**
 It's used to start a scanning process
 */
- (void)startNewSession;
/**
 It's used for single frame processing where input is UIImage
 @param completion The block to execute after the recognition process finishes
 */
- (void)recognizeImage:(UIImage * _Nonnull)image
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
/**
 It's used for single frame processing where input is binary
 @param completion The block to execute after the recognition process finishes
 */
- (void)recognizeData:(NSData * _Nonnull)data
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
- (void)recognizeImageFromPresenter:(UIViewController * _Nonnull)presenter image:(UIImage * _Nonnull)image
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
/**
 It's used for multiple frames processing
 @param cameraMode Indicates whether a stream of frames has to be processed or not
 @param completion The block to execute after the recognition process finishes
 */
- (void)recognizeImage:(UIImage * _Nonnull)image
            cameraMode:(BOOL)cameraMode
            completion:(RGLDocumentReaderCompletion _Nonnull)completion;
/**
 It's used for multiple frames processing
 @param completion The block to execute after the recognition process finishes
 */
- (void)recognizeImages:(NSArray<UIImage *> *_Nonnull)images completion:(RGLDocumentReaderCompletion _Nonnull)completion;
/**
 It's used for multiple frames processing with RGLImageInput
 @param completion The block to execute after the recognition process finishes
 */
- (void)recognizeImagesWithImageInputs:(NSArray<RGLImageInput *> *_Nonnull)inputs completion:(RGLDocumentReaderCompletion _Nonnull)completion;
/**
 It's used for multiple frames processing which are captured from the camera
 @param completion The block to execute after the recognition process finishes
 */
- (void)showScanner:(UIViewController * _Nonnull)presenter
         completion:(RGLDocumentReaderCompletion _Nonnull)completion;

/**
 It's used for the RFID chip processing
 @param completion The block to execute after the scanning process finishes
 */
- (void)startRFIDReaderFromPresenter:(UIViewController * _Nonnull)presenter
                          completion:(RGLDocumentReaderCompletion _Nonnull)completion;
/**
 It's used for the RFID chip processing
 @param notificationCallback Notifications of the RFID chip processing
 @param completion The block to execute after the scanning process finishes
 */
- (void)readRFID:(RGLRFIDNotificationCallback _Nullable)notificationCallback completion:(RGLRFIDProcessCompletion _Nonnull)completion;
/**
 It's used to stop the scanning process
 @param completion The block to execute after the scanning process finishes. This block has no return value and takes no parameters. You can specify nil for this parameter
 */
- (void)stopScanner:(void(^_Nullable)(void))completion;
/**
 It's used to stop the RFID chip processing
 @param completion The block to execute after the RFID chip processing finishes. This block has no return value and takes no parameters. You can specify nil for this parameter
 */
- (void)stopRFIDReader:(void(^_Nullable)(void))completion;
/**
 It's used to stop the RFID chip processing
 @param errorMessage The error message to display. You can specify nil for this parameter, to avoid display of error alert
 @param completion The block to execute after the RFID chip processing finishes. This block has no return value and takes no parameters. You can specify nil for this parameter
 */
- (void)stopRFIDReaderWithErrorMessage:(NSString * _Nullable)errorMessage completion:(void(^_Nullable)(void))completion NS_SWIFT_NAME(stopRFIDReader(errorMessage:completion:));
/**
 It's used to pass certificates to Document Reader that will be used during the RFID chip processing
 @param certificates PKD certificates
 */
- (void)addPKDCertificates:(NSArray <RGLPKDCertificate *> * _Nonnull)certificates NS_SWIFT_NAME(addPKDCertificates(certificates:));
/**
 It's used to remove certificates from your app that are used during the RFID chip processing
 */
- (void)clearPKDCertificates;

/// Sets the given `TCCParams` to the RFID  session. The parameters are required to be set before starting RFID session.
///
/// @param params TCC related parameters.
/// @param completion Completion block of the operation. The block is executed on the main thread.
- (void)setTCCParams:(RGLTCCParams *)params completion:(void (^_Nullable)(BOOL success, NSError * _Nullable error))completion;

- (RGLScenario * _Nullable)selectedScenario;

/**
 It's used to deinitialize Document Reader and free up RAM as a consequence of this
 */
- (void)deinitializeReader;

@end

NS_ASSUME_NONNULL_END

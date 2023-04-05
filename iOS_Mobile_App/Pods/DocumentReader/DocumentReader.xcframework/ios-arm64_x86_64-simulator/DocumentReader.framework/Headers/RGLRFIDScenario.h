#import <Foundation/Foundation.h>

typedef enum {
    /// Doc 9303, 6th edition, 2006
    RGLRFIDSdkProfilerTypeDoc9303Edition2006 = 0x00000001,
    /// LDS and PKI Maintenance, v2.0, May 21, 2014
    RGLRFIDSdkProfilerTypeDoc9303LdsPkiMaintenance = 0x00000002
} RGLRFIDSdkProfilerType NS_SWIFT_NAME(RFIDSdkProfilerType);

typedef NS_ENUM(NSInteger, RGLRFIDAuthenticationProcedureType) {
    /// Not defined
    RGLRFIDAuthenticationProcedureTypeUndefined = 0,
    /// Standard authentication procedure
    RGLRFIDAuthenticationProcedureTypeStandard = 1,
    /// Advanced authentication procedure
    RGLRFIDAuthenticationProcedureTypeAdvanced = 2,
    /// General authentication procedure
    RGLRFIDAuthenticationProcedureTypeGeneral = 3
} NS_SWIFT_NAME(RFIDAuthenticationProcedureType);

typedef NS_ENUM(NSInteger, RGLRFIDAccessControlProcedureType) {
    /// Type is not defined
    RGLRFIDAccessControlProcedureTypeUndefined = 0,
    /// Basic Access Control (BAC) / Protection (BAP)
    RGLRFIDAccessControlProcedureTypeBac = 1,
    /// Password Authenticated Connection Establishment
    RGLRFIDAccessControlProcedureTypePace = 2,
    /// Chip Authentication
    RGLRFIDAccessControlProcedureTypeCa = 3,
    /// Terminal Authentication
    RGLRFIDAccessControlProcedureTypeTa = 4,
    /// Active Authentication
    RGLRFIDAccessControlProcedureTypeAa = 5,
    /// Restricted Identification
    RGLRFIDAccessControlProcedureTypeRi = 6,
    /// Card info
    RGLRFIDAccessControlProcedureTypeCardInfo = 7
} NS_SWIFT_NAME(RFIDAccessControlProcedureType);

typedef NS_ENUM(NSInteger, RGLRFIDPasswordType) {
    /// Unknown type
    RGLRFIDPasswordTypeUnknown = 0,
    /// MRZ
    RGLRFIDPasswordTypeMrz = 1,
    /// CAN
    RGLRFIDPasswordTypeCan = 2,
    /// PIN
    RGLRFIDPasswordTypePin = 3,
    /// PUK
    RGLRFIDPasswordTypePuk = 4,
    /// eSign-PIN
    RGLRFIDPasswordTypePinEsign = 5,
    /// Scanning Area Identifier (for eDL application)
    RGLRFIDPasswordTypeSai = 6
} NS_SWIFT_NAME(RFIDPasswordType);

typedef NS_ENUM(NSInteger, RGLRFIDTerminalType) {
    /// Not defined
    RGLRFIDTerminalTypeUndefined = 0,
    /// Inspection system
    RGLRFIDTerminalTypeInspectionSystem = 1,
    /// Authentication terminal
    RGLRFIDTerminalTypeAuthenticationTerminal = 2,
    /// Signature terminal
    RGLRFIDTerminalTypeSignatureTerminal = 3,
    /// Unauthenticated terminal
    RGLRFIDTerminalTypeUnauthenticatedTerminal = 4
} NS_SWIFT_NAME(RFIDTerminalType);

typedef NS_ENUM(NSInteger, RGLESignManagementAction) {
    /// Not identified
    RGLESignManagementActionUndefined = 0,
    /// Create PIN
    RGLESignManagementActionCreatePIN = 1,
    /// Change PIN
    RGLESignManagementActionChangePIN = 2,
    /// Unblock PIN
    RGLESignManagementActionUnblockPIN = 3,
    /// Terminate PIN
    RGLESignManagementActionTerminatePIN = 4,
    /// Generate keys
    RGLESignManagementActionGenerateKeys = 5,
    /// Terminate keys
    RGLESignManagementActionTerminateKeys = 6,
    /// Sign data
    RGLESignManagementActionSignData = 7
} NS_SWIFT_NAME(ESignManagementAction);

@class RGLePassportDataGroup, RGLeIDDataGroup, RGLeDLDataGroup, RGLDocumentReaderResults, RGLReprocParams;

NS_SWIFT_NAME(RFIDScenario)
@interface RGLRFIDScenario : NSObject

@property(nonatomic, assign) BOOL autoSettings;
@property(nonatomic, assign) RGLESignManagementAction signManagementAction;
@property(nonatomic, assign) int readingBuffer;
@property(nonatomic, assign) int defaultReadingBufferSize;
@property(nonatomic, assign) int onlineTAToSignDataType;
@property(nonatomic, assign) BOOL onlineTA;
@property(nonatomic, assign) BOOL writeEid;
@property(nonatomic, assign) RGLRFIDSdkProfilerType profilerType;
@property(nonatomic, assign) RGLRFIDAuthenticationProcedureType authProcType;
@property(nonatomic, assign) RGLRFIDAccessControlProcedureType baseSMProcedure;
@property(nonatomic, assign) RGLRFIDPasswordType pacePasswordType;
@property(nonatomic, assign) RGLRFIDTerminalType terminalType;
@property(nonatomic, assign) BOOL universalAccessRights;
@property(nonatomic, assign) BOOL authorizedRestrictedIdentification;
@property(nonatomic, assign) BOOL auxVerificationCommunityID;
@property(nonatomic, assign) BOOL auxVerificationDateOfBirth;
@property(nonatomic, assign) BOOL skipAA;
@property(nonatomic, assign) BOOL strictProcessing;
@property(nonatomic, assign) BOOL pkdDSCertPriority;
@property(nonatomic, assign) BOOL pkdUseExternalCSCA;
@property(nonatomic, assign) BOOL trustedPKD;
@property(nonatomic, assign) BOOL passiveAuth;
@property(nonatomic, assign) BOOL paceStaticBinding;
@property(nonatomic, strong, nonnull) NSString *password;
@property(nonatomic, assign) BOOL useSFI;
@property(nonatomic, strong, nonnull) NSString *pkdPA;
@property(nonatomic, strong, nonnull) NSString *pkdEAC;
@property(nonatomic, assign) BOOL readEPassport;
@property(nonatomic, assign) BOOL readEID;
@property(nonatomic, assign) BOOL readEDL;
@property(nonatomic, strong, nonnull) RGLePassportDataGroup *ePassportDataGroups;
@property(nonatomic, strong, nonnull) RGLeIDDataGroup *eIDDataGroups;
@property(nonatomic, strong, nonnull) RGLeDLDataGroup *eDLDataGroups;
@property(nonatomic, strong, nonnull) NSString *mrz;
@property(nonatomic, strong, nonnull) NSString *eSignPINDefault;
@property(nonatomic, strong, nonnull) NSString *eSignPINNewValue;
@property(nonatomic, assign) BOOL authorizedSTSignature;
@property(nonatomic, assign) BOOL authorizedSTQSignature;
@property(nonatomic, assign) BOOL authorizedWriteDG17;
@property(nonatomic, assign) BOOL authorizedWriteDG18;
@property(nonatomic, assign) BOOL authorizedWriteDG19;
@property(nonatomic, assign) BOOL authorizedWriteDG20;
@property(nonatomic, assign) BOOL authorizedWriteDG21;
@property(nonatomic, assign) BOOL authorizedVerifyAge;
@property(nonatomic, assign) BOOL authorizedVerifyCommunityID;
@property(nonatomic, assign) BOOL authorizedPrivilegedTerminal;
@property(nonatomic, assign) BOOL authorizedCANAllowed;
@property(nonatomic, assign) BOOL authorizedPINManagment;
@property(nonatomic, assign) BOOL authorizedInstallCert;
@property(nonatomic, assign) BOOL authorizedInstallQCert;
@property(nonatomic, assign) BOOL applyAmendments;
@property(nonatomic, strong, nullable) RGLReprocParams *reprocParams;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
- (NSDictionary *_Nonnull)rfidScenarioDictionary;
- (NSDictionary *_Nonnull)correctedDictionaryByAutosettings:(RGLDocumentReaderResults *_Nonnull)results;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end

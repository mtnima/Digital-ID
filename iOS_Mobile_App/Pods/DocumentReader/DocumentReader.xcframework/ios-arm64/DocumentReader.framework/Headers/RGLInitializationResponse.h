#import <Foundation/Foundation.h>

NS_SWIFT_NAME(InitializationResponse)
@interface RGLInitializationResponse : NSObject

typedef NS_ENUM(NSInteger, RGLLicensingResult) {
  RGLLicensingResultOK                        =   0,
  RGLLicensingResultLicenseAbsentOrCorrupted  =   1,
  RGLLicensingResultInvalidDate               =   2,
  RGLLicensingResultInvalidVersion            =   3,
  RGLLicensingResultInvalidDeviceID           =   4,
  RGLLicensingResultInvalidSystemOrAppID      =   5,
  RGLLicensingResultNoCapabilities            =   6,
  RGLLicensingResultNoAuthenticity            =   7,
  RGLLicensingResultNoDatabase                =   10,
  RGLLicensingResultDatabaseIncorrect         =   11

};

@property (nonatomic, assign, readonly) BOOL status;
@property (nonatomic, strong, readonly) NSString *message;
@property (nonatomic, assign, readonly) BOOL showLogo;
@property (nonatomic, assign, readonly) BOOL rfidAvailable;
@property (nonatomic, strong, readonly) NSError *error;

- (instancetype)initWithJSON:(NSDictionary *)json;
+ (instancetype)initWithJSON:(NSDictionary *)json;

@end

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(License)
/// Interface contains properties to get the information about the license
@interface RGLLicense : NSObject

/**
 Allows you to get an expiration date of your license.
 */
@property(nonatomic, strong, readonly, nullable) NSDate *expiryDate;
/**
 Allows you to get a list of country identifiers which are defined for processing in the license. If the array is empty, there are no restrictions for processing.
 */
@property(nonatomic, strong, readonly, nullable) NSArray <NSString *> *countryFilter;
/**
 Allows you to verify that RFID chip reading capabilities are added to your license
 */
@property(nonatomic, assign, readonly, getter=isRfidAvailable) BOOL rfidAvailable;

- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;

@end

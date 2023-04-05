#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"
#import "RGLImageQualityGroup.h"

NS_SWIFT_NAME(ImageQuality)
@interface RGLImageQuality : NSObject

/**
 Check result type, one of RGLImageQualityCheckType values
 */
@property(nonatomic, assign, readonly, nonnull) RGLImageQualityCheckType type;
/**
 Check result, one of RGLCheckResult values
 */
@property(nonatomic, assign, readonly) RGLCheckResult result;
/**
 Check result, one of RGLSecurityFeatureType values
 */
@property(nonatomic, assign, readonly) RGLSecurityFeatureType featureType;
/**
 Coordinates of glares
 */
@property(nonatomic, strong, readonly, nonnull) NSArray<NSValue *> *boundRects; //CGRect array

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

#import <Foundation/Foundation.h>

#import "RGLDocumentReaderResults.h"
#import "RGLImageQualityCheckType.h"

NS_ASSUME_NONNULL_BEGIN

@class RGLImageQuality;

NS_SWIFT_NAME(ImageQualityGroup)
@interface RGLImageQualityGroup : NSObject

/**
 Number of results
 */
@property(nonatomic, assign, readonly) NSInteger count;
/**
 Overall check result for document page, one of RGLCheckResult values
 */
@property(nonatomic, assign, readonly) RGLCheckResult result;
/**
 An array of single check result pointers
 */
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLImageQuality *> *imageQualityList;

/**
 Index of the document page, whence the result is received
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype)init NS_UNAVAILABLE;
- (RGLCheckResult)getQualityResultWithType:(RGLImageQualityCheckType)type;
- (instancetype)initWithJSON:(NSDictionary *)json;
+ (instancetype)initWithJSON:(NSDictionary *)json;
- (NSDictionary *)jsonDictionary;

@end

NS_ASSUME_NONNULL_END

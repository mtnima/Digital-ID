#import <Foundation/Foundation.h>

@class RGLSignerInfo;

NS_SWIFT_NAME(SecurityObject)
@interface RGLSecurityObject : NSObject

@property(nonatomic, assign, readonly) NSInteger fileReference;
@property(nonatomic, strong, readonly, nonnull) NSString *objectType;
@property(nonatomic, assign, readonly) NSInteger version;
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLSignerInfo *> *signerInfos;

/// The list of remarks occured during the scanning procedure.
///
/// Each element is a `NSNumber` containing a `NSUInteger`, that belongs to the `enum eLDS_ParsingErrorCodes`
@property(nonatomic, strong, readonly, nonnull) NSArray<NSNumber *> *notifications;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

#import <Foundation/Foundation.h>
#import "RGLAuthenticityElement.h"
#import <UIKit/UIKit.h>

@class RGLElementRect;

NS_SWIFT_NAME(IdentResult)
@interface RGLIdentResult : RGLAuthenticityElement

@property(nonatomic, strong, readonly, nullable) UIImage *etalonImage;
@property(nonatomic, strong, readonly, nullable) UIImage *image;
@property(nonatomic, assign, readonly) NSInteger percentValue;
@property(nonatomic, assign, readonly) NSInteger lightIndex;
@property(nonatomic, strong, readonly, nonnull) RGLElementRect *area;

- (instancetype _Nonnull)initWithEtalonImage:(nullable UIImage *)etalonImage
                                       image:(nullable UIImage *)image
                                percentValue:(NSInteger)percentValue
                                      status:(RGLCheckResult)status
                                 elementType:(RGLSecurityFeatureType)elementType
                                        area:(nonnull RGLElementRect *)area
                             elementDiagnose:(RGLCheckDiagnose)elementDiagnose;

@end

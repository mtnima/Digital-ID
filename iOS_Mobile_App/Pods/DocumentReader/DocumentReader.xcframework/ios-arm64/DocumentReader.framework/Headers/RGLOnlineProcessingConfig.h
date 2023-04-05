//
//  RGLOnlineProcessingConfig.h
//  DocumentReader
//
//  Created by Dmitry Evglevsky on 15.06.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLProcessParams.h"

@protocol RGLURLRequestInterceptingDelegate;

typedef NS_ENUM(NSInteger, RGLOnlineProcessingMode) {
    RGLOnlineProcessingModeManual  = 0,
    RGLOnlineProcessingModeAuto    = 1
} NS_SWIFT_NAME(DocReader.OnlineProcessingMode);

typedef NS_ENUM(NSInteger, RGLOnlineProcessingImageFormat) {
    RGLOnlineProcessingImageFormatPNG   = 0,
    RGLOnlineProcessingImageFormatJPEG  = 1
} NS_SWIFT_NAME(DocReader.OnlineProcessingImageFormat);

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DocReader.OnlineProcessingConfig)
@interface RGLOnlineProcessingConfig : NSObject

@property(nonatomic, assign, readonly) RGLOnlineProcessingMode mode;
@property(nonatomic, strong, nullable) RGLProcessParams *processParams;
@property(nonatomic, strong, nullable) NSString *serviceURL;
@property(nonatomic, assign) RGLOnlineProcessingImageFormat imageFormat;
@property(nonatomic, assign) CGFloat imageCompressionQuality;

/// Delegate that responds to request intercepting events.
/// Use the delegate to modify `URLRequest` requests before they are send to the web service.
@property(nonatomic, weak, nullable) id<RGLURLRequestInterceptingDelegate> requestInterceptingDelegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithMode:(RGLOnlineProcessingMode)mode;

@end

NS_ASSUME_NONNULL_END

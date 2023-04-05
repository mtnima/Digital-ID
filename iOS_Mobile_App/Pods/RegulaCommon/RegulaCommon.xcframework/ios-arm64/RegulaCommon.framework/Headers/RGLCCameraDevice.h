//
//  RGLCCameraDevice.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/2/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RGLCCameraDevice : NSObject

@property(readonly, nonatomic, strong, nullable) AVCaptureDevice *backCamera;
@property(readonly, nonatomic, strong, nullable) AVCaptureDevice *frontCamera;

@property(readonly, nonatomic, strong, nullable) AVCaptureDevice *camera;
@property(readonly, nonatomic, assign) AVCaptureDevicePosition position;

@property(readonly, nonatomic, nullable) AVCaptureDeviceFormat *captureDeviceFormat;
@property(readonly, nonatomic, nullable) AVCaptureDeviceFormat *depthDataFormat;

@property(readonly, nonatomic, assign) CGFloat videoMaxZoomFactor;
@property(readwrite, nonatomic, assign) CGFloat videoZoomFactor;

- (void)updatePosition:(AVCaptureDevicePosition)position;

- (void)updateVideoZoomFactor:(CGFloat)videoZoomFactor
                     animated:(BOOL)animated
                   completion:(nullable dispatch_block_t)completion;

- (void)updateCaptureDeviceFormat:(nullable AVCaptureDeviceFormat *)captureDeviceFormat
                  depthDataFormat:(nullable AVCaptureDeviceFormat *)depthDataFormat
                      forPosition:(AVCaptureDevicePosition)position;

- (AVCaptureDeviceFormat *)depthDataFormatForFormat:(AVCaptureDeviceFormat *)format;
- (nullable AVCaptureDeviceFormat *)findClosestDeviceFormatByResolution:(CGSize)size forPosition:(AVCaptureDevicePosition)position;

@end

NS_ASSUME_NONNULL_END

//
//  RGLCCameraPhotoCaptureTask.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 8/13/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RGLCCameraPhotoCaptureTask;
@class AVCapturePhotoSettings;
@class UIImage;

NS_ASSUME_NONNULL_BEGIN

typedef void(^RGLCCameraPhotoCaptureTaskWillCapture)(RGLCCameraPhotoCaptureTask * _Nonnull task);
typedef void(^RGLCCameraPhotoCaptureTaskDidCapture)(RGLCCameraPhotoCaptureTask * _Nonnull task, UIImage * _Nullable image, NSError * _Nullable error);

@interface RGLCCameraPhotoCaptureTask : NSObject

@property(readonly, nonatomic, strong, nullable) NSData *jpegData;

@property(readonly, nonatomic, strong, nullable) RGLCCameraPhotoCaptureTaskWillCapture willCaptureBlock;
@property(readonly, nonatomic, strong, nullable) RGLCCameraPhotoCaptureTaskDidCapture didFinishBlock;
@property(readwrite, nonatomic, strong, nonnull) AVCapturePhotoSettings *photoSettings;

- (instancetype)initWithWillCapture:(nullable RGLCCameraPhotoCaptureTaskWillCapture)willCaptureBlock
                   didFinishCapture:(nullable RGLCCameraPhotoCaptureTaskDidCapture)didFinishBlock;

@end

NS_ASSUME_NONNULL_END

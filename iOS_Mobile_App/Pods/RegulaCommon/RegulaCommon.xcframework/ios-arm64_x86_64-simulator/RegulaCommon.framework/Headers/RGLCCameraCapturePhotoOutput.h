//
//  RGLCCameraCapturePhotoOutput.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/9/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RGLCCameraPhotoCaptureTask;
@class AVCapturePhotoOutput;
@class AVCapturePhotoSettings;
@class UIImage;

NS_ASSUME_NONNULL_BEGIN

@interface RGLCCameraCapturePhotoOutput : NSObject

@property(readonly, nonatomic, strong, nonnull) AVCapturePhotoOutput *photoOutput;

- (void)capturePhotoWithTask:(nonnull RGLCCameraPhotoCaptureTask *)task;
- (void)capturePhotoWithSettings:(nonnull AVCapturePhotoSettings *)settings
                      completion:(void(^)(UIImage * _Nullabe, NSError * _Nullable))completion;
- (void)capturePhotoWithCompletion:(void(^)(UIImage * _Nullabe, NSError * _Nullable))completion;

@end


NS_ASSUME_NONNULL_END

//
//  RGLCCameraConfiguration.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 8/17/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class AVCaptureVideoDataOutput;
@class AVCaptureAudioDataOutput;
@class AVCaptureDevice;

NS_ASSUME_NONNULL_BEGIN

typedef void(^RGLCCameraCaptureDeviceConfigurationBlock)(AVCaptureDevice * _Nonnull camera, AVCaptureDevicePosition position);
typedef void(^RGLCCameraDeviceOutputVideoConfigurationBlock)(AVCaptureVideoDataOutput * _Nonnull video);
typedef void(^RGLCCameraDeviceOutputAudioConfigurationBlock)(AVCaptureAudioDataOutput * _Nonnull audio);
typedef void(^RGLCCameraDeviceOutputDepthDataConfigurationBlock)(AVCaptureDepthDataOutput * _Nonnull depth);

@interface RGLCCameraConfiguration : NSObject

/// Defines, wheter the DeviceOutput uses AVCaptureDataOutputSynchronizer to sync the outputs. Defaults to `false`.
/// The video output acts as a master output.
/// @see `AVCaptureDataOutputSynchronizer`.
@property(readwrite, nonatomic, assign, getter=isDataOutputSynchronizationEnabled) BOOL dataOutputSynchronizationEnabled;

/// Defines, wheter the AVCaptureDepthDataOutput is added to the capture session. Defaults to `false`.
@property(readwrite, nonatomic, assign, getter=isDepthDataOutputEnabled) BOOL depthDataOutputEnabled;

/// Defines, wheter the `activeDepthDataFormat` for `AVCaptureDevice` is autimatically selected
/// based on highest resolution when new format is set with `setCaptureDeviceFormat`. Defaults to `false`.
@property(readwrite, nonatomic, assign) BOOL shouldAutomaticallySelectDepthDataFormat;

/// Defines, wheter the RGLCCamera will automatically try to decrease the video framerate when it encounters a drop in frames. Defaults to `false`
@property(readwrite, nonatomic, assign) BOOL shouldAutomaticallyDecreaseFramerate;

@property(readwrite, nonatomic, copy, nullable) RGLCCameraCaptureDeviceConfigurationBlock captureConfiguration;
@property(readwrite, nonatomic, copy, nullable) RGLCCameraDeviceOutputVideoConfigurationBlock videoConfiguration;
@property(readwrite, nonatomic, copy, nullable) RGLCCameraDeviceOutputAudioConfigurationBlock audioConfiguration;
@property(readwrite, nonatomic, copy, nullable) RGLCCameraDeviceOutputDepthDataConfigurationBlock depthConfiguration;

@end

NS_ASSUME_NONNULL_END

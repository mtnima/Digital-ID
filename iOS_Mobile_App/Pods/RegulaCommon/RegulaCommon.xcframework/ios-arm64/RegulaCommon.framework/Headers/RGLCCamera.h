//
//  RGLCCamera.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/2/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class RGLCCameraPreviewView;
@class RGLCCameraDevice;
@class RGLCCameraOutput;
@class RGLCCameraPhotoCaptureTask;
@class RGLCCameraConfiguration;

NS_ASSUME_NONNULL_BEGIN

typedef void (^RGLCCapturePhotoCompletion)(UIImage * _Nullable, NSError * _Nullable);

FOUNDATION_EXPORT NSErrorDomain const RGLCCameraErrorDomain;
typedef NS_ERROR_ENUM(RGLCCameraErrorDomain, RGLCCameraError) {
    RGLCCameraErrorPermissionNotAuthorized,
    RGLCCameraErrorPermissionNotDetermined,
};

@interface RGLCCamera : NSObject

@property(readonly, nonatomic, strong) AVCaptureSession *session;
@property(readonly, nonatomic, strong, nonnull) RGLCCameraPreviewView *previewView;
@property(readonly, nonatomic, strong, nonnull) RGLCCameraDevice *device;
@property(readonly, nonatomic, strong, nonnull) RGLCCameraOutput *output;

@property(readwrite, nonatomic, assign) AVCaptureDevicePosition currentDevicePosition;
@property(readonly, nonatomic, assign, getter=isTorchAvailable) BOOL torchAvailable;
@property(readwrite, nonatomic, assign) AVCaptureTorchMode torchMode;
@property(readwrite, nonatomic, assign, getter=isRotationEnabled) BOOL rotationEnabled;
@property(readwrite, nonatomic, assign) AVCaptureSessionPreset sessionPreset;
@property(readwrite, nonatomic, assign) CGFloat videoZoomFactor;

/// Called when an unexpected error occurs while an AVCaptureSession instance is running.
@property(readwrite, nonatomic, copy, nullable) void (^onDidRecieveRuntimeError)(RGLCCamera * _Nonnull, NSError * _Nonnull);

/// An instance of AVCaptureSession starts running. Will be also called after `onInterrupted`.
@property(readwrite, nonatomic, copy, nullable) void (^onDidStartRunning)(RGLCCamera * _Nonnull);

/// An AVCaptureSession instance may stop running automatically due to external system conditions,
/// such as the device going to sleep, or being locked by a user.
/// Will be also called after `onInterrupted`.
@property(readwrite, nonatomic, copy, nullable) void (^onDidStopRunning)(RGLCCamera * _Nonnull);

/// An AVCaptureSession may be interrupted, for example, by an incoming phone call, or alarm, or another application taking control of needed hardware resources. When appropriate, the AVCaptureSession instance will stop running automatically in response to an interruption.
/// Contains an AVCaptureSessionInterruptionReasonKey indicating the reason for the interruption.
@property(readwrite, nonatomic, copy, nullable) void (^onInterrupted)(RGLCCamera * _Nonnull, AVCaptureSessionInterruptionReason);

/// An AVCaptureSession ceases to be interrupted, for example, when a phone call ends, and hardware resources needed to run the session are again available. When appropriate, the AVCaptureSession instance that was previously stopped in response to an interruption will automatically restart once the interruption ends.
@property(readwrite, nonatomic, copy, nullable) void (^onInterruptionEnded)(RGLCCamera * _Nonnull);

/// Wraps `AVCaptureDeviceSubjectAreaDidChangeNotification`.
/// Called when the instance of AVCaptureDevice has detected a substantial change to the video subject area.
/// This callback is only sent if you first set subjectAreaChangeMonitoringEnabled to YES
@property(readwrite, nonatomic, copy, nullable) void (^onCaptureDeviceSubjectAreaDidChange)(RGLCCamera * _Nonnull, AVCaptureDevice * _Nonnull);

- (instancetype)initWithConfiguration:(RGLCCameraConfiguration *)configuration NS_DESIGNATED_INITIALIZER;

- (BOOL)start:(NSError * _Nullable *)error;
- (void)stop;

- (void)updateCaptureDeviceFormat:(nullable AVCaptureDeviceFormat *)captureDeviceFormat
                  depthDataFormat:(nullable AVCaptureDeviceFormat *)depthDataFormat
                      forPosition:(AVCaptureDevicePosition)position;

- (void)focusAtPoint:(CGPoint)point;
- (void)focusAtPoint:(CGPoint)point continuousAuto:(BOOL)continuousAuto;

- (void)toggleDevicePosition;
- (void)updateVideoZoomFactor:(CGFloat)zoomFactor animated:(BOOL)animated completion:(nullable dispatch_block_t)completion;

- (void)capturePhoto:(AVCapturePhotoSettings *)settings completion:(RGLCCapturePhotoCompletion)completion;
- (void)capturePhoto:(RGLCCapturePhotoCompletion)completion;
- (void)capturePhotoWithTask:(RGLCCameraPhotoCaptureTask *)task;

/// Calculates object height in points relative to the previewView bounds based on given distance from the camera to the object,
/// real object height and active device format used for capture.
/// @param distance Distance to the real object. Units must match @p objectHeight (e.g. cm)
/// @param objectHeight Real object height. Units must match @p distance (e.g. cm)
/// @param focalLength Focal length of currently active @c AVCaptureDeviceFormat
/// @param cameraScale videoZoomFactor of the camere
- (CGFloat)objectHeightOnPreviewForDistance:(float)distance
                           realObjectHeight:(float)objectHeight
                                focalLength:(float)focalLength
                                cameraScale:(float)cameraScale;

/// Calculates videoZoomFactor for camera to fit given object height in objectPreviewHeight given real object height and distance from the camera to the object,
/// real object height and active device format used for capture.
/// @param distance Distance to the real object. Units must match @p objectHeight (e.g. cm)
/// @param objectPreviewHeight object height in points relative to the previewView bounds
/// @param realObjectHeight Real object height. Units must match @p distance (e.g. cm)
/// @param focalLengthMM Focal length of currently active @c AVCaptureDeviceFormat.
- (CGFloat)cameraZoomForDistance:(float)distance
             objectPreviewHeight:(float)objectPreviewHeight
                realObjectHeight:(float)realObjectHeight
                     focalLength:(float)focalLengthMM;

+ (BOOL)cameraPermissionGranted;
+ (void)requestCameraPermission:(void (^)(BOOL granted))completionBlock;

@end

NS_ASSUME_NONNULL_END

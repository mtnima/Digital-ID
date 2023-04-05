//
//  RGLCCameraOutput.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/7/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

@class RGLCCameraCapturePhotoOutput;
@class RGLCCameraSampleBufferPlugin;
@class RGLCCameraMetadataPlugin;
@class RGLCCameraSynchronizedDataPlugin;
@class RGLCCameraPhotoCaptureTask;
@class RGLCCameraConfiguration;

@class AVCaptureMetadataOutput;
@class AVCaptureVideoDataOutput;
@class AVCaptureAudioDataOutput;
@class AVCaptureDepthDataOutput;
@class AVCaptureSession;
@class AVCapturePhotoSettings;
@class UIImage;

NS_ASSUME_NONNULL_BEGIN

@interface RGLCCameraOutput : NSObject

@property(readonly, nonatomic, strong, nonnull) RGLCCameraCapturePhotoOutput *imageOutput;
@property(nonatomic, readwrite, strong, nonnull) AVCaptureMetadataOutput *metadataOutput;
@property(readonly, nonatomic, strong, nonnull) AVCaptureVideoDataOutput *videoOutput;
@property(readonly, nonatomic, strong, nonnull) AVCaptureAudioDataOutput *audioOutput;
@property(readonly, nonatomic, strong, nonnull) AVCaptureDepthDataOutput *depthDataOutput;

@property(readwrite, nonatomic, strong, nonnull) NSArray<AVMetadataObjectType> *selectedMetadataObjectTypes;

- (instancetype)initWithConfiguration:(RGLCCameraConfiguration *)configuration NS_DESIGNATED_INITIALIZER;

- (void)setupCaptureOutput:(nonnull AVCaptureSession *)session queue:(dispatch_queue_t)queue;

- (void)capturePhotoWithTask:(nonnull RGLCCameraPhotoCaptureTask *)task;
- (void)capturePhotoWithSettings:(nonnull AVCapturePhotoSettings *)settings
                      completion:(void(^)(UIImage * _Nullabe, NSError * _Nullable))completion;
- (void)capturePhotoWithCompletion:(void(^)(UIImage * _Nullabe, NSError * _Nullable))completion;

- (void)addMetadataPlugin:(nonnull RGLCCameraMetadataPlugin *)plugin forKey:(nonnull NSString *)key;
- (void)removeMetadataPluginForKey:(nonnull NSString *)key;

- (void)addSynchronizedDataPlugin:(nonnull RGLCCameraSynchronizedDataPlugin *)plugin forKey:(nonnull NSString *)key;
- (void)removedSynchronizedDataPlugin:(nonnull NSString *)key;

- (void)addSampleBufferPlugin:(nonnull RGLCCameraSampleBufferPlugin *)plugin forKey:(nonnull NSString *)key;
- (void)removeSampleBufferPluginForKey:(nonnull NSString *)key;

@end

NS_ASSUME_NONNULL_END

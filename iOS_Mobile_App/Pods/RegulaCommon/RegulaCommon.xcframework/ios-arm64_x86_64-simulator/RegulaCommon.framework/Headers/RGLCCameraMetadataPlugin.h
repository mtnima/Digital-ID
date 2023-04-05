//
//  RGLCCameraMetadataPlugin.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/12/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AVCaptureVideoPreviewLayer;

@interface RGLCCameraMetadataPlugin : NSObject

@property(readonly, nonatomic, strong, nullable) AVCaptureVideoPreviewLayer *previewLayer;
@property(readwrite, nonatomic, copy, nullable) void (^onMetadataObjectsOutput)(AVCaptureMetadataOutput * _Nonnull, NSArray<AVMetadataObject *> *_Nonnull);

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPreviewLayer:(nullable AVCaptureVideoPreviewLayer *)previewLayer;

- (void)sendOutputMetadataObjects:(nonnull AVCaptureMetadataOutput *)output
                          objects:(nonnull NSArray<__kindof AVMetadataObject *> *)metadataObjects;

@end

NS_ASSUME_NONNULL_END

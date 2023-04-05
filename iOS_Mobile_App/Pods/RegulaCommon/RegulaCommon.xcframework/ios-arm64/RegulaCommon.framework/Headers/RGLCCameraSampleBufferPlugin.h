//
//  RGLCCameraSampleBufferPlugin.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/12/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AVCaptureOutput;

@interface RGLCCameraSampleBufferPlugin : NSObject

@property(readwrite, nonatomic, copy, nullable) void(^onSampleBufferOutput)(AVCaptureOutput * _Nonnull, CMSampleBufferRef);
@property(readwrite, nonatomic, copy, nullable) void(^onSampleBufferDrop)(AVCaptureOutput * _Nonnull, CMSampleBufferRef);

- (void)sendOutputSampleBuffer:(nonnull AVCaptureOutput *)output sampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (void)sendDidDropSampleBuffer:(nonnull AVCaptureOutput *)output sampleBuffer:(CMSampleBufferRef)sampleBuffer;

@end

NS_ASSUME_NONNULL_END

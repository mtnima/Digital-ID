//
//  RGLCCameraSynchronizedDataPlugin.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 15/12/2021.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@class AVDepthData;
@class AVMetadataObject;

@interface RGLCCameraSynchronizedData : NSObject

@property(nonatomic, readonly, assign) CMSampleBufferRef videoSampleBuffer;
@property(nonatomic, readonly, assign) CMSampleBufferRef audioSampleBuffer;
@property(nonatomic, readonly, strong, nonnull) NSArray<AVMetadataObject *> *metadataObjects;
@property(nonatomic, readonly, strong, nullable) AVDepthData *depthData;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithVideoSampleBuffer:(CMSampleBufferRef)videoSampleBuffer
                        audioSampleBuffer:(CMSampleBufferRef)audioSampleBuffer
                          metadataObjects:(nullable NSArray<AVMetadataObject *> *)metadataObjects
                                depthData:(nullable AVDepthData *)depthData NS_DESIGNATED_INITIALIZER;

@end

@interface RGLCCameraSynchronizedDataPlugin : NSObject

@property(readwrite, nonatomic, copy, nullable) void (^onSynchoronizedDataOutput)(RGLCCameraSynchronizedData * _Nonnull);

- (void)sendOutputSynchronizedData:(nonnull RGLCCameraSynchronizedData *)data;

@end

NS_ASSUME_NONNULL_END

//
//  RGLCCameraMetadataDetectFacesPlugin.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/11/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <RegulaCommon/RGLCCameraMetadataPlugin.h>

NS_ASSUME_NONNULL_BEGIN

@class AVMetadataFaceObject;

@interface RGLCCameraMetadataDetectFacesPlugin : RGLCCameraMetadataPlugin

@property(readwrite, nonatomic, copy, nullable) void (^onDetectFaces)(AVCaptureMetadataOutput * _Nonnull, NSArray<AVMetadataFaceObject *> *_Nonnull);

@end

NS_ASSUME_NONNULL_END

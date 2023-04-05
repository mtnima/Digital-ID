//
//  RGLCCameraPreviewView.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/2/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class AVCaptureSession;
@class AVCaptureVideoPreviewLayer;

@interface RGLCCameraPreviewView : UIView

@property(readonly, nonatomic, strong, nonnull) AVCaptureVideoPreviewLayer *previewLayer;
@property(readwrite, nonatomic, strong, nullable) AVCaptureSession *session;

@end

NS_ASSUME_NONNULL_END

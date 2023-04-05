//
//  AVCaptureConnection+RGLCUIDeviceOrientation.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/9/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface AVCaptureConnection (RGLCUIDeviceOrientation)

/// Converts UIDeviceOrientation to AVCaptureVideoOrientation
+ (AVCaptureVideoOrientation)rglc_videoOrientationFrom:(UIDeviceOrientation)orientation;

@end

NS_ASSUME_NONNULL_END

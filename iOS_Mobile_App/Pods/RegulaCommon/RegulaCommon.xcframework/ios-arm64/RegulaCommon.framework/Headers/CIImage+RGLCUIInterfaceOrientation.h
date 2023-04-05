//
//  CIImage+RGLCUIInterfaceOrientation.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/9/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <CoreImage/CoreImage.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RGLCCIImageOrientation) {
    /// 0th row is at the top, and 0th column is on the left.
    RGLCCIImageOrientationTopLeft = 1,
    /// 0th row is at the top, and 0th column is on the right.
    RGLCCIImageOrientationTopRight = 2,
    /// 0th row is at the bottom, and 0th column is on the right.
    RGLCCIImageOrientationBottomRight = 3,
    /// 0th row is at the bottom, and 0th column is on the left.
    RGLCCIImageOrientationBottomLeft = 4,
    /// 0th row is on the left, and 0th column is the top.
    RGLCCIImageOrientationLeftTop = 5,
    /// 0th row is on the right, and 0th column is the top.
    RGLCCIImageOrientationRightTop = 6,
    /// 0th row is on the right, and 0th column is the bottom.
    RGLCCIImageOrientationRightBottom = 7,
    /// 0th row is on the left, and 0th column is the bottom.
    RGLCCIImageOrientationLeftBottom = 8,
};

@interface CIImage (RGLCUIInterfaceOrientation)

/// Changes Image orientation to match given UIInterfaceOrientation.
- (nullable CIImage *)rglc_applyingUIInterfaceOrientation:(UIInterfaceOrientation)orientation;

/// Converts UIInterfaceOrientation to CIImage orientation (exif orientation).
/// See more at: https://www.awaresystems.be/imaging/tiff/tifftags/orientation.html
+ (RGLCCIImageOrientation)rglc_imageOrientationFromUIInterfaceOrienation:(UIInterfaceOrientation)orientation;

@end

NS_ASSUME_NONNULL_END

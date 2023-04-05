//
//  RGLImageQualityCheckType.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 25/03/2022.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * RGLImageQualityCheckType NS_TYPED_ENUM NS_SWIFT_NAME(ImageQualityCheckType);

/// Glares presence check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeImageGlares;

/// Focus quality check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeImageFocus;

/// Image resolution check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeImageResolution;

/// Image colorness check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeImageColorness;

/// Image perspective check, i.e. the deviation of the corners of the document from the value of 90 degrees is checked.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeImagePerspective;

/// Image quality check if the whole document page is completely within the image.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeImageBounds;

/// Image moire check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeScreenCapture;

/// Portrait image check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypePortrait;

/// Handwritten image check.
FOUNDATION_EXPORT RGLImageQualityCheckType const RGLImageQualityCheckTypeHandwritten;

FOUNDATION_EXPORT NSString *RGLImageQualityCheckTypeGetStringValue(RGLImageQualityCheckType type) CF_SWIFT_NAME(getter:ImageQualityCheckType.stringValue(self:));

NS_ASSUME_NONNULL_END

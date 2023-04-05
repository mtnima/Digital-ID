//
//  RGLGlaresCheckParams.h
//  DocumentReader
//
//  Created by Serge Rylko on 20.09.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ImageQA.GlaresCheckParams)
@interface RGLGlaresCheckParams : NSObject

/// Part of margin from the edges of the image that is ignored by glares check.
/// Type: Double.
/// Example: value 0.07 is 7% of image area is ignored .
@property (nonatomic, strong, nullable) NSNumber *imgMarginPart;

/// The maximum allowable part of glared area.
/// Type: Double.
/// Example: value 0.1 is 10% allowed.
@property (nonatomic, strong, nullable) NSNumber *maxGlaringPart;

@end

NS_ASSUME_NONNULL_END

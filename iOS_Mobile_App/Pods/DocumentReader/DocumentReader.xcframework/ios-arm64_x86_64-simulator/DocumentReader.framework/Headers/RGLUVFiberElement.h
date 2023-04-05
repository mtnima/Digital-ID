//
//  RGLUVFiberElement.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 24/02/2022.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RGLAuthenticityElement.h"
#import "RGLCheckResult.h"
#import "RGLMacros.h"

NS_ASSUME_NONNULL_BEGIN

@class RGLElementRect;

/// The results of checking of fluorescent fibers type for UV light image.
NS_SWIFT_NAME(UVFiberElement)
@interface RGLUVFiberElement : RGLAuthenticityElement

/// The number of `rectArray`, `width`, `length` and `area` items.
@property(nonatomic, readonly, assign) uint32_t rectCount;

/// Coordinates of located areas for defined fibers type.
@property(nonatomic, readonly, copy, nonnull) NSArray<RGLElementRect *> *rectArray;

/// The fiber's width value for RectArray areas in pixels.
@property(nonatomic, readonly, copy, nonnull) NSArray<NSNumber *> *width;

/// The fiber's length value for RectArray areas in pixels.
@property(nonatomic, readonly, copy, nonnull) NSArray<NSNumber *> *length;

/// The fiber's area value for RectArray areas in pixels.
@property(nonatomic, readonly, copy, nonnull) NSArray<NSNumber *> *area;

/// The fiber's colors `B`, `G`, `R`.
@property(nonatomic, readonly, copy, nonnull) NSArray<NSNumber *> *colorValues;

/// Expected fibers number.
@property(nonatomic, readonly, assign) uint32_t expectedCount;

RGL_EMPTY_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END

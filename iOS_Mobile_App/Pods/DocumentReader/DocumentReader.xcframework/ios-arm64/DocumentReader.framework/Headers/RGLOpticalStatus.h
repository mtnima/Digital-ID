//
//  RGLOpticalStatus.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 11/5/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RGLMacros.h"
#import "RGLCheckResult.h"

NS_ASSUME_NONNULL_BEGIN

/// Container for an optical related scanning statuses.
NS_SWIFT_NAME(OpticalStatus)
@interface RGLOpticalStatus : NSObject

/// Summary of all optical results.
@property(nonatomic, readonly, assign) RGLCheckResult overallStatus;

/// MRZ verification: values validity, dates, checkdigits verification.
@property(nonatomic, readonly, assign) RGLCheckResult mrz;

/// Text fields valitity: values validity for specific fields, cross-comparison of values from different sources, dates & checkdigits verification.
@property(nonatomic, readonly, assign) RGLCheckResult text;

/// Check status if document type was recognized or not.
@property(nonatomic, readonly, assign) RGLCheckResult docType;

/// Authenticity verification status.
@property(nonatomic, readonly, assign) RGLCheckResult security;

/// Input images quality verification status.
@property(nonatomic, readonly, assign) RGLCheckResult imageQA;

/// Document validity period verification status.
@property(nonatomic, readonly, assign) RGLCheckResult expiry;

/// Visible Digital Seal verification status.
@property(nonatomic, readonly, assign) RGLCheckResult vds;

/// Number of scanned document pages.
@property(nonatomic, readonly, assign) NSInteger pagesCount;

RGL_EMPTY_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END

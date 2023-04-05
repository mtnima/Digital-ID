//
//  RGLCheckResult.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 11/5/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLCheckResult) {
    /// Check was not passed, the controlled parameter is not permitted
    RGLCheckResultError = 0,
    /// Check was passed, the controlled parameter is permitted
    RGLCheckResultOk = 1,
    /// Check was not carried out
    RGLCheckResultWasNotDone = 2
} NS_SWIFT_NAME(CheckResult);

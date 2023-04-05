//
//  NSError+RGLCAdditions.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 11/19/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (RGLCAdditions)

- (nullable NSError *)rglc_firstErrorWithDomain:(nonnull NSErrorDomain)domain;
- (nullable NSError *)rglc_underlyingError;

@end

NS_ASSUME_NONNULL_END

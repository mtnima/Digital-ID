//
//  NSBundle+RGLCSDKBundle.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 6/17/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSBundle (RGLCSDKBundle)

@property(readonly, nonatomic, nullable, class) NSBundle *rglc_sdkBundle;

@end

NS_ASSUME_NONNULL_END

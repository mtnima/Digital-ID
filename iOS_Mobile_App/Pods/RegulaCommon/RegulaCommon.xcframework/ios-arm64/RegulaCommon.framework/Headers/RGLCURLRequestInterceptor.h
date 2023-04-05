//
//  RGLCURLRequestInterceptor.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 3/26/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class NSURLRequest;

typedef NSURLRequest * _Nullable (^RGLCInterceptorPrepare)(NSURLRequest * _Nonnull request);

@interface RGLCURLRequestInterceptor : NSObject

@property(readwrite, nonatomic, copy, nullable) RGLCInterceptorPrepare prepare;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithPrepare:(nullable RGLCInterceptorPrepare)prepare NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

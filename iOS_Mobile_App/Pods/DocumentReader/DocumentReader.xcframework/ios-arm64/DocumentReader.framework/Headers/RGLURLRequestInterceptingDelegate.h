//
//  RGLURLRequestInterceptingDelegate.h
//  DocumentReader
//
//  Created by Dmitry Evglevsky on 20.06.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Delegate for intercepting URL requests.
NS_SWIFT_NAME(DocReader.URLRequestInterceptingDelegate)
@protocol RGLURLRequestInterceptingDelegate <NSObject>

@required

/// Prepares `URLRequest` before sending it to the service.
- (NSURLRequest * _Nullable)interceptorPrepareRequest:(NSURLRequest * _Nonnull)request;

@end

NS_ASSUME_NONNULL_END

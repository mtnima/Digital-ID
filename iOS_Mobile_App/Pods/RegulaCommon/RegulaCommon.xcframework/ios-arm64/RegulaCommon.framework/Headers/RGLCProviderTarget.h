//
//  RGLCProviderTarget.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 11/3/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <RegulaCommon/RGLCProviderHTTPMethod.h>
#import <RegulaCommon/RGLCProviderTask.h>

NS_ASSUME_NONNULL_BEGIN

/// The protocol used to specify request configuration for a `RGLCProvider`.
NS_SWIFT_NAME(ProviderTarget)
@protocol RGLCProviderTarget <NSObject>

@required

/// The target's base `URL`. Required to be not `nil`.
@property(readonly, nonatomic, copy, nonnull) NSURL *baseURL;

/// The path to be appended to `baseURL` to form the full `URL`. Required to be not `nil`.
@property(readonly, nonatomic, copy, nonnull) NSString *path;

/// The query parameters to be added to `path`.
@property(readonly, nonatomic, strong, nullable) NSDictionary<NSString *, id> *urlParameters;

/// The HTTP method used in the request.
@property(readonly, nonatomic, assign) RGLCProviderHTTPMethod method;

/// The type of HTTP task to be performed. Required to be not `nil`.
@property(readonly, nonatomic, strong, nonnull) RGLCProviderTask *task;

/// The headers to be used in the request.
@property(readonly, nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *headers;

@end

NS_ASSUME_NONNULL_END

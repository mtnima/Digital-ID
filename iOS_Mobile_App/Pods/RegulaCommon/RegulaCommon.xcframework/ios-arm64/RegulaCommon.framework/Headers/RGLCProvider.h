//
//  RGLCProvider.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 4/19/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <RegulaCommon/RGLCProviderTarget.h>

@class RGLCURLSessionManager;

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const RGLCProviderErrorDomain;

typedef NS_ERROR_ENUM(RGLCProviderErrorDomain, RGLCProviderErrorCode) {
    /// Failed to create `NSURLRequest` from given `RGLCProviderTarget`. See underlying error `RGLCProviderTaskRequestSerializerErrorDomain`.
    RGLCProviderErrorRequestSerializationFailed,

    /// Failed to serialize networking response. See underlying error `RGLResponseSerializationErrorDomain`.
    RGLCProviderErrorResponseSerializationFailed,
    
    /// `NSHTTPURLResponse` has `statusCode` which is not specified by `acceptableStatusCodes`.
    RGLCProviderErrorStatusCode,

    /// `NSHTTPURLResponse` has `MIMEType` which is not specified by `acceptableContentTypes`.
    RGLCProviderErrorContentType,

    /// Decoding `NSData` returned by a response as `JSON` failed.
    RGLCProviderErrorJSONDecoding,

    /// Underlying `NSURLSession` completed request with an error. See an underlying error.
    RGLCProviderErrorUnderlying,
} NS_SWIFT_NAME(ProviderError);

NS_SWIFT_NAME(Provider)
@interface RGLCProvider : NSObject

/// Overrides a `baseURL` specified in target before sending a request.
@property(nonatomic, readwrite, copy, nullable) NSURL *overrideURL;

/// The acceptable HTTP status codes for responses.
/// When non-`nil`, responses with status codes not contained by the set will result in an error during validation.
/// For more information see http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
@property(nonatomic, copy, nullable) NSIndexSet *acceptableStatusCodes;


/// The acceptable MIME types for responses.
/// When non-`nil`, responses with a `Content-Type` with MIME types that do not intersect with the set will result in an error during validation.
@property(nonatomic, copy, nullable) NSSet <NSString *> *acceptableContentTypes;

/// Sends a networking request specified by `target`.
///
/// @param completion The block to call after the networking response or error. The block is called with either `response` or `error` not both.
/// `response` contains either `NSArray` or `NSDictionary` as a representation of JSON decoded response.
/// `error` contains the information about failure reason. Guaranteed to be of `RGLCProviderErrorDomain` domain.
/// Always called on the main queue.
- (void)request:(nonnull id<RGLCProviderTarget>)target completion:(nullable void(^)(id _Nullable response, NSError * _Nullable error))completion;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithSession:(RGLCURLSessionManager *)session NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

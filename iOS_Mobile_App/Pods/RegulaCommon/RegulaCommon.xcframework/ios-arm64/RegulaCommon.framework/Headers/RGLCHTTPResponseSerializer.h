//
//  RGLCHTTPResponseSerializer.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 5/22/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <RegulaCommon/RGLCURLResponseSerialization.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const RGLCNetworkingErrorFailingURLKey;
FOUNDATION_EXPORT NSString * const RGLCNetworkingErrorFailingURLResponseKey;
FOUNDATION_EXPORT NSString * const RGLCNetworkingErrorFailingURLResponseDataKey;

FOUNDATION_EXPORT NSErrorDomain const RGLResponseSerializationErrorDomain;
typedef NS_ERROR_ENUM(RGLResponseSerializationErrorDomain, RGLResponseSerializationErrorCode) {
    /// `NSHTTPURLResponse` has `statusCode` which is not specified by `acceptableStatusCodes`.
    RGLResponseSerializationErrorStatusCode = 0,

    /// `NSHTTPURLResponse` has `MIMEType` which is not specified by `acceptableContentTypes`.
    RGLResponseSerializationErrorContentType = 1,

    /// Decoding `NSData` returned by a response as `JSON` failed.
    RGLResponseSerializationErrorJSONDecoding = 2,
} NS_SWIFT_NAME(ResponseSerializationError);

/**
 `RGLCHTTPResponseSerializer` conforms to the `RGLCURLRequestSerialization` & `RGLCURLResponseSerialization` protocols, offering a concrete base implementation of query string / URL form-encoded parameter serialization and default request headers, as well as response status code and content type validation.

 Any request or response serializer dealing with HTTP is encouraged to subclass `RGLCHTTPResponseSerializer` in order to ensure consistent default behavior.
 */
@interface RGLCHTTPResponseSerializer : NSObject <RGLCURLResponseSerialization>

- (instancetype)init;

/**
 Creates and returns a serializer with default configuration.
 */
+ (instancetype)serializer;

///-----------------------------------------
/// @name Configuring Response Serialization
///-----------------------------------------

/**
 The acceptable HTTP status codes for responses. When non-`nil`, responses with status codes not contained by the set will result in an error during validation.

 See http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html
 */
@property (nonatomic, copy, nullable) NSIndexSet *acceptableStatusCodes;

/**
 The acceptable MIME types for responses. When non-`nil`, responses with a `Content-Type` with MIME types that do not intersect with the set will result in an error during validation.
 */
@property (nonatomic, copy, nullable) NSSet <NSString *> *acceptableContentTypes;

/**
 Validates the specified response and data.

 In its base implementation, this method checks for an acceptable status code and content type. Subclasses may wish to add other domain-specific checks.

 @param response The response to be validated.
 @param data The data associated with the response.
 @param error The error that occurred while attempting to validate the response.

 @return `YES` if the response is valid, otherwise `NO`.
 */
- (BOOL)validateResponse:(nullable NSHTTPURLResponse *)response
                    data:(nullable NSData *)data
                   error:(NSError * _Nullable __autoreleasing *)error;

@end

/**
 `RGLCJSONResponseSerializer` is a subclass of `RGLCHTTPResponseSerializer` that validates and decodes JSON responses.

 By default, `RGLCJSONResponseSerializer` accepts the following MIME types, which includes the official standard, `application/json`, as well as other commonly-used types:

 - `application/json`
 - `text/json`
 - `text/javascript`

 In RFC 7159 - Section 8.1, it states that JSON text is required to be encoded in UTF-8, UTF-16, or UTF-32, and the default encoding is UTF-8. NSJSONSerialization provides support for all the encodings listed in the specification, and recommends UTF-8 for efficiency. Using an unsupported encoding will result in serialization error. See the `NSJSONSerialization` documentation for more details.
 */
@interface RGLCJSONResponseSerializer : RGLCHTTPResponseSerializer

- (instancetype)init;

/**
 Options for reading the response JSON data and creating the Foundation objects. For possible values, see the `NSJSONSerialization` documentation section "NSJSONReadingOptions". `0` by default.
 */
@property (nonatomic, assign) NSJSONReadingOptions readingOptions;

/**
 Whether to remove keys with `NSNull` values from response JSON. Defaults to `NO`.
 */
@property (nonatomic, assign) BOOL removesKeysWithNullValues;

/**
 Creates and returns a JSON serializer with specified reading and writing options.

 @param readingOptions The specified JSON reading options.
 */
+ (instancetype)serializerWithReadingOptions:(NSJSONReadingOptions)readingOptions;

@end

NS_ASSUME_NONNULL_END

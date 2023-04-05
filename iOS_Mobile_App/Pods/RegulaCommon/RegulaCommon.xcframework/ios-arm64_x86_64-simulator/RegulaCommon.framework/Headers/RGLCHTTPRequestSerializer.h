//
//  RGLCHTTPRequestSerializer.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 5/22/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <RegulaCommon/RGLCURLRequestSerialization.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Returns a percent-escaped string following RFC 3986 for a query string key or value.
 RFC 3986 states that the following characters are "reserved" characters.
 - General Delimiters: ":", "#", "[", "]", "@", "?", "/"
 - Sub-Delimiters: "!", "$", "&", "'", "(", ")", "*", "+", ",", ";", "="

 In RFC 3986 - Section 3.4, it states that the "?" and "/" characters should not be escaped to allow
 query strings to include a URL. Therefore, all "reserved" characters with the exception of "?" and "/"
 should be percent-escaped in the query string.

 @param string The string to be percent-escaped.

 @return The percent-escaped string.
 */
FOUNDATION_EXPORT NSString * RGLCPercentEscapedStringFromString(NSString *string);

/**
 A helper method to generate encoded url query parameters for appending to the end of a URL.

 @param parameters A dictionary of key/values to be encoded.

 @return A url encoded query string
 */
FOUNDATION_EXPORT NSString * RGLCQueryStringFromParameters(NSDictionary *parameters);

@interface RGLCHTTPRequestSerializer : NSObject <RGLCURLRequestSerialization>

/**
 The string encoding used to serialize parameters. `NSUTF8StringEncoding` by default.
 */
@property(nonatomic, assign) NSStringEncoding stringEncoding;

/**
 Whether created requests can use the device’s cellular radio (if present). `YES` by default.

 @see NSMutableURLRequest -setAllowsCellularAccess:
 */
@property(nonatomic, assign) BOOL allowsCellularAccess;

/**
 The cache policy of created requests. `NSURLRequestUseProtocolCachePolicy` by default.

 @see NSMutableURLRequest -setCachePolicy:
 */
@property(nonatomic, assign) NSURLRequestCachePolicy cachePolicy;

/**
 Whether created requests should use the default cookie handling. `YES` by default.

 @see NSMutableURLRequest -setHTTPShouldHandleCookies:
 */
@property(nonatomic, assign) BOOL HTTPShouldHandleCookies;

/**
 Whether created requests can continue transmitting data before receiving a response from an earlier transmission. `NO` by default

 @see NSMutableURLRequest -setHTTPShouldUsePipelining:
 */
@property(nonatomic, assign) BOOL HTTPShouldUsePipelining;

/**
 The network service type for created requests. `NSURLNetworkServiceTypeDefault` by default.

 @see NSMutableURLRequest -setNetworkServiceType:
 */
@property(nonatomic, assign) NSURLRequestNetworkServiceType networkServiceType;

/**
 The timeout interval, in seconds, for created requests. The default timeout interval is 60 seconds.

 @see NSMutableURLRequest -setTimeoutInterval:
 */
@property(nonatomic, assign) NSTimeInterval timeoutInterval;

/**
 Default HTTP header field values to be applied to serialized requests. By default, these include the following:

 - `Accept-Language` with the contents of `NSLocale +preferredLanguages`
 - `User-Agent` with the contents of various bundle identifiers and OS designations

 @discussion To add or remove default request headers, use `setValue:forHTTPHeaderField:`.
 */
@property(readonly, nonatomic, strong) NSDictionary <NSString *, NSString *> *HTTPRequestHeaders;

/**
 Creates and returns a serializer with default configuration.
 */
+ (instancetype)serializer;

/**
 Sets the value for the HTTP headers set in request objects made by the HTTP client. If `nil`, removes the existing value for that header.

 @param field The HTTP header to set a default value for
 @param value The value set as default for the specified header, or `nil`
 */
- (void)setValue:(nullable NSString *)value forHTTPHeaderField:(NSString *)field;

/**
 Returns the value for the HTTP headers set in the request serializer.

 @param field The HTTP header to retrieve the default value for

 @return The value set as default for the specified header, or `nil`
 */
- (nullable NSString *)valueForHTTPHeaderField:(NSString *)field;

/**
 HTTP methods for which serialized requests will encode parameters as a query string. `GET`, `HEAD`, and `DELETE` by default.
 */
@property(nonatomic, strong) NSSet <NSString *> *HTTPMethodsEncodingParametersInURI;

/**
 Creates an `NSMutableURLRequest` object with the specified HTTP method and URL string.

 If the HTTP method is `GET`, `HEAD`, or `DELETE`, the parameters will be used to construct a url-encoded query string that is appended to the request's URL. Otherwise, the parameters will be encoded according to the value of the `parameterEncoding` property, and set as the request body.

 @param method The HTTP method for the request, such as `GET`, `POST`, `PUT`, or `DELETE`. This parameter must not be `nil`.
 @param URLString The URL string used to create the request URL.
 @param parameters The parameters to be either set as a query string for `GET` requests, or the request HTTP body.
 @param error The error that occurred while constructing the request.

 @return An `NSMutableURLRequest` object.
 */
- (NSMutableURLRequest *)requestWithMethod:(NSString *)method
                                 URLString:(NSString *)URLString
                                parameters:(nullable id)parameters
                                     error:(NSError * _Nullable __autoreleasing *)error;
@end

/**
 `RGLCJSONRequestSerializer` is a subclass of `RGLCHTTPRequestSerializer` that encodes parameters as JSON using `NSJSONSerialization`, setting the `Content-Type` of the encoded request to `application/json`.
 */
@interface RGLCJSONRequestSerializer : RGLCHTTPRequestSerializer

/**
 Options for writing the request JSON data from Foundation objects. For possible values, see the `NSJSONSerialization` documentation section "NSJSONWritingOptions". `0` by default.
 */
@property (nonatomic, assign) NSJSONWritingOptions writingOptions;

/**
 Creates and returns a JSON serializer with specified reading and writing options.

 @param writingOptions The specified JSON writing options.
 */
+ (instancetype)serializerWithWritingOptions:(NSJSONWritingOptions)writingOptions;

@end

NS_ASSUME_NONNULL_END

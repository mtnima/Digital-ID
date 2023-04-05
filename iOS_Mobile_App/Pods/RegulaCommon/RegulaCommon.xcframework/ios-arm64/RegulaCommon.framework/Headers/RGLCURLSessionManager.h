//
//  RGLCURLSessionManager.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 5/19/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <RegulaCommon/RGLCURLResponseSerialization.h>
#import <RegulaCommon/RGLCURLRequestSerialization.h>
#import <RegulaCommon/RGLCURLRequestInterceptor.h>

/**
 `RGLCURLSessionManager` creates and manages an `NSURLSession` object based on a specified `NSURLSessionConfiguration` object.

 ## Subclassing Notes

 This is the base class for `RGLCHTTPSessionManager`, which adds functionality specific to making HTTP requests. If you are looking to extend `RGLCURLSessionManager` specifically for HTTP, consider subclassing `RGLCHTTPSessionManager` instead.
 */

NS_ASSUME_NONNULL_BEGIN

@interface RGLCURLSessionManager : NSObject <NSURLSessionDelegate>

/**
 The managed session.
 */
@property(readonly, nonatomic, strong) NSURLSession *session;

/**
 The operation queue on which delegate callbacks are run.
 */
@property(readonly, nonatomic, strong) NSOperationQueue *operationQueue;

/**
 Responses sent from the server in data tasks created with `dataTaskWithRequest:success:failure:` and run using the `GET` / `POST` / et al. convenience methods are automatically validated and serialized by the response serializer. By default, this property is set to an instance of `RGLCJSONResponseSerializer`.

 @warning `responseSerializer` must not be `nil`.
 */
@property(nonatomic, strong) id <RGLCURLResponseSerialization> responseSerializer;

/**
 Intercepts incoming requests to the session manager.
 */
@property (readwrite, nonatomic, strong, nullable) RGLCURLRequestInterceptor* requestInterceptor;

/**
 Creates and returns a manager for a session created with the specified configuration. This is the designated initializer.

 @param configuration The configuration used to create the managed session.

 @return A manager for a newly-created session.
 */
- (instancetype)initWithSessionConfiguration:(nullable NSURLSessionConfiguration *)configuration NS_DESIGNATED_INITIALIZER;

/**
 Invalidates the managed session, optionally canceling pending tasks and optionally resets given session.

 @param cancelPendingTasks  Whether or not to cancel pending tasks.
 @param resetSession        Whether or not to reset the session of the manager.
 */
- (void)invalidateSessionCancelingTasks:(BOOL)cancelPendingTasks resetSession:(BOOL)resetSession;

/**
 Creates an `NSURLSessionDataTask` with the specified request.

 @param request The HTTP request for the request.
 @param completionHandler A block object to be executed when the task finishes. This block has no return value and takes three arguments: the server response, the response object created by that serializer, and the error that occurred, if any.
 */
- (NSURLSessionDataTask *)dataTaskWithRequest:(NSURLRequest *)request
                            completionHandler:(nullable void (^)(NSURLResponse *response, id _Nullable responseObject,  NSError * _Nullable error))completionHandler;

- (void)setSessionDidBecomeInvalidBlock:(void (^)(NSURLSession *session, NSError *error))block;
- (void)setSessionDidReceiveAuthenticationChallengeBlock:(nullable NSURLSessionAuthChallengeDisposition (^)(NSURLSession *session, NSURLAuthenticationChallenge *challenge, NSURLCredential * _Nullable __autoreleasing * _Nullable credential))block;

@end

NS_ASSUME_NONNULL_END

//
//  RGLCURLResponseSerialization.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 5/22/19.
//  Copyright © 2019 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol RGLCURLResponseSerialization <NSObject>

/**
 The response object decoded from the data associated with a specified response.

 @param response The response to be processed.
 @param data The response data to be decoded.
 @param error The error that occurred while attempting to decode the response data.

 @return The object decoded from the specified response data.
 */
- (nullable id)responseObjectForResponse:(nullable NSURLResponse *)response
                                    data:(nullable NSData *)data
                                   error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NOTHROW;

@end


NS_ASSUME_NONNULL_END

//
//  RGLCProviderTask.h
//  FaceSDK
//
//  Created by Pavel Kondrashkov on 11/15/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

/// The type representing a provider request task.
typedef NS_ENUM(NSUInteger, RGLCProviderTaskType) {
    /// @see `RGLCProviderTaskRequestPlain`.
    RGLCProviderTaskTypeRequestPlain,
    /// @see `RGLCProviderTaskRequestData`.
    RGLCProviderTaskTypeRequestData,
    /// @see `RGLCProviderTaskRequestParameters`.
    RGLCProviderTaskTypeRequestParameters,
} NS_SWIFT_NAME(ProviderTaskType);

NS_ASSUME_NONNULL_BEGIN

/// The base class for a request task.
NS_SWIFT_NAME(ProviderTask)
@interface RGLCProviderTask : NSObject
@property(nonatomic, readonly, assign) RGLCProviderTaskType type;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

/// The request with no additional data.
NS_SWIFT_NAME(ProviderTaskRequestPlain)
@interface RGLCProviderTaskRequestPlain : RGLCProviderTask
+ (instancetype)taskRequestPlain;
@end

/// The requests body set with data.
NS_SWIFT_NAME(ProviderTaskRequestData)
@interface RGLCProviderTaskRequestData : RGLCProviderTask
@property(nonatomic, readonly, strong) NSData *data;
+ (instancetype)taskRequestData:(NSData *)data;
@end

/// The requests body set with JSON encoded parameters.
NS_SWIFT_NAME(ProviderTaskRequestParameters)
@interface RGLCProviderTaskRequestParameters : RGLCProviderTask
@property(nonatomic, readonly, strong) NSDictionary<NSString *, id> *parameters;
+ (instancetype)taskRequestParameters:(NSDictionary<NSString *, id> *)parameters;
@end

NS_ASSUME_NONNULL_END

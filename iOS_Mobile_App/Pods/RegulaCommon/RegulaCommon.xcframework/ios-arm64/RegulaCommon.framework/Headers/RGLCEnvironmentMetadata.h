//
//  RGLCEnvironmentMetadata.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 4/16/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CLLocation;

@interface RGLCEnvironmentMetadata : NSObject

@property(readonly, nonatomic, strong, nonnull) NSString *platform;
@property(readonly, nonatomic, strong, nonnull) NSString *osVersion;
@property(readonly, nonatomic, strong, nonnull) NSString *deviceModel;
@property(readonly, nonatomic, strong, nonnull) NSString *sdkVersion;
@property(readonly, nonatomic, strong, nonnull) NSString *sdkBundleIdentifier;
@property(readonly, nonatomic, strong, nonnull) NSString *hostAppVersion;
@property(readonly, nonatomic, strong, nonnull) NSString *hostAppBundleIdentifier;
@property(readonly, nonatomic, strong, nullable) NSNumber *batteryLevelPercent;
@property(readonly, nonatomic, strong, nonnull) NSNumber *displayBrightnessLevelPercent;
@property(readonly, nonatomic, strong, nullable) CLLocation *lastLocation;

@end

NS_ASSUME_NONNULL_END

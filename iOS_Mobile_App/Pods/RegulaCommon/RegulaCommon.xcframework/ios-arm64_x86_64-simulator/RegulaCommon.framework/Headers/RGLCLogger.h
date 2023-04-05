//
//  RGLCLogger.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 5/4/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#define _RGLCLog_IMPL(level, logger, format, ...) \
    [RGLCLogger logLevel:(level) subsystem:(logger) filename:__FILE_NAME__ line:__LINE__ message:format, ##__VA_ARGS__]

#define _RGLCLogDebug_IMPL(format, logger, ...) \
    _RGLCLog_IMPL(RGLCLoggerLevelDebug, logger, format, ##__VA_ARGS__)

#define _RGLCLogVerbose_IMPL(format, logger, ...) \
    _RGLCLog_IMPL(RGLCLoggerLevelVerbose, logger, format, ##__VA_ARGS__)

#define _RGLCLogInfo_IMPL(format, logger, ...) \
    _RGLCLog_IMPL(RGLCLoggerLevelInfo, logger, format, ##__VA_ARGS__)

#define _RGLCLogWarning_IMPL(format, logger, ...) \
    _RGLCLog_IMPL(RGLCLoggerLevelWarning, logger, format, ##__VA_ARGS__)

#define _RGLCLogError_IMPL(format, logger, ...) \
    _RGLCLog_IMPL(RGLCLoggerLevelError, logger, format, ##__VA_ARGS__)

#define _RGLCLogCritical_IMPL(format, logger, ...) \
    _RGLCLog_IMPL(RGLCLoggerLevelCritical, logger, format, ##__VA_ARGS__)

#define _RGLCThrottleLog_IMPL(level, logger, timeoutSeconds, format, ...) \
    [RGLCLogger logLevel:(level) subsystem:(logger) timeout:(timeoutSeconds) filename:__FILE_NAME__ line:__LINE__ message:format, ##__VA_ARGS__]

#if INTERNAL
#define _RGLCLogInternal_IMPL(fmt, logger, ...) \
    [RGLCLogger logLevel:RGLCLoggerLevelInfo subsystem:(logger) filename:__FILE_NAME__ line:__LINE__ message:(@"[INTERNAL] " fmt), ##__VA_ARGS__]
#else
#define _RGLCLogInternal_IMPL(fmt, logger, ...)
#endif

#define RGLCLog(level, format, ...) \
    _RGLCLog_IMPL(level, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCLogDebug(format, ...) \
    _RGLCLogDebug_IMPL(format, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCLogVerbose(format, ...) \
    _RGLCLogVerbose_IMPL(format, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCLogInfo(format, ...) \
    _RGLCLogInfo_IMPL(format, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCLogWarning(format, ...) \
    _RGLCLogWarning_IMPL(format, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCLogError(format, ...) \
    _RGLCLogError_IMPL(format, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCLogCritical(format, ...) \
    _RGLCLogCritical_IMPL(format, @"RegulaCommon", ##__VA_ARGS__)

#define RGLCThrottleLog(level, timeoutSeconds, format, ...) \
    _RGLCThrottleLog_IMPL(level, @"RegulaCommon", timeoutSeconds, format, ##__VA_ARGS__)

#define RGLCLogInternal(fmt, ...) \
    _RGLCLogInternal_IMPL(fmt, @"RegulaCommon", ##__VA_ARGS__)

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RGLCLoggerLevel) {
    RGLCLoggerLevelDebug,
    RGLCLoggerLevelVerbose,
    RGLCLoggerLevelInfo,
    RGLCLoggerLevelWarning,
    RGLCLoggerLevelError,
    RGLCLoggerLevelCritical,
};

@interface RGLCLogger : NSObject

+ (void)logLevel:(RGLCLoggerLevel)level
       subsystem:(nullable NSString *)subsystem
         timeout:(CFTimeInterval)timeout
        filename:(const char *)filename
            line:(int)line
         message:(NSString *)format, ...;

+ (void)logLevel:(RGLCLoggerLevel)level
       subsystem:(nullable NSString *)subsystem
        filename:(const char *)filename
            line:(int)line
         message:(NSString *)format, ...;

@end

NS_ASSUME_NONNULL_END

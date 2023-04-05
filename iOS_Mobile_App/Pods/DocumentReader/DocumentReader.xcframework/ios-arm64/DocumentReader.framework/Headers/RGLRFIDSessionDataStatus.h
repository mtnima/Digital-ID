#import <Foundation/Foundation.h>

#import "RGLMacros.h"
#import "RGLCheckResult.h"

NS_ASSUME_NONNULL_BEGIN

/// Container for a RFID related scanning statuses.
NS_SWIFT_NAME(RFIDSessionDataStatus)
@interface RGLRFIDSessionDataStatus : NSObject

/// Summary of all RFID results.
@property(nonatomic, readonly, assign) RGLCheckResult overallStatus;

/// Acitve authentication status.
@property(nonatomic, readonly, assign) RGLCheckResult AA;

/// Basics access control status.
@property(nonatomic, readonly, assign) RGLCheckResult BAC;

/// Chip authentication status.
@property(nonatomic, readonly, assign) RGLCheckResult CA;

/// Passive authentication status.
@property(nonatomic, readonly, assign) RGLCheckResult PA;

/// Password authenticated connection establishment status.
@property(nonatomic, readonly, assign) RGLCheckResult PACE;

/// Terminal authentication status.
@property(nonatomic, readonly, assign) RGLCheckResult TA;

RGL_EMPTY_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END


//
//  RGLBytes.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 11/5/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RGLMacros.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BytesData)
@interface RGLBytesData : NSObject

@property(nonatomic, readonly, strong, nonnull) NSString *data;
@property(nonatomic, readonly, assign) NSInteger length;
@property(nonatomic, readonly, assign) NSInteger status;
@property(nonatomic, readonly, assign) NSInteger type;

RGL_EMPTY_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END

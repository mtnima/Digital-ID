//
//  RGLReprocParams.h
//  DocumentReader
//
//  Created by Dmitry Evglevsky on 8.07.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(DocReader.ReprocParams)
@interface RGLReprocParams : NSObject

@property(nonatomic, strong, nonnull) NSString *serviceURL;
@property(nonatomic, strong, nullable) NSNumber *failIfNoService;

@end

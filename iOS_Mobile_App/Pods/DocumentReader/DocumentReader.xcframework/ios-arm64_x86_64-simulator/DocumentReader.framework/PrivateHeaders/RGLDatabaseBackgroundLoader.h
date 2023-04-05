//
//  RGLDatabaseBackgroundLoader.h
//  DocumentReader
//
//  Created by Dmitry Evglevsky on 30.05.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RGLNetworkService.h"

NS_ASSUME_NONNULL_BEGIN

@interface RGLDatabaseBackgroundLoader : NSObject

- (void)getDataFromURL:(NSURL *)url progress:(RGLNetworkServiceProgress _Nullable)progressHandler
            completion:(RGLNetworkServiceCompletion _Nullable)completionHandler;
- (void)invalidateAndCancel;

@end

NS_ASSUME_NONNULL_END

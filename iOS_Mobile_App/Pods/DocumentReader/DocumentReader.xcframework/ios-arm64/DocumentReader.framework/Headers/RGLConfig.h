//
//  RGLConfig.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 8/30/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RGLMacros.h"

NS_ASSUME_NONNULL_BEGIN

/// DocumentReader configuration object.
/// Controls initialization time properties such as License and Database filepath.
NS_SWIFT_NAME(DocReader.Config)
@interface RGLConfig : NSObject

/// The license binary file loaded as `Data`.
@property(readwrite, nonatomic, strong, nonnull) NSData *licenseData;

/// Enables automatic license update check during `DocumentReader` initialization.
/// Defaults to `true`.
@property(readwrite, nonatomic, assign) BOOL licenseUpdateCheck;

/// The path to the database file.
@property(readwrite, nonatomic, copy, nullable) NSString *databasePath;

/// Defines whether the `DocumentReader` delays loading of neural networks. Defaults to `false`.
///
/// When set to `true` the initialization starts in the background thread after a completion block passed to the method
/// `-[RGLDocReader initializeReaderWithConfig:completion:]` is called. If the document processing is initiated before all the networks are loaded,
/// the `DocuentReader` will wait for it before starting the handling.
///
/// When set to `false` the initialization is performed during `DocumentReader` initialization `-[RGLDocReader initializeReaderWithConfig:completion:]` method.
@property(readwrite, nonatomic, assign, getter=isDelayedNNLoadEnabled) BOOL delayedNNLoadEnabled;

RGL_EMPTY_INIT_UNAVAILABLE

/// Creates configuration object for DocumentReader.
/// @param licenseData The license binary file loaded as `Data`.
- (instancetype)initWithLicenseData:(nonnull NSData *)licenseData NS_DESIGNATED_INITIALIZER;

/// Creates configuration object for DocumentReader.
/// @param licenseData The license binary file loaded as `Data`.
/// @param licenseUpdateCheck Enables automatic license update check during `DocumentReader` initialization.
/// @param databasePath The path to the database file.
- (instancetype)initWithLicenseData:(nonnull NSData *)licenseData
                 licenseUpdateCheck:(BOOL)licenseUpdateCheck
                       databasePath:(nullable NSString *)databasePath
               delayedNNLoadEnabled:(BOOL)delayedNNLoadEnabled;

/// Creates configuration object for DocumentReader.
/// @param licenseData The license binary file loaded as `Data`.
+ (instancetype)configWithLicenseData:(nonnull NSData *)licenseData;

/// Creates configuration object for DocumentReader.
/// @param licenseData The license binary file loaded as `Data
/// @param licenseUpdateCheck Enables automatic license update check during `DocumentReader` initialization.
/// @param databasePath The path to the database file.
+ (instancetype)configWithLicenseData:(nonnull NSData *)licenseData
                   licenseUpdateCheck:(BOOL)licenseUpdateCheck
                         databasePath:(nullable NSString *)databasePath
                 delayedNNLoadEnabled:(BOOL)delayedNNLoadEnabled;

@end

NS_ASSUME_NONNULL_END

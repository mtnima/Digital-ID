//
//  RGLTCCParams.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 14/02/2022.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocumentReader/RGLMacros.h>

NS_ASSUME_NONNULL_BEGIN

/// TCC service related parameters for RFID session configuration.
NS_SWIFT_NAME(TCCParams)
@interface RGLTCCParams : NSObject

/// The TA URL for the TCC service. The value of the property must be a valid URL string.
@property(nonatomic, readwrite, copy, nullable) NSString *serviceTAURLString;

/// The PA URL for the TCC service. The value of the property must be a valid URL string.
@property(nonatomic, readwrite, copy, nullable) NSString *servicePAURLString;

/// The URL for the certificate for a TCC service. The value of the property must be a valid URL string.
@property(nonatomic, readwrite, copy, nullable) NSString *pfxCertURLString;

/// The bytes of the certificate for a TCC service.
/// This data will be used instead of loading the certificate via `pfxCertURLString`.
@property(nonatomic, readwrite, copy, nullable) NSData *pfxCertData;

/// The passphrase for the cerficiate provided by the `pfxCertURLString` property.
@property(nonatomic, readwrite, copy, nullable) NSString *pfxPassPhrase;

- (instancetype)init;
- (instancetype)initWithServiceTAURLString:(nullable NSString *)serviceTAURLString
                        servicePAURLString:(nullable NSString *)servicePAURLString
                          pfxCertURLString:(nullable NSString *)pfxCertURLString
                               pfxCertData:(nullable NSData *)pfxCertData
                             pfxPassPhrase:(nullable NSString *)pfxPassPhrase NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END

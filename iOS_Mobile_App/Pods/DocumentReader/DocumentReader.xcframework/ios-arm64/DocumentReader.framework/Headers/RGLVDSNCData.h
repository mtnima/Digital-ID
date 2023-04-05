//
//  RGLVDSNCData.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 11/5/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RGLMacros.h"

@class RGLBytesData;
@class RGLCertificateChain;

NS_ASSUME_NONNULL_BEGIN

/// Visible Digital Seal for Non Constrained environments.
NS_SWIFT_NAME(VDSNCData)
@interface RGLVDSNCData : NSObject

/// Visible Digital Seal use case type.
/// Type is set to `icao.test` for Proof of Testing (data defined by CAPSCA), `icao.vacc` for Proof of Vaccination (data defined by WHO).
/// Other Types may be added in the future.
@property(nonatomic, readonly, strong, nullable) NSString *type;

/// Visible Digital Seal use case version.
@property(nonatomic, readonly, assign) NSInteger version;

/// Three letter code identifying the issuing state or organization.
@property(nonatomic, readonly, strong, nullable) NSString *issuingCountry;

/// The message field contains the actual data as a dictionary (JSON).
@property(nonatomic, readonly, strong, nonnull) NSDictionary *message;

/// The signature algorithm used to produce the signature. ECDSA scheme.
@property(nonatomic, readonly, strong, nullable) NSString *signatureAlgorithm;

/// The binary data of the verified digital signature.
@property(nonatomic, readonly, strong, nullable) RGLBytesData *signature;

/// The binary data of the signer certificate.
@property(nonatomic, readonly, strong, nullable) RGLBytesData *certificate;

/// The certificate chain, used for the digital signature verification.
@property(nonatomic, readonly, strong, nonnull) NSArray<RGLCertificateChain *> *certificateChain;


/// The list of remarks occured during the scanning procedure.
///
/// Each element is a `NSNumber` containing a `NSUInteger`, that belongs to the `enum eLDS_ParsingErrorCodes` or the `enum eLDS_ParsingNotificationCodes`.
@property(nonatomic, readonly, strong, nonnull) NSArray<NSNumber *> *notifications;

RGL_EMPTY_INIT_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END

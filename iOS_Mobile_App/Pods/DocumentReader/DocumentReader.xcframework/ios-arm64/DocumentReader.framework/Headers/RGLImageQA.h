//
//  RGLImageQA.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 8/27/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <DocumentReader/RGLImageQualityCheckType.h>

NS_ASSUME_NONNULL_BEGIN

@class RGLGlaresCheckParams;

NS_SWIFT_NAME(ImageQA)
/// Interface contains properties to configure image quality
@interface RGLImageQA : NSObject

/// This parameter sets threshold for Image QA check of the presented document physical dpi.
/// If actual document dpi is below this threshold, check will fail.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *dpiThreshold;

/// This parameter sets threshold for Image QA check of the presented document perspective angle in degrees.
/// If actual document perspective angle is above this threshold, check will fail.
/// Type: Integer.
@property (nonatomic, strong, nullable) NSNumber *angleThreshold;

/// This option disabled focus check during performing image quality validation.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *focusCheck;

/// This option disabled glares check during performing image quality validation.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *glaresCheck;

/// Parameters for glares image quality validation.
@property (nonatomic, strong, nullable) RGLGlaresCheckParams *glaresCheckParams;

/// This option disabled colorness check during performing image quality validation.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *colornessCheck;

/// This option disabled moire patterns check during performing image quality validation.
/// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *moireCheck;

/// This option controls the quality checks that the image should pass in order to be considered a valid input during the scanning process.
@property (nonatomic, strong, nullable) NSArray<RGLImageQualityCheckType> *expectedPass;

///
/// Specify the minimum indent from the corners of the document to the borders of the image.
/// The value reflects the allowed percentage for the indent relative to the width of the document.
/// If it is detected that the corners of the document are closer than the specified value, the status will contain an error in the `RGLDocumentReaderResults.imageQuality.imageQualityList.result` field.
 /// Type: Bool.
@property (nonatomic, strong, nullable) NSNumber *documentPositionIndent;

@end

NS_ASSUME_NONNULL_END

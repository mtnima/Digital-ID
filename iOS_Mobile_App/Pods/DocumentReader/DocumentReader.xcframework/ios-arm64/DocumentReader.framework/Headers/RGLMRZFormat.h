//
//  RGLMRZFormat.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 8/27/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Enum contains a set of identifiers determining MRZ  format
typedef NS_ENUM(NSInteger, RGLMRZFormat) {
  /// 1x30.
  RGLMRZFormatIDL,
  /// 3x30.
  RGLMRZFormatID1,
  /// 2x36.
  RGLMRZFormatID2,
  /// 2x44.
  RGLMRZFormatID3,
  /// 1x6.
  RGLMRZFormatCAN,
  /// 2x30.
  RGLMRZFormatID1_2_30,
} NS_SWIFT_NAME(MRZFormat);

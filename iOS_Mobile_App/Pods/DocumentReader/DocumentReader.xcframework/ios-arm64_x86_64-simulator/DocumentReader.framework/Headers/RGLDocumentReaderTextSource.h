//
//  RGLDocumentReaderTextSource.h
//  DocumentReader
//
//  Created by Serge Rylko on 1.09.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocumentReader/RGLDocumentReaderResults.h> //TODO: remove resultTypes to own file

NS_SWIFT_NAME(DocumentReaderTextSource)
@interface RGLDocumentReaderTextSource : NSObject

/**
 The value's origin source
 */
@property(nonatomic, assign, readonly) RGLResultType sourceType;

/**
 The value's origin source string description
 */
@property(nonnull, nonatomic, strong, readonly) NSString *source;

/**
 Overall validity status of all text fields of this source type
 */
@property(nonatomic, assign, readonly) RGLCheckResult validityStatus;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

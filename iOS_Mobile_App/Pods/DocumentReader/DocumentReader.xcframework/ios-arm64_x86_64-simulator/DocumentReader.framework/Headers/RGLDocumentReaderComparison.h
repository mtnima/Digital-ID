//
//  RGLDocumentReaderComparison.h
//  DocumentReader
//
//  Created by Serge Rylko on 1.09.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocumentReader/RGLDocumentReaderResults.h> //TODO: remove resultTypes to own file

NS_SWIFT_NAME(DocumentReaderComparison)
@interface RGLDocumentReaderComparison : NSObject

/**
The value's origin source
 */
@property(nonatomic, assign, readonly) RGLResultType sourceTypeLeft;

/**
The value's origin source
 */
@property(nonatomic, assign, readonly) RGLResultType sourceTypeRight;

/**
 The status of field comparisons
 */
@property(nonatomic, assign, readonly) RGLCheckResult status;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json sourceList:(NSDictionary *_Nonnull)sourceList;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json sourceList:(NSDictionary *_Nonnull)sourceList;;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

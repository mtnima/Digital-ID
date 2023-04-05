//
//  RGLDocumentReaderValidity.h
//  DocumentReader
//
//  Created by Serge Rylko on 1.09.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <DocumentReader/RGLDocumentReaderResults.h> //TODO: remove resultTypes to own file

NS_SWIFT_NAME(DocumentReaderValidity)
@interface RGLDocumentReaderValidity: NSObject

/**
 The value's origin source
 */
@property(nonatomic, assign, readonly) RGLResultType sourceType;

/**
 Overall validity status of all text fields of this particular field
 */
@property(nonatomic, assign, readonly) RGLCheckResult status;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json sourceList:(NSDictionary *_Nonnull)sourceList;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json sourceList:(NSDictionary *_Nonnull)sourceList;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

//
//  RGLDocumentReaderSymbol.h
//  DocumentReader
//
//  Created by Serge Rylko on 2.09.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DocumentReaderSymbol)
@interface RGLDocumentReaderSymbol : NSObject

/**
 * ASCII code of symbol
 */
@property(nonatomic, assign, readonly) NSInteger code;

/**
 * bounds result of the particular value
 */
@property(nonatomic, assign, readonly) CGRect rect;

/**
 * symbol recognition probability (0–100, %)
 */
@property(nonatomic, assign, readonly) NSInteger probability;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithJSON:(NSDictionary *)json;
+ (instancetype)initWithJSON:(NSDictionary *)json;
- (NSDictionary *)jsonDictionary;

@end

NS_ASSUME_NONNULL_END

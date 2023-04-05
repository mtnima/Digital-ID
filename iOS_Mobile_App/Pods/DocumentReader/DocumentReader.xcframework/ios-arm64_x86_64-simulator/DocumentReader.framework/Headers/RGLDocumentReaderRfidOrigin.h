//
//  RGLDocumentReaderRfidOrigin.h
//  DocumentReader
//
//  Created by Serge Rylko on 29.09.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DocumentReaderRfidOrigin)
@interface RGLDocumentReaderRfidOrigin: NSObject

@property(nonatomic, assign, readonly) NSInteger dg;
@property(nonatomic, assign, readonly) NSInteger dgTag;
@property(nonatomic, assign, readonly) NSInteger entryView;
@property(nonatomic, assign, readonly) NSInteger tagEntry;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithJSON:(NSDictionary *)json;
+ (instancetype)initWithJSON:(NSDictionary *)json;
- (NSDictionary *)jsonDictionary;

@end

NS_ASSUME_NONNULL_END

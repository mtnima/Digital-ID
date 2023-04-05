#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>
#import "RGLDocumentReaderResults.h"

NS_ASSUME_NONNULL_BEGIN

@class RGLDocumentReaderSymbol;
@class RGLDocumentReaderRfidOrigin;

NS_SWIFT_NAME(DocumentReaderValue)
@interface RGLDocumentReaderValue : NSObject

/**
 * current text field
 */
@property(nullable, nonatomic, readonly, assign) RGLDocumentReaderTextField *field;
/**
 Identifies zone whence data is extracted, one of RGLResultType values
 */
@property(nonatomic, assign, readonly) RGLResultType sourceType;
/**
 A value
 */
@property(nonatomic, strong, readonly, nonnull) NSString *value;
/**
 An original value
 */
@property(nonatomic, strong, readonly, nonnull) NSString *originalValue;
/**
 Field rectangular area coordinates on the image
 */
@property(nonatomic, assign, readonly) CGRect boundRect;
/**
 RFID origin data.
 Only for the 'RFID' source
 */
@property(nonatomic, strong, readonly, nullable) RGLDocumentReaderRfidOrigin *rfidOrigin;
/**
 Verification result, one of RGLFieldVerificationResult values
 */
@property(nonatomic, assign, readonly) RGLFieldVerificationResult validity RGL_DEPRECATED(6.6, "Use `RGLDocumentReaderTextField`'s property `validityList` instead.");
/**
 A comparison result of a textual field values where the key is one of RGLResultType values and the value is one of RGLFieldVerificationResult values
 */
@property(nonatomic, strong, readonly, nonnull) NSDictionary <NSNumber *, NSNumber *> *comparison RGL_DEPRECATED(6.6, "Use `RGLDocumentReaderTextField`'s property `comparisonList` instead.");
;
/**
 An index of the document page whence the textual field is extracted
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;
/**
 Textual field recognition probability (0 - 100, %)
 */
@property(nonatomic, assign, readonly) NSInteger probability;

/**
 * list of all symbols for this value
 */
@property(nonatomic, strong, readonly) NSArray <RGLDocumentReaderSymbol *> *originalSymbols;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json
                                field:(RGLDocumentReaderTextField *)field;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json
                                field:(RGLDocumentReaderTextField *)field;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

NS_ASSUME_NONNULL_END

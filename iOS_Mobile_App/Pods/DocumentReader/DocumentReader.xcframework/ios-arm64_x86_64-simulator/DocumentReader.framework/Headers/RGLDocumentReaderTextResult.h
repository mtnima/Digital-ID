#import <Foundation/Foundation.h>
#import "RGLDocumentReaderResults.h"

@class RGLDocumentReaderTextField;
@class RGLDocumentReaderTextSource;

NS_SWIFT_NAME(DocumentReaderTextResult)
@interface RGLDocumentReaderTextResult : NSObject

/**
 An array of textual results
 */
@property(nonatomic, strong, readonly, nonnull) NSArray <RGLDocumentReaderTextField *> *fields;

/**
 Textual fields check result, one of RGLCheckResult values
 */
@property(nonatomic, assign, readonly) RGLCheckResult status;

/**
 List of all available origin source
 with overall validity status of all text fields of a particular source type
 */
@property(nonnull, nonatomic, strong, readonly) NSArray <RGLDocumentReaderTextSource *> *availableSourceList;

/**
 Comparison status of all text fields
 */
@property(nonatomic, assign, readonly) RGLCheckResult comparisonStatus;

/**
 Validity status of all text fields
 */
@property(nonatomic, assign, readonly) RGLCheckResult validityStatus;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;
- (void)sortByFieldType:(BOOL)desc;

@end

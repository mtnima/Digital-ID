#import <Foundation/Foundation.h>
#import "RGLProcessParams.h"
#import "RGLDocumentReaderBarcodeResult.h"

@class RGLPDF417Info;

NS_SWIFT_NAME(DocumentReaderBarcodeField)
@interface RGLDocumentReaderBarcodeField : NSObject

/**
 Decoded barcode type
 */
@property(nonatomic, assign, readonly) RGLBarcodeType barcodeType;
/**
 Indicates barcode reading result
 */
@property(nonatomic, assign, readonly) RGLBarcodeResult status;
/**
 Contains the information about the PDF417 barcode
 */
@property(nonatomic, strong, readonly, nullable) RGLPDF417Info *pdf417Info;
/**
 Results of reading data from barcode modules
 */
@property(nonatomic, strong, readonly, nonnull) NSData *data;
/**
 Indicates an index of the document page, whence the result is received
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

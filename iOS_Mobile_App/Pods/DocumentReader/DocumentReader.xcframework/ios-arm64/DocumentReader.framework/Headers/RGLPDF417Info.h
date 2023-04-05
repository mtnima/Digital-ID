#import <Foundation/Foundation.h>

NS_SWIFT_NAME(PDF417Info)
@interface RGLPDF417Info : NSObject

/**
 Barcode error correction level
 */
@property(nonatomic, assign, readonly) NSInteger errorLevel;
/**
 Number of columns in a barcode
 */
@property(nonatomic, assign, readonly) NSInteger columns;
/**
 Number of rows in a barcode
 */
@property(nonatomic, assign, readonly) NSInteger rows;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

@end

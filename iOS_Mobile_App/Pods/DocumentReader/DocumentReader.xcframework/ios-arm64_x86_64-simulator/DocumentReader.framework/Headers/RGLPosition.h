#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLDocumentReaderResults.h"
#import "RGLDocumentReaderDocumentType.h"

NS_SWIFT_NAME(Position)
@interface RGLPosition : NSObject

/**
 Document width and height
 */
@property(nonatomic, assign, readonly) CGSize size;
/**
 Document center coordinates
 */
@property(nonatomic, assign, readonly) CGPoint center;
/**
 Document left top corner coordinates
 */
@property(nonatomic, assign, readonly) CGPoint leftTop;
/**
 Document left bottom corner coordinates
 */
@property(nonatomic, assign, readonly) CGPoint leftBottom;
/**
 Document right top corner coordinates
 */
@property(nonatomic, assign, readonly) CGPoint rightTop;
/**
 Document right bottom corner coordinates
 */
@property(nonatomic, assign, readonly) CGPoint rightBottom;
/**
 Document rotation angle
 */
@property(nonatomic, assign, readonly) double angle;

/**
 Internal use parameter
 */
@property(nonatomic, assign, readonly) double perspectiveTr;
/**
 Internal use parameter
 */
@property(nonatomic, assign, readonly) double objArea;
/**
 Internal use parameter
 */
@property(nonatomic, assign, readonly) double objIntAngleDev;
/**
 Internal use parameter
 */
@property(nonatomic, assign, readonly) RGLCheckResult resultStatus;
/**
 Document format
 */
@property(nonatomic, assign, readonly) RGLDocFormat docFormat;
/**
 Index of the document page, whence the result is received
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;
/**
 Resolution in dots per inch
 */
@property(nonatomic, assign, readonly) NSInteger dpi;
/**
 Internal use parameter
 */
@property(nonatomic, assign, readonly) NSInteger inverse;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

+ (NSDictionary *_Nonnull)dictionaryFromPoint:(CGPoint)point;

@end

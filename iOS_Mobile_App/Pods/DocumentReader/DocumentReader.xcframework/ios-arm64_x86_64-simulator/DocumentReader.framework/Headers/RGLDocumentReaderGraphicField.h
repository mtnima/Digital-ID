#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "RGLDocumentReaderJsonResultGroup.h"

NS_SWIFT_NAME(DocumentReaderGraphicField)
@interface RGLDocumentReaderGraphicField : NSObject

/**
 Identifies zone whence data is extracted
 */
@property(nonatomic, assign, readonly) RGLResultType sourceType;
/**
 Graphic field logical type, one of RGLGraphicFieldType values
 */
@property(nonatomic, assign, readonly) RGLGraphicFieldType fieldType;
/**
 Graphic field symbolic name
 */
@property(nonatomic, strong, readonly, nonnull) NSString *fieldName;
/**
 Field area coordinates on the general image
 */
@property(nonatomic, assign, readonly) CGRect boundRect;
/**
 An image
 */
@property(nonatomic, strong, readonly, nonnull) UIImage *value;
/**
 Light type, one of RGLGraphicFieldLight values
 */
@property(nonatomic, assign, readonly) RGLGraphicFieldLight lightType;
/**
 Light symbolic name
 */
@property(nonatomic, strong, readonly, nonnull) NSString *lightName;
/**
 An index of the document page whence the graphic field is extracted
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype _Nonnull)init NS_UNAVAILABLE;
- (instancetype _Nonnull)initWithSourceType:(RGLResultType)sourceType fieldType:(RGLGraphicFieldType)fieldType boundRect:(CGRect)boundRect value:(UIImage *_Nonnull)value light:(RGLGraphicFieldLight) light pageIndex:(NSInteger)pageIndex;
- (instancetype _Nonnull)initWithFieldType:(RGLGraphicFieldType)fieldType valueJSON:(NSDictionary *_Nullable)json;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
- (NSDictionary *_Nonnull)jsonDictionary;

+ (NSString *_Nullable)graphicFieldTypeName:(RGLGraphicFieldType)graphicFieldType;
+ (NSString *_Nullable)graphicFieldLightName:(RGLGraphicFieldLight)graphicFieldLight;

@end

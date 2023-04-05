#import <Foundation/Foundation.h>
#import "RGLDocReaderDocumentsDatabase.h"

NS_SWIFT_NAME(DocReaderVersion)
/// Interface contains properties to get the information about the SDK
@interface RGLDocReaderVersion : NSObject

/**
 A version of the API framework
 */
@property (nonatomic, strong, nullable) NSString *api;
/**
 A version of the Core framework
 */
@property (nonatomic, strong, nullable) NSString *core;
/**
 A type of the Core framework
 */
@property (nonatomic, strong, nullable) NSString *coreMode;
/**
 A version of the database
 */
@property (nonatomic, strong, nonnull) RGLDocReaderDocumentsDatabase *database;

- (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end

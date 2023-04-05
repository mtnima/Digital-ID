#import <Foundation/Foundation.h>

NS_SWIFT_NAME(DocReaderDocumentsDatabase)
/// Interface contains properties to get the information about the database
@interface RGLDocReaderDocumentsDatabase : NSObject

/**
 An ID of the database, e.g. BLR, RUS.
 */
@property (nonatomic, strong, readonly, nullable) NSString *databaseID;
/**
 A version of the database
 */
@property (nonatomic, strong, readonly, nullable) NSString *version;
/**
 A date when the database was created
 */
@property (nonatomic, strong, readonly, nullable) NSString *date;
/**
 A list of supported documents in the database
 */
@property (nonatomic, strong, readonly, nullable) NSString *databaseDescription;
/**
 A number of countries included in the database
 */
@property (nonatomic, assign, readonly) NSInteger countriesNumber;
/**
 A number of documents included in the database
 */
@property (nonatomic, assign, readonly) NSInteger documentsNumber;

- (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;

@end

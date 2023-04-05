#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, RGLDocReaderFrame) {
    /// Size of the frame depends on the scenario, that means default values are used
    RGLDocReaderFrameScenarioDefault = 0,
    /// Full frame
    RGLDocReaderFrameMax = 1,
    /// No frame
    RGLDocReaderFrameNone = 2,
    /// Size of the frame corresponds to the ID-3 format in the portrait mode and to the ID-1 in the landscape mode
    RGLDocReaderFrameDocument = 3
} NS_SWIFT_NAME(DocReaderFrame);

typedef NS_ENUM(NSInteger, RGLDocReaderOrientation) {
    /// Both portrait and landscape modes
    RGLDocReaderOrientationRotate = 0,
    /// Portrait mode
    RGLDocReaderOrientationPortrait = 1,
    /// Landscape mode
    RGLDocReaderOrientationLandscape = 2
} NS_SWIFT_NAME(DocReaderOrientation);

typedef NS_ENUM(NSInteger, RGLCameraFrameShapeType) {
    /// Camera frame is rectangle
    RGLCameraFrameShapeTypeLine,
    /// Camera frame only consists of corners of the rectangle
    RGLCameraFrameShapeTypeCorners
} NS_SWIFT_NAME(CameraFrameShapeType);

NS_SWIFT_NAME(Scenario)
@interface RGLScenario : NSObject

@property(nonatomic, strong, readonly, nonnull) NSString *identifier;
@property(nonatomic, assign, readonly) RGLDocReaderFrame frame;
@property(nonatomic, assign, readonly) double frameKWHLandscape;
@property(nonatomic, assign, readonly) double frameKWHPortrait;
@property(nonatomic, assign, readonly) double frameKWHDoublePageSpreadPortrait;
@property(nonatomic, assign, readonly) double frameKWHDoublePageSpreadLandscape;
@property(nonatomic, strong, readonly, nonnull) NSString *scenarioDescription;
@property(nonatomic, assign, readonly) BOOL barcodeExt;
@property(nonatomic, assign, readonly) BOOL faceExt;
@property(nonatomic, assign, readonly) BOOL multiPageOff;
@property(nonatomic, assign, readonly) BOOL seriesProcessMode;
@property(nonatomic, strong, readonly, nonnull) NSString *caption;
@property(nonatomic, assign, readonly) BOOL uvTorch;
@property(nonatomic, assign, readonly) RGLDocReaderOrientation frameOrientation;
@property(nonatomic, assign, readonly) BOOL manualCrop;

- (instancetype _Nonnull)initWithIdentifier:(NSString *_Nonnull)identifier frame:(RGLDocReaderFrame)frame frameKWHLandscape:(double)frameKWHLandscape frameKWHPortrait:(double)frameKWHPortrait frameKWHDoublePageSpreadPortrait:(double)frameKWHDoublePageSpreadPortrait frameKWHDoublePageSpreadLandscape:(double)frameKWHDoublePageSpreadLandscape scenarioDescription:(NSString *_Nonnull)scenarioDescription barcodeExt:(BOOL)barcodeExt faceExt:(BOOL)faceExt multiPageOff:(BOOL)multiPageOff caption:(NSString *_Nonnull)caption uvTorch:(BOOL)uvTorch frameOrientation:(RGLDocReaderOrientation)frameOrientation seriesProcessMode:(BOOL)seriesProcessMode manualCrop:(BOOL)manualCrop;
- (instancetype _Nonnull)initWithJSON:(NSDictionary *_Nonnull)json;
+ (instancetype _Nonnull)initWithJSON:(NSDictionary * _Nonnull)json;
+ (NSArray * _Nullable)arrayFromJSON:(NSDictionary * _Nonnull)json;

@end

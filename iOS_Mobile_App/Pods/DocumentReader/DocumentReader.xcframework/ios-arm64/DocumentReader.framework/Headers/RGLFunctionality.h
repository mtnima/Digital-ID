#import <Foundation/Foundation.h>

#import "RGLScenario.h"
#import "RGLOnlineProcessingConfig.h"
#import "RGLDocumentReaderCameraViewController.h"

typedef NS_ENUM(NSInteger, RGLCaptureMode) {
    /**
     A flow of frames is taken for recognition right after a scenario is started.
     */
    RGLCaptureModeAuto                   =   0,
    /**
     A flow of frames is taken for recognition right after the Capture button is pushed
     */
    RGLCaptureModeCaptureVideo           =   1,
    /**
     A single frame is taken for recognition right after the Capture button is pushed.
     */
    RGLCaptureModeCaptureFrame           =   2
} NS_SWIFT_NAME(CaptureMode);

NS_SWIFT_NAME(RecordScanningProcessDelegate)
@protocol RGLRecordScanningProcessDelegate <NSObject>
@optional
/*!
 * @abstract Called by DocumentReader when recording process started.
 *
 * @return A output file URL for every record. Use new file name for every new scanning session.
 *         Already existing files will not overwritten, and error will be produced.
 */
- (nonnull NSURL *)recordingOutputFileURL;

/*!
 * @abstract Called by DocumentReader when recording process finished.
 *
 * @param fileURL The output file URL. Contains URL to recording output for every scanning session.
 */
- (void)didFinishRecordingToFile:(nonnull NSURL *)fileURL;

/*!
 * @abstract Called by DocumentReader when an error has occurred for some reason.
 *
 * @param error The error object.
 */
- (void)didFailWithError:(nonnull NSError *)error;
@end

@class RGLDocumentReaderCameraViewController;

NS_SWIFT_NAME(Functionality)
@interface RGLFunctionality : NSObject

@property(nonatomic, weak, nullable) RGLDocumentReaderCameraViewController *cameraViewController;
/**
 Set this setting to override the default cropping frame on the camera view controller provided by scenarios. Default: RGLDocReaderFrameScenarioDefault.
 */
@property(nonatomic, assign) RGLDocReaderFrame cameraFrame;
/**
 If it's set to true, the button that allows you to turn on/off the torch will be displayed. Default: true.
 */
@property(nonatomic, assign) BOOL showTorchButton;
/**
 If it's set to true, the button that allows you to close the camera view controller will be displayed. Default: true.
 */
@property(nonatomic, assign) BOOL showCloseButton;
/**
 If it's set to true, the button that allows you to take a picture and process it as a single frame will be displayed. Default: false.
 */
@property(nonatomic, assign) BOOL showCaptureButton;
/**
 If it's set to true, the button that allows you to change the camera frame type will be displayed. Default: false.
 */
@property(nonatomic, assign) BOOL showChangeFrameButton;
/**
 If it's set to true, the button that allows you to change a position of a capture device for the video session will be displayed. Default: false.
 */
@property(nonatomic, assign) BOOL showCameraSwitchButton;
/**
 If it's set to true, the button that allows you to skip processing of the next page of a document will be displayed. Default: true.
 */
@property(nonatomic, assign) BOOL showSkipNextPageButton;
/**
 If it's set to true, camera frames won't be taken for recognition while a camera is focusing. Default: true.
 */
@property(nonatomic, assign) BOOL skipFocusingFrames;
/**
 Allows you to specify the frame resolution.
 */
@property(nonatomic, strong, nullable) AVCaptureSessionPreset videoSessionPreset;
/**
 If it's set to true, camera frames won't be taken for recognition while a device is moving based on motion sensors. Default: true.
 */
@property(nonatomic, assign) BOOL videoCaptureMotionControl;
/**
 Allows you to specify an orientation of the camera view controller. Default: UIInterfaceOrientationMaskAllButUpsideDown.
 */
@property(nonatomic, assign) UIInterfaceOrientationMask orientation;
/**
 If it's set to true, once the scanning process is finished, the camera view controller will be dismissed. Default: true.
 */
@property(nonatomic, assign) BOOL singleResult;
/**
 Allows you to specify a position of a capture device for the video session. Default: AVCaptureDevicePositionUnspecified.
 */
@property(nonatomic, assign) AVCaptureDevicePosition cameraPosition;
/**
 Allows you to specify a name of a Regula device that will be used with Document Reader SDK.
 */
@property(nonatomic, strong, nullable) NSString *btDeviceName;
/**
 If it's set to true, allows you to connect to the external Regula Bluetooth devices like Regula 1120 and others.
 */
@property(nonatomic, assign, getter=isUseAuthenticator) BOOL useAuthenticator;
/**
 Allows you to specify a time interval when the Capture button has to be displayed after the document is detected. Don't forget to set the "showCaptureButton" to true, otherwise, it won't be displayed. Default: 5.
 */
@property(nonatomic, assign) NSTimeInterval showCaptureButtonDelayFromDetect;
/**
 Allows you to specify a time interval when the Capture button has to be displayed after the scanning process is started. Don't forget to set the "showCaptureButton" to true, otherwise, it won't be displayed. Default: 10.
 */
@property(nonatomic, assign) NSTimeInterval showCaptureButtonDelayFromStart;
/**
 Allows you to specify the video processing mode. Default: RGLCaptureModeAuto.
 */
@property(nonatomic, assign) RGLCaptureMode captureMode;
/**
 If it's set to true, the metadata will be displayed over the camera preview during document processing, namely the perspective angle value. Default: false.
 */
@property(nonatomic, assign) BOOL showMetadataInfo;
/**
 If it's set to true, allows you to adjust a zoom level using the pinch gesture (its range is from 1x to 10x). Default: false.
 */
@property(nonatomic, assign) BOOL isZoomEnabled;
/**
 Allows you to set the desired zoom level (its range from 1x to 10x). Default: 1.0.
 */
@property(nonatomic, assign) CGFloat zoomFactor;
@property(nonatomic, assign) BOOL recordScanningProcess;
@property(nonatomic, weak, nullable) id<RGLRecordScanningProcessDelegate> recordScanningProcessDelegate;
/**
 If it's set to true, scanner operate in manual multipage scanning mode. Set this flag to true, if you wanna create for example, custom logic (or UI) between scanning document pages. Default: false.
 */
@property(nonatomic, assign) BOOL manualMultipageMode;

@property(nonatomic, strong, nullable) NSNumber *forcePagesCount;

@property(nonatomic, strong, nullable) RGLOnlineProcessingConfig *onlineProcessingConfig;

@end

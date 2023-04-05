#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "RGLScenario.h"
#import "RGLProcessParams.h"
#import "RGLCornerView.h"
#import "RGLPreviewView.h"
#import "RGLMaskView.h"
#import "RGLActivityIndicator.h"
#import "RGLDocumentView.h"
#import "RGLDocumentReaderResults.h"
#import "RGLImageQualityGroup.h"
#import "RGLDocumentPosition.h"
#import "RGLFunctionality.h"

#import <CoreMotion/CoreMotion.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, RGLCameraScanMode) {
    RGLCameraScanModeContinues,
    RGLCameraScanModeCapture
} NS_SWIFT_NAME(CameraScanMode);

typedef NS_ENUM(NSInteger, RGLTorchModeDevice) {
    RGLTorchModeDeviceClearScreen = 0,
    RGLTorchModeDeviceWhiteScreen  = 1
} NS_SWIFT_NAME(TorchModeDevice);

@class RGLDocumentReaderCameraViewController, RGLDocumentReaderResults;

typedef NS_ENUM(NSInteger, RGLCameraViewControllerAction) {
    RGLCameraViewControllerActionDone,
    RGLCameraViewControllerActionProcess,
    RGLCameraViewControllerActionCancel,
    RGLCameraViewControllerActionMorePagesAvailable,
    RGLCameraViewControllerBadLicense,
    RGLCameraViewControllerActionProcessWhiteFlashLight,
    RGLCameraViewControllerOnlineProcessingError,
    RGLCameraViewControllerOnlineProcessingStarted
} NS_SWIFT_NAME(CameraViewControllerAction);

typedef void (^RGLCameraViewControllerHandler)(RGLDocumentReaderCameraViewController * _Nullable controller,
                                            RGLCameraViewControllerAction action,
                                            RGLDocumentReaderResults * _Nullable results) NS_SWIFT_NAME(CameraViewControllerHandler);

@protocol RGLDocumentReaderCameraViewControllerDelegate <NSObject>

- (BOOL)didMotionControlEnabledInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)didSkipFocusingFramesInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showCaptureButtonInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showChangeFrameSizeButtonInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showSwapCameraButtonInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showTorchButtonInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showCloseButtonInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable AVCaptureSessionPreset )videoSessionPresetInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showLogoInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showHelpAnimationInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)multipageProcessingInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIInterfaceOrientationMask)supportedOrientationsInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (void)startNewPageInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showStatusMessagesInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showResultMessagesInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIColor *)tintColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIColor *)resultStatusTextColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIFont *)resultStatusTextFontInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIColor *)resultStatusBackgroundColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIColor *)cameraFrameDefaultColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIColor *)cameraFrameActiveColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cameraFrameBorderWidthInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cameraFrameWidthOfssetInCameraController:(RGLDocumentReaderCameraViewController * )controller;
- (BOOL)cameraFrameHideInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIColor *)statusTextColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIFont *)statusTextFontInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIColor *)statusBackgroundColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIColor *)activityIndicatorViewColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIColor *)skipMultipageButtonBackgroundColorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (RGLCameraFrameShapeType)cameraFrameShapeTypeInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cornerViewLineLengthInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showNextPageAnimationInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showMaskViewInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (RGLDocReaderFrame)cameraFrameSizeInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (RGLDocReaderFrame)defaultCameraFrameSizeInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable NSArray<NSNumber *> *)barcodeTypesInCameraController:(RGLDocumentReaderCameraViewController * )controller;
- (AVCaptureDevicePosition)cameraPositionInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)showSkipNextPageButtonInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIImage *)helpAnimationImageInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIImage *)multipageAnimationFrontImageInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIImage *)multipageAnimationBackImageInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)statusPositionMultiplierInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)resultStatusPositionMultiplierInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIImage *)borderBackgroundImageInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)isUseAuthenticatorInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable NSString *)btDeviceNameInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (nullable NSString *)cameraStatusInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cameraFrameVerticalPositionMultiplier:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cameraFrameCornerRadius:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cameraBorderAspectRatioPortrait:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)cameraBorderAspectRatioLandscape:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)isShowCaptureButton:(RGLDocumentReaderCameraViewController *)controller;
- (NSTimeInterval)showCaptureButtonDelayFromDetect:(RGLDocumentReaderCameraViewController *)controller;
- (NSTimeInterval)showCaptureButtonDelayFromStart:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)shouldStartRecordingOnCapture:(RGLDocumentReaderCameraViewController *)controller;
- (BOOL)shouldStartAutoRecording:(RGLDocumentReaderCameraViewController *)controller;
- (nullable UIImage *)hologramAnimationImageInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (CGFloat)hologramAnimationPositionMultiplierInCameraController:(RGLDocumentReaderCameraViewController *)controller;
- (UIViewContentMode)hologramAnimationContentModeInCameraController:(RGLDocumentReaderCameraViewController *)controller;

@end

@class RGLDocumentReaderCameraViewControllerDelegate;

NS_SWIFT_NAME(DocumentReaderCameraViewController)
@interface RGLDocumentReaderCameraViewController : UIViewController

@property(nonatomic, assign) BOOL resultStatusLocked;

@property(readonly, nonatomic, assign) AVCaptureDevicePosition cameraPosition;
@property(nonatomic, assign) BOOL showHelpPopup;
@property(nonatomic, assign) BOOL helpAnimationShowed;
@property(nonatomic, assign) BOOL showResultMessages;
@property(nonatomic, assign) BOOL showStatusMessages;
@property(nonatomic, assign) BOOL recognizeWasInterrupted;
@property(nonatomic, assign) BOOL skipNextPageRecognition;
@property(nonatomic, assign) double motionRate;
@property(nonatomic, strong, nullable) NSString *cameraStatusString;

@property(nonatomic, strong, nullable) RGLDocumentReaderResults *latestResult;

@property (nonatomic, getter=isCameraControllerPresentedModally) BOOL cameraControllerPresentedModally;

@property(nonatomic, strong, nullable) RGLPreviewView *previewView;
@property(nonatomic, strong, nullable) UIButton *closeButton;
@property(nonatomic, strong, nullable) UIButton *flashButton;
@property(nonatomic, strong, nullable) UIButton *swapCameraButton;
@property(nonatomic, strong, nullable) UIButton *bleButton;
@property(nonatomic, strong, nullable) UIButton *batteryButton;
@property(nonatomic, strong, nullable) UILabel *statusLabel;
@property(nonatomic, strong, nullable) UIView *statusView;
@property(nonatomic, strong, nullable) UIButton *captureButton;
@property(nonatomic, strong, nullable) UIButton *skipMultipageButton;
@property(nonatomic, strong, nullable) UILabel *resultStatus;
@property(nonatomic, strong, nullable) UILabel *metadataLabel;
@property(nonatomic, strong, nullable) UIView *resultStatusView;
@property(nonatomic, strong, nullable) UIButton *frameSizeButton;
@property(nonatomic, strong, nullable) RGLMaskView *maskView;
@property(nonatomic, strong, nullable) UILabel *logoLabel;
@property(nonatomic, strong, nullable) UIImageView *logoImage;
@property(nonatomic, strong, nullable) RGLCornerView *borderView;
@property(nonatomic, strong, nullable) UIView *focusView;
@property(nonatomic, strong, nullable) UILabel *cameraUnavailableLabel;
@property(nonatomic, strong, nullable) RGLActivityIndicator *activityIndicator;
@property(nonatomic, strong, nullable) RGLDocumentView *multipageScaningView;
@property(nonatomic, strong, nullable) RGLDocumentView *helpAnimationView;
@property(nonatomic, strong, nullable) UIImageView *borderPlaceholderImage;
@property(nonatomic, assign) BOOL barcodeEnabled;
@property(nonatomic, assign) BOOL faceEnabled;
@property(nonatomic, assign) RGLCameraScanMode cameraScanMode;
@property(nonatomic, strong, nullable) UILabel *customLabel;
@property(nonatomic, strong, nullable) UIView *customContentView;

@property(nonatomic, weak, nullable) id<RGLDocumentReaderCameraViewControllerDelegate> cameraViewControllerDelegate;
@property(nonatomic, strong, nullable) RGLCameraViewControllerHandler cameraViewControllerHandler;
@property(nonatomic, assign) BOOL recognitionIsActive;

@property(nonatomic, assign) BOOL showChangeFrameButton;

@property(nonatomic, assign) RGLDocReaderFrame currentCameraFrame;

- (void)closeTapped:(UIButton *)button;
- (void)flashTapped:(UIButton *)button;
- (void)swapTapped:(UIButton *)button;
- (void)captureButtonTapped:(UIButton *)button;
- (void)skipMultipageTapped:(UIButton *)button;
- (void)changeFrameTapped:(UIButton *)button;
- (void)processParamChanged;
- (void)setHiddenForFlashButton:(BOOL)isHidden;
- (void)setHiddenForCloseButton:(BOOL)isHidden;
- (void)setHiddenForCaptureButton:(BOOL)isHidden;
- (void)setHiddenForSwapCameraButton:(BOOL)isHidden;
- (void)setVideoSessionPreset:(AVCaptureSessionPreset )sessionPreset;
- (void)setVideoZoomFactor:(CGFloat)videoZoomFactor;
- (void)setAVCaptureDevicePosition:(AVCaptureDevicePosition)cameraPosition;

- (void)notifyTintColorChanged;
- (void)notifyResultStatusTextColorChanged;
- (void)notifyResultStatusTextFontChanged;
- (void)notifyCameraFrameDefaultColorChanged;
- (void)notifyCameraFrameActiveColorChanged;
- (void)notifyStatusTextColorChanged;
- (void)notifyStatusTextFontChanged;
- (void)notifyStatusBackgroundColorChanged;
- (void)notifyShowStatusMessagesChanged;
- (void)notifyShowResultStatusMessagesChanged;
- (void)notifyCameraStatusChanged;
- (void)notifyCameraResultStatusChanged;
- (void)notifyCameraFrameShapeTypeChanged;
- (void)notifyMultipageButtonBackgroundColorChanged;
- (void)notifyCameraFrameBorderWidthChanged;
- (void)notifyActivityIndicatorColorChanged;
- (void)notifyResultStatusBackgroundColorChanged;
- (void)notifyCameraFrameLineLengthChanged;
- (void)notifyCameraFrameOffsetWidthChanged;
- (void)notifyShowBackgroundMaskChanged;
- (void)notifyBorderBackgroundImageChanged;
- (void)notifyBackgroundMaskAlphaChanged;
- (void)notifyMultipageAnimationFrontImageContentModeChanged;
- (void)notifyMultipageAnimationBackImageContentModeChanged;
- (void)notifyBorderBackgroundImageContentModeChanged;
- (void)notifyMultipageAnimationFrontImageChanged;
- (void)notifyMultipageAnimationBackImageChanged;
- (void)notifyCustomLabelStatusChanged;
- (void)notifyHologramAnimationImageChanged;
- (void)notifyhologramAnimationImageContentModeChanged;
- (void)notifyCustomUILayerJSONChanged;

- (void)closeCameraViewController:(void(^_Nullable)(void))completion;
    
@end

NS_ASSUME_NONNULL_END

#import <UIKit/UIKit.h>

#import "RGLDocumentReaderCameraViewController.h"

@class RGLDocumentReaderCameraViewController;

NS_SWIFT_NAME(Customization)
@interface RGLCustomization : NSObject

/// If it's set to true, the animation showing how to position a document will be displayed. Default: false.
@property(nonatomic, assign) BOOL showHelpAnimation;

/// Allows you to set any UIImage for the help animation.
@property(nonatomic, strong, nullable) UIImage *helpAnimationImage;

/// If it's set to true, status messages during the document processing will be shown. Default: true.
@property(nonatomic, assign) BOOL showStatusMessages;

/// If it's set to true, result status messages during the document processing will be shown. Default: true.
@property(nonatomic, assign) BOOL showResultStatusMessages;

/// Allows you to set any NSString to the status.
@property(nonatomic, strong, nullable) NSString *status;

/// Allows you to set any NSString to the result status.
@property(nonatomic, strong, nullable) NSString *resultStatus;

/// Allows you to change the location of the status.
/// For example, if you set the multiplier to 0.5 and the number of pixels by vertical is equal to 800, your message will be centralized and located at 200 px from the top,
/// i.e. (800 / 2) * 0.5 = 200 px. If the multiplier is equal to 1, the message will be centered.
/// If the multiplier is equal to zero, the default location will be used. Default: 0.
@property(nonatomic, assign) CGFloat statusPositionMultiplier;

/// Allows you to change the location of the result status.
/// For example, if you set the multiplier to 0.5 and the number of pixels by vertical is equal to 800, your message will be centralized and located at 200 px from the top,
/// i.e. (800 / 2) * 0.5 = 200 px. If the multiplier is equal to 1, the message will be centered.
/// If the multiplier is equal to zero, the default location will be used. Default: 0.
@property(nonatomic, assign) CGFloat resultStatusPositionMultiplier;

/// Allows you to set a shape type for the camera frame. Default: RGLCameraFrameShapeTypeLine.
@property(nonatomic, assign) RGLCameraFrameShapeType cameraFrameShapeType;

/// Allows you to customize the beginning and ending of stroked lines of the camera frame. Default: kCGLineCapButt.
@property(nonatomic, assign) CGLineCap cameraFrameLineCap;

/// Allows you to set a color for all visual elements.
@property(nonatomic, strong, null_resettable) UIColor *tintColor;

/// Allows you to set a color for the result status messages. Default: UIColor.whiteColor.
@property(nonatomic, strong, null_resettable) UIColor *resultStatusTextColor;

/// Allows you to set a font for the result status messages.
@property(nonatomic, strong, null_resettable) UIFont *resultStatusTextFont;

/// Allows you to set a color of the background for the result status messages.
@property(nonatomic, strong, nullable) UIColor *resultStatusBackgroundColor;

/// Allows you to set a color for the camera frame when a document is out of the camera frame or is not detected. Default: UIColor.whiteColor.
@property(nonatomic, strong, null_resettable) UIColor *cameraFrameDefaultColor;

/// Allows you to set a color for the camera frame when a document is detected. Default: UIColor.greenColor.
@property(nonatomic, strong, null_resettable) UIColor *cameraFrameActiveColor;

/// Allows you to set thickness of the camera frame borders. Default: 3.
@property(nonatomic, assign) CGFloat cameraFrameBorderWidth;

/// Allows you to set a color for the status messages. Default: UIColor.whiteColor.
@property(nonatomic, strong, nullable) UIColor *statusTextColor;

/// Allows you to set a font for the status messages.
@property(nonatomic, strong, null_resettable) UIFont *statusTextFont;

/// Allows you to set a background color for the status messages. Default: UIColor.clearColor.
@property(nonatomic, strong, nullable) UIColor *statusBackgroundColor;

/// Allows you to set a color for the activity indicator.
@property(nonatomic, strong, nullable) UIColor *activityIndicatorColor;

/// Allows you to set a color for the "Skip next page" button.
@property(nonatomic, strong, nullable) UIColor *multipageButtonBackgroundColor;

/// Allows you to set any UIImage for the multipage animation (front side).
@property(nonatomic, strong, nullable) UIImage *multipageAnimationFrontImage;

/// Allows you to set any UIImage for the multipage animation (back side).
@property(nonatomic, strong, nullable) UIImage *multipageAnimationBackImage;

/// Allows you to set length of the lines of the camera frame. It's applied once you change the "cameraFrameShapeType" property to "RGLCameraFrameShapeTypeCorners". Default: 25.
@property(nonatomic, assign) CGFloat cameraFrameLineLength;

/// Allows you to set an aspect ratio of the camera frame (portrait orientation). Default: 0.
@property(nonatomic, assign) CGFloat cameraFramePortraitAspectRatio;

/// Allows you to set an aspect ratio of the camera frame (landscape orientation). Default: 0.
@property(nonatomic, assign) CGFloat cameraFrameLandscapeAspectRatio;

/// Allows you to set an offset for the camera frame (portrait orientation). Default: 3.
@property(nonatomic, assign) CGFloat cameraFrameOffsetWidth;

/// If it's set to true, the animation asking for processing the next page will be displayed. Default: true.
@property(nonatomic, assign) BOOL showNextPageAnimation;

/// If it's set to true, the background mask next to the camera frame will be displayed. Default: true.
@property(nonatomic, assign) BOOL showBackgroundMask;

/// Allows you to set any UIImage within the camera frame.
@property(nonatomic, strong, nullable) UIImage *borderBackgroundImage;

/// Allows you to set intensity of the background mask. Default: 0.3.
@property(nonatomic, assign) CGFloat backgroundMaskAlpha;

/// Allows you to specify how a view of the help animation adjusts its content when its size changes. Default: UIViewContentModeScaleAspectFit.
@property(nonatomic, assign) UIViewContentMode helpAnimationImageContentMode;

/// Allows you to specify how a view of the multipage animation (front side) adjusts its content when its size changes. Default: UIViewContentModeScaleToFill.
@property(nonatomic, assign) UIViewContentMode multipageAnimationFrontImageContentMode;

/// Allows you to specify how a view of the multipage animation (back side) adjusts its content when its size changes. Default: UIViewContentModeScaleToFill.
@property(nonatomic, assign) UIViewContentMode multipageAnimationBackImageContentMode;

/// Allows you to specify how a view within the camera frame adjusts its content when its size changes. Default: UIViewContentModeScaleAspectFit.
@property(nonatomic, assign) UIViewContentMode borderBackgroundImageContentMode;

/// Allows you to change the location of the camera frame vertically.
@property(nonatomic, assign) CGFloat cameraFrameVerticalPositionMultiplier;

/// Allows you to change the location of the custom status.
/// For example, if you set the multiplier to 0.5 and the number of pixels by vertical is equal to 800, your message will be centralized and located at 200 px from the top,
/// i.e. (800 / 2) * 0.5 = 200 px. If the multiplier is equal to 1, the message will be centered.
/// If the multiplier is equal to zero, the default location will be used. Default: 1.
@property(nonatomic, assign) CGFloat customStatusPositionMultiplier;

/// Allows you to create a custom status as NSAttributedString.
@property(nonatomic, strong, nullable) NSAttributedString *customLabelStatus;

/// Allows you to set a corner radius of the camera frame. Default: 10.
@property(nonatomic, assign) CGFloat cameraFrameCornerRadius;

/// Allows you to set any UIImage for the torch button when its state is ON.
@property(nonatomic, strong, nullable) UIImage *torchButtonOnImage;

/// Allows you to set any UIImage for the torch button when its state is OFF.
@property(nonatomic, strong, nullable) UIImage *torchButtonOffImage;

/// Allows you to set any UIImage for the close button.
@property(nonatomic, strong, nullable) UIImage *closeButtonImage;

/// Allows you to set any UIImage for the capture button.
@property(nonatomic, strong, nullable) UIImage *captureButtonImage;

/// Allows you to set any UIImage for the button that allows changing shapes of the camera (collapsed state).
@property(nonatomic, strong, nullable) UIImage *changeFrameButtonCollapseImage;

/// Allows you to set any UIImage for the button that allows changing shapes of the camera (expanded state).
@property(nonatomic, strong, nullable) UIImage *changeFrameButtonExpandImage;

/// Allows you to set any UIImage for the button that allows changing positions of the capture device.
@property(nonatomic, strong, nullable) UIImage *cameraSwitchButtonImage;

/// Allows you to set a size for the toolbar (it's where all buttons are located).
@property(nonatomic, assign) CGFloat toolbarSize;

/// Allows you to set any `UIImage` for the hologram animation.
/// When set to `nil` the default image will be used.
/// This property can be set during the scanning process to tailor the user experiese for different types of documents.
@property(nonatomic, strong, nullable) UIImage *hologramAnimationImage;

/// Allows you to specify how a view of the help animation adjusts its content when its size changes.
/// Defaults to `UIViewContentModeScaleAspectFit`.
@property(nonatomic, assign) UIViewContentMode hologramAnimationImageContentMode;

/// Allows you to change the location of the hologram animation.
/// For example, if you set the multiplier to 0.5 and the number of pixels by vertical is equal to 800,
/// the animation will be centralized and located at 200 px from the top, i.e. (800 / 2) * 0.5 = 200 px.
/// If the multiplier is set to 1, the animation will be centered.
/// If the multiplier is set to 0, the default value will be used. Defaults to 1.
@property(nonatomic, assign) CGFloat hologramAnimationPositionMultiplier;

@property(nonatomic, strong, nullable) NSDictionary *customUILayerJSON;

@end

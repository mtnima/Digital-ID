#import <UIKit/UIKit.h>

@class RGLCCameraPreviewView;
@class AVCaptureVideoPreviewLayer;
@class AVCaptureSession;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PreviewView)
@interface RGLPreviewView : UIView

@property(readonly, nonatomic, strong, nullable) RGLCCameraPreviewView *contentView;
@property(readonly, nonatomic, strong, nullable) AVCaptureVideoPreviewLayer *previewLayer;
@property(readonly, nonatomic, strong, nullable) AVCaptureSession *session;

- (void)showCaptureEffect;
- (void)setCameraPreviewView:(RGLCCameraPreviewView *)view;

@end

NS_ASSUME_NONNULL_END

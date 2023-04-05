//
//  RGLCVideoRecorder.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 23/02/2022.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const RGLCVideoRecorderErrorDomain;

typedef NS_ERROR_ENUM(RGLCVideoRecorderErrorDomain, RGLCVideoRecorderErrorCode) {
  RGLCVideoRecorderErrorNotStarted,
  RGLCVideoRecorderErrorInProgress,
  RGLCVideoRecorderErrorAlreadyCompleted,
  RGLCVideoRecorderErrorInvalidDestinationURL,
  RGLCVideoRecorderErrorAssetWriterFailed,
} NS_SWIFT_NAME(VideoRecorderError);

@interface RGLCVideoRecorder : NSObject

/// Records new frame at a given presentation time.
///
/// @param imageBuffer The image buffer from camera stream.
/// @param presentationTime The time at which the video frame was presented to the user.
/// @param completion The completion block that indicates completion of the operation.
///                   Optionally sends an error of `RGLCVideoRecorderErrorDomain` domain if the appending of a video frame failed.
///                   The block is always called on the main thread.
- (void)recordImageBuffer:(CVImageBufferRef)imageBuffer
       atPresentationTime:(CMTime)presentationTime
               completion:(void (^ _Nullable)(NSError * _Nullable error))completion;

/// Starts video recording by initializing the asset writer to the designated location specified at `fileURL` with given `fileType` and `outputSettings`.
///
/// @param fileURL The desired location where the video-file will be stored.
/// @param outputFileType The media type of the samples the input accepts.
/// @param settings The settings to use for encoding the media you append to the output.
///                 Create an output settings dictionary manually, or use `AVOutputSettingsAssistant` to create preset-based settings.
/// @param completion The completion block that indicates completion of the operation.
///                   Optionally sends an error of `RGLCVideoRecorderErrorDomain` domain if the start of recording failed.
///                   If there is no error that means the recorder has started successfully.
///                   The block is always called on the main thread.
- (void)startRecordingAtFileURL:(NSURL *)fileURL
                       fileType:(AVFileType)outputFileType
                 outputSettings:(nullable NSDictionary<NSString *, id> *)settings
                     completion:(void (^ _Nullable)(NSError * _Nullable error))completion;

/// Stops video recording and exports the video asset to the provided `fileURL` at the start of recording.
///
/// @param completion The completion block of the operation.
///                   Sends either a destination url or an error of `RGLCVideoRecorderErrorDomain` domain depending on the result of the operation.
///                   The block is always called on the main thread.
- (void)stopRecordingWithCompletion:(void (^_Nullable)(NSURL * _Nullable url, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END

//
//  RegulaCommon.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 7/21/21.
//

// :MARK: Camera
#import <RegulaCommon/RGLCCamera.h>
#import <RegulaCommon/RGLCCameraMetadataPlugin.h>
#import <RegulaCommon/RGLCCameraMetadataDetectFacesPlugin.h>
#import <RegulaCommon/RGLCCameraSampleBufferPlugin.h>
#import <RegulaCommon/RGLCCameraSynchronizedDataPlugin.h>
#import <RegulaCommon/RGLCCameraPreviewView.h>
#import <RegulaCommon/RGLCCameraPhotoCaptureTask.h>
#import <RegulaCommon/RGLCCameraConfiguration.h>

// :MARK: Networking
#import <RegulaCommon/RGLCURLRequestSerialization.h>
#import <RegulaCommon/RGLCURLResponseSerialization.h>
#import <RegulaCommon/RGLCURLRequestInterceptor.h>
#import <RegulaCommon/RGLCURLSessionManager.h>
#import <RegulaCommon/RGLCHTTPSessionManager.h>
#import <RegulaCommon/RGLCHTTPResponseSerializer.h>
#import <RegulaCommon/RGLCHTTPRequestSerializer.h>

// :MARK: Provider
#import <RegulaCommon/RGLCProviderTarget.h>
#import <RegulaCommon/RGLCProviderHTTPMethod.h>
#import <RegulaCommon/RGLCProvider.h>
#import <RegulaCommon/RGLCProviderTask.h>

// :MARK: Logging
#import <RegulaCommon/RGLCLogger.h>
#import <RegulaCommon/RGLCLoggingViewController.h>

// :MARK: Other
#import <RegulaCommon/RGLCVideoRecorder.h>
#import <RegulaCommon/RGLCEnvironmentMetadata.h>
#import <RegulaCommon/NSError+RGLCAdditions.h>
#import <RegulaCommon/CVPixelBufferRef+RGLCAdditions.h>

// :MARK: Internal
#import <RegulaCommon/RGLCCameraDevice.h>
#import <RegulaCommon/NSBundle+RGLCSDKBundle.h>
#import <RegulaCommon/CIImage+RGLCUIInterfaceOrientation.h>
#import <RegulaCommon/AVCaptureConnection+RGLCUIDeviceOrientation.h>
#import <RegulaCommon/RGLCCameraOutput.h>
#import <RegulaCommon/RGLCCameraCapturePhotoOutput.h>

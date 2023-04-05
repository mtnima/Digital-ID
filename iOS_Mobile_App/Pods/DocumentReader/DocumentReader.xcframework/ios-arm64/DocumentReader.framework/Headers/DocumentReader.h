#import <UIKit/UIKit.h>

@class ProcessParams;

//! Project version number for DocumentReader.
FOUNDATION_EXPORT double DocumentReaderVersionNumber;

//! Project version string for DocumentReader.
FOUNDATION_EXPORT const unsigned char DocumentReaderVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <DocumentReader/PublicHeader.h>
#import <DocumentReader/RGLDocReader.h>
#import <DocumentReader/RGLDocReaderVersion.h>
#import <DocumentReader/RGLScenario.h>

#import <DocumentReader/RGLMacros.h>
#import <DocumentReader/RGLDocumentReaderResults.h>
#import <DocumentReader/RGLDocumentReaderDocumentType.h>
#import <DocumentReader/RGLDocumentReaderTextResult.h>
#import <DocumentReader/RGLDocumentReaderTextField.h>
#import <DocumentReader/RGLDocumentReaderTextSource.h>
#import <DocumentReader/RGLDocumentReaderValue.h>
#import <DocumentReader/RGLDocumentReaderComparison.h>
#import <DocumentReader/RGLDocumentReaderValidity.h>
#import <DocumentReader/RGLDocumentReaderSymbol.h>
#import <DocumentReader/RGLDocumentReaderRfidOrigin.h>
#import <DocumentReader/RGLDocumentReaderGraphicResult.h>
#import <DocumentReader/RGLDocumentReaderJsonResultGroup.h>
#import <DocumentReader/RGLPosition.h>
#import <DocumentReader/RGLDocumentPosition.h>
#import <DocumentReader/RGLBarcodePosition.h>
#import <DocumentReader/RGLMrzPosition.h>
#import <DocumentReader/RGLImageQualityGroup.h>
#import <DocumentReader/RGLImageQuality.h>
#import <DocumentReader/RGLDocumentReaderAuthenticityResult.h>
#import <DocumentReader/RGLRFIDSessionData.h>
#import <DocumentReader/RGLRFIDNotify.h>
#import <DocumentReader/RGLDocumentReaderGraphicField.h>
#import <DocumentReader/RGLRFIDScenario.h>
#import <DocumentReader/RGLProcessParams.h>
#import <DocumentReader/RGLDataGroup.h>
#import <DocumentReader/RGLePassportDataGroup.h>
#import <DocumentReader/RGLeIDDataGroup.h>
#import <DocumentReader/RGLeDLDataGroup.h>
#import <DocumentReader/RGLDocReaderDocumentsDatabase.h>
#import <DocumentReader/RGLAccessControlProcedureType.h>
#import <DocumentReader/RGLApplication.h>
#import <DocumentReader/RGLFile.h>
#import <DocumentReader/RGLFileData.h>
#import <DocumentReader/RGLSecurityObjectCertificates.h>
#import <DocumentReader/RGLCertificateData.h>
#import <DocumentReader/RGLSecurityObject.h>
#import <DocumentReader/RGLSignerInfo.h>
#import <DocumentReader/RGLAuthority.h>
#import <DocumentReader/RGLAttribute.h>
#import <DocumentReader/RGLRFIDValue.h>
#import <DocumentReader/RGLExtension.h>
#import <DocumentReader/RGLCertificateChain.h>
#import <DocumentReader/RGLValidity.h>
#import <DocumentReader/RGLCardProperties.h>
#import <DocumentReader/RGLAuthenticityCheck.h>
#import <DocumentReader/RGLAuthenticityElement.h>
#import <DocumentReader/RGLSecurityFeatureCheck.h>
#import <DocumentReader/RGLElementRect.h>
#import <DocumentReader/RGLIdentResult.h>
#import <DocumentReader/RGLPhotoIdentResult.h>
#import <DocumentReader/RGLUVFiberElement.h>
#import <DocumentReader/RGLDocumentReaderBarcodeResult.h>
#import <DocumentReader/RGLDocumentReaderBarcodeField.h>
#import <DocumentReader/RGLPDF417Info.h>
#import <DocumentReader/RGLCornerView.h>
#import <DocumentReader/RGLPreviewView.h>
#import <DocumentReader/RGLMaskView.h>
#import <DocumentReader/RGLActivityIndicator.h>
#import <DocumentReader/RGLDocumentView.h>
#import <DocumentReader/RGLPAResourcesIssuer.h>
#import <DocumentReader/RGLPKDCertificate.h>
#import <DocumentReader/RGLPAAttribute.h>
#import <DocumentReader/RGLTAChallenge.h>
#import <DocumentReader/RGLExternalConstants.h>
#import <DocumentReader/RGLMRZFormat.h>
#import <DocumentReader/RGLImageQA.h>
#import <DocumentReader/RGLGlaresCheckParams.h>
#import <DocumentReader/RGLVDSNCData.h>
#import <DocumentReader/RGLBytesData.h>
#import <DocumentReader/RGLImageQualityCheckType.h>
#import <DocumentReader/RGLTCCParams.h>

#import <DocumentReader/RGLDocumentReaderResultsStatus.h>
#import <DocumentReader/RGLRFIDSessionDataStatus.h>
#import <DocumentReader/RGLOpticalStatus.h>
#import <DocumentReader/RGLCheckResult.h>

#import <DocumentReader/RGLConfig.h>
#import <DocumentReader/RGLFunctionality.h>
#import <DocumentReader/RGLCustomization.h>
#import <DocumentReader/RGLInitializationResponse.h>
#import <DocumentReader/RGLLicense.h>

#import <DocumentReader/RGLFieldType.h>
#import <DocumentReader/eLDS_ParsingErrorCodes.h>
#import <DocumentReader/eLDS_ParsingNotificationCodes.h>
#import <DocumentReader/RGLImageInput.h>
#import <DocumentReader/RGLReprocParams.h>
#import <DocumentReader/RGLOnlineProcessingConfig.h>
#import <DocumentReader/RGLURLRequestInterceptingDelegate.h>

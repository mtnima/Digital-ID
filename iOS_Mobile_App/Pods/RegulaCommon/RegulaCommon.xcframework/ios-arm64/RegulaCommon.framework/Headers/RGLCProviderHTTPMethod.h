//
//  RGLCProviderHTTPMethod.h
//  RegulaCommon
//
//  Created by Pavel Kondrashkov on 11/3/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#ifndef RGLCProviderMethod_h
#define RGLCProviderMethod_h

/// The type representing HTTP methods.
NS_SWIFT_NAME(ProviderHTTPMethod)
typedef NS_ENUM(NSInteger, RGLCProviderHTTPMethod) {
    /// `GET` Method.
    RGLCProviderHTTPMethodGet,
    /// `HEAD` Method.
    RGLCProviderHTTPMethodHead,
    /// `POST` Method.
    RGLCProviderHTTPMethodPost,
    /// `PUT` Method.
    RGLCProviderHTTPMethodPut,
    /// `PATCH` Method.
    RGLCProviderHTTPMethodPatch,
    /// `DELETE` Method.
    RGLCProviderHTTPMethodDelete,
};

#endif /* RGLCProviderMethod_h */

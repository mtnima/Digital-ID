//
//  RGLMacros.h
//  DocumentReader
//
//  Created by Pavel Kondrashkov on 8/30/21.
//  Copyright © 2021 Regula. All rights reserved.
//

#define RGL_DEPRECATED(Version, msg) __attribute__((deprecated("Deprecated in DocumentReader " #Version ". " msg)))

#define RGL_EMPTY_INIT_UNAVAILABLE \
    - (instancetype)init __attribute__((unavailable("Not the designated initializer."))); \
    + (instancetype)new __attribute__((unavailable("Not the designated initializer.")));

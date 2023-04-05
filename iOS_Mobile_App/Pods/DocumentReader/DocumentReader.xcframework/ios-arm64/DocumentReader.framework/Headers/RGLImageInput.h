//
//  RGLImageInput.h
//  DocumentReader
//
//  Created by Dmitry Evglevsky on 27.05.22.
//  Copyright © 2022 Regula. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "RGLDocumentReaderGraphicField.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DocReader.ImageInput)
@interface RGLImageInput : NSObject

/**
 An image
 */
@property(nonatomic, strong, readonly, nonnull) UIImage *image;
/**
 Light type, one of RGLGraphicFieldLight values
 */
@property(nonatomic, assign, readonly) RGLGraphicFieldLight lightType;
/**
 An index of the document page whence the graphic field is extracted
 */
@property(nonatomic, assign, readonly) NSInteger pageIndex;

- (instancetype)initWithImage:(UIImage *)image light:(RGLGraphicFieldLight)light pageIndex:(NSInteger)pageIndex;

@end

NS_ASSUME_NONNULL_END

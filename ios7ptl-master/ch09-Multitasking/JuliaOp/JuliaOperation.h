//  Copyright (c) 2012 Rob Napier
//
//  This code is licensed under the MIT License:
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.
//
#import <Foundation/Foundation.h>
#import <complex.h>

@interface JuliaOperation : NSOperation
@property (nonatomic, readwrite, assign) NSUInteger width;
@property (nonatomic, readwrite, assign) NSUInteger height;
@property (nonatomic, readwrite, assign) complex long double c;
@property (nonatomic, readwrite, assign) complex long double blowup;
@property (nonatomic, readwrite, assign) CGFloat contentScaleFactor;
@property (nonatomic, readwrite, assign) NSUInteger rScale;
@property (nonatomic, readwrite, assign) NSUInteger gScale;
@property (nonatomic, readwrite, assign) NSUInteger bScale;
//这个属性在外面使用时，只能够读，不能够写，但是在当前类中，是可读写的

@property (nonatomic, readonly, strong) UIImage *image;
@end

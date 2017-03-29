//
//  SCTViewController.m
//  BlurDemo
//
//  Created by Mugunth on 19/8/13.
//  Copyright (c) 2013 Steinlogic Consulting and Training Pte Ltd. All rights reserved.
//

#import "SCTViewController.h"

#import "UIImage+ImageEffects.h"

@interface SCTViewController ()
@property (nonatomic, strong) IBOutlet UIImageView *bgImageView;
@property (strong, nonatomic) CALayer *layer;
@end

@implementation SCTViewController

- (void)viewDidLoad
{
  [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

-(IBAction)buttonAction:(id)sender {
  //创建一个图层
  self.layer = [CALayer layer];
    //设置图层的frame大小
  self.layer.frame = CGRectMake(0, 0, self.view.bounds.size.width, 300);
    //将图层作为view图层的子图层
  [self.view.layer addSublayer:self.layer];
  float scale = [UIScreen mainScreen].scale;
    //开启位图上下文
  UIGraphicsBeginImageContextWithOptions(self.view.frame.size, YES, scale);
    //首先获得屏幕的截屏
  [self.view drawViewHierarchyInRect:self.view.frame afterScreenUpdates:NO];
  __block UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
  UIGraphicsEndImageContext();
//获取图片中的某个特定区域
  CGImageRef imageRef = CGImageCreateWithImageInRect(image.CGImage,
                                                     CGRectMake(self.layer.frame.origin.x * scale,
                                                                self.layer.frame.origin.y * scale,
                                                                self.layer.frame.size.width * scale,
                                                                self.layer.frame.size.height * scale));
    //CGImage -> UIImage
  image = [UIImage imageWithCGImage:imageRef];
    
  image = [image applyBlurWithRadius:40.0f
                           tintColor:[UIColor colorWithWhite:0.2 alpha:0.2]
               saturationDeltaFactor:0.0f
                           maskImage:self.bgImageView.image];
    //这里不需要创建一个UIImageView，创建一个CALayer就ok
  self.layer.contents = (__bridge id)(image.CGImage);
}

- (void)didReceiveMemoryWarning
{
  [super didReceiveMemoryWarning];
  // Dispose of any resources that can be recreated.
}

@end

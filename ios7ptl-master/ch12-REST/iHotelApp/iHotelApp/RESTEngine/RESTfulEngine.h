//
//  RESTfulEngine.h
//  iHotelApp
//
//  Created by Mugunth on 25/05/11.
//  Copyright 2011 Steinlogic. All rights reserved.
// iHotelApp 核心
//封装了大部分的网络相关操作

#import <Foundation/Foundation.h>
#import "RESTfulOperation.h"
#import "JSONModel.h"

#define kAccessTokenDefaultsKey @"ACCESS_TOKEN"

typedef void (^VoidBlock)(void);
typedef void (^ModelBlock)(JSONModel* aModelBaseObject);
typedef void (^ArrayBlock)(NSMutableArray* listOfModelBaseObjects);
typedef void (^ErrorBlock)(NSError* engineError);
/**
 *  这里专门提供了一个属性。用来访问或设置accessToken。
 */
@interface RESTfulEngine : MKNetworkEngine {

    NSString *_accessToken;
}

@property (nonatomic) NSString *accessToken;

-(id)loginWithName:(NSString*) loginName
           password:(NSString*) password                         
        onSucceeded:(VoidBlock) succeededBlock 
            onError:(ErrorBlock)errorBlock;

-(RESTfulOperation*) fetchMenuItemsOnSucceeded:(ArrayBlock) succeededBlock 
                                       onError:(ErrorBlock) errorBlock;

-(RESTfulOperation*) fetchMenuItemsFromWrongLocationOnSucceeded:(ArrayBlock) succeededBlock 
                                                        onError:(ErrorBlock) errorBlock;
@end

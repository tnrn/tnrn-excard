//
//  EXOCRVECardInfo.h
//  ExCardSDK
//
//  Created by kubo on 16/9/6.
//  Copyright (c) 2015年 kubo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *	@brief 行驶证识别回调状态码
 *
 *	@discussion 识别回调中获取状态码
 */
#define VE_CODE_SUCCESS         (0)
#define VE_CODE_CANCEL          (1)
#define VE_CODE_FAIL            (-1)
#define VE_CODE_FAIL_TIMEOUT    (-2)
#define VE_CODE_INITFAIL        (-3)

/**
 *	@brief 行驶证数据模型类
 */
@interface EXOCRVECardInfo : NSObject

@property (nonatomic, strong) NSString *plateNo;        //号牌号码
@property (nonatomic, strong) NSString *vehicleType;    //车辆类型
@property (nonatomic, strong) NSString *owner;          //所有人
@property (nonatomic, strong) NSString *address;        //住址
@property (nonatomic, strong) NSString *model;          //品牌型号
@property (nonatomic, strong) NSString *useCharacter;   //使用性质
@property (nonatomic, strong) NSString *engineNo;       //发动机号
@property (nonatomic, strong) NSString *VIN;            //车辆识别代码
@property (nonatomic, strong) NSString *registerDate;   //注册日期
@property (nonatomic, strong) NSString *issueDate;      //发证日期

@property (nonatomic, strong) UIImage *fullImg;         //行驶证全图

-(NSString *)toString;

@end

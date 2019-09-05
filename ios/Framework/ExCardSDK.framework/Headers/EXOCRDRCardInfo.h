//
//  EXOCRDRCardInfo.h
//  ExCardSDK
//
//  Created by kubo on 16/9/6.
//  Copyright (c) 2015年 kubo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *	@brief 驾驶证识别回调状态码
 *
 *	@discussion 识别回调中获取状态码
 */
#define DR_CODE_SUCCESS         (0)
#define DR_CODE_CANCEL          (1)
#define DR_CODE_FAIL            (-1)
#define DR_CODE_FAIL_TIMEOUT    (-2)
#define DR_CODE_INITFAIL        (-3)

/**
 *	@brief 驾驶证数据模型类
 */
@interface EXOCRDRCardInfo : NSObject

@property (nonatomic, strong) NSString *name;       //姓名
@property (nonatomic, strong) NSString *sex;        //性别
@property (nonatomic, strong) NSString *nation;     //国籍
@property (nonatomic, strong) NSString *cardId;     //证号(身份证号)
@property (nonatomic, strong) NSString *address;    //住址
@property (nonatomic, strong) NSString *birth;      //出生日期
@property (nonatomic, strong) NSString *issueDate;  //初次领证时间
@property (nonatomic, strong) NSString *driveType;  //准驾车型
@property (nonatomic, strong) NSString *validDate;  //有效期至日期

@property (nonatomic, strong) UIImage *fullImg;     //驾驶证全图
@property (nonatomic, strong) UIImage *faceImg;     //人脸截图

-(NSString *)toString;

@end

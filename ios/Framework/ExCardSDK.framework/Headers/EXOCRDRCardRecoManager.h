//
//  EXOCRDRCardRecoManager.h
//  ExCardSDK
//
//  Created by kubo on 16/9/6.
//  Copyright © 2016年 kubo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EXOCRDRCardInfo.h"

/**
 *	@brief 驾驶证识别回调EXOCRCompletedDRCardBlock, EXOCRCanceledBlock, EXOCRFailedBlock
 *
 *	@discussion 用来设定异步调用的回调
 */
typedef void (^EXOCRCompletedDRCardBlock)(int statusCode, EXOCRDRCardInfo *drInfo);
typedef void (^EXOCRCanceledBlock)(int statusCode);
typedef void (^EXOCRFailedBlock)(int statusCode, UIImage *recoImg);

@interface EXOCRDRCardRecoManager : NSObject
/**
 *	@brief 获取EXOCRDRCardRecoManager实例化对象
 *  @return EXOCRDRCardRecoManager对象
 */
+(instancetype)sharedManager:(UIViewController *)vc;

/**
 * @brief 静态图片识别方法
 * @param image - 待识别静态图像
 * @param completedBlock - 识别成功回调，获取识别结果EXOCRDRCardInfo对象
 * @param EXOCRFailedBlock - 识别失败回调
 */
-(void)recoDRCardFromStillImage:(UIImage *)image
                    OnCompleted:(EXOCRCompletedDRCardBlock)completedBlock
                       OnFailed:(EXOCRFailedBlock)EXOCRFailedBlock;

/**
 * @brief 设置扫描超时时间，默认扫描视图在failblock中回调，自定义扫描视图在代理方法recoTimeout中回调（自定义扫描视图建议自行添加超时逻辑，不使用该接口）
 * @param timeout - 超时时间（默认为0，无超时）
 */
-(void)setRecoTimeout:(NSTimeInterval)timeout;

/**
 * @brief 扫描页面调用方式设置，设置扫描页面调用方式
 * @param bByPresent - 是否以present方式调用，默认为NO，YES-以present方式调用，NO-以sdk默认方式调用(push或present)
 */
-(void)displayScanViewControllerByPresent:(BOOL)bByPresent;

/**
 TabBarController是否交给SDK设置隐藏
 
 @param bControl 是否交给SDK控制（YES:扫描页隐藏TabBarController，退出扫描页时显示;NO:由开发者自行控制TabBarController是否隐藏;默认为YES）
 */
-(void)controlTabBarControllerHiddenBySDK:(BOOL)bControl;

/**
 NavigationrController是否交给SDK设置隐藏
 
 @param bControl 是否交给SDK控制（YES:扫描页隐藏NavigationrController，退出扫描页时显示;NO:由开发者自行控制NavigationrController是否隐藏;默认为YES）
 */
-(void)controlNavigationrControllerHiddenBySDK:(BOOL)bControl;

#pragma mark - 默认扫描视图
/**
 * @brief 调用驾驶证扫描识别(若自定义扫描视图，请使用recoDRCardFromStreamByCustomScanView方法调用识别)
 * @param completedBlock - 识别完成回调，获取识别结果EXOCRDRCardInfo对象
 * @param EXOCRCanceledBlock - 识别取消回调
 * @param EXOCRFailedBlock - 识别失败回调
 */
-(void)recoDRCardFromStreamOnCompleted:(EXOCRCompletedDRCardBlock)completedBlock
                            OnCanceled:(EXOCRCanceledBlock)EXOCRCanceledBlock
                              OnFailed:(EXOCRFailedBlock)EXOCRFailedBlock;

/**
 * @brief 扫描页设置，是否显示logo
 * @param bDisplayLogo - 默认为YES
 */
-(void)setDisplayLogo:(BOOL)bDisplayLogo;

/**
 * @brief 扫描页设置，是否开启本地相册识别
 * @param bEnablePhotoRec - 默认为YES
 */
-(void)setEnablePhotoRec:(BOOL)bEnablePhotoRec;

/**
 扫描页设置，相册识别是否返回原图
 
 @param bOriginalImage 默认为NO
 */
-(void)setPhotoRecoOriginalImage:(BOOL)bOriginalImage;

/**
 扫描页设置，是否在光线较暗时开启闪光灯（仅在默认扫描视图中有效）
 
 @param bAutoFlash 默认为YES
 */
-(void)setAutoFlash:(BOOL)bAutoFlash;

/**
 * @brief 扫描页设置，扫描框颜色
 * @param rgbColor - rgb颜色值(例:0xffffff)
 * @param alpha - 透明度(例：0.8f, 0-1之间)
 */
-(void)setScanFrameColorRGB:(long)rgbColor andAlpha:(float)alpha;

/**
 * @brief 扫描页设置，扫描字体颜色
 * @param rgbColor - rgb颜色值(例:0xffffff)
 */
-(void)setScanTextColorRGB:(long)rgbColor;

/**
 * @brief 扫描页设置，扫描提示文字
 * @param tipStr - 提示文字
 */
-(void)setScanTips:(NSString *)tipStr;

/**
 * @brief 扫描页设置，扫描提示文字字体名称及字体大小
 * @param fontName - 字体名称
 * @param fontSize - 字体大小
 */
-(void)setScanTipsFontName:(NSString *)fontName andFontSize:(float)fontSize;

#pragma mark - 自定义扫描视图
/**
 *	@brief 设置自定义扫描视图，当前版本仅支持横屏识别（若自定义扫描视图，其他扫描页设置接口将无效）
 *         自定义扫描视图frame须与竖屏屏幕大小一致
 *         建议：1.自定义扫描视图frame设置为[UIScreen mainScreen].bounds(须保证width小于height)
 *              2.自定义扫描视图扫描框宽高比设置为720:454，以达到最佳识别效果
 *  @return YES-设置自定义扫描视图成功，NO-设置自定义扫描视图失败
 *  @param customScanView - 自定义扫描试图
 */
-(BOOL)setCustomScanView:(UIView *)customScanView;

/**
 暂停识别（仅在设置自定义扫描视图成功后生效）
 
 @param bShouldStop 是否暂停视频流（默认为NO）
 */
-(void)pauseRecoWithStopStream:(BOOL)bShouldStop;

/**
 继续识别（仅在设置自定义扫描视图成功后生效）
 */
-(void)continueReco;

/**
 *	@brief 退出扫描识别控制器（仅在设置自定义扫描视图成功后生效）
 */
-(void)dismissScanViewControllerAnimated:(BOOL)animated;

/**
 *	@brief 闪光灯开启与关闭（仅在设置自定义扫描视图成功后生效）
 *  @param bMode - 闪光灯模式，YES-打开闪光灯，NO-关闭闪光灯
 */
-(void)setFlashMode:(BOOL)bMode;

/**
 * @brief 调用驾驶证扫描识别(若默认扫描视图，请使用recoDRCardFromStreamOnCompleted:OnCanceled:OnFailed:方法调用识别)
 */
-(void)recoDRCardFromStreamByCustomScanView;
@end

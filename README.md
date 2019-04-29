[![npm][npm-badge]][npm]
[![react-native][rn-badge]][rn]
[![MIT][license-badge]][license]
[![Downloads](https://img.shields.io/npm/dm/tnrn-excard.svg)](https://www.npmjs.com/package/tnrn-excard)

易道博识-图像识别 for [React Native][rn].


[npm-badge]: https://img.shields.io/npm/v/tnrn-excard.svg
[npm]: https://www.npmjs.com/package/tnrn-excard
[rn-badge]: https://img.shields.io/badge/react--native-v0.40-05A5D1.svg
[rn]: https://facebook.github.io/react-native
[license-badge]: https://img.shields.io/dub/l/vibe-d.svg
[license]: https://raw.githubusercontent.com/tnrn/tnrn-excard/master/LICENSE


## Getting Started

First, `cd` to your RN project directory, and install RNMK through [rnpm](https://github.com/rnpm/rnpm) . If you don't have rnpm, you can install RNMK from npm with the command `npm i -S tnrn-excard` and link it manually (see below).

### iOS

* #### React Native < 0.29 (Using rnpm)

  `rnpm install tnrn-excard`

* #### React Native >= 0.29
  `$npm install -S tnrn-excard`

  `$react-native link tnrn-excard`

* ### Notice

  在 `Build Settings->Search Paths->Framework Search Paths` 中加入路径 `$(SRCROOT)/../node_modules/tnrn-excard/ios/Framework`

  在 `Build Settings->Link->Other Linker Flags` 中加入 `-framework "ExCardSDK"` 和 `-framework "ExBankCardSDK"`

  最后还需要手动导入 `bundle` 资源文件：

  在主工程中找到 `Libraries` 下面的 `RNKitExcard`，然后找到 `Framework` 文件夹，鼠标右键 `show in finder`，然后将里面的两个 `.bundle` 文件拖入主工程中

### Android

* #### React Native < 0.29 (Using rnpm)

  `rnpm install tnrn-excard`

* #### React Native >= 0.29
  `$npm install -S tnrn-excard`

  `$react-native link tnrn-excard`

#### Manually
1. JDK 7+ is required
1. Add the following snippet to your `android/settings.gradle`:

  ```gradle
include ':tnrn-excard'
project(':tnrn-excard').projectDir = new File(rootProject.projectDir, '../node_modules/tnrn-excard/android/app')
  ```
  
1. Declare the dependency in your `android/app/build.gradle`
  
  ```gradle
  dependencies {
      ...
      compile project(':tnrn-excard')
  }
  ```
  
1. Import `import io.tnrn.excard.EXOCRPackage;` and register it in your `MainActivity` (or equivalent, RN >= 0.32 MainApplication.java):

  ```java
  @Override
  protected List<ReactPackage> getPackages() {
      return Arrays.asList(
              new MainReactPackage(),
              new EXOCRPackage()
      );
  }
  ```
1. Add Module `ExBankCardSDK` And `ExCardSDK` In Your Main Project.

Finally, you're good to go, feel free to require `tnrn-excard` in your JS files.

Have fun! :metal:

## Basic Usage

Import library

```
import RNExcard from 'tnrn-excard';
```

### Init

```jsx
RNExcard.config({
  DisplayLogo: false
  ....
})
```

#### Init Params

| Key | Type | Default | Description |
| --- | --- | --- | --- |
| OrientationMask | string | 'MaskAll' | 方向设置，设置扫描页面支持的识别方向 |
| ByPresent | BOOL | NO | 扫描页面调用方式设置,是否以present方式调用，默认为NO，YES-以present方式调用，NO-以sdk默认方式调用(push或present) |
| NumberOfSpace | BOOL | YES | 结果设置，银行卡号是否包含空格 |
| DisplayLogo | BOOL | YES | 是否显示logo |
| EnablePhotoRec | BOOL | YES | EnablePhotoRec |
| FrameColor | int |  | 扫描框颜色, 必须与FrameAlpha共同设置 |
| FrameAlpha | float |  | 扫描框透明度, 必须与FrameColor共同设置 |
| ScanTextColor | int |  | 扫描字体颜色 |
| IDCardScanNormalTextColor | int |  | 正常状态扫描字体颜色 (身份证) |
| IDCardScanErrorTextColor | int |  | 错误状态扫描字体颜色 (身份证) |
| BankScanTips | string | | 银行卡扫描提示文字 |
| DRCardScanTips | string | | 驾驶证扫描提示文字 |
| VECardScanTips | string | | 行驶证扫描提示文字 |
| BankScanTips | string | | 银行卡扫描提示文字 |
| IDCardScanFrontNormalTips | string | | 身份证正常状态正面扫描提示文字 |
| IDCardScanFrontErrorTips | string | | 身份证错误状态正面扫描提示文字 |
| IDCardScanBackNormalTips | string | | 身份证正常状态背面扫描提示文字 |
| IDCardScanBackErrorTips | string | | 身份证错误状态背面扫描提示文字 |
| fontName | string | | 扫描提示文字字体名称 |
| ScanTipsFontSize | float | | 扫描提示文字字体大小 |
| IDCardNormalFontName | string | | 正常状态扫描提示文字字体名称 |
| IDCardNormalFontSize | float | | 正常状态扫描提示文字字体大小 |
| IDCardErrorFontName | string | | 错误状态扫描提示文字字体名称 |
| IDCardErrorFontSize | float | | 错误状态扫描提示文字字体大小 |
| quality | float | | 图片清晰度, 范围(0-1) |

##### OrientationMask

- Portrait
- LandscapeLeft
- LandscapeRight
- PortraitUpsideDown
- Landscape
- MaskAll
- AllButUpsideDown

### 一、银行卡识别

#### 1. 使用摄像头、相册识别

```jsx
try {
	const result = await RNExcard.recoBankFromStream();
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

#### 2. 使用远程或本地图片识别

```jsx
try {
	const imagePath = '...';
	const result = await RNExcard.recoBankFromStillImage(imagePath);
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

返回值

| Key | Type | Default | Description |
| --- | --- | --- | --- |
| bankName | string |  | 银行名称 |
| cardName | string |  | 卡名称 |
| cardType | string |  | 卡类型 |
| cardNum | string |  | 卡号 |
| validDate | string |  | 有限期 |
| fullImgPath | string |  | 银行卡全图 |
| cardNumImgPath | string |  | 银行卡号截图 |

### 二、驾驶证识别

#### 1. 使用摄像头、相册识别

```jsx
try {
	const result = await RNExcard.recoDRCardFromStream();
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

#### 2. 使用远程或本地图片识别

```jsx
try {
	const imagePath = '...';
	const result = await RNExcard.recoDRCardFromStillImage(imagePath);
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

返回值

| Key | Type | Default | Description |
| --- | --- | --- | --- |
| name | string |  | 姓名 |
| sex | string |  | 性别 |
| nation | string |  | 国籍 |
| cardId | string |  | 身份证号码 |
| address | string |  | 住址 |
| birth | string |  | 出生日期 |
| issueDate | string |  | 初次领证时间 |
| driveType | string |  | 准驾车型 |
| validDate | string |  | 有效期至日期 |
| fullImgPath | string |  | 驾驶证全图 |

### 三、行驶证识别

#### 1. 使用摄像头、相册识别

```jsx
try {
	const result = await RNExcard.recoVECardFromStream();
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

#### 2. 使用远程或本地图片识别

```jsx
try {
	const imagePath = '...';
	const result = await RNExcard.recoVECardFromStillImage(imagePath);
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

返回值

| Key | Type | Default | Description |
| --- | --- | --- | --- |
| plateNo | string |  | 号牌号码 |
| vehicleType | string |  | 车辆类型 |
| owner | string |  | 所有人 |
| address | string |  | 住址 |
| model | string |  | 品牌型号 |
| useCharacter | string |  | 使用性质 |
| engineNo | string |  | 发动机号 |
| VIN | string |  | 车辆识别代码 |
| registerDate | string |  | 注册日期 |
| issueDate | string |  | 发证日期 |
| fullImgPath | string |  | 行驶证全图 |

### 四、身份证识别

#### 1. 使用摄像头、相册识别

```jsx
try {
	const bFront = true  // 身份证方向，true-正面，false-背面
	const result = await RNExcard.recoIDCardFromStreamWithSide(bFront);
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

#### 2. 使用远程或本地图片识别

```jsx
try {
	const imagePath = '...';
	const result = await RNExcard.recoIDCardFromStillImage(imagePath);
} catch (error) {
	if (error.code === -1) {
		console.log('on cancel')
	} else {
		console.log(error)
	}
}
```

返回值

| Key | Type | Default | Description |
| --- | --- | --- | --- |
| type | int |  | 1:正面  2:反面 |
| name | string |  | 姓名 |
| gender | string |  | 性别 |
| nation | string |  | 名族 |
| birth | string |  | 出生 |
| address | string |  | 地址 |
| code | string |  | 身份证 |
| issue | string |  | 签发机关 |
| valid | string |  | 有效期 |
| frontShadow | int |  | 1:正面图像有遮挡 0:正面图像无遮挡 |
| backShadow | int |  | 1:背面图像有遮挡 0:背面图像无遮挡 |
| faceImgPath | string |  | 人脸截图 |
| frontFullImgPath | string |  | 身份证正面全图 |
| backFullImgPath | string | | 身份证背面全图 |

### 五、常量

```jsx
const sdkVersion = RNExcard.sdkVersion;
const kernelVersion = RNExcard.kernelVersion;
```

| Key | Type | Default | Description |
| --- | --- | --- | --- |
| sdkVersion | string |  | sdk版本号 |
| kernelVersion | string |  | 识别核心版本号 |

### 六、clean 清理图片临时目录

```jsx
try {
	const result = await RNExcard.clean();
} catch (error) {
	console.log(error)
}
```

## Contribution

- [@simamn](mailto:liwei0990@gmail.com) The main author.

## Questions

Feel free to [contact me](mailto:liwei0990@gmail.com) or [create an issue](https://github.com/tnrn/tnrn-excard/issues/new)

> made with ♥

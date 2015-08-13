
本项目演示了把一个c语言的库, 进行封装并移植到不同平台的方法。 
目前是在Windows平台下进行编码、编译及演示。Windows平台编译，三星安卓真机测试通过。
本文档需要完善，目前只写了粗略概要.
本文实践过程中,作者参考了一些常用库的使用方法,如BaiduLBS_AndroidSDK_Lib.zip。


1 目录介绍

1.1 demo_third_lib 
表示某个c语言编写的第三方开源库. 如libevent,libpcap等. 本项目演示了如何把开源库编译成特定平台的方法,如android(ARM)平台(本文生成静态库).

1.2 demo_my_c_lib 
对 demo_third_lib 生成的开源库的封装, 并加入适当的业务逻辑. 比如调用libevent接口自动重连服务器的功能逻辑. 再比如报文的编解码等业务实现.  本项目需要调用 demo_third_lib 的库, 生成特定平台的库(本文生成静态库).

1.3 demo_android_sdk 
一个普通的java项目, 对 demo_my_c_lib 提供的接口用java接口来转换,使开发者方便的用于安卓项目中. 这类项目通常是一个普通的jni封装,使c接口变为java接口. 本项目中演示了把底层c接口变换后, 生成一个jar包及动态库的方法.

1.4 demo_android_sdk_test 
一个普通的android application项目. 本项目引入了 demo_android_sdk 生成的jar包和so动态库. 通过调用jar包的java函数来调用了底层的c语言函数. 开发者对于底层c语言库不需要了解过多,只需要知道 demo_android_sdk 提供的jar包的各接口即可.

1.5 demo_ios_sdk 
对 demo_my_c_lib 提供的接口用object-c接口来转换,使开发者方便的用于ios项目中. 

1.6 demo_ios_sdk_test 
一个普通的 ios 项目. 本项目引入了 demo_ios_sdk 生成的动态库. 


2 未完成列表

2.1 完成其它平台演示. 如ios平台. windows、linux不在本文讨论范围.

2.2 完成开源库真正引入,并实际调用演示, 如libevent, libpcap

2.3 事件的实现. 如c语言库如何向android库发送事件通知.



3 在其它开发平台编译

本文所述项目是在Windows7平台下编译、测试通过的。
在Ubuntu平台、MAC平台如何进行编译演示待完成.
作者开发测试环境如下,
ndk: android-ndk-r10e
sdk: android-19
adt: ecplise-adt v22.6.2
device: samsung GT-I9220(NOTE1)



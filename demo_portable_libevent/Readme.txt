
本项目演示了把libevent移植到android及ios平台的方法.
涉及交叉编译、jni等技术.
其中libevent 在android平台移植完成,在三星真机测试通过,成功在手机上通过libevent的tcp连接到服务端. 
在ios平台移植待完成.

demo_lib_libevent 是 libevent的arm平台移植.
demo_lib_easynetwork 是 使用libevent封装自己的业务逻辑.
demo_easynetwork_sdk 是 通过jni把 demo_lib_easynetwork 转换成 java接口.
demo_easynetwork_sdk_test 是 普通android应用程序,导入了demo_easynetwork_sdk输出的jar包和so库,成功调用到底层c封装的函数.


读者可参照另一项目 demo_portable_library.


本项目的参考资料:

NDK 调用第三方库及系统库的分析
http://blog.csdn.net/m_rabbits/article/details/46740987

在Ubuntu上交叉编译Android libevent库
http://blog.csdn.net/sozell/article/details/8898646

使用cygwin和NDK编译Android版本的libevent
http://blog.csdn.net/sozell/article/details/8914735

Android.mk简介
http://blog.csdn.net/hudashi/article/details/7059006

关于Android NDK中调用第三方的动态库
http://android100.cnblogs.com/p/android-sdk-config.html

JAVA基础之理解JNI原理
http://www.cnblogs.com/mandroid/archive/2011/06/15/2081093.html

Android开发实践：JNI层线程回调Java函数示例
http://ticktick.blog.51cto.com/823160/1358558

当JNI遇到多线程－－java对象如何被C++中的多个线程访问?
http://blog.csdn.net/hust_liuX/article/details/1460486

JNI总结
http://www.cnblogs.com/chang290/archive/2012/10/04/2711411.html

JNI学习二：字符串参数传递与返回值
http://blog.csdn.net/zgyulongfei/article/details/7409441

android ndk jni 字符串 String jstring
http://jingyan.baidu.com/article/a3a3f811e0fc248da2eb8a00.html

jstring 与 wchar_t 的那点事
http://www.2cto.com/kf/201406/312201.html

android ndk 开发建议
http://jingyan.baidu.com/article/ac6a9a5e7dbe282b653eac9b.html



在Ubuntu_12.04上交叉编译成功.
源码从下面下载得到
https://github.com/ventureresearch/libevent

笔者是通过下面这篇文章中说的 configure.sh 方式来编译的,
在Ubuntu上交叉编译Android libevent库
http://blog.csdn.net/sozell/article/details/8898646

该源码包中与官方包相比多了Android.mk，所以理论上可以用$NDK/ndk-build来编译. 作者暂未使用这种方式来编译测试.


另外, 查阅过程发现了该文章, 在android上使用libevent进行dns解析时要注意一下。
libevent 在 Android 上的一个改进
http://www.2cto.com/kf/201401/270520.html

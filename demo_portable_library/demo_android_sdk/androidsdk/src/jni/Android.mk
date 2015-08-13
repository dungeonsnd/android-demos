######################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := libmyc
LOCAL_SRC_FILES := ./../../../../demo_my_c_lib/obj/local/armeabi/libmyc.a
include $(PREBUILT_STATIC_LIBRARY) 


include $(CLEAR_VARS)  
LOCAL_MODULE := thirdlib
LOCAL_SRC_FILES := ./../../../../demo_third_lib/obj/local/armeabi/libthirdlib.a
include $(PREBUILT_STATIC_LIBRARY) 


include $(CLEAR_VARS)
LOCAL_MODULE    := TestSdk
LOCAL_SRC_FILES := com_cy_androidsdk_TestSdk.c
LOCAL_C_INCLUDES := ./../../../demo_my_c_lib/jni/include
LOCAL_STATIC_LIBRARIES :=libmyc libthirdlib
include $(BUILD_SHARED_LIBRARY)

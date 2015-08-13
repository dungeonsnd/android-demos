######################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := thirdlib
LOCAL_SRC_FILES := ./../../demo_third_lib/obj/local/armeabi/libthirdlib.a  
LOCAL_EXPORT_C_INCLUDES := ./../../demo_third_lib/jni/include
include $(PREBUILT_STATIC_LIBRARY) 


include $(CLEAR_VARS)
LOCAL_MODULE    := myc
LOCAL_SRC_FILES := src/myc.c
LOCAL_C_INCLUDES := ./../demo_third_lib/jni/include
LOCAL_STATIC_LIBRARIES :=libthirdlib
include $(BUILD_STATIC_LIBRARY)

######################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := thirdlib
LOCAL_SRC_FILES := ./../../demo_lib_libevent/obj/local/armeabi/libevent_core.a  
include $(PREBUILT_STATIC_LIBRARY) 


include $(CLEAR_VARS)
LOCAL_MODULE    := easynetwork
LOCAL_SRC_FILES := src/easynetwork.cpp src/event_util.cpp
LOCAL_C_INCLUDES := ../demo_lib_libevent/include ./jni/include
LOCAL_STATIC_LIBRARIES :=libevent_core
include $(BUILD_STATIC_LIBRARY)

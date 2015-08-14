######################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := libeasynetwork
LOCAL_SRC_FILES := ../../demo_lib_easynetwork/obj/local/armeabi/libeasynetwork.a
include $(PREBUILT_STATIC_LIBRARY) 


include $(CLEAR_VARS)  
LOCAL_MODULE := libevent_core
LOCAL_SRC_FILES := ../../demo_lib_libevent/obj/local/armeabi/libevent_core.a
include $(PREBUILT_STATIC_LIBRARY) 


include $(CLEAR_VARS)
LOCAL_MODULE    := easynetwork4j
LOCAL_SRC_FILES := com_cy_easynetwork_EasyNetwork.c
LOCAL_C_INCLUDES := ../demo_lib_easynetwork/jni/include
LOCAL_STATIC_LIBRARIES :=libeasynetwork libevent_core
LOCAL_LDLIBS :=  -L$(SYSROOT)/usr/lib -llog
include $(BUILD_SHARED_LIBRARY)

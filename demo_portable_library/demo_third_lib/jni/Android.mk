######################################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := thirdlib
LOCAL_SRC_FILES := src/main.c src/add.c

include $(BUILD_STATIC_LIBRARY)

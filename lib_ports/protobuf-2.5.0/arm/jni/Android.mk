################## Build ProtoBuf ################
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_ARM_MODE := arm
LOCAL_CPPFLAGS += -frtti
LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := libprotobuf
LOCAL_MODULE_TAGS := optional
LOCAL_CPP_EXTENSION := .cc

LOCAL_SRC_FILES := \
src/protobuf-2.5.0/src/google/protobuf/io/coded_stream.cc                \
src/protobuf-2.5.0/src/google/protobuf/stubs/common.cc                   \
src/protobuf-2.5.0/src/google/protobuf/descriptor.cc                     \
src/protobuf-2.5.0/src/google/protobuf/descriptor.pb.cc                  \
src/protobuf-2.5.0/src/google/protobuf/descriptor_database.cc            \
src/protobuf-2.5.0/src/google/protobuf/dynamic_message.cc                \
src/protobuf-2.5.0/src/google/protobuf/extension_set.cc                  \
src/protobuf-2.5.0/src/google/protobuf/extension_set_heavy.cc            \
src/protobuf-2.5.0/src/google/protobuf/generated_message_reflection.cc   \
src/protobuf-2.5.0/src/google/protobuf/generated_message_util.cc         \
src/protobuf-2.5.0/src/google/protobuf/io/gzip_stream.cc                 \
src/protobuf-2.5.0/src/google/protobuf/compiler/importer.cc              \
src/protobuf-2.5.0/src/google/protobuf/message.cc                        \
src/protobuf-2.5.0/src/google/protobuf/message_lite.cc                   \
src/protobuf-2.5.0/src/google/protobuf/stubs/once.cc                     \
src/protobuf-2.5.0/src/google/protobuf/compiler/parser.cc                \
src/protobuf-2.5.0/src/google/protobuf/io/printer.cc                     \
src/protobuf-2.5.0/src/google/protobuf/reflection_ops.cc                 \
src/protobuf-2.5.0/src/google/protobuf/repeated_field.cc                 \
src/protobuf-2.5.0/src/google/protobuf/service.cc                        \
src/protobuf-2.5.0/src/google/protobuf/stubs/structurally_valid.cc       \
src/protobuf-2.5.0/src/google/protobuf/stubs/strutil.cc                  \
src/protobuf-2.5.0/src/google/protobuf/stubs/substitute.cc               \
src/protobuf-2.5.0/src/google/protobuf/text_format.cc                    \
src/protobuf-2.5.0/src/google/protobuf/io/tokenizer.cc                   \
src/protobuf-2.5.0/src/google/protobuf/unknown_field_set.cc              \
src/protobuf-2.5.0/src/google/protobuf/wire_format.cc                    \
src/protobuf-2.5.0/src/google/protobuf/wire_format_lite.cc               \
src/protobuf-2.5.0/src/google/protobuf/io/zero_copy_stream.cc            \
src/protobuf-2.5.0/src/google/protobuf/io/zero_copy_stream_impl.cc       \
src/protobuf-2.5.0/src/google/protobuf/io/zero_copy_stream_impl_lite.cc  \


LOCAL_C_INCLUDES += . \
$(LOCAL_PATH)/src/protobuf-2.5.0/src \
$(LOCAL_PATH)/src/protobuf-2.5.0

LOCAL_LDLIBS := -llog -lgcc -lpthread \
      $NDK/sources/cxx-stl/gnu-libstdc++/4.9/libs/armeabi/libgnustl_static.a

#ifndef NDK_ROOT
#include external/stlport/libstlport.mk
#endif
include $(BUILD_STATIC_LIBRARY)



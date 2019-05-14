LOCAL_PATH := $(call my-dir)

#
# libdebugservice_jni.so
#
include $(CLEAR_VARS)

LOCAL_MODULE := libdebugservice_jni
LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := \
    $(TOP)/external/debugger/include    \

LOCAL_SRC_FILES :=      \
    Debugger_jni.cpp    \

LOCAL_SHARED_LIBRARIES := \
    libutils            \
    libcutils           \
    libbinder           \
    libnativehelper     \
    libandroid_runtime  \
    libdebugservice     \

include $(BUILD_SHARED_LIBRARY)

include $(call all-makefiles-under,$(LOCAL_PATH))

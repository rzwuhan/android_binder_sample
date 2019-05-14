LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libdebugservice
LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := \
    $(TOP)/external/debugger/include    \

LOCAL_SRC_FILES := \
    IDebugger.cpp           \
    IDebuggerListener.cpp   \

LOCAL_SHARED_LIBRARIES := \
    libutils        \
    libcutils       \
    libbinder       \

include $(BUILD_SHARED_LIBRARY)

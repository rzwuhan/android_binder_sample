LOCAL_PATH := $(call my-dir)

#
# debugger_sample
#
include $(CLEAR_VARS)

LOCAL_MODULE := debugger_sample
LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := \
    $(TOP)/external/debugger/include    \

LOCAL_SRC_FILES := \
    main.cpp      \

LOCAL_SHARED_LIBRARIES := \
    libutils        \
    libcutils       \
    libbinder       \
    libdebugservice \

include $(BUILD_EXECUTABLE)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := debugserver
LOCAL_MODULE_TAGS := optional

LOCAL_C_INCLUDES := \
    $(TOP)/external/debugger/include    \

LOCAL_SRC_FILES := \
    DebuggerService.cpp \
    main_server.cpp     \

LOCAL_SHARED_LIBRARIES := \
    libutils        \
    libcutils       \
    libbinder       \
    libdebugservice \

include $(BUILD_EXECUTABLE)

#define LOG_NDEBUG 0
#define LOG_TAG "DebuggerService"

#include <binder/IMemory.h>
#include <cutils/debugger.h>

#include "IDebuggerListener.h"
#include "DebuggerService.h"

using namespace android;

DebuggerService::DebuggerService() :
        mListener(NULL) {
    ALOGI("DebuggerService started (pid=%d)", getpid());
}

DebuggerService::~DebuggerService() {
    ALOGI("%s", __func__);
}

void DebuggerService::dumpBacktrace(const int pid, const int fd) {
    ALOGI("%s", __func__);
    dump_backtrace_to_file(pid, fd);
}

void DebuggerService::dumpBacktraceAsync(const int pid) {
    ALOGI("%s", __func__);
}

void DebuggerService::setListener(const sp<IDebuggerListener> &listener) {
    ALOGI("%s", __func__);
    if (mListener != NULL)
        mListener.clear();

    mListener = listener;
}




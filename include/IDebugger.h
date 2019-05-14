#ifndef ANDROID_IDEBUGGER_H
#define ANDROID_IDEBUGGER_H

#include <cutils/native_handle.h>
#include <binder/IInterface.h>

namespace android {

class IDebuggerListener;

/**
 * interface for client and service
 *
 * BpDebugger是代理端(调用进程)实现类
 * BnDebugger(服务进程)实现类
 */
class IDebugger : public IInterface {

public:

    DECLARE_META_INTERFACE(Debugger);

    virtual void dumpBacktrace(const int pid, const int fd) = 0;

    virtual void dumpBacktraceAsync(const int pid) = 0;

    virtual void setListener(const sp<IDebuggerListener> &listener) = 0;

    static char const *getServiceName() { return "my.debugger.service"; }
};

// ----------------------------------------------------------------------------

class BnDebugger : public BnInterface<IDebugger> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel &data,
                                Parcel *reply,
                                uint32_t flags = 0);
};

} // namespace android

#endif
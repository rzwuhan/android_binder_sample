#ifndef ANDROID_IDEBUGGER_SERVICE_H
#define ANDROID_IDEBUGGER_SERVICE_H

#include <binder/BinderService.h>

#include "IDebugger.h"
#include "IDebuggerListener.h"

namespace android {

class DebuggerService :
        public BinderService<DebuggerService>,
        public BnDebugger {

    friend class BinderService<DebuggerService>;

public:
    /////////////////////////////////////////////////////////////////////
    // Implementation of BinderService<T>
    static char const *getServiceName() { return IDebugger::getServiceName(); }

    DebuggerService();

    virtual ~DebuggerService();

    /////////////////////////////////////////////////////////////////////
    // Implementation of IDebugger
    virtual void dumpBacktrace(const int pid, const int fd);

    virtual void dumpBacktraceAsync(const int pid);

    virtual void setListener(const sp<IDebuggerListener> &listener);


private:
    sp<IDebuggerListener>     mListener;
};

} // namespace android

#endif //ANDROID_IDEBUGGER_SERVICE_H

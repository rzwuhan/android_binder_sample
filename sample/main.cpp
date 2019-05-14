#define LOG_NDEBUG 0
#define LOG_TAG "DebuggerSample"

#include <utils/Log.h>
#include <binder/BinderService.h>
#include <binder/MemoryHeapBase.h>

#include "IDebugger.h"

using namespace android;

sp<IDebugger> getService() {
    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder = sm->getService(String16(IDebugger::getServiceName()));
    if (binder == NULL) {
        ALOGE("get service failed [%s]", __func__);
        return NULL;
    }
    sp<IDebugger> service = interface_cast<IDebugger>(binder);
    if (service == NULL) {
        ALOGE("cast service to IDebugger failed [%s]", __func__);
        return NULL;
    }
    return service;
}

int main() {
    getService()->dumpBacktrace(1, STDOUT_FILENO);
    return 0;
}

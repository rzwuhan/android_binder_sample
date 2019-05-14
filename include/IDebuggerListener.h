#ifndef ANDROID_IDEBUGGER_LISTENER_H
#define ANDROID_IDEBUGGER_LISTENER_H

#include <binder/IInterface.h>
#include <binder/IMemory.h>

namespace android {

// 回调数据类型
enum {
    IDEBUGGER_MSG_BACKTRACE,
};

class IDebuggerListener : public IInterface {
public:
    DECLARE_META_INTERFACE(DebuggerListener);

    virtual void dataCallback(int32_t msgType, const sp<IMemoryHeap> &memory) = 0;
};

class BnDebuggerListener : public BnInterface<IDebuggerListener> {
public:
    virtual status_t onTransact(uint32_t code,
                                const Parcel &data,
                                Parcel *reply,
                                uint32_t flags = 0);
};

}

#endif //ANDROID_IDEBUGGER_LISTENER_H

#include <binder/Parcel.h>

#include "IDebuggerListener.h"

namespace android {

enum {
    DATA_CALLBACK = IBinder::FIRST_CALL_TRANSACTION,
};

class BpDebuggerListener : public BpInterface<IDebuggerListener> {
public:
    BpDebuggerListener(const sp<IBinder> &impl) :
            BpInterface<IDebuggerListener>(impl) {
    }

    virtual void dataCallback(int32_t msgType, const sp<IMemoryHeap> &memory) {
        Parcel data, reply;
        data.writeInterfaceToken(IDebuggerListener::getInterfaceDescriptor());
        data.writeInt32(msgType);
        data.writeStrongBinder(IInterface::asBinder(memory));
        remote()->transact(DATA_CALLBACK, data, &reply);
    }
};

IMPLEMENT_META_INTERFACE(DebuggerListener, "my.libservice.listener");

// ----------------------------------------------------------------------------

status_t BnDebuggerListener::onTransact(
        uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags) {
    switch (code) {
        case DATA_CALLBACK: {
            CHECK_INTERFACE(Itestbinder, data, reply);
            int32_t msgType = data.readInt32();
            sp<IMemoryHeap> memory = interface_cast<IMemoryHeap>(data.readStrongBinder());
            dataCallback(msgType, memory);
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
}

}

#include <binder/Parcel.h>
#include <binder/IMemory.h>

#include "IDebugger.h"
#include "IDebuggerListener.h"

namespace android {

enum {
    DUMP_BACKTRACE = IBinder::FIRST_CALL_TRANSACTION,
    DUMP_BACKTRACE_ASYNC,
    SET_CALLBACK,
};

class BpDebugger : public BpInterface<IDebugger> {
public:
    BpDebugger(const sp<IBinder> &impl)
        : BpInterface<IDebugger>(impl) {
    }

    void dumpBacktrace(const int pid, const int fd) {
        Parcel data, reply;
        data.writeInterfaceToken(IDebugger::getInterfaceDescriptor());
        data.writeInt32(pid);
        data.writeFileDescriptor(fd);
        remote()->transact(DUMP_BACKTRACE, data, &reply);
    }

    void dumpBacktraceAsync(const int pid) {
        Parcel data, reply;
        data.writeInterfaceToken(IDebugger::getInterfaceDescriptor());
        data.writeInt32(pid);
        remote()->transact(DUMP_BACKTRACE_ASYNC, data, &reply);
    }

    void setListener(const sp<IDebuggerListener> &listener) {
        Parcel data, reply;
        data.writeInterfaceToken(IDebugger::getInterfaceDescriptor());
        data.writeStrongBinder(IInterface::asBinder(listener));
        remote()->transact(SET_CALLBACK, data, &reply);
    }

};

IMPLEMENT_META_INTERFACE(Debugger, IDebugger::getServiceName());

// ----------------------------------------------------------------------

status_t BnDebugger::onTransact(
    uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags) {
    CHECK_INTERFACE(IDebugger, data, reply);
    switch (code) {
        case DUMP_BACKTRACE: {
            int pid = data.readInt32();
            int fd = data.readFileDescriptor();
            dumpBacktrace(pid, fd);
            return NO_ERROR;
        }
        case DUMP_BACKTRACE_ASYNC: {
            int pid = data.readInt32();
            dumpBacktraceAsync(pid);
            return NO_ERROR;
        }
        case SET_CALLBACK: {
            sp<IDebuggerListener> listener = interface_cast<IDebuggerListener>(data.readStrongBinder());
            setListener(listener);
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
}

}

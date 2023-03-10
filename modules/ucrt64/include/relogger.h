/*** Autogenerated by WIDL 8.0-rc1 from include/relogger.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __relogger_h__
#define __relogger_h__

#ifndef __WIDL_INLINE
#if defined(__cplusplus) || defined(_MSC_VER)
#define __WIDL_INLINE inline
#elif defined(__GNUC__)
#define __WIDL_INLINE __inline__
#endif
#endif

/* Forward declarations */

#ifndef __ITraceEvent_FWD_DEFINED__
#define __ITraceEvent_FWD_DEFINED__
typedef interface ITraceEvent ITraceEvent;
#ifdef __cplusplus
interface ITraceEvent;
#endif /* __cplusplus */
#endif

#ifndef __ITraceEventCallback_FWD_DEFINED__
#define __ITraceEventCallback_FWD_DEFINED__
typedef interface ITraceEventCallback ITraceEventCallback;
#ifdef __cplusplus
interface ITraceEventCallback;
#endif /* __cplusplus */
#endif

#ifndef __ITraceRelogger_FWD_DEFINED__
#define __ITraceRelogger_FWD_DEFINED__
typedef interface ITraceRelogger ITraceRelogger;
#ifdef __cplusplus
interface ITraceRelogger;
#endif /* __cplusplus */
#endif

#ifndef __CTraceRelogger_FWD_DEFINED__
#define __CTraceRelogger_FWD_DEFINED__
#ifdef __cplusplus
typedef class CTraceRelogger CTraceRelogger;
#else
typedef struct CTraceRelogger CTraceRelogger;
#endif /* defined __cplusplus */
#endif /* defined __CTraceRelogger_FWD_DEFINED__ */

/* Headers for imported files */

#include <unknwn.h>
#include <oaidl.h>
#include <ocidl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _EVENT_DESCRIPTOR {
    USHORT Id;
    UCHAR Version;
    UCHAR Channel;
    UCHAR Level;
    UCHAR Opcode;
    USHORT Task;
    ULONGLONG Keyword;
} EVENT_DESCRIPTOR;
typedef struct _EVENT_DESCRIPTOR *PEVENT_DESCRIPTOR;
typedef const EVENT_DESCRIPTOR *PCEVENT_DESCRIPTOR;
typedef struct _EVENT_HEADER {
    USHORT Size;
    USHORT HeaderType;
    USHORT Flags;
    USHORT EventProperty;
    ULONG ThreadId;
    ULONG ProcessId;
    LARGE_INTEGER TimeStamp;
    GUID ProviderId;
    EVENT_DESCRIPTOR EventDescriptor;
    union {
        struct {
            ULONG KernelTime;
            ULONG UserTime;
        } DUMMYSTRUCTNAME;
        ULONG64 ProcessorTime;
    } DUMMYUNIONNAME;
    GUID ActivityId;
} EVENT_HEADER;
typedef struct _EVENT_HEADER *PEVENT_HEADER;
typedef struct _ETW_BUFFER_CONTEXT {
    union {
        struct {
            UCHAR ProcessorNumber;
            UCHAR Alignment;
        } DUMMYSTRUCTNAME;
        USHORT ProcessorIndex;
    } DUMMYUNIONNAME;
    USHORT LoggerId;
} ETW_BUFFER_CONTEXT;
typedef struct _ETW_BUFFER_CONTEXT *PETW_BUFFER_CONTEXT;
typedef struct _EVENT_HEADER_EXTENDED_DATA_ITEM {
    USHORT Reserved1;
    USHORT ExtType;
    USHORT Linkage;
    USHORT DataSize;
    ULONGLONG DataPtr;
} EVENT_HEADER_EXTENDED_DATA_ITEM;
typedef struct _EVENT_HEADER_EXTENDED_DATA_ITEM *PEVENT_HEADER_EXTENDED_DATA_ITEM;
typedef struct _EVENT_RECORD {
    EVENT_HEADER EventHeader;
    ETW_BUFFER_CONTEXT BufferContext;
    USHORT ExtendedDataCount;
    USHORT UserDataLength;
    EVENT_HEADER_EXTENDED_DATA_ITEM *ExtendedData;
    void *UserData;
    void *UserContext;
} EVENT_RECORD;
typedef struct _EVENT_RECORD *PEVENT_RECORD;
typedef ULONG64 TRACEHANDLE;
typedef ULONG64 *PTRACEHANDLE;
/*****************************************************************************
 * ITraceEvent interface
 */
#ifndef __ITraceEvent_INTERFACE_DEFINED__
#define __ITraceEvent_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITraceEvent, 0x8cc97f40, 0x9028, 0x4ff3, 0x9b,0x62, 0x7d,0x1f,0x79,0xca,0x7b,0xcb);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("8cc97f40-9028-4ff3-9b62-7d1f79ca7bcb")
ITraceEvent : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Clone(
        ITraceEvent **NewEvent) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetUserContext(
        void **UserContext) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetEventRecord(
        PEVENT_RECORD *EventRecord) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetPayload(
        BYTE *Payload,
        ULONG PayloadSize) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetEventDescriptor(
        PCEVENT_DESCRIPTOR EventDescriptor) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetProcessId(
        ULONG ProcessId) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetProcessorIndex(
        ULONG ProcessorIndex) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetThreadId(
        ULONG ThreadId) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetThreadTimes(
        ULONG KernelTime,
        ULONG UserTime) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetActivityId(
        LPCGUID ActivityId) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetTimeStamp(
        LARGE_INTEGER *TimeStamp) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetProviderId(
        LPCGUID ProviderId) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITraceEvent, 0x8cc97f40, 0x9028, 0x4ff3, 0x9b,0x62, 0x7d,0x1f,0x79,0xca,0x7b,0xcb)
#endif
#else
typedef struct ITraceEventVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITraceEvent *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITraceEvent *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITraceEvent *This);

    /*** ITraceEvent methods ***/
    HRESULT (STDMETHODCALLTYPE *Clone)(
        ITraceEvent *This,
        ITraceEvent **NewEvent);

    HRESULT (STDMETHODCALLTYPE *GetUserContext)(
        ITraceEvent *This,
        void **UserContext);

    HRESULT (STDMETHODCALLTYPE *GetEventRecord)(
        ITraceEvent *This,
        PEVENT_RECORD *EventRecord);

    HRESULT (STDMETHODCALLTYPE *SetPayload)(
        ITraceEvent *This,
        BYTE *Payload,
        ULONG PayloadSize);

    HRESULT (STDMETHODCALLTYPE *SetEventDescriptor)(
        ITraceEvent *This,
        PCEVENT_DESCRIPTOR EventDescriptor);

    HRESULT (STDMETHODCALLTYPE *SetProcessId)(
        ITraceEvent *This,
        ULONG ProcessId);

    HRESULT (STDMETHODCALLTYPE *SetProcessorIndex)(
        ITraceEvent *This,
        ULONG ProcessorIndex);

    HRESULT (STDMETHODCALLTYPE *SetThreadId)(
        ITraceEvent *This,
        ULONG ThreadId);

    HRESULT (STDMETHODCALLTYPE *SetThreadTimes)(
        ITraceEvent *This,
        ULONG KernelTime,
        ULONG UserTime);

    HRESULT (STDMETHODCALLTYPE *SetActivityId)(
        ITraceEvent *This,
        LPCGUID ActivityId);

    HRESULT (STDMETHODCALLTYPE *SetTimeStamp)(
        ITraceEvent *This,
        LARGE_INTEGER *TimeStamp);

    HRESULT (STDMETHODCALLTYPE *SetProviderId)(
        ITraceEvent *This,
        LPCGUID ProviderId);

    END_INTERFACE
} ITraceEventVtbl;

interface ITraceEvent {
    CONST_VTBL ITraceEventVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITraceEvent_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITraceEvent_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITraceEvent_Release(This) (This)->lpVtbl->Release(This)
/*** ITraceEvent methods ***/
#define ITraceEvent_Clone(This,NewEvent) (This)->lpVtbl->Clone(This,NewEvent)
#define ITraceEvent_GetUserContext(This,UserContext) (This)->lpVtbl->GetUserContext(This,UserContext)
#define ITraceEvent_GetEventRecord(This,EventRecord) (This)->lpVtbl->GetEventRecord(This,EventRecord)
#define ITraceEvent_SetPayload(This,Payload,PayloadSize) (This)->lpVtbl->SetPayload(This,Payload,PayloadSize)
#define ITraceEvent_SetEventDescriptor(This,EventDescriptor) (This)->lpVtbl->SetEventDescriptor(This,EventDescriptor)
#define ITraceEvent_SetProcessId(This,ProcessId) (This)->lpVtbl->SetProcessId(This,ProcessId)
#define ITraceEvent_SetProcessorIndex(This,ProcessorIndex) (This)->lpVtbl->SetProcessorIndex(This,ProcessorIndex)
#define ITraceEvent_SetThreadId(This,ThreadId) (This)->lpVtbl->SetThreadId(This,ThreadId)
#define ITraceEvent_SetThreadTimes(This,KernelTime,UserTime) (This)->lpVtbl->SetThreadTimes(This,KernelTime,UserTime)
#define ITraceEvent_SetActivityId(This,ActivityId) (This)->lpVtbl->SetActivityId(This,ActivityId)
#define ITraceEvent_SetTimeStamp(This,TimeStamp) (This)->lpVtbl->SetTimeStamp(This,TimeStamp)
#define ITraceEvent_SetProviderId(This,ProviderId) (This)->lpVtbl->SetProviderId(This,ProviderId)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT ITraceEvent_QueryInterface(ITraceEvent* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG ITraceEvent_AddRef(ITraceEvent* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG ITraceEvent_Release(ITraceEvent* This) {
    return This->lpVtbl->Release(This);
}
/*** ITraceEvent methods ***/
static __WIDL_INLINE HRESULT ITraceEvent_Clone(ITraceEvent* This,ITraceEvent **NewEvent) {
    return This->lpVtbl->Clone(This,NewEvent);
}
static __WIDL_INLINE HRESULT ITraceEvent_GetUserContext(ITraceEvent* This,void **UserContext) {
    return This->lpVtbl->GetUserContext(This,UserContext);
}
static __WIDL_INLINE HRESULT ITraceEvent_GetEventRecord(ITraceEvent* This,PEVENT_RECORD *EventRecord) {
    return This->lpVtbl->GetEventRecord(This,EventRecord);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetPayload(ITraceEvent* This,BYTE *Payload,ULONG PayloadSize) {
    return This->lpVtbl->SetPayload(This,Payload,PayloadSize);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetEventDescriptor(ITraceEvent* This,PCEVENT_DESCRIPTOR EventDescriptor) {
    return This->lpVtbl->SetEventDescriptor(This,EventDescriptor);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetProcessId(ITraceEvent* This,ULONG ProcessId) {
    return This->lpVtbl->SetProcessId(This,ProcessId);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetProcessorIndex(ITraceEvent* This,ULONG ProcessorIndex) {
    return This->lpVtbl->SetProcessorIndex(This,ProcessorIndex);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetThreadId(ITraceEvent* This,ULONG ThreadId) {
    return This->lpVtbl->SetThreadId(This,ThreadId);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetThreadTimes(ITraceEvent* This,ULONG KernelTime,ULONG UserTime) {
    return This->lpVtbl->SetThreadTimes(This,KernelTime,UserTime);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetActivityId(ITraceEvent* This,LPCGUID ActivityId) {
    return This->lpVtbl->SetActivityId(This,ActivityId);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetTimeStamp(ITraceEvent* This,LARGE_INTEGER *TimeStamp) {
    return This->lpVtbl->SetTimeStamp(This,TimeStamp);
}
static __WIDL_INLINE HRESULT ITraceEvent_SetProviderId(ITraceEvent* This,LPCGUID ProviderId) {
    return This->lpVtbl->SetProviderId(This,ProviderId);
}
#endif
#endif

#endif


#endif  /* __ITraceEvent_INTERFACE_DEFINED__ */

#ifndef __ITraceRelogger_FWD_DEFINED__
#define __ITraceRelogger_FWD_DEFINED__
typedef interface ITraceRelogger ITraceRelogger;
#ifdef __cplusplus
interface ITraceRelogger;
#endif /* __cplusplus */
#endif

/*****************************************************************************
 * ITraceEventCallback interface
 */
#ifndef __ITraceEventCallback_INTERFACE_DEFINED__
#define __ITraceEventCallback_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITraceEventCallback, 0x3ed25501, 0x593f, 0x43e9, 0x8f,0x38, 0x3a,0xb4,0x6f,0x5a,0x4a,0x52);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("3ed25501-593f-43e9-8f38-3ab46f5a4a52")
ITraceEventCallback : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE OnBeginProcessTrace(
        ITraceEvent *HeaderEvent,
        ITraceRelogger *Relogger) = 0;

    virtual HRESULT STDMETHODCALLTYPE OnFinalizeProcessTrace(
        ITraceRelogger *Relogger) = 0;

    virtual HRESULT STDMETHODCALLTYPE OnEvent(
        ITraceEvent *Event,
        ITraceRelogger *Relogger) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITraceEventCallback, 0x3ed25501, 0x593f, 0x43e9, 0x8f,0x38, 0x3a,0xb4,0x6f,0x5a,0x4a,0x52)
#endif
#else
typedef struct ITraceEventCallbackVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITraceEventCallback *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITraceEventCallback *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITraceEventCallback *This);

    /*** ITraceEventCallback methods ***/
    HRESULT (STDMETHODCALLTYPE *OnBeginProcessTrace)(
        ITraceEventCallback *This,
        ITraceEvent *HeaderEvent,
        ITraceRelogger *Relogger);

    HRESULT (STDMETHODCALLTYPE *OnFinalizeProcessTrace)(
        ITraceEventCallback *This,
        ITraceRelogger *Relogger);

    HRESULT (STDMETHODCALLTYPE *OnEvent)(
        ITraceEventCallback *This,
        ITraceEvent *Event,
        ITraceRelogger *Relogger);

    END_INTERFACE
} ITraceEventCallbackVtbl;

interface ITraceEventCallback {
    CONST_VTBL ITraceEventCallbackVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITraceEventCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITraceEventCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITraceEventCallback_Release(This) (This)->lpVtbl->Release(This)
/*** ITraceEventCallback methods ***/
#define ITraceEventCallback_OnBeginProcessTrace(This,HeaderEvent,Relogger) (This)->lpVtbl->OnBeginProcessTrace(This,HeaderEvent,Relogger)
#define ITraceEventCallback_OnFinalizeProcessTrace(This,Relogger) (This)->lpVtbl->OnFinalizeProcessTrace(This,Relogger)
#define ITraceEventCallback_OnEvent(This,Event,Relogger) (This)->lpVtbl->OnEvent(This,Event,Relogger)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT ITraceEventCallback_QueryInterface(ITraceEventCallback* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG ITraceEventCallback_AddRef(ITraceEventCallback* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG ITraceEventCallback_Release(ITraceEventCallback* This) {
    return This->lpVtbl->Release(This);
}
/*** ITraceEventCallback methods ***/
static __WIDL_INLINE HRESULT ITraceEventCallback_OnBeginProcessTrace(ITraceEventCallback* This,ITraceEvent *HeaderEvent,ITraceRelogger *Relogger) {
    return This->lpVtbl->OnBeginProcessTrace(This,HeaderEvent,Relogger);
}
static __WIDL_INLINE HRESULT ITraceEventCallback_OnFinalizeProcessTrace(ITraceEventCallback* This,ITraceRelogger *Relogger) {
    return This->lpVtbl->OnFinalizeProcessTrace(This,Relogger);
}
static __WIDL_INLINE HRESULT ITraceEventCallback_OnEvent(ITraceEventCallback* This,ITraceEvent *Event,ITraceRelogger *Relogger) {
    return This->lpVtbl->OnEvent(This,Event,Relogger);
}
#endif
#endif

#endif


#endif  /* __ITraceEventCallback_INTERFACE_DEFINED__ */

/*****************************************************************************
 * ITraceRelogger interface
 */
#ifndef __ITraceRelogger_INTERFACE_DEFINED__
#define __ITraceRelogger_INTERFACE_DEFINED__

DEFINE_GUID(IID_ITraceRelogger, 0xf754ad43, 0x3bcc, 0x4286, 0x80,0x09, 0x9c,0x5d,0xa2,0x14,0xe8,0x4e);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("f754ad43-3bcc-4286-8009-9c5da214e84e")
ITraceRelogger : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE AddLogfileTraceStream(
        BSTR LogfileName,
        void *UserContext,
        TRACEHANDLE *TraceHandle) = 0;

    virtual HRESULT STDMETHODCALLTYPE AddRealtimeTraceStream(
        BSTR LoggerName,
        void *UserContext,
        TRACEHANDLE *TraceHandle) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterCallback(
        ITraceEventCallback *Callback) = 0;

    virtual HRESULT STDMETHODCALLTYPE Inject(
        ITraceEvent *Event) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateEventInstance(
        TRACEHANDLE TraceHandle,
        ULONG Flags,
        ITraceEvent **Event) = 0;

    virtual HRESULT STDMETHODCALLTYPE ProcessTrace(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetOutputFilename(
        BSTR LogfileName) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetCompressionMode(
        BOOLEAN CompressionMode) = 0;

    virtual HRESULT STDMETHODCALLTYPE Cancel(
        ) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ITraceRelogger, 0xf754ad43, 0x3bcc, 0x4286, 0x80,0x09, 0x9c,0x5d,0xa2,0x14,0xe8,0x4e)
#endif
#else
typedef struct ITraceReloggerVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        ITraceRelogger *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        ITraceRelogger *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        ITraceRelogger *This);

    /*** ITraceRelogger methods ***/
    HRESULT (STDMETHODCALLTYPE *AddLogfileTraceStream)(
        ITraceRelogger *This,
        BSTR LogfileName,
        void *UserContext,
        TRACEHANDLE *TraceHandle);

    HRESULT (STDMETHODCALLTYPE *AddRealtimeTraceStream)(
        ITraceRelogger *This,
        BSTR LoggerName,
        void *UserContext,
        TRACEHANDLE *TraceHandle);

    HRESULT (STDMETHODCALLTYPE *RegisterCallback)(
        ITraceRelogger *This,
        ITraceEventCallback *Callback);

    HRESULT (STDMETHODCALLTYPE *Inject)(
        ITraceRelogger *This,
        ITraceEvent *Event);

    HRESULT (STDMETHODCALLTYPE *CreateEventInstance)(
        ITraceRelogger *This,
        TRACEHANDLE TraceHandle,
        ULONG Flags,
        ITraceEvent **Event);

    HRESULT (STDMETHODCALLTYPE *ProcessTrace)(
        ITraceRelogger *This);

    HRESULT (STDMETHODCALLTYPE *SetOutputFilename)(
        ITraceRelogger *This,
        BSTR LogfileName);

    HRESULT (STDMETHODCALLTYPE *SetCompressionMode)(
        ITraceRelogger *This,
        BOOLEAN CompressionMode);

    HRESULT (STDMETHODCALLTYPE *Cancel)(
        ITraceRelogger *This);

    END_INTERFACE
} ITraceReloggerVtbl;

interface ITraceRelogger {
    CONST_VTBL ITraceReloggerVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define ITraceRelogger_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITraceRelogger_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITraceRelogger_Release(This) (This)->lpVtbl->Release(This)
/*** ITraceRelogger methods ***/
#define ITraceRelogger_AddLogfileTraceStream(This,LogfileName,UserContext,TraceHandle) (This)->lpVtbl->AddLogfileTraceStream(This,LogfileName,UserContext,TraceHandle)
#define ITraceRelogger_AddRealtimeTraceStream(This,LoggerName,UserContext,TraceHandle) (This)->lpVtbl->AddRealtimeTraceStream(This,LoggerName,UserContext,TraceHandle)
#define ITraceRelogger_RegisterCallback(This,Callback) (This)->lpVtbl->RegisterCallback(This,Callback)
#define ITraceRelogger_Inject(This,Event) (This)->lpVtbl->Inject(This,Event)
#define ITraceRelogger_CreateEventInstance(This,TraceHandle,Flags,Event) (This)->lpVtbl->CreateEventInstance(This,TraceHandle,Flags,Event)
#define ITraceRelogger_ProcessTrace(This) (This)->lpVtbl->ProcessTrace(This)
#define ITraceRelogger_SetOutputFilename(This,LogfileName) (This)->lpVtbl->SetOutputFilename(This,LogfileName)
#define ITraceRelogger_SetCompressionMode(This,CompressionMode) (This)->lpVtbl->SetCompressionMode(This,CompressionMode)
#define ITraceRelogger_Cancel(This) (This)->lpVtbl->Cancel(This)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT ITraceRelogger_QueryInterface(ITraceRelogger* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG ITraceRelogger_AddRef(ITraceRelogger* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG ITraceRelogger_Release(ITraceRelogger* This) {
    return This->lpVtbl->Release(This);
}
/*** ITraceRelogger methods ***/
static __WIDL_INLINE HRESULT ITraceRelogger_AddLogfileTraceStream(ITraceRelogger* This,BSTR LogfileName,void *UserContext,TRACEHANDLE *TraceHandle) {
    return This->lpVtbl->AddLogfileTraceStream(This,LogfileName,UserContext,TraceHandle);
}
static __WIDL_INLINE HRESULT ITraceRelogger_AddRealtimeTraceStream(ITraceRelogger* This,BSTR LoggerName,void *UserContext,TRACEHANDLE *TraceHandle) {
    return This->lpVtbl->AddRealtimeTraceStream(This,LoggerName,UserContext,TraceHandle);
}
static __WIDL_INLINE HRESULT ITraceRelogger_RegisterCallback(ITraceRelogger* This,ITraceEventCallback *Callback) {
    return This->lpVtbl->RegisterCallback(This,Callback);
}
static __WIDL_INLINE HRESULT ITraceRelogger_Inject(ITraceRelogger* This,ITraceEvent *Event) {
    return This->lpVtbl->Inject(This,Event);
}
static __WIDL_INLINE HRESULT ITraceRelogger_CreateEventInstance(ITraceRelogger* This,TRACEHANDLE TraceHandle,ULONG Flags,ITraceEvent **Event) {
    return This->lpVtbl->CreateEventInstance(This,TraceHandle,Flags,Event);
}
static __WIDL_INLINE HRESULT ITraceRelogger_ProcessTrace(ITraceRelogger* This) {
    return This->lpVtbl->ProcessTrace(This);
}
static __WIDL_INLINE HRESULT ITraceRelogger_SetOutputFilename(ITraceRelogger* This,BSTR LogfileName) {
    return This->lpVtbl->SetOutputFilename(This,LogfileName);
}
static __WIDL_INLINE HRESULT ITraceRelogger_SetCompressionMode(ITraceRelogger* This,BOOLEAN CompressionMode) {
    return This->lpVtbl->SetCompressionMode(This,CompressionMode);
}
static __WIDL_INLINE HRESULT ITraceRelogger_Cancel(ITraceRelogger* This) {
    return This->lpVtbl->Cancel(This);
}
#endif
#endif

#endif


#endif  /* __ITraceRelogger_INTERFACE_DEFINED__ */

/*****************************************************************************
 * CTraceRelogger coclass
 */

DEFINE_GUID(CLSID_CTraceRelogger, 0x7b40792d, 0x05ff, 0x44c4, 0x90,0x58, 0xf4,0x40,0xc7,0x1f,0x17,0xd4);

#ifdef __cplusplus
class DECLSPEC_UUID("7b40792d-05ff-44c4-9058-f440c71f17d4") CTraceRelogger;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(CTraceRelogger, 0x7b40792d, 0x05ff, 0x44c4, 0x90,0x58, 0xf4,0x40,0xc7,0x1f,0x17,0xd4)
#endif
#endif

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __relogger_h__ */

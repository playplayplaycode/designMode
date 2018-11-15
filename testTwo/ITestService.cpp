#define LOG_TAG "TestService"

#include <utils/Log.h>

#include "ITestService.h"


using namespace android;
enum
{
        TEST_A = IBinder::FIRST_CALL_TRANSACTION,
        TEST_B,
        TEST_C,
        GET_BUFFER
};

class BpTestService: public BpInterface<ITestService>
{
        public:
        BpTestService(const sp<IBinder>& impl):BpInterface<ITestService>(impl)
        {}
        public:
        void test_a()
        {
                Parcel data;
                data.writeInterfaceToken(ITestService::ITestService::getInterfaceDescriptor());
                Parcel reply;
                remote()->transact(TEST_A,data,&reply);
        }
        void test_b()
        {
                Parcel data;
                data.writeInterfaceToken(ITestService::ITestService::getInterfaceDescriptor());
                Parcel reply;
                remote()->transact(TEST_B,data,&reply);
        }
        void test_c()
        {
                Parcel data;
                data.writeInterfaceToken(ITestService::ITestService::getInterfaceDescriptor());
                Parcel reply;
                remote()->transact(TEST_C,data,&reply);
        }
        sp<IMemory> getBuffer()
        {
                Parcel data;
                data.writeInterfaceToken(ITestService::ITestService::getInterfaceDescriptor());

                Parcel reply;
                remote()->transact(GET_BUFFER,data,&reply);

                sp<IMemory> buffer = interface_cast<IMemory>(reply.readStrongBinder());
                return buffer;
        }
};

IMPLEMENT_META_INTERFACE(TestService,"shy.zhikai.ITestService");

status_t BnTestService::onTransact(uint32_t code,const Parcel& data,Parcel* reply,uint32_t flags)
{
        switch(code)
        {
                case TEST_A:
                {
                        CHECK_INTERFACE(ITestService,data,reply);
                        test_a();

                        return NO_ERROR;
                }
                case TEST_B:
                {
                        CHECK_INTERFACE(ITestService,data,reply);
                        test_b();

                        return NO_ERROR;
                }
                case TEST_C:
                {
                        CHECK_INTERFACE(ITestService,data,reply);
                        test_c();
                        return NO_ERROR;
                }
                case GET_BUFFER:
                {
                        CHECK_INTERFACE(ITestService,data,reply);
                        sp<IMemory> buffer = getBuffer();
                        if(buffer != NULL)
                        {
                                reply->writeStrongBinder(buffer->asBinder());
                        }
                        return NO_ERROR;
                }
                default:
                {
                        return BBinder::onTransact(code,data,reply,flags);
                }
        }
        return NO_ERROR;
}


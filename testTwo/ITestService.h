#ifndef ITESTSERVICE_ZHIKAI_H_
#define ITESTSERVICE_ZHIKAI_H_

#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IBinder.h>
#include <binder/IServiceManager.h>

#define TEST_SERVICE "shy.zhikai.TestService"
#define SHARED_BUFFER_SIZE 4

using namespace android;
class ITestService:public IInterface
{
public:
        DECLARE_META_INTERFACE(TestService);
        virtual void test_a() = 0;
        virtual void test_b() = 0;
        virtual void test_c() = 0;
        virtual sp<IMemory> getBuffer() = 0;
};

class BnTestService:public BnInterface<ITestService>
{
public:
        virtual status_t onTransact(uint32_t code,const Parcel& data,Parcel* reply ,uint32_t flags = 0);

};

#endif

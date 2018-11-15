#define LOG_TAG "TestServer"
#include <stdlib.h>
#include <fcntl.h>
#include <utils/Log.h>
#include <binder/MemoryHeapBase.h>
#include <binder/MemoryBase.h>
#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>

#include "ITestService.h"

using namespace android;

class TestService:public BnTestService
{
public:
        TestService()
        {
                sp<MemoryHeapBase> heap = new MemoryHeapBase(SHARED_BUFFER_SIZE,0,"SharedBuffer");
                if(heap != NULL)
                {
                        mMemory = new MemoryBase(heap,0,SHARED_BUFFER_SIZE);
                        int32_t* data = (int32_t*)mMemory->pointer();
                        if(data != NULL)
                        {
                                *data = 0;
                        }
                }
        }
        virtual ~TestService()
        {
                mMemory = NULL;
        }
public:
        static void instantiate()
        {
                defaultServiceManager()->addService(String16(TEST_SERVICE),new TestService);
        }

        void test_a()
        {
                printf("This is test_a!\n");
        }

        void test_b()
        {
                printf("This is test_b!\n");
        }
        void test_c()
        {
                printf("This is test_c\n");
        }
        virtual sp<IMemory> getBuffer()
        {
                return mMemory;
        }
private:
        sp<MemoryBase> mMemory;
};

int main(int argc,char** argv)
{
        TestService::instantiate();

        ProcessState::self()->startThreadPool();
        IPCThreadState::self()->joinThreadPool();

        return 0;
}

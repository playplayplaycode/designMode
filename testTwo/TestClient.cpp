#define LOG_TAG "TestClient"

#include <utils/String16.h>
#include <utils/String8.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>

#include "ITestService.h"
using namespace android;
int main()
{
        sp<IBinder> binder = defaultServiceManager()->getService(String16(TEST_SERVICE));
        if(binder == NULL)
        {
                //LOGE("Failed to get test service");
                return -1;
        }
        sp<ITestService> service = ITestService::asInterface(binder);
        if(service == NULL)
        {
                //LOGE("Failed to get test service interface");
                return -2;
        }

        service->test_a();
        service->test_b();
        service->test_c();
        sp<IMemory> buffer = service->getBuffer();
        if(buffer == NULL)
        {
                return -3;
        }
        int32_t* data = (int32_t*)buffer->pointer();
        printf("The value of the shared buffer is %d \n",*data);
        *data = *data + 1;

        printf("Add value 1 to the shared buffer\n");

        return 0;
}


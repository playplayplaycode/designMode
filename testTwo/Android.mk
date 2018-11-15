LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder

#LOCAL_CFLAGS := -DANDROID_VERSION=$(PLATFORM_SDK_VERSION)

LOCAL_MODULE	:= TestServer 
LOCAL_SRC_FILES := \
	TestServer.cpp \
	ITestService.cpp

#CPP_FLAG := -fpermissive -Wwrite-strings
#LOCAL_CFLAGS += -pie -fPIE
#LOCAL_LDFLAGS += -pie -fPIE
#LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)
LOCAL_SHARED_LIBRARIES := \
	libcutils libutils libbinder
LOCAL_MODULE := TestClient
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := ITestService.cpp\
	TestClient.cpp
include $(BUILD_EXECUTABLE)


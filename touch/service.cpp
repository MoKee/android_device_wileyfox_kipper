/*
 * Copyright (C) 2019 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "vendor.mokee.touch@1.0-service.kipper"

#include <android-base/logging.h>
#include <binder/ProcessState.h>
#include <hidl/HidlTransportSupport.h>

#include "KeyDisabler.h"

using android::sp;
using android::OK;

using ::vendor::mokee::touch::V1_0::IKeyDisabler;
using ::vendor::mokee::touch::V1_0::implementation::KeyDisabler;

int main() {
    sp<IKeyDisabler> keyDisabler = new KeyDisabler();

    android::hardware::configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (keyDisabler->registerAsService() != OK) {
        LOG(ERROR) << "Cannot register keydisabler HAL service.";
        return 1;
    }
    LOG(INFO) << "Touch HAL service is ready.";

    android::hardware::joinRpcThreadpool();

    LOG(ERROR) << "Touchscreen HAL service failed to join thread pool.";
    return 1;
}

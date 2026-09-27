#include <gtest/gtest.h>
#include "DeviceController.h"

TEST(DeviceController, BatteryConsumptionOverUpdateWindow) {
    DeviceController deviceController(100.0, 100.0, 10.0, 1000.0, 500.0);

    deviceController.start();
    deviceController.increaseMotorSpeed(1000);

    deviceController.update(0.1);

    EXPECT_DOUBLE_EQ(deviceController.getBatteryCharge(), 51.0);
}
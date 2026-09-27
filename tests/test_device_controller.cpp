#include <gtest/gtest.h>
#include "DeviceController.h"

TEST(DeviceController, StateTransitions) {
    DeviceController deviceController(100.0, 50.0, 10.0, 1000.0, 500.0);

    EXPECT_EQ(deviceController.getState(), DeviceState::OFF);

    deviceController.start();
    deviceController.start();
    EXPECT_EQ(deviceController.getState(), DeviceState::IDLE);

    deviceController.increaseMotorSpeed(200);
    EXPECT_EQ(deviceController.getState(), DeviceState::RUNNING);

    deviceController.decreaseMotorSpeed(100);
    EXPECT_EQ(deviceController.getState(), DeviceState::RUNNING);

    deviceController.decreaseMotorSpeed(100);
    EXPECT_EQ(deviceController.getState(), DeviceState::IDLE);

    deviceController.shutdown();
    deviceController.shutdown();
    EXPECT_EQ(deviceController.getState(), DeviceState::OFF);

    deviceController.increaseMotorSpeed(100);
    EXPECT_EQ(deviceController.getState(), DeviceState::OFF);
}
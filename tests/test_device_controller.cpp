#include <cassert>
#include "DeviceController.h"

void testDeviceController() {
    DeviceController deviceController(100.0, 50.0, 10.0, 1000.0, 500.0);

    assert(deviceController.getState() == DeviceState::OFF);

    deviceController.start();
    deviceController.start();
    assert(deviceController.getState() == DeviceState::IDLE);

    deviceController.increaseMotorSpeed(200);
    assert(deviceController.getState() == DeviceState::RUNNING);

    deviceController.decreaseMotorSpeed(100);
    assert(deviceController.getState() == DeviceState::RUNNING);

    deviceController.decreaseMotorSpeed(100);
    assert(deviceController.getState() == DeviceState::IDLE);

    deviceController.shutdown();
    deviceController.shutdown();
    assert(deviceController.getState() == DeviceState::OFF);

    deviceController.increaseMotorSpeed(100);
    assert(deviceController.getState() == DeviceState::OFF);
}
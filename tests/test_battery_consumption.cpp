#include <cassert>
#include "DeviceController.h"

void testBatteryConsumption() {
    DeviceController deviceController(100.0, 100.0, 10.0, 1000.0, 500.0);

    deviceController.start();
    deviceController.increaseMotorSpeed(1000);

    deviceController.update(0.1);

    assert(deviceController.getBatteryCharge() == 50.0);
}
#include <iostream>

#include "Battery.h"
#include "Charger.h"
#include "Motor.h"
#include "DeviceController.h"

void testBattery();
void testCharger();
void testMotor();
void testDeviceController();
void testBatteryConsumption();

int main() {
    std::cout << "Running tests...\n" << std::endl;

    std::cout << "Testing battery..." << std::endl;
    testBattery();

    std::cout << "Testing charger..." << std::endl;
    testCharger();

    std::cout << "Testing motor..." << std::endl;
    testMotor();

    std::cout << "Testing device controller..." << std::endl;
    testDeviceController();

    std::cout << "Testing battery consumption..." << std::endl;
    testBatteryConsumption();

    std::cout << "\n...tests completed.";
    return 0;
}
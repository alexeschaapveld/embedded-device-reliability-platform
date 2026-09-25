#include <iostream>
#include "Battery.h"
#include "Charger.h"
#include "Motor.h"

void testBattery();
void testCharger();
void testMotor();

int main() {
    std::cout << "Running tests...\n" << std::endl;

    std::cout << "Testing battery..." << std::endl;
    testBattery();

    std::cout << "Testing charger..." << std::endl;
    testCharger();

    std::cout << "Testing motor..." << std::endl;
    testMotor();

    std::cout << "\n...tests completed.";
    return 0;
}
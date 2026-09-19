#include <iostream>
#include "Battery.h"

int main() {
    std::cout << "Running tests..." << std::endl;

    //Test 1: Create Battery with max charge 100 and cur charge of 20
    Battery battery(100.0, 20.0);
    if(battery.getMaxCharge() == 100.0 && battery.getCurrentCharge() == 20.0) {
        std::cout << "[PASS] Test 1: Battery creation" << std::endl;
    } else {
        std::cout << "[FAIL] Test 1: Battery creation" << std::endl;
    }
    //Test 2: Draw more charge than current charge 
    battery.changeCurrentCharge(-30.0);
    if(battery.getCurrentCharge() == 0.0) {
        std::cout << "[PASS] Test 2: Draw more charge than current charge" << std::endl;
    } else {
        std::cout << "[FAIL] Test 2: Draw more charge than current charge" << std::endl;
    }
    //Test 3: Add more charge than max charge
    battery.changeCurrentCharge(150.0);
    if(battery.getCurrentCharge() == 100.0) {
        std::cout << "[PASS] Test 3: Add more charge than max charge" << std::endl;
    } else {
        std::cout << "[FAIL] Test 3: Add more charge than max capacity" << std::endl;
    }
    
    return 0;
}
#include <iostream>
#include "Battery.h"
#include "Charger.h"
#include "Motor.h"

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

    std::cout << std::endl << std::endl;

    //Initialize a charger with a rate of 50 watts
    Charger charger(50.0);
    if(charger.getCurrentChargeRate() == 50) {
        std::cout << "[PASS] Test 1: Charger creation" << std::endl;
    } else {
        std::cout << "[FAIL] Test 1: Charger creation" << std::endl;
    }

    //Change charge rate to 0 watts
    charger.setCurrentChargeRate(0);
    if(charger.getCurrentChargeRate() == 0) {
        std::cout << "[PASS] Test 2: Charge value set to zero" << std::endl;
    } else {
        std::cout << "[FAIL] Test 2: Charge value set to zero" << std::endl;
    }

    //Change charge rate to discharge
    charger.setCurrentChargeRate(-50.0);
    if(charger.getCurrentChargeRate() == -50) {
        std::cout << "[PASS] Test 3: Charger discharging" << std::endl;
    } else {
        std::cout << "[FAIL] Test 3: Charger discharging" << std::endl;
    }

    std::cout << std::endl << std::endl;

    //Motor Creation
    Motor motor(100, 200);
    if(motor.getMaxSpeed() == 100 && motor.getMaxPower() == 200) {
        std::cout << "[PASS] Test 1: Create valid motor" << std::endl;
    } else {
        std::cout << "[FAIL] Test 1: Create valid motor" << std::endl;
    }
    //Invalid Motor Creation
    try {
        Motor motor2(-100, -200);
        std::cout << "[FAIL] Test 2: Successful rejection of invalid motor" << std::endl;
    } catch(const std::invalid_argument& e) {
        std::cout << "[PASS] Test 2: Successful rejection of invalid motor" << std::endl;
    }
    //Increase Speed
    motor.increaseSpeed(50);
    if(motor.getCurrentSpeed() == 50) {
        std::cout << "[PASS] Test 3: Increase Speed" << std::endl;
    } else {
        std::cout << "[FAIL] Test 3: Increase Speed" << std::endl;
    }
    //Decrease Speed
    motor.decreaseSpeed(25);
    if(motor.getCurrentSpeed() == 25) {
        std::cout << "[PASS] Test 4: Decrease Speed" << std::endl;
    } else {
        std::cout << "[FAIL] Test 4: Decrease Speed" << std::endl;
    }
    //Running State
    motor.decreaseSpeed(25);
    if(motor.isRunning()) {
        std::cout << "[PASS] Test 5: Test running state" << std::endl;
    } else {
        std::cout << "[FAIL] Test 5: Test running state" << std::endl;
    }
    //Set Valid Load
    motor.setLoad(1);
    if(motor.getLoad() == 1) {
        std::cout << "[PASS] Test 6: Valid Load" << std::endl;
    } else {
        std::cout << "[FAIL] Test 6: Valid Load" << std::endl;
    }
    
    std::cout << "...tests completed.";
    return 0;
}
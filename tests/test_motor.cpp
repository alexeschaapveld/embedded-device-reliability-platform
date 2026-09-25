#include "Motor.h"
#include <cassert>

void testMotor() {
    Motor motor(1000, 500);

    assert(motor.getMaxSpeed() == 1000);

    assert(motor.getMaxPower() == 500);

    assert(motor.getCurrentSpeed() == 0);

    assert(motor.getLoad() == 0);

    assert(!motor.isRunning());

    motor.increaseSpeed(200);
    assert(motor.getCurrentSpeed() == 200);
    assert(motor.isRunning());

    motor.decreaseSpeed(150);
    assert(motor.getCurrentSpeed() == 50);
    assert(motor.isRunning());

    motor.setLoad(50);
    assert(motor.getLoad() == 50);

    motor.increaseSpeed(2000);
    assert(motor.getCurrentSpeed() == 1000);

    motor.decreaseSpeed(5000);
    assert(motor.getCurrentSpeed() == 0);
    assert(!motor.isRunning());

    motor.increaseSpeed(500);
    assert(motor.getPowerConsumption() == 250);

    motor.increaseSpeed(500);
    assert(motor.getPowerConsumption() == 500);
}
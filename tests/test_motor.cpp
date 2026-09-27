#include "Motor.h"
#include <gtest/gtest.h>

TEST(Motor, SpeedLoadAndPowerBehavior) {
    Motor motor(1000, 500);

    EXPECT_DOUBLE_EQ(motor.getMaxSpeed(), 1000);

    EXPECT_DOUBLE_EQ(motor.getMaxPower(), 500);

    EXPECT_DOUBLE_EQ(motor.getCurrentSpeed(), 0);

    EXPECT_DOUBLE_EQ(motor.getLoad(), 0);

    EXPECT_FALSE(motor.isRunning());

    motor.increaseSpeed(200);
    EXPECT_DOUBLE_EQ(motor.getCurrentSpeed(), 200);
    EXPECT_TRUE(motor.isRunning());

    motor.decreaseSpeed(150);
    EXPECT_DOUBLE_EQ(motor.getCurrentSpeed(), 50);
    EXPECT_TRUE(motor.isRunning());

    motor.setLoad(50);
    EXPECT_DOUBLE_EQ(motor.getLoad(), 50);

    motor.increaseSpeed(2000);
    EXPECT_DOUBLE_EQ(motor.getCurrentSpeed(), 1000);

    motor.decreaseSpeed(5000);
    EXPECT_DOUBLE_EQ(motor.getCurrentSpeed(), 0);
    EXPECT_FALSE(motor.isRunning());

    motor.increaseSpeed(500);
    EXPECT_DOUBLE_EQ(motor.getPowerConsumption(), 250);

    motor.increaseSpeed(500);
    EXPECT_DOUBLE_EQ(motor.getPowerConsumption(), 500);
}
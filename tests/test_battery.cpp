#include "Battery.h"
#include <gtest/gtest.h>

TEST(Battery, ClampsChargeWithinBounds) {
    Battery battery(100, 20);

    EXPECT_DOUBLE_EQ(battery.getCurrentCharge(), 20);

    battery.changeCurrentCharge(-30);
    EXPECT_DOUBLE_EQ(battery.getCurrentCharge(), 0);

    battery.changeCurrentCharge(150);
    EXPECT_DOUBLE_EQ(battery.getCurrentCharge(), 100);
}
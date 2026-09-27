#include "Charger.h"
#include <gtest/gtest.h>

TEST(Charger, GetAndSetChargeRate) {
    Charger charger(50);

    EXPECT_DOUBLE_EQ(charger.getCurrentChargeRate(), 50);

    charger.setCurrentChargeRate(-50);
    EXPECT_DOUBLE_EQ(charger.getCurrentChargeRate(), -50);
}
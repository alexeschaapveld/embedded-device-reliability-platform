#include "Battery.h"
#include <cassert>

void testBattery() {
    Battery battery(100, 20);

    assert(battery.getCurrentCharge() == 20);

    battery.changeCurrentCharge(-30);
    assert(battery.getCurrentCharge() == 0);

    battery.changeCurrentCharge(150);
    assert(battery.getCurrentCharge() == 100);
}
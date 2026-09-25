#include <Charger.h>>
#include <cassert>

void testCharger() {
    Charger charger(50);

    assert(charger.getCurrentChargeRate() == 50);

    charger.setCurrentChargeRate(-50);
    assert(charger.getCurrentChargeRate() == -50);
}
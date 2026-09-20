#include "Charger.h"

Charger::Charger(double currentChargeRate)
    : currentChargeRate_(currentChargeRate) {}

double Charger::getCurrentChargeRate() const { return currentChargeRate_; }

void Charger::setCurrentChargeRate(double currentChargeRate) { currentChargeRate_ = currentChargeRate; }
#include "Battery.h"

Battery::Battery(double maxCharge, double currentCharge)
    : maxCharge_(maxCharge), currentCharge_(currentCharge) {}

double Battery::getMaxCharge() const { return maxCharge_;}
double Battery::getCurrentCharge() const { return currentCharge_; }

void Battery::changeCurrentCharge(double change) {
    currentCharge_ += change;
    if(currentCharge_ < 0) { currentCharge_ = 0; }
    if(currentCharge_ > maxCharge_) {currentCharge_ = maxCharge_;}
}

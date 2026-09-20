#include "Motor.h"
#include <stdexcept> //For std::invalid_argument()

Motor::Motor(double maxSpeed, double maxPower) {
    if(maxSpeed <= 0 || maxPower <= 0) { 
        throw std::invalid_argument("Invalid motor parameters");
    }
    maxSpeed_ = maxSpeed;
    maxPower_ = maxPower;
    currentSpeed_ = 0;
    load_ = 0;
}
double Motor::getCurrentSpeed() const { return currentSpeed_; }
double Motor::getMaxSpeed() const { return maxSpeed_; }
double Motor::getMaxPower() const {return maxPower_; }
double Motor::getLoad() const {return load_; }
bool Motor::isRunning() const {return currentSpeed_ != 0; }

void Motor::increaseSpeed(double amount) {currentSpeed_ += amount; }
void Motor::decreaseSpeed(double amount) {currentSpeed_ -= amount; }
void Motor::setLoad(double amount) {load_ = amount; }

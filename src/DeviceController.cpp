#include "DeviceController.h""

DeviceController::DeviceController( 
                    double maxBatteryCharge,
                    double currentBatteryCharge,
                    double chargeRate,
                    double maxMotorSpeed,
                    double maxMotorPower
                    )
                    :
                    battery_(maxBatteryCharge, currentBatteryCharge),
                    charger_(chargeRate),
                    motor_(maxMotorSpeed, maxMotorPower),
                    state_(DeviceState::OFF)
{}
DeviceState DeviceController::getState() const { return state_; }
void DeviceController::start() {
    if (state_ == DeviceState::OFF) 
        state_ = DeviceState::IDLE;
}

void DeviceController::shutdown() {
    if (state_ == DeviceState::IDLE || state_ == DeviceState::RUNNING) {
        motor_.decreaseSpeed(motor_.getCurrentSpeed());
        state_ = DeviceState::OFF;
    } 
}

void DeviceController::increaseMotorSpeed(double amount) {
    if(state_ == DeviceState::IDLE || state_ == DeviceState::RUNNING) {
        motor_.increaseSpeed(amount);
        if(motor_.isRunning()) {
            state_ = DeviceState::RUNNING;
        }
    }
}

void DeviceController::decreaseMotorSpeed(double amount) {
    if(state_ == DeviceState::RUNNING) {
        motor_.decreaseSpeed(amount);
        if(!motor_.isRunning()) {
            state_ = DeviceState::IDLE;
        }
    }
}

void DeviceController::update(double timeElapsed) {
    if(timeElapsed <= 0)
        return;
    if(motor_.isRunning()) {
        double power = motor_.getPowerConsumption();
        double energy = power * timeElapsed;
        battery_.changeCurrentCharge(-energy);
    }
    if(motor_.isRunning() && battery_.getCurrentCharge() <= 0) {
        motor_.decreaseSpeed(motor_.getCurrentSpeed());
        state_ = DeviceState::FAULT;
    }
}

//Getters
double DeviceController::getBatteryCharge() const { return battery_.getCurrentCharge(); }
double DeviceController::getMotorSpeed() const { return motor_.getCurrentSpeed(); }
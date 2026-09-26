#include "SimulationService.h"

SimulationService::SimulationService(
    double maxBatteryCharge,
    double currentBatteryCharge,
    double chargeRate,
    double maxMotorSpeed,
    double maxMotorPower
)
    : deviceController_(
        maxBatteryCharge,
        currentBatteryCharge,
        chargeRate,
        maxMotorSpeed,
        maxMotorPower
    )
{}

void SimulationService::start() { deviceController_.start(); }
void SimulationService::shutdown() { deviceController_.shutdown(); }

void SimulationService::increaseMotorSpeed(double amount) { deviceController_.increaseMotorSpeed(amount); }
void SimulationService::decreaseMotorSpeed(double amount) { deviceController_.decreaseMotorSpeed(amount); }

void SimulationService::advanceTime(double seconds) { deviceController_.update(seconds); }

DeviceState SimulationService::getState() const { return deviceController_.getState(); }
double SimulationService::getBatteryCharge() const { return deviceController_.getBatteryCharge(); }
double SimulationService::getMotorSpeed() const { return deviceController_.getMotorSpeed(); }
double SimulationService::getMotorPowerConsumption() const { return deviceController_.getMotorPowerConsumption(); }
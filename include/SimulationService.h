#ifndef SIMULATIONSERVICE_H
#define SIMULATIONSERVICE_H

#include "DeviceController.h"

class SimulationService {
    public:
        SimulationService(double maxBatteryCharge, double currentBatteryCharge, double chargeRate, double maxMotorSpeed, double maxMotorPower);

        void start();
        void shutdown();

        void increaseMotorSpeed(double amount);
        void decreaseMotorSpeed(double amount);

        void advanceTime(double seconds);

        DeviceState getState() const;
        double getBatteryCharge() const;
        double getMotorSpeed() const;
        double getMotorPowerConsumption() const;

    private:
        DeviceController deviceController_;
};

#endif //SIMULATIONSERVICE_H
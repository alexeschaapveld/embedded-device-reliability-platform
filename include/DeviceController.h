#ifndef DEVICE_CONTROLLER_H
#define DEVICE_CONTROLLER_H

#include "Charger.h"
#include "Battery.h"
#include "Motor.h"

enum class DeviceState {
    OFF,
    IDLE,
    RUNNING,
    FAULT
};

class DeviceController {
    public:
        DeviceController(   double maxBatteryCharge, 
                            double currentBatteryCharge, 
                            double chargeRate,
                            double maxMotorSpeed, 
                            double maxMotorPower
                        );
    private:
        Battery battery_;
        Charger charger_;
        Motor motor_;
        DeviceState state_;
};


#endif //DEVICE_CONTROLLER_H
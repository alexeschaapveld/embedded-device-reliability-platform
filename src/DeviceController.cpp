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
                    motor_(maxMotorSpeed, maxMotorPower)
                    state_(DeviceState::OFF)
{}
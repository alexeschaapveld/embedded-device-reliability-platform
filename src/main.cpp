#include <iostream>
#include <sstream>
#include <string>

#include "SimulationService.h"

std::string stateToString(DeviceState state) {
    switch(state) {
        case DeviceState::OFF:
            return "OFF";
        case DeviceState::IDLE:
            return "IDLE";
        case DeviceState::RUNNING:
            return "RUNNING";
        case DeviceState::FAULT:
            return "FAULT";
    }
    return "ERROR";
}

void printHelp() {
    std::cout
        << "\nCommands:\n"
        << "  start\n"
        << "  increase <amount>\n"
        << "  decrease <amount>\n"
        << "  advance <seconds>\n"
        << "  charge <power>\n"
        << "  shutdown\n"
        << "  status\n"
        << "  help\n"
        << "  exit\n\n";
}

int main() {
    SimulationService simulation(100.0, 100.0, 10.0, 1000.0, 500.0);
    std::cout << "<-----Embedded Device Simulator----->" << std::endl;
    printHelp();
    std::string line;
    while(true) {
        std::cout << "> ";
        std::getline(std::cin, line); //Reads entire user input until \n 
        std::stringstream input(line); //turns into a stream 
        std::string command;
        input >> command;

        if(command == "start") {
            simulation.start();
        } else if(command == "shutdown") {
            simulation.shutdown();
        } else if(command == "help") {
            printHelp();
        } else if(command == "exit") {
            break;
        } else if(command == "increase") {
            double amount;
            if(input >> amount) {
                simulation.increaseMotorSpeed(amount);
            } else {
                std::cout << "Usage: increase <amount>" << std::endl;
            }
        } else if(command == "decrease") {
            double amount;
            if(input >> amount) {
                simulation.decreaseMotorSpeed(amount);
            } else {
                std::cout << "Usage: decrease <amount>" << std::endl;
            }
        } else if(command == "advance") {
            double seconds;
            if(input >> seconds) {
                simulation.advanceTime(seconds);
            } else {
                std::cout << "Usage: advance <seconds>" << std::endl;
            }
        } else if(command == "status") {
            std::cout   << "\nState: " << stateToString(simulation.getState())
                        << "\nBattery: " << simulation.getBatteryCharge()
                        << "\nMotor speed: " << simulation.getMotorSpeed()
                        << "\nMotor power: " << simulation.getMotorPowerConsumption()
                        << std::endl << std::endl;
        } else if(command == "charge") {
            double power;
            if(input >> power) {
                simulation.setCurrentChargeRate(power);
            }
        } else {
            std::cout << "Unknown command. Type 'help' for commands. " << std::endl;
        }
    }
    return 0;
}
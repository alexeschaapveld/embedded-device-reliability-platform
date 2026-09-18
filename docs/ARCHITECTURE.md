# Architecture

## Project Purpose

The Embedded Device Reliability & Test Platform is a C++ simulation of a resource-constrained embedded device.

The simulated device is based on a simplified cordless power tool. The project is not reproducing a real product, merely creating a controlled enviroment to explore embedded software concepts.

## Initial Engineering Goals

This project will involve:

- Concurrent subsystem design
- Shared state and sunchronization
- Device state management
- Inter-component communication
- Failure handling
- Fault testing
- System performance
- CI and validation infastructure

## Simulated Device

The device will contain:

- Battery
- Motor
- Temperature Sensor
- Device Controller
- Communication System
- Logger

## Device States

The initial state model will include:

- OFF
- IDLE
- RUNNING 
- FAULT

Initial expected transitions:

OFF -> IDLE -> RUNNING

Fault conditions may transition the system into:

RUNNING -> FAULT

The exact state transitions have not been fully defined.

## Initial Concurrency Model

The project is expected to contain independent execution paths for:

- Battery updates
- Motor behavior
- Sensor updates
- Communication

## Communication

The device will eventually communicate using a custom designed protocol. Commands may include:

- GET_STATUS
- GET_BATTERY
- START_MOTOR
- STOP_MOTOR
- RESET_FAULT

## Fault Injection

The system will eventually support reproducible faults such as:

- Low battery
- Overtemperature
- Sensor timeout
- Communication timeout
- Dropped messages
- Corrupted messages

## Development Philosphy

Every major feature will follow this process:

1. Define the engineering problem
2. Implement a solution
3. Test behavior against expected behavior
4. Record results
5. Identify limitations
6. Refine the design
7. Document the result
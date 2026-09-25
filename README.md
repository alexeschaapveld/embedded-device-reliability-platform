# Embedded Device Reliability & Test Platform

A C++ simulation of a resource constrained embedded device designed to explore multithreading, synchronization, communication protocols, fault injection, automated testing, and CI.

This is a simulated device based on a cordless power tool. The project does not reproduce a real product.

## Status

In Development

## Current Stage

Milestone 2 - Component and Device Controller Implementation

## Current Progress

### Implemented

- C++ project structure using CMake
- Battery component
- Battery charge state and bounds management
- Battery behavior tests
- Charger component
- Motor component
- DeviceController
- Device state management (`OFF`, `IDLE`, `RUNNING`, `FAULT`)
- Device startup and shutdown behavior
- Motor speed control through DeviceController
- Time-based battery consumption
- Battery depletion fault handling
- DeviceController and battery interaction tests

## In Progress

- Expanding device behavior and validation
- Charging behavior
- Fault injection and fault handling

## Planned Systems

- Temperature sensing
- Multithreaded device subsystems
- Device communication protocol
- Fault injection
- Automated testing
- Performance testing
- CI/test automation

## Technologies to Use/Learn

- C++
- CMake
- GitHub Actions
- Linux/WSL
- GoogleTest

## Project Goal

This project is being developed to explore embedded systems engineering. Each stage is designed to introduce a new engineering problem, followed by implementation, testing, measurement, and documentation.

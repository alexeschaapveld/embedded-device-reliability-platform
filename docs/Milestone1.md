# Milestone 1 - System Definition

**Status:** In Progress
**Commits:** Commits made from 9/18 to 9/19

## Goal
This milestone establishes three core subsystems(battery, charger, and motor) and a controller that coordinates them. This provides a simulated device to inject faults into in the future.

## Components

### 1. Battery
- Tracks current charge and maximum charge
- Uses getters to ensure charge will not go out of bounds

### 2. Charger
- Represents charge/discharge rate of battery
- Rate can be positive(charging) or negative(discharging)

### 3. Motor
- Simulates motor speed, power draw, load, and if it's running
- Constructor rejects invalid configs, besides that assumes valid inputs

### Controller
**Responsibility:** Coordinates three subsystems
**Design Decisions:** In-Progress

## Testing
**Test Approach:** Manuel pass/fail assertions printed to stdout. Migration planned in future to Github Actions.

## Learning
I had to consider what each subsystem is responsible for, and how to minimize overlap or redundent values.


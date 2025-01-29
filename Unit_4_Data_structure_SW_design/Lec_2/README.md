# Autonomous Vehicle Collision Avoidance System

## Introduction
This report outlines the design and implementation of an **Autonomous Vehicle Collision Avoidance System**. The system uses **ultrasonic sensors** to detect obstacles and adjusts the vehicle's speed to avoid collisions. The system is composed of several modules, including:

- **Collision Avoidance (CA)**
- **DC Motor Control (DC)**
- **Ultrasonic Sensor (US)**

## Requirements

### Functional Requirements:
- The system should detect obstacles within a specified distance.
- The system should adjust the vehicle's speed based on the distance to the obstacle.
- The system should maintain a safe distance threshold.
- The system should have states for waiting and driving.

### Non-Functional Requirements:
- The system should respond to obstacles within a specified time frame.
- The system should be reliable and maintain consistent performance.

## Design Diagrams

### System Block Diagram:
- **Collision_Avoidance (CA)**: Manages the distance and speed, and communicates with the DC Motor and Ultrasonic Sensor.
- **US_Sensor**: Measures the distance to obstacles and sends this data to the CA module.
- **DC_Motor**: Controls the speed of the vehicle based on commands from the CA module.

## Sequence of Operations

### Initialization:
1. The system initializes the **DC Motor** and **Ultrasonic Sensor**.
2. The **CA module** sets the initial speed and distance thresholds.

### Waiting State:
1. The system remains idle until an obstacle is detected within the threshold distance.
2. The **Ultrasonic Sensor** continuously measures the distance.

### Driving State:
1. When an obstacle is detected within the threshold, the **CA module** calculates the required speed reduction.
2. The **CA module** sends the new speed setting to the **DC Motor**.
3. The **DC Motor** adjusts the vehicle's speed accordingly.

### Obstacle Avoidance:
1. If the distance to the obstacle decreases further, the system may **stop the vehicle** or take **evasive action**.
2. The system returns to the **waiting state** once the obstacle is no longer within the threshold distance.

## Case Study/Activity

### Scenario: The vehicle is moving towards an obstacle.

#### Activity:
1. The **Ultrasonic Sensor** detects the obstacle and sends the distance data to the **CA module**.
2. The **CA module** determines that the distance is below the threshold and sets the speed to **30**.
3. The **DC Motor** reduces the vehicle's speed to **30**.
4. The vehicle continues to monitor the distance and adjusts speed as necessary.


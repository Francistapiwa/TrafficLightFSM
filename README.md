# TrafficLightFSM
This project implements a Finite State Machine (FSM)-based traffic light control system on the ESP32 microcontroller using the FreeRTOS environment. It simulates real-world traffic light behavior with four states: RED, RED_YELLOW, GREEN, and YELLOW, and incorporates dynamic pedestrian input handling.

The system operates in real time, using a timer-based counter to manage transitions between light states. Pedestrian interaction is simulated through non-blocking input (scanf), allowing a user to request crossing by pressing a key. The FSM logic ensures that the pedestrian request is only honored after a safe duration (e.g., after 20 seconds of green light), mimicking actual intersection behavior.

This project is part of an embedded systems coursework assignment and demonstrates:

Real-time task scheduling using FreeRTOS

State machine design in C

Human interaction simulation via polling

Embedded programming for IoT devices

It is ideal for learners and developers looking to explore the fundamentals of FSMs in embedded systems and real-time operating environments.

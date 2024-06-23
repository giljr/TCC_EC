
# Project: TCC - Trabalho de Conclusao de Curso - Engenharia da Computacao
 ## Undergraduate Qualification For a career in Computer Engineering

This work aims to protect the code for my undergraduate thesis in Computer Engineering. The title is "DETECÇÃO DE INTRUSÕES RESIDENCIAIS USANDO DRONES E INTELIGÊNCIA ARTIFICIAL," which translates to "DETECTION OF RESIDENTIAL INTRUSIONS USING DRONES AND ARTIFICIAL INTELLIGENCE" in English.

We use Espressif's Rainmaker platform to monitor crucial access points of the residence and deploy a drone for surveillance. This project was presented between July and September of 2024 at UNINTER University. See [Demo Video](https://youtu.be/gKBFeZe--7g) for simulation.

## What is ESP RainMaker API

The ESP RainMaker API is a powerful tool for IoT development, offering a range of standard types, parameters, and functions that simplify the creation, configuration, and management of IoT devices. This allows developers to focus on innovation, ensures consistent and reliable performance, and facilitates seamless integration into a broader IoT ecosystem.

## What is ESP RainMaker Framework 

The API provided in the ESP RainMaker framework is a powerful tool for IoT developers. It simplifies the creation and management of smart devices, integrates them into a robust ecosystem, and allows developers to focus on innovation and quality. For a programmer, having access to such APIs is invaluable as it accelerates development, ensures reliability, and opens up a wide range of possibilities for creating smart, connected devices.

## DOCS & API Reference

#### Get all items
[ESP RainMaker - Welcome Page](https://rainmaker.espressif.com/)

[Documentations - ESP RainMaker library for Arduino](https://github.com/espressif/arduino-esp32/blob/master/libraries/RainMaker/README.md) 

[ESP RainMaker - Get Started](https://rainmaker.espressif.com/docs/get-started.html)




## Installation
Requirements:

    ESP32 board and Arduino IDE configured with ESP32 support.
    ESP RainMaker library installed.
    4 X [WiFi LoRa 32(V2)](https://heltec.org/project/wifi-lora-32-v3/) Produced by Heltec Automation  

Steps to Implement:

    Setup in Arduino IDE:
        Ensure you have the ESP RainMaker library installed.
        If not, install it through the Library Manager in 
        Arduino IDE (Tools -> Manage Libraries).

    Hardware Setup:
        Connect the PIR sensor's output pin to a GPIO pin 
        on your ESP32 board (e.g., GPIO 16).

    Code Implementation:
        Implement the custom MotionSensor class that extends Device for RainMaker integration.
        Update RainMaker parameters accordingly when motion is detected or stops.

Here's how the code can be structured:

## 🗺️ Roadmap  - This example demonstrates the ESP RainMaker integration with a standard Motion Sensor device using an ESP32.

[Code # 00](/00_DRONE_LAUNCH) - **Drone Drive** - This code is for the PIRs that activate the drone automatically. SIMULATION - Jun 23, 2024.

[Code # 02](/02_PIR_CB_BUZ1) - **Callback and Buzzer Drive** - This code launches the drone automatically triggered by PIR#3. SIMULATION - Jun 23, 2024.

[Code # 03](/03_PIR_NO_BUZ2) -  **No Buzzer Drive** - This code is for the PIRs that send information to mobile. SIMULATION - Jun 23, 2024.

    

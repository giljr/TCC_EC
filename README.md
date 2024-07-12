
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

[Code # 00](/00_drone_launch.ino) - **Drone Drive** - This code is for the PIRs that activate the drone automatically. SIMULATION - Jun 23, 2024.

[Code # 02](/02_PIR_NO_BUZ1.ino) - **Callback and Buzzer Drive** - This code launches the drone automatically triggered by PIR#3. SIMULATION - Jun 23, 2024.

[Code # 03](/03_PIR_CB_BUZ3.ino) -  **No Buzzer Drive** - This code is for the PIRs that send information to mobile. SIMULATION - Jun 23, 2024.


[Code # 04](/01_setup_camera_send_email.py) -  **Camera Set up & send email - Raspi** - This code is for Raspberry Pi Zero w/ camera zero v1. SIMULATION - Jul 10, 2024.


[Code # 05](/02_flask_web_server.py) -  **Web Server Setup - Raspi** - This code is for serve the web page to render in mobile. Use Bootstrap -  Jul 10, 2024.


[Code # 06](/index.html) -  **Index page 'Home Security System' - Raspi** - This is the welcome page for 'Home Security System'- Use Bootstrap - Jul 10, 2024.


[Code # 07](/secure_house.html) -  **Services page 'Home Security System' - Raspi** - This implements two services: Check for photos & Clean Resources - Use Bootstrap - Jul 10, 2024.

    

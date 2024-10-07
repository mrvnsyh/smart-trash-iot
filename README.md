# Smart Trash Bin Based on IoT Automation
## Project Overview
This project involves the development of a **Smart Trash Bin** using an IoT embedded system. The system integrates hardware components such as sensors and a WiFi module, programmed via the **Arduino IDE**, and connects to the **ThingsBoard** IoT platform for monitoring and control. The aim is to automate waste management by creating a smart system that can detect trash, open the lid automatically, and provide real-time monitoring data via IoT.

## Features
- **Automated Lid Control**: The lid opens and closes automatically when objects are detected near the trash bin.
- **Distance Measurement**: Measures the trash level in the bin using ultrasonic sensors to detect the bin's fullness.
- **Object Detection**: Infrared (IR) sensors detect nearby objects, triggering the lid mechanism.
- **IoT Monitoring**: Real-time data visualization and monitoring using ThingsBoard, including bin status and sensor data.
- **Wireless Connectivity**: Uses the ESP8266 WiFi module for communication between the smart bin and the ThingsBoard platform.

## Components Used
- **ESP8266 WiFi Module**: Enables wireless communication with the ThingsBoard IoT platform.
- **Servo Motor**: Controls the automatic lid mechanism.
- **Power Supply Module**: Regulates the voltage supply to various components.
- **IR Sensors**: Detect nearby objects to open the bin lid.
- **Ultrasonic Sensors**: Measure the distance to detect trash levels inside the bin.
- **Arduino IDE**: Used for programming and controlling the components.
  
## System Architecture
1. **Object Detection**: When an object is detected by the IR sensor, the servo motor opens the lid.
2. **Distance Measurement**: The ultrasonic sensor measures the trash level and sends the data to the ESP8266.
3. **IoT Data Monitoring**: The ESP8266 sends the sensor data to the ThingsBoard platform for remote monitoring and alerts.
4. **Power Management**: The power supply module ensures stable voltage distribution to all components.

## How It Works
1. **Lid Control**: When an object is detected by the IR sensor, the servo motor is activated to open the trash bin lid.
2. **Trash Level Detection**: The ultrasonic sensor continuously measures the trash level and sends real-time data to the IoT platform.
3. **Data Visualization**: Sensor data is visualized on the ThingsBoard platform, allowing users to monitor bin status remotely.

## Requirements
- **Hardware**:
  - ESP8266 WiFi Module
  - Servo Motor
  - IR Sensors
  - Ultrasonic Sensors
  - Power Supply Module
  - Jumper Wires
  - Breadboard or PCB
- **Software**:
  - Arduino IDE (with necessary libraries for ESP8266, IR sensor, and ultrasonic sensor)
  - ThingsBoard Account for IoT integration
  - Internet connection for data transmission

## Installation and Setup
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/mrvnsyh/smart-trash-iot
2. **Arduino Setup**:

- Install the Arduino IDE.
- Add the ESP8266 board to your Arduino IDE.
- Download and include necessary libraries such as Servo, ESP8266WiFi, and ThingsBoard SDK.

3. **Wiring**:

- Connect the ESP8266 to the servo motor, IR sensors, and ultrasonic sensors as per the circuit diagram (to be included in your documentation).

4. **ThingsBoard Setup**:

- Create an account on ThingsBoard.
- Create a new device for the smart trash bin and obtain the access token.
- Configure the Arduino sketch with your WiFi credentials and the ThingsBoard token.

5. **Upload Code**:

- Open the Arduino IDE.
- Upload the provided code to your ESP8266 board.

6. **Monitor the Data**:

- Once the system is powered on, the data will start being transmitted to the ThingsBoard dashboard.
- Monitor the bin status, trash levels, and other sensor data remotely.

**License**
This project is licensed under the MIT License. See the LICENSE file for more details.

**Acknowledgments**
Arduino
ThingsBoard
Open-source libraries and contributors

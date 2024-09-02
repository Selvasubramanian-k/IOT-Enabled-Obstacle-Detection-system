
# IoT Enabled Obstacle Detection System

This project implements an IoT-based obstacle detection system using an Arduino UNO, IR obstacle sensor, and an Ethernet shield. The system detects obstacles in its path and displays the status on a web page, making it accessible from any device connected to the same network.

## Table of Contents
- [Overview](#overview)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Code Explanation](#code-explanation)
- [Future Improvements](#future-improvements)
- [License](#license)

## Overview
The obstacle detection system uses an IR sensor to detect objects in front of it. If an obstacle is detected, the system alerts the user by showing a warning message on a web page. The data is sent from the Arduino UNO to a connected web server using an Ethernet shield.

## Components
- Arduino UNO
- Arduino Ethernet Shield
- IR Obstacle Sensor
- LED (for visual indication)
- Ethernet Crossover Cable
- Jumper Wires

## Circuit Diagram
(Insert a circuit diagram here showing the connections between the Arduino, IR sensor, LED, and Ethernet shield)

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/iot-obstacle-detection.git
   ```
2. Open the project in the Arduino IDE.
3. Upload the `obstacle_detection.ino` code to your Arduino UNO.

## Usage
1. Connect the Ethernet shield to your Arduino UNO and connect it to your network using the Ethernet crossover cable.
2. Power the Arduino using a USB cable or an external power source.
3. Open a web browser and enter the IP address `192.168.1.177` to view the obstacle detection status.

## Code Explanation
The code initializes the Ethernet library with the MAC and IP address, sets up the input and output pins, and listens for incoming HTTP requests. Based on the IR sensor readings, it updates the web page with the current status (obstacle detected or path clear).

## Future Improvements
- Add support for multiple sensors to cover a wider area.
- Implement real-time alerts through email or SMS.
- Enhance the web interface for better visualization.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---
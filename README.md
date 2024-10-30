<a id="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/One-Bit-Myanmar/mahar-link.git">
    <img src="./image/mahar-link-logo.png" alt="Logo">
  </a>
</div>

<div align="center">
  <h3 align="center">IOT device for weather morintoring</h3>

  <p align="center">
    The weather IoT system that continuously monitors temperature and humidity using a DHT22 sensor transmitting real-time data for easy remote access and monitoring.
    <br />
    <a href="https://github.com/One-Bit-Myanmar/IOT-for-weather-mornitoring/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/One-Bit-Myanmar/IOT-for-weather-mornitoring/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This Weather IoT project is designed to monitor and transmit real-time environmental data—specifically temperature and humidity—using an ESP32 or ESP8266 microcontroller with a DHT22 sensor. The system connects to a WiFi network and uses the MQTT protocol to send sensor data to a cloud-based or local MQTT broker, such as HiveMQ’s public broker.

### 1. Hardware Components
- **ESP32 or ESP8266 Microcontroller**: The main controller responsible for reading data from the sensor and handling network communication.
- **DHT22 Sensor**: A digital sensor that measures temperature and humidity, known for its accuracy and ease of use.
- **Wiring and Power**: The DHT22 sensor connects to one of the GPIO pins on the ESP board, while the board is powered via USB or battery.

### 2. Data Collection and Processing
- The ESP32/ESP8266 reads temperature and humidity data from the DHT22 sensor at regular intervals (e.g., every 2 seconds).
- Each data point (temperature and humidity) is packaged into a JSON-formatted message, allowing easy parsing and display on various devices or platforms.

### 3. Networking and Communication
- **WiFi Connection**: The ESP connects to a WiFi network, which provides internet access for transmitting data.
- **MQTT Protocol**: The project uses the MQTT (Message Queuing Telemetry Transport) protocol, a lightweight messaging protocol commonly used in IoT due to its low bandwidth requirements. 
- **MQTT Broker**: All data is published to an MQTT broker (e.g., `broker.mqttdashboard.com`), where it can be accessed in real-time by subscribing devices or applications.

### 4. Data Publishing and Real-Time Monitoring
- After processing, the ESP publishes the JSON message containing temperature and humidity data to a specified MQTT topic (e.g., `wokwi-weather` or `iot/weather`).
- Using an MQTT client (like HiveMQ’s WebSocket client), users can subscribe to the MQTT topic to view real-time data updates in a browser or app. Each time the temperature or humidity changes, a new message is published to the MQTT topic.

### 5. Applications and Use Cases
- **Real-Time Environmental Monitoring**: Ideal for tracking temperature and humidity in homes, greenhouses, or storage facilities.
- **Remote Weather Stations**: The project can serve as a basic weather station that can be monitored remotely, without needing any on-site presence.
- **Educational Projects**: This setup is also a valuable educational tool, providing hands-on experience with IoT, MQTT, and sensor integration.


<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With


* [![Arduino][Next.js]][Next-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

To successfully build and run the IoT Weather Monitoring System, you’ll need the following:

#### Hardware Requirements
| **Component**                | **Description**                                                                                                 |
|------------------------------|-----------------------------------------------------------------------------------------------------------------|
| **ESP32 or ESP8266**         | Microcontroller board. Ensure your board is functional and compatible with the Arduino IDE.                     |
| **DHT22 Sensor**             | A DHT22 temperature and humidity sensor for environmental data collection.                                      |
| **Wiring and Breadboard**    | Jumper wires and a breadboard for secure connections between the microcontroller and sensor.                    |
| **Power Supply**             | USB cable or battery pack to power the ESP32/ESP8266.                                                           |
| **Testing Platform**         | If you just want to test, you can go to [Wokwi](https://wokwi.com/). Additionally, you can view this IoT project in [This IoT's Wokwi](https://wokwi.com/projects/413198851762210817). |

#### Software Requirements
#### Software Requirements

| **Requirement**             | **Description**                                                                                                 |
|-----------------------------|-----------------------------------------------------------------------------------------------------------------|
| **Arduino IDE**             | Download and install the Arduino IDE for programming the ESP32 or ESP8266. Ensure the **ESP32/ESP8266 board libraries** are installed in the Arduino IDE. |
| **Arduino Libraries**       | **PubSubClient** library for MQTT communication. **DHT Sensor Library** for reading data from the DHT22 sensor. |
| **WiFi Network**            | Access to a 2.4GHz WiFi network (compatible with most ESP boards) with SSID and password available.             |

#### MQTT Broker
- **MQTT Broker** (e.g., HiveMQ’s public broker or Mosquitto)
  - If using the public HiveMQ broker, no additional setup is required.
  - Ensure the MQTT broker is reachable from your network and supports the MQTT protocol on port `1883`.

#### Optional
- **MQTT Dashboard or Client**
  - HiveMQ’s [WebSocket Client](http://www.hivemq.com/demos/websocket-client/) or any other MQTT client for subscribing to the topic and viewing real-time data.
- **Cloud Integration** (optional)
  - If you want to log or analyze data, consider setting up a cloud IoT platform (e.g., AWS IoT or Google Cloud IoT).


### Installation

Follow these steps to install and set up the IoT Weather Monitoring System:

#### 1. Hardware Setup
1. **Connect the DHT22 Sensor** to the ESP32 or ESP8266:
    - Connect the **VCC** pin of the DHT22 to the **3.3V** pin on the ESP board.
    - Connect the **GND** pin of the DHT22 to the **GND** pin on the ESP board.
    - Connect the **Data** pin of the DHT22 to a digital **GPIO pin** (e.g., GPIO15) on the ESP board.

2. **Power the ESP32/ESP8266** using a USB cable connected to your computer or an external power source.

#### 2. Software Setup
1. **Download and Install the Arduino IDE**:
   - [Download Arduino IDE](https://www.arduino.cc/en/software) and install it on your computer.
   - Install the **ESP32/ESP8266 board libraries** via the Arduino Board Manager.
  
2. **Install Required Libraries**:
   - Open the Arduino IDE and go to **Sketch > Include Library > Manage Libraries**.
   - Search for and install the following libraries:
     - **PubSubClient** (for MQTT communication)
     - **DHT Sensor Library** (for reading data from the DHT22 sensor)

#### 3. Code Setup
1. **Open the Code**:
   - Copy the provided code into a new sketch in the Arduino IDE.
2. **Update WiFi and MQTT Credentials**:
   - Replace `SSID` and `PASSWORD` in the code with your WiFi network name and password.
   - Set the `mqtt_server` to `"broker.mqttdashboard.com"` (or another MQTT broker if you have one).
3. **Verify and Upload Code**:
   - Select your ESP32 or ESP8266 board from **Tools > Board**.
   - Choose the correct **Port** from **Tools > Port**.
   - Click on **Verify** to check for any errors, and then **Upload** the code to the board.

#### 4. Connect to the MQTT Broker
1. **Verify Connection**:
   - Open the **Serial Monitor** in the Arduino IDE to confirm that the ESP has successfully connected to WiFi and the MQTT broker.
   - You should see periodic messages indicating the current temperature and humidity readings being published to the MQTT topic.
2. **Monitor Data with MQTT Client**:
   - Open an MQTT client, like the [HiveMQ WebSocket Client](http://www.hivemq.com/demos/websocket-client/).
   - Connect to the MQTT broker and subscribe to the topic you set (e.g., `iot/weather`) to view real-time data.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Usage

The IoT Weather Monitoring System is a powerful yet simple tool for continuously monitoring environmental conditions, providing real-time data that is easily accessible from anywhere. Below are some common use cases and the benefits of using this system:

### Real-Time Environmental Monitoring
| **Use Case**              | **Description**                                                                                                                                               |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Home Monitoring**       | Track indoor temperature and humidity to maintain a comfortable living environment, and receive alerts when conditions reach uncomfortable or potentially harmful levels. |
| **Greenhouses and Gardens** | Monitor climate conditions in greenhouses to ensure optimal temperature and humidity for plant growth, reducing the risk of plant stress or disease.                |
| **Storage Facilities**    | Maintain the ideal environment for sensitive materials (e.g., electronics, food, documents) by tracking temperature and humidity levels and preventing conditions that could lead to deterioration. |

### Remote Weather Station

- The system acts as a lightweight, affordable remote weather station, ideal for individuals, hobbyists, or researchers in rural or outdoor areas.
- **Weather Data Collection**: Collect environmental data over time, gaining insights into local weather patterns without the need for expensive equipment.
- **Public Weather Sharing**: Share data with local communities or organizations that may benefit from having real-time environmental data, especially in areas without formal weather stations.

### Educational and Learning Tool
- **Hands-On Learning for IoT Concepts**: This project serves as an excellent learning resource for students and beginners, providing experience with microcontrollers, sensors, and MQTT.
- **Understanding Cloud and Network Communication**: Gain knowledge of cloud-based communication, networking protocols (e.g., MQTT), and data publishing by seeing how sensor data travels from a device to the cloud.

### Data Logging and Automation (Advanced Usage)

- **Data Analysis**: Integrate with cloud platforms like AWS IoT or Google Cloud IoT to log data for long-term analysis, helping identify trends and enabling predictive insights.
- **Smart Automation**: Set up smart actions based on specific conditions, such as automatically turning on a fan or humidifier if temperature or humidity thresholds are exceeded.

### Benefits
- **Remote Access**: Data is accessible via any internet-connected device, allowing users to stay informed about environmental changes in real-time.
- **Low-Cost and Scalable**: Compared to commercial weather stations, this project is highly affordable and scalable, with the ability to add additional sensors or functionalities as needed.
- **Flexibility**: The system can be adapted to various environments and expanded to suit specific needs, making it suitable for both small and large applications.

This IoT Weather Monitoring System is a practical, versatile solution that combines ease of use with powerful capabilities, enabling users to gain valuable environmental insights and take proactive actions based on real-time data.


<p align="right">(<a href="#readme-top">back to top</a>)</p>




[Next.js]: https://img.shields.io/badge/arduino-00979C?style=for-the-badge&logo=arduino&logoColor=white
[Next-url]: https://www.arduino.cc/
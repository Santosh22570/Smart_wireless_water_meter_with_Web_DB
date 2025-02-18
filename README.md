# 🚰 Smart Wireless Water Meter with Web DB

A **Smart Wireless Water Meter** that monitors water consumption, ensures water quality, and enables real-time remote control via a **web-based database [ThingSpeak IoT platform](https://thingspeak.mathworks.com/channels/2819273)**. This IoT-based system optimizes water usage, prevents wastage, and provides real-time alerts.

## 📌 Features
- 📡 **IoT-Based Wireless Monitoring** (ESP32-based)
- 📊 **Real-Time Data Visualization** on **ThingSpeak**
- 🌊 **Water Flow Tracking** (FS400 Sensor)
- 💧 **Water Quality Monitoring** (TDS Sensor)
- 📢 **Automated Pump Control** (Relay System)
- 🛠 **Remote Access & Alerts** via a web-based dashboard

## 🛠️ Tech Stack
| Component                   | Technology Used         |
|-----------------------------|-------------------------|
| **Microcontroller**         | ESP32                   |
| **Water Flow Sensor**       | FS400                   |
| **Water Quality Sensor**    | TDS Sensor              |
| **Tank Level Sensor**       | Ultrasonic Sensor       |
| **Communication**           | Wi-Fi (ESP32)           |
| **Cloud Platform**          | ThingSpeak              |
| **Software**                | Arduino IDE, Embedded C |

## 📜 Installation Guide

### 1️⃣ Prerequisites
- ESP32 Microcontroller
- Sensors (FS400, TDS, Ultrasonic)
- Relay module for pump control
- **Arduino IDE** for firmware
- **ThingSpeak** account for IoT dashboard

### 2️⃣ Setup Hardware
1. Connect ESP32 with sensors:
   - **FS400 Flow Sensor** → Measures water flow
   - **TDS Sensor** → Checks water quality
   - **Ultrasonic Sensor** → Monitors water level
   - **Relay Module** → Controls motor/pump
2. Ensure correct wiring and power connections.

### 3️⃣ Firmware Setup
1. Install **Arduino IDE** and add the **ESP32 board package**.
2. Download required libraries:
   ```sh
   ArduinoJson, WiFi, ThingSpeak
3. Flash ESP32 with the provided Arduino sketch.
4. Configure Wi-Fi credentials and ThingSpeak API key.

### 4️⃣ Web Dashboard (ThingSpeak)
1. Create a **ThingSpeak Channel**.
2. Set up **fields**:
    - **Flow Rate**
    - **Water Quality (TDS)**
    - **Tank Level**
    - **Pump Status**
3. Integrate **API keys** in the ESP32 code.

### 🚀 Usage
1. Power on the **ESP32**.
2. Sensors collect **flow rate, TDS, and water levels**.
3. Data is sent to **ThingSpeak** for real-time monitoring.
4. The system **automatically controls** the pump.
5. Alerts trigger when **quality or water levels** are critical.

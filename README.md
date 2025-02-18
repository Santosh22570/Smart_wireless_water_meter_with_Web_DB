# 🚰 Smart Wireless Water Meter with Web DB

A **Smart Wireless Water Meter** that monitors water consumption, ensures water quality, and enables real-time remote control via a **web-based database [ThingSpeak IoT platform](https://thingspeak.mathworks.com/channels/2819273)**. This IoT-based system optimizes water usage, prevents wastage, and provides real-time alerts.

---

## 📌 Features
- 📡 **IoT-Based Wireless Monitoring** (ESP32-based)
- 📊 **Real-Time Data Visualization** on **ThingSpeak**
- 🌊 **Water Flow Tracking** (FS400 Sensor)
- 💧 **Water Quality Monitoring** (TDS Sensor)
- 📢 **Automated Pump Control** (Relay System)
- 🛠 **Remote Access & Alerts** via a web-based dashboard

---

## 🛠️ Tech Stack
| Component                      | Technology Used            |
|--------------------------------|----------------------------|
| **Microcontroller**            | ESP32                      |
| **Water Flow Sensor**          | FS400                      |
| **Water Quality Sensor**       | TDS Sensor                 |
| **Tank Level Sensor**          | Ultrasonic Sensor          |
| **Communication**              | Wi-Fi (ESP32)              |
| **Cloud Platform**             | ThingSpeak                 |
| **Software**                   | Arduino IDE, Embedded C    |

---

## 👨‍💻 Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/sandeepku-s/Smart_wireless_water_meter_with_Web_DB.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Smart_wireless_water_meter_with_Web_DB
   ```
3. Open the project in VS Code.

---

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

---

## Software Requirement:
- [Arduino IDE](https://www.arduino.cc/)
> Arduino IDE used to upload programming in ESP32 Board with required library.
- [Thingspeak](https://thingspeak.com/)
> ThingSpeak is a cloud-based IoT analytics platform service that lets you collect, view, and examine real-time data streams. Data can be sent from your devices to ThingSpeak, enabling instantaneous live data display.

---

## 🚀 Usage
1. Power on the **ESP32**.
2. Sensors collect **flow rate, TDS, and water levels**.
3. Data is sent to **ThingSpeak** for real-time monitoring.
4. The system **automatically controls** the pump.
5. Alerts trigger when **quality or water levels** are critical.

---

## Under the Guidence:
- [Mrs. SWETHA S KULKARNI](https://www.linkedin.com/in/swetha-s-kulkarni-87280b101/)
- [Dr. DEEPTI RAJ]()

## Team members:
- [HARSHAN S](https://www.linkedin.com/in/harshan-s/)
- [K SANTOSH](https://www.linkedin.com/in/k-santosh-102a73310/)
- [MANOJ KUMAR C S](https://www.linkedin.com/in/manoj-kumar-c-s-a981a0254/)
- [SANDEEPKUMAR S](https://www.linkedin.com/in/sandeepku-s/)

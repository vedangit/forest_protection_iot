# 🌳 Forest Protection IoT Project 🌳

An IoT-based forest monitoring system that detects forest fires, monitors environmental conditions, and uses RFID for access control, integrated with tilt and flex sensors to detect unauthorized actions such as tree cutting. This project uses Arduino Uno as the main controller along with various modules like temperature sensors, RFID, servo motors, and flex sensors to ensure forest safety.

## 🎯 Features
- 🔥 **Fire Detection**: Monitors temperature and humidity using a DHT22 sensor to detect potential fires.
- 🔑 **RFID Access Control**: Approves access for authorized individuals using RFID technology.
- 🔐 **Locking Mechanism**: Servo motor locking system that opens only when authorized RFID tags are scanned.
- 📐 **Tilt Detection**: Uses a tilt sensor to detect suspicious movements of trees.
- 🌲 **Tree Cutting Detection**: Implements a flex sensor to detect potential tree cutting activities.

## 🛠️ Components
1. **Arduino Uno**
2. **DHT22 Temperature & Humidity Sensor**
3. **RFID RC522 Module**
4. **Servo Motor** 
5. **Flex Sensor** 
6. **ESP8266** 
7. **SIM800L** 

## 🚀 Getting Started

### 1. 📦 Prerequisites

Make sure you have the following libraries installed in your Arduino IDE:
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
- [MFRC522 RFID Library](https://github.com/miguelbalboa/rfid)
- [Servo Library](https://www.arduino.cc/en/Reference/Servo)

### 2. 🔧 Connections

| Component     | Description                          |
|---------------|--------------------------------------|
| DHT22         | Temperature and Humidity Sensor      |
| RFID RC522    | RFID Reader                          |
| Servo Motor   | Locking Mechanism                    |
| Flex Sensor   | Detects tree bending (cutting)       |


### 3. 📂 Directory Structure

```plaintext
📁 ForestProtectionIoT
├── 📄 forest_protection.ino         # Main file
├── 📄 tempsensor.ino                # Temperature sensor code
├── 📄 rfid.ino                      # RFID reader code
├── 📄 flexsensor.ino                # Flex sensor for tree cutting detection
├── 📄 rfid.h                        # Header file for RFID functions
├── 📄 tempsensor.h                  # Header file for temperature sensor functions
└── README.md                        # Project documentation
```

### 4. 📜 Usage

1. Clone this repository and open the `forest_protection.ino` file in your Arduino IDE.
2. Upload the code to your Arduino Uno.
3. **RFID Authorization**: Update the UID of the authorized RFID tag in the `rfid.h` file.
4. Monitor serial output for temperature, humidity, and tree status, and control the lock with the RFID system.

### 5. 🧩 Modules

#### 🔥 Temperature Sensor (DHT22)

Monitors environmental conditions to detect fire hazards.

```cpp
float temperature = readTemperature();
if (isFireDetected(temperature)) {
    Serial.println("🔥 Fire detected!");
}
```

#### 🔑 RFID Access Control

Allows only authorized users to unlock the system.

```cpp
if (isAuthorizedTag()) {
    Serial.println("🔓 Access granted!");
    // Unlock the servo
} else {
    Serial.println("🔒 Access denied!");
}
```

#### 🌲 Flex Sensor (Tree Cutting Detection)

Detects unusual bending that might indicate tree cutting.

```cpp
if (isTreeCut()) {
    Serial.println("🌲 Tree cutting detected!");
}
```

### 6. 🖼️ Schematic Diagram

Here's a basic schematic to connect all the components:

[Include a visual diagram showing the wiring connections between the Arduino and the components]

## 📚 Libraries Used
- [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
- [MFRC522 RFID Library](https://github.com/miguelbalboa/rfid)
- [Servo Library](https://www.arduino.cc/en/Reference/Servo)

## 👨‍💻 Contributors
- [Vedangi Thokal](https://github.com/vedangit)
- [Siddhi Murkute](https://github.com/siddhimurkute)



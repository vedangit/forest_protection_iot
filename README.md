# Forest Protection IoT System

A real-time forest protection system designed to detect forest fires, tree cutting, and environmental changes using IoT sensors. This project leverages Arduino-based sensors, Supabase for database storage, Blynk for remote notifications, RFID for access control, and Next.js for building a full-stack web application for monitoring and alerting.

## Features

- **Real-Time Monitoring**: Displays sensor data (temperature, humidity, tilt) in real-time on a dashboard.
- **Forest Fire Detection**: Alerts when temperature exceeds a predefined threshold indicating potential fire risks.
- **Tilt Detection for Tree Cutting**: Detects unusual tilts using an MPU6050 sensor, triggering an alert in case of illegal tree cutting or suspicious activity.
- **RFID Access Control**: An RFID system for access control, allowing authorized personnel to unlock restricted areas using an RFID tag and triggering access logs.
- **Full-Stack Web App**: Developed using Next.js with both backend API for data collection and a frontend dashboard for monitoring sensor data.
- **Database Integration**: Uses Supabase for storing sensor data and making it accessible through the web application.

## Technologies Used

- **Arduino UNO**
- **Next.js**: Framework for building the full-stack web application (both API and frontend).
- **Supabase**: Used for database storage to save and retrieve sensor data in real-time.
- **Blynk**: For remote monitoring and sending notifications based on sensor readings.
- **Node MCU (ESP8266)**: Used for Wi-Fi connectivity and communication with the backend server.
- **MPU6050 & DHT11 Sensors**: For detecting tilt (tree cutting) and environmental data (temperature and humidity).
- **RC522 RFID Module**: For integrating RFID access control to ensure authorized access to the monitored areas.

## Project Overview

### Backend (API)
The backend API is built using Next.js. It accepts sensor data from the IoT device and stores it in the Supabase database. The data includes:
- **Temperature**: Captured using the DHT11 sensor.
- **Humidity**: Captured using the DHT11 sensor.
- **Tilt**: Measured using the MPU6050 sensor, triggering alerts for any suspicious movement.
- **RFID Access Logs**: Logs RFID-based access events to track authorized personnel.

### Frontend (Dashboard)
The frontend dashboard displays real-time sensor data and alerts on a user-friendly interface. Built with Next.js, it provides:
- **Real-time Data Visualization**: Displays current temperature, humidity, and tilt data in an interactive format.
- **Alerts**: Triggered when the temperature exceeds a defined threshold for fire detection or when tilt is detected, indicating potential tree cutting.

### Remote Monitoring
Blynk is integrated for remote monitoring of sensor readings, allowing notifications for alerts (fire detection, tilt detection, unauthorized access). The system also logs events, such as high temperature, tilt detection, and RFID-based access control.


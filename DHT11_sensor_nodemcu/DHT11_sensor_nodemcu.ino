#define BLYNK_TEMPLATE_ID "TMPL3xCAeFFKo"
#define BLYNK_TEMPLATE_NAME "IOT II"
#define BLYNK_AUTH_TOKEN " "
#define BLYNK_PRINT Serial

#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <DHT.h>
#include <MPU6050.h>
#include <Wire.h>
#include <ESP8266HTTPClient.h>

MPU6050 mpu;



char ssid[] = " ";
char pass[] = " ";

const char* serverUrl = " "; // Your deployed URL
const char* supabaseUrl =" ";
const char* supabaseKey = " ";
char auth[] = " "; // Blynk Auth Token

// DHT sensor
#define DHTPIN 2 // Digital pin for DHT
#define DHTTYPE DHT11 // Change to DHT22 if using DHT22

DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;

// Tilt detection settings
float tiltThreshold = 15.0; // Threshold for tilt detection
bool isTilted = false;

// MPU6050 setup
int16_t ax, ay, az;
float tiltAngle = 0.0;

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);

  // Initialize WiFi and Blynk
  Blynk.begin(auth, ssid, pass);

  // Initialize DHT sensor
  dht.begin();

  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }

  // Setup SimpleTimer to send sensor data
  timer.setInterval(1000L, sendSensor);
}

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if(t > 0.5) {
    Serial.println("Chances of forest fire!");
    Blynk.logEvent("forest_fire");
  }

  // Send data to Blynk
  Blynk.virtualWrite(V5, h); // Humidity for gauge
  Blynk.virtualWrite(V6, t); // Temperature for gauge
}

void loop() {
  Blynk.run(); // Initiate Blynk
  timer.run(); // Run SimpleTimer

  // Get accelerometer data from MPU6050
  mpu.getAcceleration(&ax, &ay, &az);

  // Convert raw accelerometer data to tilt angle (in degrees)
  tiltAngle = atan2(ay, sqrt(ax * ax + az * az)) * 180 / PI;

  // Print tilt angle to Serial Monitor
  Serial.print("Tilt Angle: ");
  Serial.println(tiltAngle);

  // Check if tilt angle exceeds the threshold
  if (tiltAngle > tiltThreshold) {
    Serial.println("Tilt detected!");
    // Send tilt status to Blynk (Virtual Pin V7)
    Blynk.virtualWrite(V7, 1);
    Blynk.logEvent("tilt_detected");
  } else {
    Blynk.virtualWrite(V7, 0);
  }

  delay(500);  // Delay to avoid flooding the serial output and Blynk updates

  // Send data to the server
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    WiFiClient client;  // Create a WiFiClient object
    http.begin(client, serverUrl);  // Use WiFiClient object for HTTPClient

    http.addHeader("Content-Type", "application/json");
    float h = dht.readHumidity();
    float t = dht.readTemperature(); 
    
    // Prepare JSON payload
    String payload = "{\"temperature\":" + String(t) + ",\"humidity\":" + String(h) + ",\"tilt\":" + String(tiltAngle) + "}";

    // Send HTTP POST request
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Data sent successfully: " + response);
    } else {
      Serial.println("Error in sending data: " + String(httpResponseCode));
    }

    http.end();  // End HTTP connection
  } else {
    Serial.println("WiFi Disconnected");
  }
}

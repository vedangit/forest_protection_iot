#include <Adafruit_Sensor.h>
#include "tiltsensor.h"

#include <Arduino.h>
#include "tempsensor.h"
#include "rfid.h"
#include "servo.h"
#include "flex.h"
#include "wifi.h"
#include "gps.h"  // Include the GPS functionality

#define LED_PIN 7 // Define the pin for the LED

void setup() {
    
     
    Serial.begin(115200);
  
    setupRFID();
    readCardUID();
    setupServo();
    
}

void loop() {

  readCardUID();
   
}

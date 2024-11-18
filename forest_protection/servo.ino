#include <Servo.h>
#include "servo.h"

// Define the servo object
Servo lockServo;

// Define the lock position angles
#define SERVO_PIN 6  // Servo connected to pin 6
#define LOCKED_POSITION 0    // Position when locked
#define UNLOCKED_POSITION 90 // Position when unlocked

void setupServo() {
    lockServo.attach(SERVO_PIN);
    lockServo.write(LOCKED_POSITION);  // Initialize the servo in the locked position
    Serial.println("Servo initialized to locked position.");
}

void unlockServo() {
    lockServo.write(UNLOCKED_POSITION);  // Unlock position
    Serial.println("Servo unlocked.");
}

void engageLock() {  // Renamed from lockServo to engageLock
    lockServo.write(LOCKED_POSITION);    // Lock position
    Serial.println("Servo locked.");
}

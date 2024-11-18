#include <SPI.h>
#include <MFRC522.h>
#include "rfid.h"
#include "servo.h" 

// Create an instance of the MFRC522 class
MFRC522 rfid(SS_PIN, RST_PIN);

void setupRFID() {
    Serial.begin(115200);
    SPI.begin(); // Initialize SPI bus
    rfid.PCD_Init(); // Initialize RFID reader
    Serial.println("RFID reader initialized.");
}

void readCardUID() {
    // Look for new cards
    if (!rfid.PICC_IsNewCardPresent()) {
        return;
    }

    // Select one of the cards
    if (!rfid.PICC_ReadCardSerial()) {
        return;
    }

    // Print the UID of the card
    Serial.print("Card UID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? "0" : ""); // Add leading zero
        Serial.print(rfid.uid.uidByte[i], HEX);
        Serial.print(i < rfid.uid.size - 1 ? ":" : ""); // Add ":" separator
    }
    Serial.println();

    // Check if the UID matches the authorized tag
    if (memcmp(rfid.uid.uidByte, AUTHORIZED_UID, rfid.uid.size) == 0) {
        Serial.println("Authorized tag detected.");
        unlockServo();
        delay(5000);
        engageLock();
    } else {
        Serial.println("Unauthorized tag detected.");
    }
}

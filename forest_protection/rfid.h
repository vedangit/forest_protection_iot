#ifndef RFID_H
#define RFID_H

#include <SPI.h>
#include <MFRC522.h>

// Define the pins for the RFID reader
#define RST_PIN         9   // Reset pin
#define SS_PIN          10  // Slave select pin

// Predefined authorized RFID UID (change to your RFID tag UID)
const byte AUTHORIZED_UID[] = {0xD9, 0xCE, 0xCB, 0x59}; // Your card's UID

// Create an instance of the MFRC522 class
extern MFRC522 rfid;

void setupRFID();
bool isAuthorizedTag();
void readCardUID();

#endif // RFID_H

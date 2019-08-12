// LoRaMESH_Radioenge - Version: Latest 
#include <LMESH.h>

/*
  Radioenge Equipamentos de Telecomunicações
  
  Application example using the EndDevice LoRaMESH Radioenge together with
  the Arduino Uno.
  
  This script:
    - Initializes the software serial interface on the pins 6 (RX) and 7 (TX).
    - Reads the local device ID to check if it is a master or slave.
    - If it is a master:
      - Waits for messages from slaves and shows the payload on the monitor.
      - Replies each message with an acknowledge.
    - If it is a slave:
      - Configures the GPIO 5 as analog input.
      - Reads the analog inputs and sends to the master periodically.
*/

/* Includes ---------------------- */
#include <SoftwareSerial.h>
#include <stdint.h>
#include <stdbool.h>

/* Defines ----------------------- */
#define CMD_ANALOG  50

/* Payload buffer */
uint8_t bufferPayload[MAX_PAYLOAD_SIZE] = {0};
uint8_t payloadSize = 0;

/* Local device ID */
uint16_t localId;

/* Remote device ID */
uint16_t remoteId;

/* Local device Unique ID */
uint32_t localUniqueId;

/* Local device Net */
uint16_t localNet;

/* Received command */
uint8_t command;

bool isMaster;

/* Value read on the analog input */
uint16_t AdcIn;

/* SoftwareSerial handles */
SoftwareSerial* hSerialCommands = NULL;

/* Initialization routine */
void setup() {
  delay(1000);
  Serial.begin(9600); /* Initialize monitor serial */
  
  /* Initialize SoftwareSerial */
  hSerialCommands = SerialCommandsInit(7, 6, 9600);

  /* Gets the local device ID */
  if(LocalRead(&localId, &localNet, &localUniqueId) != MESH_OK)
    Serial.print("Couldn't read local ID\n\n");
  else
  {
    Serial.print("Local ID: ");
    Serial.println(localId);
    Serial.print("Local NET: ");
    Serial.println(localNet);
    Serial.print("Local Unique ID: ");
    Serial.println(localUniqueId, HEX);
    Serial.print("\n");

    WriteConfig(1, 9,localUniqueId);
  }
}

/* Main loop */
void loop() {

  
}

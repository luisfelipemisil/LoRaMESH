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
uint16_t remoteId = 1;

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
//SoftwareSerial* hSerialCommands = NULL;

/* Initialization routine */
void setup() {
  delay(1000);
  Serial1.begin(9600); /* Initialize monitor serial */
  SerialTranspInit(9600);


  bufferPayload[0] = 26;
  bufferPayload[1] = 1;

  
  if(PrepareFrameTransp(2, bufferPayload, 2) != MESH_OK){
    Serial1.print("Erro ao preparar playload transparente");
  }

  if(SendPacket() != MESH_OK){
    Serial1.print("Erro ao enviar.");
  }
  else{
    Serial1.print("mandei");
  }

}

/* Main loop */
void loop() {

  if(ReceivePacketTransp(&remoteId, bufferPayload, &payloadSize, 5000) == MESH_OK){
      
      Serial1.print("\nID: ");
      Serial1.print(remoteId);
      Serial1.print("\ndados: ");
      Serial1.println(bufferPayload[0]);
      Serial1.print(bufferPayload[1]);
      Serial1.print("V\n");

      /* Replies the message - ACK*/
      bufferPayload[0] = 0;
      bufferPayload[1] = 0;

      PrepareFrameTransp(remoteId,bufferPayload, 2);  // Payload size = 2
      SendPacket();
    }
  
}

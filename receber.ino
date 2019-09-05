
#include "EspLoRaMesh.h"


/* Payload buffer */
uint8_t bufferPayload[MAX_PAYLOAD_SIZE] = {0};
uint8_t payloadSize = 0;
uint16_t otherId;

/* Value read on the analog input */
uint16_t AdcIn = 0x00;


void setup() {

  Serial.begin(9600); /* Initialize monitor serial */
  Serial1.begin(9600);
  

  // declarar o id e net do Lora - deve-se antes saber por leitura do nó qual o seu id, a essa lib não permite isso.
  //loraId ( id da lora , net );
  loraId(1,0); // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<!!!!!!!

}

void loop() {
  
  if(ReceivePacketTransp(&otherId, bufferPayload,&payloadSize, 5000) == MESH_OK){
    Serial1.print("Recebido ");
    Serial1.println(bufferPayload[0]);
    Serial1.println(bufferPayload[1]);
    Serial1.println(bufferPayload[2]);
  } 
}
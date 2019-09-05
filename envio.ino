
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

  bufferPayload[0] = 26;
  bufferPayload[1] = 04;
  bufferPayload[2] = 96;

}

void loop() {
if(PrepareFrameTransp(0, &bufferPayload[0], 3) != MESH_OK){
    Serial1.println("Erro ao preparar playload transparente");
  }
  else
    Serial1.println("pac ok");

  if(SendPacket() != MESH_OK){
    Serial1.println("Erro ao enviar.");
  }
  else{
    Serial1.println("mandei");
    Serial1.println(bufferPayload[0]);
    Serial1.println(bufferPayload[1]);
    Serial1.println(bufferPayload[2]);
  }
  delay(1000);
}
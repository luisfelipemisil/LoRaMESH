/* ---------------------------------------------------
        Radioenge Equipamentos de Telecomunicações
   ---------------------------------------------------
    This library contains a set of functions to configure
    and operate the EndDevice LoRaMESH Radioenge
  
  Date: 13/12/18
*/
#ifndef _LORA_MESH_
#define _LORA_MESH_

#include <stdint.h>
#include <stdbool.h>
#include "Arduino.h"
#include <SoftwareSerial.h>

/* ----- Defines ------ */

#define MAX_PAYLOAD_SIZE 232
#define MAX_BUFFER_SIZE 237


typedef enum{
  MESH_OK,
  MESH_ERROR
} MeshStatus_Typedef;

void loraId(uint16_t id, uint16_t net);

MeshStatus_Typedef PrepareFrameTransp(uint16_t id, uint8_t* payload, uint8_t payloadSize);

MeshStatus_Typedef SendPacket();

MeshStatus_Typedef ReceivePacketTransp(uint16_t* id, uint8_t* payload, uint8_t* payloadSize, uint32_t timeout);

#endif

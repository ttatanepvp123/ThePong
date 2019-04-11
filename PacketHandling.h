#ifndef PACKETHANDLING_H_INCLUDED
#define PACKETHANDLING_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum ePlayerPacket {
    PACKET_BALL_X,
    PACKET_BALL_Y,
    PACKET_BALL_DIRX,
    PACKET_BALL_DIRY,
    PACKET_PAD1_X,
    PACKET_PAD1_Y,
    PACKET_PAD2_X,
    PACKET_PAD2_Y,

    /* AJOUTER NOUVELLES INFOS */

    PACKET_INFO_MAX //Taille max de la table
};

void EncodePacket(char paquet[], float data[], int tailleTableData);
void DecodePacket(float tInfoPaquet[], char paquet[],int packetMaxSize);

#endif // PACKETHANDLING_H_INCLUDED
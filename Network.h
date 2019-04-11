#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include "Struct.h"
#include "server/PacketHandling.h"
#include<stdio.h>
#include<winsock2.h>
#include<string.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
//#define SERVER "90.118.132.209"  //ip address of udp server
#define SERVER "86.202.108.99"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 20030   //The port on which to listen for incoming data


Socket initSocket(Socket sok);
void askServer(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,Uint32 deltaTime, Socket sok);


#endif // NETWORK_H_INCLUDED

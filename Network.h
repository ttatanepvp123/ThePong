#ifndef NETWORK_H_INCLUDED 
#define NETWORK_H_INCLUDED
#ifdef _WIN32

#include "Struct.h"
#include "server/PacketHandling.h"
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib") //Winsock Library
#include <string.h>
#define SERVER "127.0.0.1"  //ip address of tcp server
#define BUFLEN 512  //Max length of buffer
#define PORT 20030   //The port on which to listen for incoming data


Socket initSocket(Socket sok);
void askServer(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,Uint32 deltaTime, Socket sok);

#endif
#endif // NETWORK_H_INCLUDED

#include<stdio.h>
#include<winsock2.h>
#include<string.h>
 
#include "Struct.h"
#include "UpdateGameServer.h"
#include "define.h"
#include "PacketHandling.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library
 
#define BUFLEN 512  //Max length of buffer
#define PORT 20030   //The port on which to listen for incoming data
 
int main(int argc, char *argv[])
{
    SOCKET s;
    struct sockaddr_in server, si_other, j1, j2;
    int slen , recv_len;
    char buf[BUFLEN];
    WSADATA wsa;
 
    slen = sizeof(si_other) ;
     
    //Initialise winsock
    printf("\n[ LOG ] : Initialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("[ ERROR ] : Failed. Error Code : %d",WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("[ OK ] : Initialised.\n");
     
    //Create a socket
    if((s = socket(AF_INET , SOCK_DGRAM , 0 )) == INVALID_SOCKET)
    {
        printf("[ ERROR ] : Could not create socket : %d" , WSAGetLastError());
    }
    printf("[ OK ] : Socket created.\n");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( PORT );
     
    //Bind
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("[ ERROR ] : Bind failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    puts("[ OK ] : Bind done");
 
/*
    //Initialisation J1
    j1.sin_family = AF_INET;
    //j1.sin_addr.s_addr = NULL;
    j1.sin_addr.s_addr = "127.0.0.1";
    j1.sin_port = htons( PORT );

    //Initialisation J2
    j2.sin_family = AF_INET;
    //j2.sin_addr.s_addr = NULL;
    j2.sin_addr.s_addr = "86.202.108.99";
    j2.sin_port = htons( PORT );
    
    //Initialisation des joueurs
    while (j1.sin_addr.s_addr == NULL || j2.sin_addr.s_addr == NULL) {
        printf("Initialisation des joueurs");

        //Réception data, le 1er qui envoie est J1, l'autre J2.
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR)
        {
            printf("recvfrom() failed with error code : %d" , WSAGetLastError());
            exit(EXIT_FAILURE);
        }

        //Printf du message reçu
        printf("Data: %s\n" , buf);

        //On sauvegarde l'adresse IP du Joueur si on l'a pas déjà
        if (j1.sin_addr.s_addr == NULL) {
            j1.sin_addr.s_addr = buf; //TODO - vérifier
        }
        else {
            if (j1.sin_addr.s_addr != buf) {
                j2.sin_addr.s_addr = buf; //TODO - vérifier
            } 
        }
    }

    //Les deux joueurs sont connus, on lance la partie
    if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR)
    {
        printf("sendto() failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
*/

    //Initialisation du jeu côté serveur
    Raquette Raquette1 = {0};
    Raquette *pRaquette1 = NULL;
    pRaquette1 = &Raquette1;

    Raquette Raquette2 = {0};
    Raquette *pRaquette2 = NULL;
    pRaquette2 = &Raquette2;

    Ball Balle = {0};
    Ball *pBalle = NULL;
    pBalle = &Balle;

    /*
    if(modeBall == 1){
        pBalle->mode = 1;
    }
    */
    
    Keyboard keyboard = {0};
    Keyboard *pKeyboard = &keyboard;
    pKeyboard->ArrowDown = 0;
    pKeyboard->ArrowUp = 0;
    pKeyboard->Keyz = 0;
    pKeyboard->Keys = 0;

    InitGame(pRaquette1,pRaquette2,pBalle,0);

    int updateTimer = UPDATE_TIMER;
    int renderTimer = RENDER_TIMER;
    int pauseTimer = 0;

    while(1) {
        printf("[ LOG ] : Waiting for data...\n");
        fflush(stdout);
         
        //clear the buffer by filling null, it might have previously received data
        memset(buf,'\0', BUFLEN);
         
        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == SOCKET_ERROR) {
            printf("[ ERROR ] : recvfrom() failed with error code : %d" , WSAGetLastError());
            exit(EXIT_FAILURE);
        }
         
        //print details of the client/peer and the data received
        printf("[ LOG ] : Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("[ LOG ] : Data: %s\n" , buf);

        //Décodage de paquet
        float tInfoPaquet[10] = {0}; //Normalement juste 7 infos (client) et 2 (serveur)
        DecodePacket (tInfoPaquet,buf,BUFLEN);

        printf("info paquet 1 : %d\n",tInfoPaquet[0]);
        printf("info paquet 2 : %d\n",tInfoPaquet[1]);

        //On update le keyboard selon les infos du joueur
        if (strcmp(inet_ntoa(si_other.sin_addr),"90.118.132.209")==0) { //TAttane /*90.118.132.209*/
            if (tInfoPaquet[0] == 0) {
                pKeyboard->ArrowUp = 0;
                pKeyboard->ArrowDown = 0;
            }
            else if (tInfoPaquet[0] == 1) {
                pKeyboard->ArrowUp = 1;
                pKeyboard->ArrowDown = 0;
            }
            else if (tInfoPaquet[0] == 2) {
                pKeyboard->ArrowUp = 0;
                pKeyboard->ArrowDown = 1;
            }
            else if (tInfoPaquet[0] == 3) {
                break;
            }
        }
        else { //IP = "86.202.108.99" //Sophia
            if (tInfoPaquet[0] == 0) {
                pKeyboard->Keyz = 0;
                pKeyboard->Keys = 0;
            }
            else if (tInfoPaquet[0] == 1) {
                pKeyboard->Keyz = 1;
                pKeyboard->Keys = 0;
            }
            else if (tInfoPaquet[0] == 2) {
                pKeyboard->Keyz = 0;
                pKeyboard->Keys = 1;
            }
            else if (tInfoPaquet[0] == 3) {
                break;
            }
        }

        printf("\nPad1 Y (av) : %f\n",pRaquette1->y);
        printf("Pad2 Y (av) : %f\n",pRaquette2->y);
        printf("pBalle X (av) : %f\n",pBalle->x);
        printf("keyz (av) : %d\n",pKeyboard->Keyz);
        printf("keyUp (av) : %d\n",pKeyboard->ArrowUp);

        //On update le jeu
        UpdateGameServer(pKeyboard,pRaquette1,pRaquette2,pBalle,tInfoPaquet[1]);

        printf("\nPad1 Y (ap) : %f\n",pRaquette1->y);
        printf("Pad2 Y (ap) : %f\n",pRaquette2->y);
        printf("pBalle X (ap) : %f\n",pBalle->x);
        printf("keyz (ap) : %d\n",pKeyboard->Keyz);
        printf("keyUp (ap) : %d\n",pKeyboard->ArrowUp);
        
        //Préparation réponse client
        char paquet[BUFLEN] = "";
        float data[PACKET_INFO_MAX-1] = {0};
        data[PACKET_BALL_X] = pBalle->x;
        data[PACKET_BALL_Y] = pBalle->y;
        data[PACKET_BALL_DIRX] = pBalle->dirx;
        data[PACKET_BALL_DIRY] = pBalle->diry;
        data[PACKET_PAD1_X] = pRaquette1->x;
        data[PACKET_PAD1_Y] = pRaquette1->y;
        data[PACKET_PAD2_X] = pRaquette2->x;
        data[PACKET_PAD2_Y] = pRaquette2->y;

        EncodePacket(paquet,data,PACKET_INFO_MAX-1);
        printf("paquet : %s\n",paquet);

        //now reply the client with the same data
        if (sendto(s, paquet, BUFLEN, 0, (struct sockaddr*) &si_other, slen) == SOCKET_ERROR) {
            printf("sendto() failed with error code : %d" , WSAGetLastError());
            exit(EXIT_FAILURE);
        }

        pKeyboard->ArrowUp = 0;
        pKeyboard->ArrowDown = 0;
        pKeyboard->Keyz = 0;
        pKeyboard->Keys = 0;

    }
 
    closesocket(s);
    WSACleanup();
     
    return 0;
}
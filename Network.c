#ifdef _WIN32
#include "Network.h"

Socket initSocket(Socket sok) {
    //Pour ne pas le réinitialiser s'il est déjà créé
    sok.needInit = 0;
    
    sok.slen = sizeof(sok.si_other);

    //Initialise winsock
    //if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    if (WSAStartup(MAKEWORD(2,2),(&sok.wsa)) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    //printf("Initialised.\n");
     
    //create socket
    if ( (sok.s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
    {
        printf("socket() failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
     
    //setup address structure
    memset((char *) &(sok.si_other), 0, sizeof(sok.si_other));
    sok.si_other.sin_family = AF_INET;
    sok.si_other.sin_port = htons(PORT);
    sok.si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

    return sok;
}

void askServer(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,Uint32 deltaTime, Socket sok) {
    //Envoyer keyboard + ; + delatime
    char paquet[BUFLEN] = "";
    float data[2] = {0};
    if (pKeyboard->Keyz == 1 && pKeyboard->Keys == 0) data[0] = 1;
    else if (pKeyboard->Keyz == 0 && pKeyboard->Keys == 1) data[0] = 2;
    //else if (pKeyboard->echap == 1) data[0] = 2;
    else data[0] = 0;
    data[1] = deltaTime;

    EncodePacket(paquet,data,2);

    //send the message
    printf("Envoyé : %s\n" , paquet);
    if (sendto(sok.s, paquet, strlen(paquet) , 0 , (struct sockaddr *) (&sok.si_other), sok.slen) == SOCKET_ERROR)
    {
        printf("sendto() failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }

    //Ecouter pour recevoir :
    char paquetrecu[BUFLEN] = "";

    if (recvfrom(sok.s, paquetrecu, BUFLEN, 0, (struct sockaddr *) (&sok.si_other), (&sok.slen)) == SOCKET_ERROR)
    {
        printf("recvfrom() failed with error code : %d" , WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Recu : %s\n" , paquetrecu);

    float tInfoPaquet[10] = {0}; //Normalement juste 3 infos
    DecodePacket (tInfoPaquet,paquetrecu,BUFLEN);
    printf("Paquet decode\n");

    pBalle->x = tInfoPaquet[0];
    pBalle->y = tInfoPaquet[1];
    pBalle->dirx = tInfoPaquet[2];
    pBalle->diry = tInfoPaquet[3];
    pRaquette1->x = tInfoPaquet[4];
    pRaquette1->y = tInfoPaquet[5];
    pRaquette2->x = tInfoPaquet[6];
    pRaquette2->y = tInfoPaquet[7];
    printf("finboucle \n");
}

#endif
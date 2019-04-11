#include "PacketHandling.h"


void EncodePacket(char paquet[], float data[], int tailleTableData) {
    //sprintf(paquet, "%d;%d;%d", test1,test2,test3);

    int i=0;
    for (i=0;i<tailleTableData;i++) {
        if (i == 0) sprintf(paquet, "%f", data[i]);
        else sprintf(paquet, "%s;%f", paquet, data[i]);
    }
}


void DecodePacket(float tInfoPaquet[], char paquet[],int packetMaxSize) { 
    //Exemple de packet reçu : 12;25;28;264f
    char currentChar = 'a';
    char tmpBufer[10] = "";
    int tmpBuferPos = 0;
    int infoPos = 0;

    int i = 0;
    for (i=0;i<packetMaxSize;i++) {
        currentChar = paquet[i];

        //Pas un ";" -> c'est une donnée en cours
        if (currentChar != ';' && currentChar != '\0') {
            tmpBufer[tmpBuferPos] = currentChar;
            tmpBuferPos++;
        }
        //C'est un ";" -> donnée terminée
        else {
            //On termine la donnée et on stocke l'entier correspondant
            tmpBufer[tmpBuferPos] = '\0';
            float tmp = atof(tmpBufer);
            tInfoPaquet[infoPos] = tmp;
            infoPos++;

            //Reset du buffer temporaire et on passe à la suite
            tmpBuferPos = 0;
        }

        //Fin du paquet
        if (currentChar == '\0') {
            printf("Fin",tmpBufer);
            break;
        }
    }
}
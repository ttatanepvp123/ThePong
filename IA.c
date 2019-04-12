#include "stdio.h"
#include <SDL2/SDL.h>
#include <time.h> //pour le random
#include "define.h"
#include "Struct.h"

#define TEMPS_DE_BUG 2
#define TEMPS_DE_REACTION 200
#define CHANCE 85//SUR 100

int IArandom(int a, int b){
    SDL_Delay(1);
    return rand()%b+a;
}

int HardEventIA(Raquette *pRaquette,Ball *pball) {
    float centreDeLaBall = (pball->h / 2) + pball->y;
    float centreDaLaRaquette = (pRaquette->h / 2) + pRaquette->y;
    printf("centreDeLaBall %f // centreDaLaRaquette %f\n",centreDeLaBall, centreDaLaRaquette);


    if (centreDaLaRaquette > centreDeLaBall){
        printf("input [%f] [%f] output [1]\n",centreDeLaBall, centreDeLaBall);
        return 1;
    } else if (centreDaLaRaquette < centreDeLaBall){
        printf("input [%f] [%f] output [2]\n",centreDeLaBall, centreDeLaBall);
        return 2;
    } else {
        printf("input [%f] [%f] output [0]\n",centreDeLaBall, centreDeLaBall);
        return 0;
    }
}

int LowEventIA(Raquette *pRaquette,Ball *pball) {
    static int direction = 0;
    static int temps = 0;
    float centreDeLaBall = pball->h / 2 + pball->y;
    float centreDaLaRaquette = pRaquette->h / 2 + pRaquette->y;
    if(temps > 0){
        temps --;
        if(direction == 1){
            return 1;
        } else if(direction == 2){
            return 2;
        }
    } else if(pball->dirx <0){

        int nombreAleatoire = 0;
        nombreAleatoire = IArandom(0,100);
        printf("number [%d] \n",nombreAleatoire);
        if(nombreAleatoire < CHANCE){
            if (centreDaLaRaquette > centreDeLaBall){
                printf("input [%f] [%f] output [1]\n",centreDeLaBall, centreDeLaBall);
                temps = TEMPS_DE_REACTION;
                direction = 1;
                return 1;
            } else if (centreDaLaRaquette < centreDeLaBall){
                printf("input [%f] [%f] output [2]\n",centreDeLaBall, centreDeLaBall);
                temps = TEMPS_DE_REACTION;
                direction = 2;
                return 2;
            } else {
                printf("input [%f] [%f] output [0]\n",centreDeLaBall, centreDeLaBall);
                temps = TEMPS_DE_REACTION;
                direction = 0;
                return 0;
            }
        } else if(nombreAleatoire > CHANCE){
            if (centreDaLaRaquette > centreDeLaBall){
                printf("input [%f] [%f] output [1]\n",centreDeLaBall, centreDeLaBall);
                temps = TEMPS_DE_BUG;
                direction = 2;
                return 2;
            } else if (centreDaLaRaquette < centreDeLaBall){
                printf("input [%f] [%f] output [2]\n",centreDeLaBall, centreDeLaBall);
                temps = TEMPS_DE_BUG;
                direction = 1;
                return 1;
            } else {
                printf("input [%f] [%f] output [0]\n",centreDeLaBall, centreDeLaBall);
                if(nombreAleatoire == 19){
                    temps = TEMPS_DE_BUG;
                    direction = 1;
                    return 1;
                }

                if(nombreAleatoire == 20){
                    temps = TEMPS_DE_BUG;
                    direction = 2;
                    return 2;
                }
            }
        } 

    }
}
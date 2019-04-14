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
    int returner = 0;

    if (centreDaLaRaquette > centreDeLaBall){
        returner = 1;
    } else if (centreDaLaRaquette < centreDeLaBall){
        returner = 2;
    } else {
        returner = 0;
    }
    printf("[ HARD AI ] : [%f,%f] -> %d\n",centreDaLaRaquette ,centreDeLaBall ,returner);
    return returner;
}

int LowEventIA(Raquette *pRaquette,Ball *pball) {
    static int direction = 0;
    static int temps = 0;
    float centreDeLaBall = pball->h / 2 + pball->y;
    float centreDaLaRaquette = pRaquette->h / 2 + pRaquette->y;
    if(temps > 0){
        temps --;
        printf("[ EASY AI ] : last direction %d\n", direction);
        return direction;
    } else if(pball->dirx <0){
        int nombreAleatoire = 0;
        nombreAleatoire = IArandom(0,100);
        if(nombreAleatoire < CHANCE){
            if (centreDaLaRaquette > centreDeLaBall){
                temps = TEMPS_DE_REACTION;
                direction = 1;
            } else if (centreDaLaRaquette < centreDeLaBall){
                temps = TEMPS_DE_REACTION;
                direction = 2;
            } else {
                temps = TEMPS_DE_REACTION;
                direction = 0;
            }
            printf("[ EASY AI ] : [%f,%f,%d] -> %d\n",centreDaLaRaquette ,centreDeLaBall, nombreAleatoire, direction);
            return direction;
        } else {
            if (centreDaLaRaquette >= centreDeLaBall){
                temps = TEMPS_DE_BUG;
                direction = 2;
            } else if (centreDaLaRaquette < centreDeLaBall){
                temps = TEMPS_DE_BUG;
                direction = 1;
            }
            printf("[ EASY AI ] : [%f,%f,%d] -> %d\n",centreDaLaRaquette ,centreDeLaBall, nombreAleatoire, direction);
            return direction;
        } 
    } else {
         printf("[ EASY AI ] : waiting\n");
    }
    
}
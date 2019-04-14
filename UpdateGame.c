#include "UpdateGame.h"
#include "InitGame.h"
#include "IA.h"
#include <stdio.h>
#include "sound.h"

void EventBallMode(Ball *pBalle, int TypeEvent);

void UpdateGame(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,Uint32 deltaTime,int modeRaquette1,int modeRaquette2) {
    UpdatePad1(pKeyboard,pBalle,pRaquette1,deltaTime,modeRaquette1);
    UpdatePad2(pKeyboard,pBalle,pRaquette2,deltaTime,modeRaquette2);
    UpdateBall(pBalle,pRaquette1,pRaquette2,pKeyboard,deltaTime);
}

void UpdatePad1(Keyboard *pKeyboard,Ball *pBalle,Raquette *pRaquette1,Uint32 deltaTime,int mode) {
    int tmp = 0;
    if (mode == 1){//MODE BOT HARD
        tmp = HardEventIA(pRaquette1,pBalle);
        if (tmp == 1 && pRaquette1->y>=0) {
            pRaquette1->y -= pRaquette1->speed*deltaTime/1000;
        } else if (tmp == 2 && pRaquette1->y+pRaquette1->h<=1) {
            pRaquette1->y += pRaquette1->speed*deltaTime/1000;
        }
    } else if (mode == 2){//MODE BOT LOW
        tmp = LowEventIA(pRaquette1,pBalle);
        if (tmp == 1 && pRaquette1->y>=0) {
            pRaquette1->y -= pRaquette1->speed*deltaTime/1000;
        } else if (tmp == 2 && pRaquette1->y+pRaquette1->h<=1) {
            pRaquette1->y += pRaquette1->speed*deltaTime/1000;
        }
    } else {//MODE PLAYE
        if (pKeyboard->Keyz && pRaquette1->y>=0) {
            pRaquette1->y -= pRaquette1->speed*deltaTime/1000;
            printf("[ PLAYER 1 ] : up\n");
        } else if (pKeyboard->Keys && pRaquette1->y+pRaquette1->h<=1) {
            pRaquette1->y += pRaquette1->speed*deltaTime/1000;
            printf("[ PLAYER 1 ] : down\n");
        } else {
            printf("[ PLAYER 1 ] : waiting\n");
        }
    }

    //Debug Option
    if(pKeyboard->Keyi){
        pRaquette1->speed ++;
    }

    if(pKeyboard->Keyk){
        pRaquette1->speed --;
    }

    if(pKeyboard->Keyl){
        pRaquette1->speed = PAD_SPEED;
    }
}

void UpdatePad2(Keyboard *pKeyboard,Ball *pBalle,Raquette *praquette2,Uint32 deltaTime,int mode) {
    int tmp = 0;
    if (mode == 1){//MODE BOT HARD
        tmp = HardEventIA(praquette2,pBalle);
        if (tmp == 1 && praquette2->y>=0) {
            praquette2->y -= praquette2->speed*deltaTime/1000;
        } else if (tmp == 2 && praquette2->y+praquette2->h<=1) {
            praquette2->y += praquette2->speed*deltaTime/1000;
        }
    } else if (mode == 2){//MODE BOT LOW
        tmp = LowEventIA(praquette2,pBalle);
        if (tmp == 1 && praquette2->y>=0) {
            praquette2->y -= praquette2->speed*deltaTime/1000;
        } else if (tmp == 2 && praquette2->y+praquette2->h<=1) {
            praquette2->y += praquette2->speed*deltaTime/1000;
        }
    } else {//MODE PLAYE
        if (pKeyboard->ArrowUp && praquette2->y>=0) {
            printf("[ PLAYER 2 ] : up\n");
            praquette2->y -= praquette2->speed*deltaTime/1000;
        } else if (pKeyboard->ArrowDown && praquette2->y+praquette2->h<=1) {
            praquette2->y += praquette2->speed*deltaTime/1000;
            printf("[ PLAYER 2 ] : down\n");
        } else {
            printf("[ PLAYER 2 ] : waiting\n");
        }
        

        //Debug Option
        if(pKeyboard->Keyi){
            praquette2->speed ++;
        }

        if(pKeyboard->Keyk){
            praquette2->speed --;
        }

        if(pKeyboard->Keyl){
            praquette2->speed = PAD_SPEED;
        }
    }
}

void UpdateBall(Ball *pBalle,Raquette *pRaquette1,Raquette *pRaquette2,Keyboard *pKeyboard,Uint32 deltaTime) {
    static int soundNumberPlaylist = 5000;

    if(soundNumberPlaylist == 5000){
        soundNumberPlaylist = sound_addFX(PATH_FX_BALLTOPAD);
    }
    pBalle->x += (pBalle->speed*deltaTime/1000)*pBalle->dirx;
    pBalle->y += (pBalle->speed*deltaTime/1000)*pBalle->diry;

    //depasse le mur gauche
    if (pBalle->x<0) {
        pRaquette2->Score ++;
        InitGame(pRaquette1,pRaquette2,pBalle,1);
    }

    //depasse le mur droit
    if (pBalle->x+pBalle->w>1) {
        pRaquette1->Score ++;
        InitGame(pRaquette1,pRaquette2,pBalle,1);
    }

    //rebond mur haut
    if (pBalle->y<0) {
        pBalle->y = 0;
        pBalle->diry *= -1;
    }

    //rebond mur bas
    if (pBalle->y+pBalle->h>1) {
        pBalle->y = 1-pBalle->h;
        pBalle->diry *= -1;
    }

    //Collision raquette gauche
    if (RectCollision(pRaquette1,pBalle)) {
        pBalle->x = pRaquette1->x+pRaquette1->w+0.0001; //On replace la balle un petit peu avant la raquette

        //Calcul rebond sur Y
        pBalle->diry = ((pBalle->y + (pBalle->h/2)) - pRaquette1->y) / pRaquette1->h;
        pBalle->diry -= 0.5;
        if (pBalle->diry>0.5) pBalle->diry=0.5;
        if (pBalle->diry<-0.5) pBalle->diry=-0.5;
        if (pBalle->diry<0) pBalle->dirx = 1+pBalle->diry;
        else pBalle->dirx = 1-pBalle->diry;

        sound_FXPlay(soundNumberPlaylist,5);

        EventBallMode(pBalle, EVENT_COLLISION_RAQUETTE);
    }

    //Collision raquette droite
    if (RectCollision(pRaquette2,pBalle)) {
        pBalle->x = pRaquette2->x-pBalle->w-0.0001; //On replace la balle un petit peu avant la raquette

        //Calcul rebond sur Y
        pBalle->diry = ((pBalle->y + (pBalle->h/2)) - pRaquette2->y) / pRaquette2->h;
        pBalle->diry -= 0.5;
        if (pBalle->diry>0.5) pBalle->diry=0.5;
        if (pBalle->diry<-0.5) pBalle->diry=-0.5;
        if (pBalle->diry<0) pBalle->dirx = 1+pBalle->diry;
        else pBalle->dirx = 1-pBalle->diry;

        sound_FXPlay(soundNumberPlaylist,6);

        pBalle->dirx *= -1;
        
        EventBallMode(pBalle, EVENT_COLLISION_RAQUETTE);
    }

    //Debug option
    if(pKeyboard->Keyt){
        pBalle->speed ++;
    }

    if(pKeyboard->Keyg){
        pBalle->speed --;
    }

    if(pKeyboard->Keyh){
        pBalle->speed = BALL_SPEED;
    }
    printf("[ BALL ] : [%f,%f]\n", pBalle->dirx, pBalle->diry);
    printf("[ BALL ] : [%f,%f]\n", pBalle->x, pBalle->y);
}

int RectCollision(Raquette *pRaquette,Ball *pBalle) {
    if (pRaquette->x+pRaquette->w < pBalle->x) {
        return 0;
    }
    if (pRaquette->x > pBalle->x+pBalle->w) {
        return 0;
    }
    if (pRaquette->y+pRaquette->h < pBalle->y) {
        return 0;
    }
    if (pRaquette->y > pBalle->y+pBalle->h) {
        return 0;
    }
    else return 1;
}

void EventBallMode(Ball *pBalle, int TypeEvent){
    if(TypeEvent == EVENT_COLLISION_RAQUETTE){


        if(pBalle->mode == 1){
            pBalle->mode + 20;
        }

    }
}
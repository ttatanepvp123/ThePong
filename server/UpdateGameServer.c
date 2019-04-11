#include "UpdateGameServer.h"

int UpdateGameServer(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,int updateTimer){
    UpdatePad1(pKeyboard,pBalle,pRaquette1,updateTimer);
    UpdatePad2(pKeyboard,pBalle,pRaquette2,updateTimer);
    UpdateBall(pBalle,pRaquette1,pRaquette2,pKeyboard,updateTimer/2);
}

void UpdatePad1(Keyboard *pKeyboard,Ball *pBalle,Raquette *pRaquette1,int deltaTime) {
    if (pKeyboard->Keyz && pRaquette1->y>=0) {
    pRaquette1->y -= pRaquette1->speed*deltaTime/1000;
    }
    if (pKeyboard->Keys && pRaquette1->y+pRaquette1->h<=SCREEN_HEIGHT) {
        pRaquette1->y += pRaquette1->speed*deltaTime/1000;
    }
}

void UpdatePad2(Keyboard *pKeyboard,Ball *pBalle,Raquette *praquette2,int deltaTime) {
    if (pKeyboard->ArrowUp && praquette2->y>=0) {
        praquette2->y -= praquette2->speed*deltaTime/1000;
    }
    if (pKeyboard->ArrowDown && praquette2->y+praquette2->h<=SCREEN_HEIGHT) {
        praquette2->y += praquette2->speed*deltaTime/1000;
    }
}

void UpdateBall(Ball *pBalle,Raquette *pRaquette1,Raquette *pRaquette2,Keyboard *pKeyboard,int deltaTime) {
    pBalle->x += (pBalle->speed*deltaTime/1000)*pBalle->dirx;
    pBalle->y += (pBalle->speed*deltaTime/1000)*pBalle->diry;

    //d�passe le mur gauche
    if (pBalle->x<=0) {
        pRaquette2->Score ++;
        InitGame(pRaquette1,pRaquette2,pBalle,1);
    }

    //d�passe le mur droit
    if (pBalle->x+pBalle->w>SCREEN_WIDTH) {
        pRaquette1->Score ++;
        InitGame(pRaquette1,pRaquette2,pBalle,1);
    }

    //rebond mur haut
    if (pBalle->y<0) {
        pBalle->y = 0;
        pBalle->diry *= -1;
    }

    //rebond mur bas
    if (pBalle->y+pBalle->h>SCREEN_HEIGHT) {
        pBalle->y = SCREEN_HEIGHT-pBalle->h;
        pBalle->diry *= -1;
    }

    //Collision raquette gauche
    if (RectCollision(pRaquette1,pBalle)) {
        pBalle->x = pRaquette1->x+pRaquette1->w;

        //Calcul rebond sur Y
        pBalle->diry = ((pBalle->y + (pBalle->h/2)) - pRaquette1->y) / pRaquette1->h;
        pBalle->diry -= 0.5;
        if (pBalle->diry>0.5) pBalle->diry=0.5;
        if (pBalle->diry<-0.5) pBalle->diry=-0.5;
        if (pBalle->diry<0) pBalle->dirx = 1+pBalle->diry;
        else pBalle->dirx = 1-pBalle->diry;
    }

    //Collision raquette droite
    if (RectCollision(pRaquette2,pBalle)) {
        pBalle->x = pRaquette2->x-pBalle->w;

        //Calcul rebond sur Y
        pBalle->diry = ((pBalle->y + (pBalle->h/2)) - pRaquette2->y) / pRaquette2->h;
        pBalle->diry -= 0.5;
        if (pBalle->diry>0.5) pBalle->diry=0.5;
        if (pBalle->diry<-0.5) pBalle->diry=-0.5;
        if (pBalle->diry<0) pBalle->dirx = 1+pBalle->diry;
        else pBalle->dirx = 1-pBalle->diry;

        pBalle->dirx *= -1;
    }

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
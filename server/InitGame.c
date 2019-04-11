#include "InitGame.h"

void InitGame(Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,int InGame) {
    InitGamePad1(pRaquette1, InGame);
    InitGamePad2(pRaquette2, InGame);
    InitGameBall(pBalle, InGame);
}

void InitGamePad1(Raquette *pRaquette1, int InGame){
    pRaquette1->x = PAD_DISTANCE_TO_EDGE;
    pRaquette1->y = SCREEN_HEIGHT/2 - PAD_HEIGHT/2;
    pRaquette1->w = PAD_WIDTH;
    pRaquette1->h = PAD_HEIGHT;
    if (InGame == 0) pRaquette1->speed = PAD_SPEED;
    if (InGame == 0) pRaquette1->Score = 0;
}

void InitGamePad2(Raquette *pRaquette2,int InGame){
    pRaquette2->x = SCREEN_WIDTH - PAD_DISTANCE_TO_EDGE - PAD_WIDTH;
    pRaquette2->y = SCREEN_HEIGHT/2 - PAD_HEIGHT/2;
    pRaquette2->w = PAD_WIDTH;
    pRaquette2->h = PAD_HEIGHT;
    if (InGame == 0) pRaquette2->speed = PAD_SPEED;
    if (InGame == 0) pRaquette2->Score = 0;
}

void InitGameBall(Ball *pBalle,int InGame){
    pBalle->x = SCREEN_WIDTH/2 - BALL_SIZE/2;
    pBalle->y = SCREEN_HEIGHT/2 - BALL_SIZE/2;
    pBalle->w = BALL_SIZE;
    pBalle->h = BALL_SIZE;
    pBalle->dirx = -1;
    pBalle->diry = 0;
    if (InGame == 0) pBalle->speed = BALL_SPEED;
}
#ifndef UPDATEGAMESERVER_H_INCLUDED
#define UPDATEGAMESERVER_H_INCLUDED

#include "InitGame.h"
#include "define.h"
#include "Struct.h"
int UpdateGameServer(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,int updateTimer);
void UpdatePad1(Keyboard *pKeyboard,Ball *pBalle,Raquette *pRaquette1,int deltaTime);
void UpdatePad2(Keyboard *pKeyboard,Ball *pBalle,Raquette *praquette2,int deltaTime);
void UpdateBall(Ball *pBalle,Raquette *pRaquette1,Raquette *pRaquette2,Keyboard *pKeyboard,int deltaTime);
int RectCollision(Raquette *pRaquette,Ball *pBalle);

#endif
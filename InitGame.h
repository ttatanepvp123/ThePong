#ifndef INITGAME_H_INCLUDED
#define INITGAME_H_INCLUDED

#include "Struct.h"
#include "define.h"

void InitGame(Raquette *pRaquette1, Raquette *pRaquette2, Ball *pBalle, int InGame);
void InitGamePad1(Raquette *pRaquette1, int InGame);
void InitGamePad2(Raquette *pRaquette2, int InGame);
void InitGameBall(Ball *pBalle,int InGame);

#endif // INITGAME_H_INCLUDED

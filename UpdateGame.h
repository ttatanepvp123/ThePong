#ifndef UPDATEGAME_H_INCLUDED
#define UPDATEGAME_H_INCLUDED

#include <SDL2/SDL.h>
#include "Struct.h"
#include "define.h"

void UpdateGame(Keyboard *pKeyboard,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,Uint32 deltaTime,int modeRaquette1,int modeRaquette2);
void UpdatePad1(Keyboard *pKeyboard,Ball *pBalle,Raquette *pRaquette1,Uint32 deltaTime,int mode);
void UpdatePad2(Keyboard *pKeyboard,Ball *pBalle,Raquette *pRaquette2,Uint32 deltaTime,int mode);
void UpdateBall(Ball *pBalle,Raquette *pRaquette1,Raquette *pRaquette2,Keyboard *pKeyboard,Uint32 deltaTime);

int RectCollision(Raquette *pRaquette,Ball *pBalle);

#endif // UPDATEGAME_H_INCLUDED

#ifndef MENUBOUTON_H_INCLUDED
#define MENUBOUTON_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "struct.h"
#include "define.h"


int MenuUpdate(Mouse *pMouse, MenuTexture *pMenuTexture, int menuState);
int MenuUpdateMain(Mouse *pMouse, MenuTexture *pMenuTexture);
int MenuUpdatePlay(Mouse *pMouse, MenuTexture *pMenuTexture);
int MenuUpdateOptions(Mouse *pMouse, MenuTexture *pMenuTexture);

int CheckMouseOnButton(Mouse *pMouse, SDL_Rect *pButton);

/*
//int MenuBouton(SDL_Rect *BtnTitle, SDL_Rect *BtnBotLow, SDL_Rect *BtnPlay, SDL_Rect *BtnQuit, SDL_Rect *BtnDiscord,SDL_Rect *BtnBotHard, Mouse *pMouse);
int MenuBouton(MenuTexture *pMenuTexture, Mouse *pMouse);
*/

#endif

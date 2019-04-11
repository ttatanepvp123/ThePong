#ifndef RENDERGAME_H_INCLUDED
#define RENDERGAME_H_INCLUDED

#include <SDL2/SDL.h>
#include "Struct.h"
#include "define.h"

void RenderGame(SDL_Renderer *pRenderer,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,GameTexture *pGameTextures, Screen *pScr);

#endif // RENDERGAME_H_INCLUDED

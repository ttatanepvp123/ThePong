#ifndef LOADTEXTURES_H_INCLUDED
#define LOADTEXTURES_H_INCLUDED

#include <SDL2/SDL.h>
#include "Struct.h"
#include "define.h"

void LoadTextures(SDL_Renderer *Renderer,MenuTexture *pMenuTextures,GameTexture *pGameTextures);
void UnLoadTextures(MenuTexture *pMenuTextures,GameTexture *pGameTextures);

void LoadMenuTextures(SDL_Renderer *Renderer,MenuTexture *pMenuTextures);
void UnLoadMenuTextures(MenuTexture *pMenuTextures);

void LoadGameTextures(SDL_Renderer *Renderer,GameTexture *pGameTextures);
void UnLoadGameTextures(GameTexture *pGameTextures);

#endif // LOADTEXTURES_H_INCLUDED

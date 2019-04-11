#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED

#include <SDL2/SDL.h>
#include "Struct.h"

int EventsGame(Keyboard *pKeyboard, Mouse *pMouse, Screen *pScr);
int EventsMenu(Mouse *pMouse, Screen *pScr);

#endif // EVENTS_H_INCLUDED

#include "Events.h"

int EventsGame(Keyboard *pKeyboard, Mouse *pMouse, Screen *pScr) {

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        //vérifications QUIT -> Croix fenetre ou Echap
        if (event.type == SDL_QUIT) return 0; //on renvoie faux pour quitter le jeu et revenir au menu
        if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
            return 0; //On permet de quitter via la touche �chap aussi
        }

        //CLAVIER - TOUCHE ENFONCEE
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pKeyboard->ArrowUp=1;
                    break;
                case SDLK_DOWN:
                    pKeyboard->ArrowDown=1;
                    break;
                case SDLK_z:
                    pKeyboard->Keyz=1;
                    break;
                case SDLK_s:
                    pKeyboard->Keys=1;
                    break;
                case SDLK_t:
                    pKeyboard->Keyt=1;
                    break;
                case SDLK_g:
                    pKeyboard->Keyg=1;
                    break;
                case SDLK_h:
                    pKeyboard->Keyh=1;
                    break;
                case SDLK_i:
                    pKeyboard->Keyi=1;
                    break;
                case SDLK_k:
                    pKeyboard->Keyk=1;
                    break;
                case SDLK_l:
                    pKeyboard->Keyl=1;
                    break;
            }
        }
        //CLAVIER - TOUCHE RELACHEE
        else if (event.type == SDL_KEYUP) {
            switch(event.key.keysym.sym) {
                case SDLK_UP:
                    pKeyboard->ArrowUp=0;
                    break;
                case SDLK_DOWN:
                    pKeyboard->ArrowDown=0;
                    break;
                case SDLK_z:
                    pKeyboard->Keyz=0;
                    break;
                case SDLK_s:
                    pKeyboard->Keys=0;
                    break;
                case SDLK_t:
                    pKeyboard->Keyt=0;
                    break;
                case SDLK_g:
                    pKeyboard->Keyg=0;
                    break;
                case SDLK_h:
                    pKeyboard->Keyh=0;
                    break;
                case SDLK_i:
                    pKeyboard->Keyi=0;
                    break;
                case SDLK_k:
                    pKeyboard->Keyk=0;
                    break;
                case SDLK_l:
                    pKeyboard->Keyl=0;
                    break;
            }
        }

        //SOURIS - MOUVEMENT
        if (event.type == SDL_MOUSEMOTION) {
            pMouse->MouseX=event.motion.x;
            pMouse->MouseY=event.motion.y;
        }
        //SOURIS - CLIC ENFONCE
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pMouse->MouseLeftClic=1;
                    break;
            }
        }
        //SOURIS - CLIC RELACHE
        else if (event.type == SDL_MOUSEBUTTONUP) {
            switch(event.button.button) {
                case SDL_BUTTON_LEFT:
                    pMouse->MouseLeftClic=0;
                    break;
            }
        }

        //Ecran redimensionné
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            pScr->w = event.window.data1;
            pScr->h = event.window.data2;
            pScr->needResize = 1;
        }
    }

    return 1; //on renvoie vrai pour continuer � jouer
}


int EventsMenu(Mouse *pMouse, Screen *pScr) {

    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) return 1;

        //Clic d�tect�
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                pMouse->MouseLeftClic = 1;
            }
        }
        //Clic relach�
        else if (event.type == SDL_MOUSEBUTTONUP) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                pMouse->MouseLeftClic = 0;
            }
        }

        //D�placement souris
        if (event.type == SDL_MOUSEMOTION) {
            pMouse->MouseX = event.motion.x;
            pMouse->MouseY = event.motion.y;
        }

        //Ecran redimensionné
        if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
            pScr->w = event.window.data1;
            pScr->h = event.window.data2;
            pScr->needResize = 1;
        }
    }

    return 0;
}

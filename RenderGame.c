#include "RenderGame.h"

void RenderGame(SDL_Renderer *pRenderer,Raquette *pRaquette1,Raquette *pRaquette2,Ball *pBalle,GameTexture *pGameTextures, Screen *pScr) {
    //Nettoyage de l'�cran
    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
    SDL_RenderClear(pRenderer);


    //Cr�ation d'un SDL_Rect pour la position d'affichage des �l�ments
    SDL_Rect dst;

    //Dessin du fond (en gris clair)
    SDL_SetRenderDrawColor(pRenderer,180,180,180,255);
    dst.w = 10;
    dst.h = 10;
    dst.x = pScr->w/2 - dst.w/2;

    int i;
    for (i=5;i<pScr->h;i+=20) {
        dst.y = i;
        SDL_RenderFillRect(pRenderer,&dst);
    }


    //Dessin des scores (en gris fonc�)
    SDL_SetRenderDrawColor(pRenderer,100,100,100,255);
    SDL_Rect src;
    src.y = 0;
    src.w = 60;
    src.h = 60;
    int marge = 20;
    dst.w = 100;
    dst.h = 100;
    dst.y = marge;
    //Dessin du score J1 (raquette de gauche)
    int scoreToDraw = pRaquette1->Score;
    if (scoreToDraw <= 9) {
        dst.x = pScr->w/2 - marge - dst.w;
        src.x = 0;
        while (scoreToDraw>0) {
            src.x += src.w;
            scoreToDraw --;
        }
        SDL_RenderCopy(pRenderer,pGameTextures->pTextureNum,&src,&dst);
    }
    else {
        //1er chiffre
        dst.x = pScr->w/2 - marge*2 - dst.w*2;
        src.x = 0;
        while (scoreToDraw>9) {
            src.x += src.w;
            scoreToDraw -= 10;
        }
        SDL_RenderCopy(pRenderer,pGameTextures->pTextureNum,&src,&dst);

        //2nd chiffre
        dst.x += dst.w;
        src.x = 0;
        while (scoreToDraw>0) {
            src.x += src.w;
            scoreToDraw --;
        }
        SDL_RenderCopy(pRenderer,pGameTextures->pTextureNum,&src,&dst);
    }
    //Dessin du score J2 (raquette de droite)
    scoreToDraw = pRaquette2->Score;
    if (scoreToDraw <= 9) {
        dst.x = pScr->w/2 + marge;
        src.x = 0;
        while (scoreToDraw>0) {
            src.x += src.w;
            scoreToDraw --;
        }
        SDL_RenderCopy(pRenderer,pGameTextures->pTextureNum,&src,&dst);
    }
    else {
        //1er chiffre
        dst.x = pScr->w/2 + marge;
        src.x = 0;
        while (scoreToDraw>9) {
            src.x += src.w;
            scoreToDraw -= 10;
        }
        SDL_RenderCopy(pRenderer,pGameTextures->pTextureNum,&src,&dst);

        //2nd chiffre
        dst.x += dst.w;
        src.x = 0;
        while (scoreToDraw>0) {
            src.x += src.w;
            scoreToDraw --;
        }
        SDL_RenderCopy(pRenderer,pGameTextures->pTextureNum,&src,&dst);
    }


    //Dessin des Raquettes et de la balle (en blanc pour les raquettes, selon texture pour la balle)
    SDL_SetRenderDrawColor(pRenderer,255,255,255,255);

    //Dessin Raquette 1
    dst.x = pRaquette1->x*pScr->w;
    dst.y = pRaquette1->y*pScr->h;
    dst.w = pRaquette1->w*pScr->w;
    dst.h = pRaquette1->h*pScr->h;
    SDL_RenderFillRect(pRenderer,&dst);
    //Dessin Raquette 2
    dst.x = pRaquette2->x*pScr->w;
    dst.y = pRaquette2->y*pScr->h;
    dst.w = pRaquette2->w*pScr->w;
    dst.h = pRaquette2->h*pScr->h;
    SDL_RenderFillRect(pRenderer,&dst);
    //Dessin Balle
    dst.x = pBalle->x*pScr->w;
    dst.y = pBalle->y*pScr->h;
    dst.w = pBalle->w*pScr->w;
    dst.h = pBalle->h*pScr->h;
    SDL_RenderCopy(pRenderer, pGameTextures->pTextureBall, &pGameTextures->InTextureBallPos, &dst);


    //Affichage a l'ecran
    SDL_RenderPresent(pRenderer);
}

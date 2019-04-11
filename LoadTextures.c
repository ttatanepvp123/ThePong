#include "LoadTextures.h"

void LoadTextures(SDL_Renderer *Renderer,MenuTexture *pMenuTextures,GameTexture *pGameTextures) {
    LoadMenuTextures(Renderer,pMenuTextures);
    LoadGameTextures(Renderer,pGameTextures);
}



void UnLoadTextures(MenuTexture *pMenuTextures,GameTexture *pGameTextures) {
    UnLoadMenuTextures(pMenuTextures);
    UnLoadGameTextures(pGameTextures);
}



void LoadMenuTextures(SDL_Renderer *pRenderer,MenuTexture *pMenuTextures) {

    //Chargement des images du menu dans une SDL_Surface temporaire
    SDL_Surface *pSurfTemp = NULL;
    pSurfTemp = SDL_LoadBMP("img/asset_200x100.bmp");

    //Convertissage de la surface en texture
    pMenuTextures->pTextureAssets = SDL_CreateTextureFromSurface(pRenderer,pSurfTemp);

    //On a plus besoin de la surface
    SDL_FreeSurface(pSurfTemp);


    //Definition des positions des elements dans la texture
    //MAINMENU - TITLE
    pMenuTextures->InTextureTitle.x = 600;
    pMenuTextures->InTextureTitle.y = 0;
    pMenuTextures->InTextureTitle.w = 200;
    pMenuTextures->InTextureTitle.h = 100;
    //MAINMENU - TITLE HOVER
    pMenuTextures->InTextureTitleHover.x = 600;
    pMenuTextures->InTextureTitleHover.y = 100;
    pMenuTextures->InTextureTitleHover.w = 200;
    pMenuTextures->InTextureTitleHover.h = 100;


    //MAINMENU - PLAY
    pMenuTextures->InTextureBtnPlay.x = 0;
    pMenuTextures->InTextureBtnPlay.y = 0;
    pMenuTextures->InTextureBtnPlay.w = 200;
    pMenuTextures->InTextureBtnPlay.h = 100;
    //MAINMENU - PLAY HOVER
    pMenuTextures->InTextureBtnPlayHover.x = 0;
    pMenuTextures->InTextureBtnPlayHover.y = 100;
    pMenuTextures->InTextureBtnPlayHover.w = 200;
    pMenuTextures->InTextureBtnPlayHover.h = 100;


    //MAINMENU - OPTIONS
    pMenuTextures->InTextureBtnOptions.x = 400;
    pMenuTextures->InTextureBtnOptions.y = 0;
    pMenuTextures->InTextureBtnOptions.w = 200;
    pMenuTextures->InTextureBtnOptions.h = 100;
    //MAINMENU - OPTIONS HOVER
    pMenuTextures->InTextureBtnOptionsHover.x = 400;
    pMenuTextures->InTextureBtnOptionsHover.y = 100;
    pMenuTextures->InTextureBtnOptionsHover.w = 200;
    pMenuTextures->InTextureBtnOptionsHover.h = 100;


    //MAINMENU - QUIT
    pMenuTextures->InTextureBtnQuit.x = 200;
    pMenuTextures->InTextureBtnQuit.y = 0;
    pMenuTextures->InTextureBtnQuit.w = 200;
    pMenuTextures->InTextureBtnQuit.h = 100;
    //MAINMENU - QUIT HOVER
    pMenuTextures->InTextureBtnQuitHover.x = 200;
    pMenuTextures->InTextureBtnQuitHover.y = 100;
    pMenuTextures->InTextureBtnQuitHover.w = 200;
    pMenuTextures->InTextureBtnQuitHover.h = 100;


    // ----------------------------
    // ---- MENU PLAY -------------
    // ----------------------------

    //MENUPLAY - 2P
    pMenuTextures->InTextureBtn2P.x = 0;
    pMenuTextures->InTextureBtn2P.y = 400;
    pMenuTextures->InTextureBtn2P.w = 200;
    pMenuTextures->InTextureBtn2P.h = 100;
    //MENUPLAY - 2P
    pMenuTextures->InTextureBtn2PHover.x = 0;
    pMenuTextures->InTextureBtn2PHover.y = 500;
    pMenuTextures->InTextureBtn2PHover.w = 200;
    pMenuTextures->InTextureBtn2PHover.h = 100;


    //MENUPLAY - HardBot
    pMenuTextures->InTextureBtnHardB.x = 200;
    pMenuTextures->InTextureBtnHardB.y = 200;
    pMenuTextures->InTextureBtnHardB.w = 200;
    pMenuTextures->InTextureBtnHardB.h = 100;
    //MENUPLAY - HardBot
    pMenuTextures->InTextureBtnHardBHover.x = 200;
    pMenuTextures->InTextureBtnHardBHover.y = 300;
    pMenuTextures->InTextureBtnHardBHover.w = 200;
    pMenuTextures->InTextureBtnHardBHover.h = 100;


    //MENUPLAY - EasyBot
    pMenuTextures->InTextureBtnEasyB.x = 400;
    pMenuTextures->InTextureBtnEasyB.y = 200;
    pMenuTextures->InTextureBtnEasyB.w = 200;
    pMenuTextures->InTextureBtnEasyB.h = 100;
    //MENUPLAY - EasyBot
    pMenuTextures->InTextureBtnEasyBHover.x = 400;
    pMenuTextures->InTextureBtnEasyBHover.y = 300;
    pMenuTextures->InTextureBtnEasyBHover.w = 200;
    pMenuTextures->InTextureBtnEasyBHover.h = 100;


    //MENUPLAY - Online
    pMenuTextures->InTextureBtnOnline.x = 0;
    pMenuTextures->InTextureBtnOnline.y = 200;
    pMenuTextures->InTextureBtnOnline.w = 200;
    pMenuTextures->InTextureBtnOnline.h = 100;
    //MENUPLAY - Online
    pMenuTextures->InTextureBtnOnlineHover.x = 0;
    pMenuTextures->InTextureBtnOnlineHover.y = 300;
    pMenuTextures->InTextureBtnOnlineHover.w = 200;
    pMenuTextures->InTextureBtnOnlineHover.h = 100;


    //MENUPLAY - Back
    pMenuTextures->InTextureBtnBack.x = 200;
    pMenuTextures->InTextureBtnBack.y = 400;
    pMenuTextures->InTextureBtnBack.w = 200;
    pMenuTextures->InTextureBtnBack.h = 100;
    //MENUPLAY - Back
    pMenuTextures->InTextureBtnBackHover.x = 200;
    pMenuTextures->InTextureBtnBackHover.y = 500;
    pMenuTextures->InTextureBtnBackHover.w = 200;
    pMenuTextures->InTextureBtnBackHover.h = 100;
}



void LoadGameTextures(SDL_Renderer *Renderer,GameTexture *pGameTextures) {
    //Chargement des images du jeu dans une SDL_Surface temporaire
    SDL_Surface *pSurfTemp = NULL;
    pSurfTemp = SDL_LoadBMP("img/asset.bmp");

    //Convertissage de la surface en texture
    pGameTextures->pTextureBall = SDL_CreateTextureFromSurface(Renderer,pSurfTemp);


    //Chargement des caract�res alphanum�riques
    pSurfTemp = SDL_LoadBMP("img/num_60x60.bmp");
    
    //Convertissage de la surface en texture
    pGameTextures->pTextureNum = SDL_CreateTextureFromSurface(Renderer,pSurfTemp);


    //On a plus besoin de la surface
    SDL_FreeSurface(pSurfTemp);

    //Chargement de la position de la balle dans les textures
    pGameTextures->InTextureBallPos.x = 459;
    pGameTextures->InTextureBallPos.y = 333;
    pGameTextures->InTextureBallPos.h = 100;
    pGameTextures->InTextureBallPos.w = 100;
}



void UnLoadMenuTextures(MenuTexture *pMenuTextures){
    if (pMenuTextures->pTextureAssets!=NULL) SDL_DestroyTexture(pMenuTextures->pTextureAssets);
}



void UnLoadGameTextures(GameTexture *pGameTextures) {
    if (pGameTextures->pTextureNum!=NULL) SDL_DestroyTexture(pGameTextures->pTextureNum);
    if (pGameTextures->pTextureBall!=NULL) SDL_DestroyTexture(pGameTextures->pTextureBall);
}

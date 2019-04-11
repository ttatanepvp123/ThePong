#include "MenuRender.h"

void MenuRender(SDL_Renderer *pRenderer,MenuTexture *pMenuTextures,int menuState){

    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);
    SDL_RenderClear(pRenderer);
    SDL_SetRenderDrawColor(pRenderer,0,0,0,255);

    switch (menuState) {
        case MENU_STATE_MAIN:
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcTitle,&pMenuTextures->DstTitle);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnPlay,&pMenuTextures->DstBtnPlay);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnOptions,&pMenuTextures->DstBtnOptions);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnQuit,&pMenuTextures->DstBtnQuit);
            break;
        case MENU_STATE_PLAY:
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtn2P,&pMenuTextures->DstBtn2P);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnHardB,&pMenuTextures->DstBtnHardB);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnEasyB,&pMenuTextures->DstBtnEasyB);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnOnline,&pMenuTextures->DstBtnOnline);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnBack,&pMenuTextures->DstBtnBack);
            break;
        case MENU_STATE_OPTIONS:
            /*SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcTitle,&pMenuTextures->DstTitle);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnPlay,&pMenuTextures->DstBtnPlay);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnOptions,&pMenuTextures->DstBtnOptions);
            SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->SrcBtnQuit,&pMenuTextures->DstBtnQuit);*/
            break;
        default:

            break;
    }

    /*
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTextureTitleBtn,&pMenuTextures->OnScreenTitleBtn);
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTexturePlayBtn,&pMenuTextures->OnScreenPlayBtn);
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTextureQuitBtn,&pMenuTextures->OnScreenQuitBtn);
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTextureDiscordBtn,&pMenuTextures->OnScreenDiscordBtn);
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTexturePlayeBotLowBtn,&pMenuTextures->OnScreenPlayeBotLowBtn);
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTexturePlayBotHardBtn,&pMenuTextures->OnScreenPlayBotHardBtn);
    SDL_RenderCopy(pRenderer,pMenuTextures->pTextureAssets,&pMenuTextures->InTextureOnlineBtn,&pMenuTextures->OnScreenOnlineBtn);
    */


    SDL_RenderPresent(pRenderer);
}

#include "MenuInit.h"

void MenuInit(MenuTexture *pMenuTextures, Screen *pScr) {
    MenuInitMainMenu(pMenuTextures, pScr);
    MenuInitPlayMenu(pMenuTextures, pScr);
    MenuInitOptionsMenu(pMenuTextures, pScr);
}


void MenuInitMainMenu(MenuTexture *pMenuTextures, Screen *pScr) {
    
    //Les boutons sont centrés sur la moitié basse de l'écran. Même taille pour tous.
    int btnWidth = pScr->w*0.25;
    int btnHeight = pScr->h*0.15;
    int btnX = (pScr->w / 2) - (btnWidth / 2);
    int padding = pScr->h/2; //On démarre les Y à la moitié basse de l'écran, s'ajoute à Y.
    int constPadding = 5; //Espacement entre les boutons


    //TITRE INDEPENDANT DES DONNEES D'UN BOUTON CLASSIQUE !
    //MAINMENU - TITLE SRC
    pMenuTextures->SrcTitle = pMenuTextures->InTextureTitle;
    //MAINMENU - TITLE DST
    pMenuTextures->DstTitle.w = pScr->w*0.75;
    pMenuTextures->DstTitle.h = pScr->h*0.25;
    pMenuTextures->DstTitle.x = (pScr->w / 2) - (pMenuTextures->DstTitle.w / 2);
    pMenuTextures->DstTitle.y = pScr->h*0.05;
    //TITRE INDEPENDANT DES DONNEES D'UN BOUTON CLASSIQUE !


    //MAINMENU - PLAY SRC
    pMenuTextures->SrcBtnPlay = pMenuTextures->InTextureBtnPlay;
    //MAINMENU - PLAY DST
    pMenuTextures->DstBtnPlay.w = btnWidth;
    pMenuTextures->DstBtnPlay.h = btnHeight;
    pMenuTextures->DstBtnPlay.x = btnX;
    pMenuTextures->DstBtnPlay.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;


    //MAINMENU - OPTIONS SRC
    pMenuTextures->SrcBtnOptions = pMenuTextures->InTextureBtnOptions;
    //MAINMENU - OPTIONS DST
    pMenuTextures->DstBtnOptions.w = btnWidth;
    pMenuTextures->DstBtnOptions.h = btnHeight;
    pMenuTextures->DstBtnOptions.x = btnX;
    pMenuTextures->DstBtnOptions.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;


    //MAINMENU - QUIT SRC
    pMenuTextures->SrcBtnQuit = pMenuTextures->InTextureBtnQuit;
    //MAINMENU - QUIT DST
    pMenuTextures->DstBtnQuit.w = btnWidth;
    pMenuTextures->DstBtnQuit.h = btnHeight;
    pMenuTextures->DstBtnQuit.x = btnX;
    pMenuTextures->DstBtnQuit.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;
}


void MenuInitPlayMenu(MenuTexture *pMenuTextures, Screen *pScr) {
    
    //Les boutons sont centrés sur la moitié basse de l'écran. Même taille pour tous.
    int btnWidth = pScr->w*0.25;
    int btnHeight = pScr->h*0.15;
    int btnX = (pScr->w / 2) - (btnWidth / 2);
    int padding = pScr->h*0.1;
    int constPadding = 5; //Espacement entre les boutons


    //MENUPLAY - 2P
    pMenuTextures->SrcBtn2P = pMenuTextures->InTextureBtn2P;
    //MENUPLAY - 2P
    pMenuTextures->DstBtn2P.w = btnWidth;
    pMenuTextures->DstBtn2P.h = btnHeight;
    pMenuTextures->DstBtn2P.x = btnX;
    pMenuTextures->DstBtn2P.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;


    //MENUPLAY - HardBot
    pMenuTextures->SrcBtnHardB = pMenuTextures->InTextureBtnHardB;
    //MENUPLAY - HardBot
    pMenuTextures->DstBtnHardB.w = btnWidth;
    pMenuTextures->DstBtnHardB.h = btnHeight;
    pMenuTextures->DstBtnHardB.x = btnX;
    pMenuTextures->DstBtnHardB.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;


    //MENUPLAY - EasyBot
    pMenuTextures->SrcBtnEasyB = pMenuTextures->InTextureBtnEasyB;
    //MENUPLAY - EasyBot
    pMenuTextures->DstBtnEasyB.w = btnWidth;
    pMenuTextures->DstBtnEasyB.h = btnHeight;
    pMenuTextures->DstBtnEasyB.x = btnX;
    pMenuTextures->DstBtnEasyB.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;


    //MENUPLAY - Online
    pMenuTextures->SrcBtnOnline = pMenuTextures->InTextureBtnOnline;
    //MENUPLAY - Online
    pMenuTextures->DstBtnOnline.w = btnWidth;
    pMenuTextures->DstBtnOnline.h = btnHeight;
    pMenuTextures->DstBtnOnline.x = btnX;
    pMenuTextures->DstBtnOnline.y = padding;

    //Maj du padding suivant
    padding += btnHeight + constPadding;


    //MENUPLAY - Back
    pMenuTextures->SrcBtnBack = pMenuTextures->InTextureBtnBack;
    //MENUPLAY - Back
    pMenuTextures->DstBtnBack.w = btnWidth;
    pMenuTextures->DstBtnBack.h = btnHeight;
    pMenuTextures->DstBtnBack.x = btnX;
    pMenuTextures->DstBtnBack.y = padding;
}


void MenuInitOptionsMenu(MenuTexture *pMenuTextures, Screen *pScr) {

}


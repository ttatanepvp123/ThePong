#include "MenuUpdate.h"


int MenuUpdate(Mouse *pMouse, MenuTexture *pMenuTexture, int menuState) {
	switch (menuState) {
		case MENU_STATE_MAIN:
			return MenuUpdateMain(pMouse,pMenuTexture);
			break;
		case MENU_STATE_PLAY:
			return MenuUpdatePlay(pMouse,pMenuTexture);
			break;
		case MENU_STATE_OPTIONS:
			return MenuUpdateOptions(pMouse,pMenuTexture);
			break;
		default:
			return -1;
			break;
	}
}



int MenuUpdateMain(Mouse *pMouse, MenuTexture *pMenuTexture) {
	//On prend par défaut le bouton normal (non survolé)
	pMenuTexture->SrcBtnPlay = pMenuTexture->InTextureBtnPlay;
	pMenuTexture->SrcBtnOptions = pMenuTexture->InTextureBtnOptions;
	pMenuTexture->SrcBtnQuit = pMenuTexture->InTextureBtnQuit;

	//bouton PLAY ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnPlay))){
    	pMenuTexture->SrcBtnPlay = pMenuTexture->InTextureBtnPlayHover;
		if(pMouse->MouseLeftClic) return MENU_MAIN_PLAY;
	}

	//bouton OPTIONS ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnOptions))){
    	pMenuTexture->SrcBtnOptions = pMenuTexture->InTextureBtnOptionsHover;
		if(pMouse->MouseLeftClic) return MENU_MAIN_OPTIONS;
	}

	//bouton QUIT ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnQuit))){
    	pMenuTexture->SrcBtnQuit = pMenuTexture->InTextureBtnQuitHover;
		if(pMouse->MouseLeftClic) return MENU_MAIN_QUIT;
	}

	return -1;
}



int MenuUpdatePlay(Mouse *pMouse, MenuTexture *pMenuTexture) {
	//On prend par défaut le bouton normal (non survolé)
	pMenuTexture->SrcBtn2P = pMenuTexture->InTextureBtn2P;
	pMenuTexture->SrcBtnHardB = pMenuTexture->InTextureBtnHardB;
	pMenuTexture->SrcBtnEasyB = pMenuTexture->InTextureBtnEasyB;
	pMenuTexture->SrcBtnOnline = pMenuTexture->InTextureBtnOnline;
	pMenuTexture->SrcBtnBack = pMenuTexture->InTextureBtnBack;

	//bouton 2PLAYERS LOCAL ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtn2P))){
    	pMenuTexture->SrcBtn2P = pMenuTexture->InTextureBtn2PHover;
		if(pMouse->MouseLeftClic) return MENU_PLAY_TWOPLAYERS;
	}

	//bouton HARD BOT ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnHardB))){
    	pMenuTexture->SrcBtnHardB = pMenuTexture->InTextureBtnHardBHover;
		if(pMouse->MouseLeftClic) return MENU_PLAY_HARDBOT;
	}

	//bouton EASY BOT ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnEasyB))){
    	pMenuTexture->SrcBtnEasyB = pMenuTexture->InTextureBtnEasyBHover;
		if(pMouse->MouseLeftClic) return MENU_PLAY_EASYBOT;
	}

	//bouton ONLINE ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnOnline))){
    	pMenuTexture->SrcBtnOnline = pMenuTexture->InTextureBtnOnlineHover;
		if(pMouse->MouseLeftClic) return MENU_PLAY_ONLINE;
	}

	//bouton BACK ?
	if(CheckMouseOnButton(pMouse, &(pMenuTexture->DstBtnBack))){
    	pMenuTexture->SrcBtnBack = pMenuTexture->InTextureBtnBackHover;
		if(pMouse->MouseLeftClic) return MENU_PLAY_BACK;
	}

	return -1;
}



int MenuUpdateOptions(Mouse *pMouse, MenuTexture *pMenuTexture) {
	
}



int CheckMouseOnButton(Mouse *pMouse, SDL_Rect *pButton) {
    //Souris est à gauche du bouton
	if (pMouse->MouseX < pButton->x) {
        return 0;
    }
    //Souris est à droite du bouton
    if (pMouse->MouseX > pButton->x+pButton->w) {
        return 0;
    }
    //Souris est en dessous du bouton
    if (pMouse->MouseY < pButton->y) {
        return 0;
    }
    //Souris est au dessous du bouton
    if (pMouse->MouseY > pButton->y+pButton->h) {
        return 0;
    }
    else return 1;
}



/*
//int MenuBouton(SDL_Rect *BtnTitle, SDL_Rect *BtnBotLow, SDL_Rect *BtnPlay, SDL_Rect *BtnQuit, SDL_Rect *BtnDiscord,SDL_Rect *BtnBotHard, Mouse *pMouse){
int MenuBouton(MenuTexture *pMenuTexture, Mouse *pMouse){
	//int tempsPrecedent = 0, tempsActuel = 0;
	Uint32 tempsActuel = 0;
	static int numberClicTitle = 0;
	static Uint32 numberClicTitleLimiteTime = 0;
	static int stopedAlert = 0;
	if(numberClicTitle == 3 && stopedAlert < 3){
		stopedAlert = numberClicTitle;
		return MENU_CLIC_BTN_SPEED_AMPLIFIED;
	}
	while(1){
		tempsActuel = SDL_GetTicks();

    	if(EventsMenu(pMouse) == 1){
    		return MENU_CLIC_BTN_QUIT;
    	}

	    if(pMouse->MouseLeftClic == 1){
	        if(pMouse->MouseX >= pMenuTexture->OnScreenPlayBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenPlayBtn.x + pMenuTexture->OnScreenPlayBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenPlayBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenPlayBtn.y + pMenuTexture->OnScreenPlayBtn.h)){

	            return MENU_CLIC_BTN_PLAY;
	        }

	        if(pMouse->MouseX >= pMenuTexture->OnScreenQuitBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenQuitBtn.x + pMenuTexture->OnScreenQuitBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenQuitBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenQuitBtn.y + pMenuTexture->OnScreenQuitBtn.h)){

	            return MENU_CLIC_BTN_QUIT;
			}
			
			if(pMouse->MouseX >= pMenuTexture->OnScreenPlayBotHardBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenPlayBotHardBtn.x + pMenuTexture->OnScreenPlayBotHardBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenPlayBotHardBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenPlayBotHardBtn.y + pMenuTexture->OnScreenPlayBotHardBtn.h)){

	            return MENU_CLIC_BTN_HARDBOT;
			}
			
			if(pMouse->MouseX >= pMenuTexture->OnScreenOnlineBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenOnlineBtn.x + pMenuTexture->OnScreenOnlineBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenOnlineBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenOnlineBtn.y + pMenuTexture->OnScreenOnlineBtn.h)){

	            return MENU_CLIC_BTN_ONLINE;
			}

			if(pMouse->MouseX >= pMenuTexture->OnScreenPlayeBotLowBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenPlayeBotLowBtn.x + pMenuTexture->OnScreenPlayeBotLowBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenPlayeBotLowBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenPlayeBotLowBtn.y + pMenuTexture->OnScreenPlayeBotLowBtn.h)){

	            return MENU_CLIC_BTN_LOWBOT;
			}

			if(pMouse->MouseX >= pMenuTexture->OnScreenDiscordBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenDiscordBtn.x + pMenuTexture->OnScreenDiscordBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenDiscordBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenDiscordBtn.y + pMenuTexture->OnScreenDiscordBtn.h)){

                pMouse->MouseLeftClic = 0 ;

                //return MENU_CLIC_BTN_DISCORD;
			}

			if(pMouse->MouseX >= pMenuTexture->OnScreenTitleBtn.x &&
                pMouse->MouseX <= (pMenuTexture->OnScreenTitleBtn.x + pMenuTexture->OnScreenTitleBtn.w) &&
                pMouse->MouseY >= pMenuTexture->OnScreenTitleBtn.y &&
                pMouse->MouseY <= (pMenuTexture->OnScreenTitleBtn.y + pMenuTexture->OnScreenTitleBtn.h)){
				if(tempsActuel - 400 > numberClicTitleLimiteTime){
					numberClicTitle ++;
					printf("Title Clic Number : %d\n", numberClicTitle);
					numberClicTitleLimiteTime = SDL_GetTicks();
					return 0;
				}
	        }

		}
        SDL_Delay(1);
    }
}
*/
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED


#include "include/SDL2/SDL.h"
#include<winsock2.h>


typedef struct Screen {
    int w;
    int h;
    int needResize;
} Screen;

typedef struct Mouse {
    int MouseX;
    int MouseY;
    int MouseLeftClic;
    int MouseRightClic;
    int MouseWheelUp;
    int MouseWheelDown;
} Mouse;

typedef struct Keyboard {
    int ArrowUp;
    int ArrowDown;
    int Keyz;
    int Keys;
    //debug
    int Keyt;
    int Keyg;
    int Keyh;
    int Keyi;
    int Keyk;
    int Keyl;
} Keyboard;

typedef struct Raquette {
    float x;
    float y;
    float w;
    float h;
    float speed;
    int Score;
    int mode;
} Raquette;

typedef struct Ball {
    float x;
    float y;
    float w;
    float h;
    float dirx;
    float diry;
    float speed;
    int mode;
} Ball;

typedef struct GameTexture {
    //SDL_Texture *pTextureAlpha;
    SDL_Texture *pTextureNum;
    SDL_Texture *pTextureBall;
    SDL_Rect InTextureBallPos;
} GameTexture;

typedef struct MenuTexture {
    SDL_Texture *pTextureAssets;

    /*
    //4 Rectangels, présentés sous la forme :
    POSITION NON HOVER DANS TEXTURE
    POSITION HOVER DANS TEXTURE
    POSITION SOURCE (sera une des deux positions ci dessus)
    POSITION DESTINATION (pour l'affichage à l'écran)
    */

    //MAINMENU - TITLE
    SDL_Rect InTextureTitle;
    SDL_Rect InTextureTitleHover;
    SDL_Rect SrcTitle;
    SDL_Rect DstTitle;

    //MAINMENU - PLAY
    SDL_Rect InTextureBtnPlay;
    SDL_Rect InTextureBtnPlayHover;
    SDL_Rect SrcBtnPlay;
    SDL_Rect DstBtnPlay;

    //MAINMENU - OPTIONS
    SDL_Rect InTextureBtnOptions;
    SDL_Rect InTextureBtnOptionsHover;
    SDL_Rect SrcBtnOptions;
    SDL_Rect DstBtnOptions;

    //MAINMENU - QUIT
    SDL_Rect InTextureBtnQuit;
    SDL_Rect InTextureBtnQuitHover;
    SDL_Rect SrcBtnQuit;
    SDL_Rect DstBtnQuit;

    //MENUPLAY - 2P
    SDL_Rect InTextureBtn2P;
    SDL_Rect InTextureBtn2PHover;
    SDL_Rect SrcBtn2P;
    SDL_Rect DstBtn2P;

    //MENUPLAY - HardBot
    SDL_Rect InTextureBtnHardB;
    SDL_Rect InTextureBtnHardBHover;
    SDL_Rect SrcBtnHardB;
    SDL_Rect DstBtnHardB;

    //MENUPLAY - EasyBot
    SDL_Rect InTextureBtnEasyB;
    SDL_Rect InTextureBtnEasyBHover;
    SDL_Rect SrcBtnEasyB;
    SDL_Rect DstBtnEasyB;

    //MENUPLAY - Online
    SDL_Rect InTextureBtnOnline;
    SDL_Rect InTextureBtnOnlineHover;
    SDL_Rect SrcBtnOnline;
    SDL_Rect DstBtnOnline;

    //MENUPLAY - Back
    SDL_Rect InTextureBtnBack;
    SDL_Rect InTextureBtnBackHover;
    SDL_Rect SrcBtnBack;
    SDL_Rect DstBtnBack;

} MenuTexture;

enum MenuClics {
    MENU_CLIC_BTN_PLAY=1,
    MENU_CLIC_BTN_QUIT=2,
    MENU_CLIC_BTN_DISCORD=3,
    MENU_CLIC_BTN_HARDBOT=4,
    MENU_CLIC_BTN_LOWBOT=5,
    MENU_CLIC_BTN_SPEED_AMPLIFIED=6,
    MENU_CLIC_BTN_ONLINE=7
};

enum enumMenuState {
    MENU_STATE_MAIN,
    MENU_STATE_PLAY,
    MENU_STATE_OPTIONS
};

enum enumMenuClics {
    MENU_MAIN_PLAY,
    MENU_MAIN_OPTIONS,
    MENU_MAIN_QUIT,
    
    MENU_PLAY_TWOPLAYERS,
    MENU_PLAY_HARDBOT,
    MENU_PLAY_EASYBOT,
    MENU_PLAY_ONLINE,
    MENU_PLAY_BACK,
    
    MENU_OPTIONS_SOUND,
    MENU_OPTIONS_RESOLUTION,
    MENU_OPTIONS_BACK
};

typedef struct Socket {
    int needInit;
    struct sockaddr_in si_other;
    int s;
    int slen;
    WSADATA wsa;
} Socket;

#endif // STRUCT_H_INCLUDED

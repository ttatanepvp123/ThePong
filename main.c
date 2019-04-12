#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/*INITIALISATIONS*/
#include "define.h"
#include "Struct.h"
#include "LoadTextures.h"
#include "sound.h"
#include "SystemLog.h"

/*GENERIQUE PROGRAMME*/
#include "Timers.h"
#include "Events.h"

/*SPECIFIQUE MENU*/
#include "MenuInit.h"
#include "MenuUpdate.h"
#include "MenuRender.h"

/*SPECIFIQUE JEU*/
#include "InitGame.h"
#include "UpdateGame.h"
#include "RenderGame.h"

/*SPECIFIQUE MULTIJOUEUR*/
#include "Network.h"




int main(int argc, char** argv) {

    printf("THE PONG GAME\n"
    "By Sophia and Ttatanepvp123\n");

    //Taille de l'écran. Par défaut : 800x600 (comme ça on est sûr que ça passe partout)
    Screen Scr = {800,600,1};
    Screen *pScr = &Scr;

    srand(time(NULL));

    //Init generale SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
        WriteLogPong("ERREUR : Initialisation SDL", 1, 1);
        exit(EXIT_FAILURE);
    } else {
        WriteLogPong("Log : Initialisation SDL", 0, 0);
    }

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        fprintf(stdout,"Échec de l'initialisation de Mix_OpenAudio (%s)\n",SDL_GetError());
        return -1;
    };

    //Init Fenetre
    SDL_Window *pWindows = NULL;
    //pWindows = SDL_CreateWindow("Pong Game SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pScr->w, pScr->h, SDL_WINDOW_RESIZABLE);
    pWindows = SDL_CreateWindow("Pong Game SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, pScr->w, pScr->h,0);

    if(pWindows == NULL){
        WriteLogPong("ERREUR : Creation de la Fenetre", 1, 1);
        exit(EXIT_FAILURE);
    } else {
        WriteLogPong("Log : Creation de la Fenetre", 0, 0);
    }

    //Init Renderer
    SDL_Renderer *pRenderer = NULL;
    pRenderer = SDL_CreateRenderer(pWindows, -1 , 0);

    if(pRenderer == NULL){
        WriteLogPong("ERREUR : Creation du Renderer", 1, 1);
        exit(EXIT_FAILURE);
    } else {
        WriteLogPong("Log : Creation du Renderer", 0, 0);
    }

    //Chargement Textures
    MenuTexture MenuTextures;
    MenuTexture *pMenuTextures=NULL;
    pMenuTextures = &MenuTextures;

    GameTexture GameTextures;
    GameTexture *pGameTextures = NULL;
    pGameTextures = &GameTextures;

    LoadTextures(pRenderer,pMenuTextures,pGameTextures);

    //chargemengt system audio
    

    //Variables generales
    //Clavier & Souris
    Mouse mouse = {0};
    Mouse *pMouse = &mouse;
    Keyboard keyboard = {0};
    Keyboard *pKeyboard = &keyboard;

    #ifdef _WIN32
    //Socket pour multijoueur (initialisation "needInit" à true)
    Socket sokt;
    sokt.needInit = 1;
    #endif

    //Variables pour fonctionnement boucles
    int loopMenu = 1;
    int loopGame = 0;
    int menuState = MENU_STATE_MAIN;

    Uint32 deltaTime = 0;

    //Variable De Mode
    int modeMulti = 0;
    int modeRaquette1 = 0;// Utilise dans UpdateGame.c
    int modeRaquette2 = 0;// Utilise dans UpdateGame.c
    int modeAffichage = 0;
    int modeBall = 0;
    /* 0 = Mode original sois : en mode fenetre 600x800
     *      CODE :
     * 1 = Mode plein écran en redimensionne la qualité d'écran
     *      CODE :
     * 2 = je sais pas
     *      CODE : 
     * Pour le fichier MenuBouton.c ligne ~40~
     */

    sound_MusicPlay(sound_addMusic(PATH_MUSIC_1));

    int secretModeSound = sound_addFX(PATH_SECRET_MODE);


    //Boucle generale
    while (loopMenu) {
        modeMulti = 0;
        
        //Récupération des évènements menu - Exit quand ça renvoie 1
        if(EventsMenu(pMouse,pScr)){
    		loopMenu = 0;
    	}

        //Chargement des positions des items menu lorsque la taille change (et au 1er passage pour initialiser)
        if (pScr->needResize) {
            printf("menu resized !! \n");
            MenuInit(pMenuTextures,pScr);
            pScr->needResize = 0;
        }

        //Update 
        switch (MenuUpdate(pMouse,pMenuTextures,menuState)) {
            case MENU_MAIN_PLAY:
                menuState = MENU_STATE_PLAY;
                modeRaquette1 = 0;
                WriteLogPong("Log : MENU_MAIN_PLAY", 0, 0);
                printf("play !! \n");
                break;
            case MENU_MAIN_OPTIONS:
                menuState = MENU_STATE_OPTIONS;
                WriteLogPong("Log : MENU_MAIN_OPTIONS", 0, 0);
                printf("options !! \n");
                break;
            case MENU_MAIN_QUIT:
                loopMenu = 0;
                WriteLogPong("Log : MENU_MAIN_QUIT", 0, 0);
                printf("quit !! \n");
                break;


            case MENU_PLAY_TWOPLAYERS:
                loopGame = 1;
                modeRaquette1 = 0;
                WriteLogPong("Log : MENU_PLAY_TWOPLAYERS", 0, 0);
                printf("play 2P local !! \n");
                break;
            case MENU_PLAY_HARDBOT:
                loopGame = 1;
                modeRaquette1 = 1;
                WriteLogPong("Log : MENU_PLAY_HARDBOT", 0, 0);
                printf("play hardbot !! \n");
                break;
            case MENU_PLAY_EASYBOT:
                loopGame = 1;
                modeRaquette1 = 2;
                WriteLogPong("Log : MENU_PLAY_EASYBOT", 0, 0);
                printf("play easybot !! \n");
                break;
            case MENU_PLAY_ONLINE:
                loopGame = 1;
                modeRaquette1 = 0;
                modeMulti = 1;
                WriteLogPong("Log : MENU_PLAY_ONLINE", 0, 0);
                printf("play online !! \n");
                break;
            case MENU_PLAY_BACK:
                menuState = MENU_STATE_MAIN;
                WriteLogPong("Log : MENU_PLAY_BACK", 0, 0);
                printf("back to main menu !! \n");
                break;
                

            default:
                break;
        }
        pMouse->MouseLeftClic = 0;

        MenuRender(pRenderer,pMenuTextures,menuState);

        //FinBoucle si le jeu ne démarre pas.

        

        //Demarrage du jeu
        if (loopGame) {
            // SDL_SetWindowsFullscreen(pWindows);



            Raquette Raquette1 = {0};
            Raquette *pRaquette1 = NULL;
            pRaquette1 = &Raquette1;

            Raquette Raquette2 = {0};
            Raquette *pRaquette2 = NULL;
            pRaquette2 = &Raquette2;

            Ball Balle = {0};
            Ball *pBalle = NULL;
            pBalle = &Balle;

            if(modeBall == 1){
                pBalle->mode = 1;
            }

            pKeyboard->ArrowDown = 0;
            pKeyboard->ArrowUp = 0;
            pKeyboard->Keyz = 0;
            pKeyboard->Keys = 0; 
            #ifdef HJBHBDFFDJ
            //Initialisation du socket (si ce n'est pas déjà fait)
            if (modeMulti && sokt.needInit) sokt = initSocket(sokt);
            #endif

            WriteLogPong("Log : Fonction Executed : InitGame", 0, 0);
            InitGame(pRaquette1,pRaquette2,pBalle,0);

            Uint32 updateTimer = UPDATE_TIMER;
            Uint32 renderTimer = RENDER_TIMER;
            Uint32 pauseTimer = 0;

            deltaTime = Timer(deltaTime);
            while (loopGame) {
                pauseTimer = 0;
                loopGame = EventsGame(pKeyboard,pMouse,pScr);


                deltaTime = Timer(deltaTime);
                updateTimer += deltaTime - pauseTimer;
                renderTimer += deltaTime - pauseTimer;


                //Update fait en local si solo, par serveur en multi
                if (modeMulti) {
                    #ifdef _WIN32
                    askServer(pKeyboard,pRaquette1,pRaquette2,pBalle,deltaTime,sokt);
                    #endif
                }
                else {
                    if (updateTimer>=UPDATE_TIMER) {
                        UpdateGame(pKeyboard,pRaquette1,pRaquette2,pBalle,updateTimer,modeRaquette1,modeRaquette2);
                        updateTimer=0;
                    }
                }
                

                if (renderTimer>=RENDER_TIMER) {
                    RenderGame(pRenderer,pRaquette1,pRaquette2,pBalle,pGameTextures,pScr); //Affiche ?l'?ran le jeu
                    renderTimer=0;
                }
                SDL_Delay(1);
            }
            WriteLogPong("Log : Fisnish Game", 0, 0);
        }
        SDL_Delay(1);
    }


    //Destruction Textures
    WriteLogPong("Log : Fonction Executed : UnLoadTextures", 0, 0);
    UnLoadTextures(pMenuTextures,pGameTextures);
    

    //Fin programme
    WriteLogPong("Log : Fonction Executed : SDL fonction destroy", 0, 0);
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindows);
    SDL_Quit();

    WriteLogPong("Log : FINISH EXECUTION \n\n", 0, 0);
    return EXIT_SUCCESS;
}
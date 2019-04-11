#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

/*#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768*/
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define UPDATE_TIMER 4
#define RENDER_TIMER 16
#define SPACE_ENTER_BUTTON_Y 5 //espace entre les bouton du menu en y

#define PAD_WIDTH 0.03
#define PAD_HEIGHT 0.3
#define PAD_DISTANCE_TO_EDGE 0.02
#define BALL_SIZE 0.03

#define PAD_SPEED 0.5
#define BALL_SPEED 1

/*
#define PAD_WIDTH 20
#define PAD_HEIGHT 100
#define PAD_DISTANCE_TO_EDGE 10
#define BALL_SIZE 10

#define PAD_SPEED 500
#define BALL_SPEED 1150
*/

//chemin des son 
#define PATH_FX_BALLTOPAD "Audio/ballToPad.wav"
#define PATH_MUSIC_1 "Audio/MusicToGoodGame.wav"
#define PATH_SECRET_MODE "Audio/SecretModeSound.wav"
//EVENT Balle
#define EVENT_COLLISION_RAQUETTE 1

#endif
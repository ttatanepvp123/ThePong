
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int sound_MusicPlay(int music);
int sound_addFX(char *chaine);
void sound_FXPlay(int sound, int channel);




Mix_Chunk **soundFX = NULL;
Mix_Music **soundMusic = NULL;
int nbrSoundFX=0;
int nbrSoundMusic=0;



int sound_addMusic(char *chaine){
    nbrSoundMusic++;

    if( soundMusic == NULL ){
        soundMusic = malloc(nbrSoundMusic * sizeof(Mix_Chunk));
        if(soundMusic == NULL){
            printf("sound_addMusic(). Erreur avec malloc(nbrSoundMusic... %s\n", Mix_GetError());
            return -1;
        }
        printf("soundMusic nbrSoundMusic %d\n", nbrSoundMusic);
    }else{

        soundMusic = realloc(soundMusic, nbrSoundMusic * sizeof(Mix_Chunk));
        if(soundMusic == NULL){
            printf("sound_addMusic(). Erreur avec realloc(nbrSoundMusic... %s\n", Mix_GetError());
            return -1;
        }
        printf("soundMusic nbrSoundMusic %d\n", nbrSoundMusic);
    }

    soundMusic[nbrSoundMusic-1] = Mix_LoadMUS(chaine);
	if (soundMusic[nbrSoundMusic-1] == NULL){
        printf("sound_addMusic(). Erreur Mix_LoadMUS(chaine) %s\n ", Mix_GetError());
        printf("%s\n ", chaine);
        return -1;
    }

    return nbrSoundMusic-1;

}

int sound_MusicPlay(int music){
    if ( Mix_PlayMusic( soundMusic[music], -1) == -1 ){
        fprintf(stdout,"sound_MusicPlay() Erreur Mix_PlayMusic( soundMusic[music]... %s \n", Mix_GetError());
        return -1;
    }
}


int sound_addFX(char *chaine){
    nbrSoundFX++;

    if( soundFX == NULL ){
        soundFX = malloc(nbrSoundFX * sizeof(Mix_Chunk));
        if(soundFX == NULL){
            printf("sound_addFX(). Erreur avec malloc(nbrSoundFX... ");
            return -1;
        }
        printf("soundFX nbrSoundFX %d\n", nbrSoundFX);
    }else{

        soundFX = realloc(soundFX, nbrSoundFX * sizeof(Mix_Chunk));
        if(soundFX == NULL){
            printf("sound_addFX(). Erreur avec realloc(nbrSoundFX... ");
            return -1;
        }
        printf("soundMusic nbrSoundFX %d\n", nbrSoundFX);
    }

    soundFX[nbrSoundFX-1] = Mix_LoadWAV(chaine);
	if (soundFX[nbrSoundFX-1] == NULL){
        printf("sound_addFX(). Erreur Mix_LoadWAV(chaine) %s\n ", Mix_GetError());
        printf("%s\n ", chaine);
        return -1;
    }

    return nbrSoundFX-1;

}


void sound_FXPlay(int sound, int channel){
    Mix_PlayChannel(channel, soundFX[sound], 0);
}

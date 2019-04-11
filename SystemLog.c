#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#ifdef _WIN32
#include <windows.h>
#endif

/*  ENGLISH
 *WriteLogPong user manual ()
 *Commit:
 *         error sentence (do not put an error code)
 *Error:
 *         0 = no error
 *         1 = error of the SDL
 *       +1 = other error
 *msgbox:
 *         0 = no msgbox
 *         1 = put a msgbox
 *
 * ==============================
 * FR
 * ==============================
 * 
 *mode d'emploi de WriteLogPong()
 *Commit : 
 *        phrase d'erreur (ne pas mettre un code d'erreur)
 *Error :
 *        0 = pas d'erreur
 *        1 = erreur de la SDL
 *      +1 = autre erreur 
 *msgbox :
 *        0 = pas de msgbox
 *        1 = mettre une msgbox
 */

int WriteLogPong(char *Commit, int Error, int messageBox){

    FILE* fichier = NULL;

    fichier = fopen("Log.txt", "a+");

    if (fichier != NULL)
    {
        if(Error == 0){
            fprintf(fichier,"%s \n",Commit);
        } else if(Error == 1){
            fprintf(fichier,"%s > %s : Error SDL \n", Commit, SDL_GetError());
        } else if(Error > 1){
            fprintf(fichier, "%s > %d", Commit, Error);
        } else {
            printf("Error Log Fonction\n");
        }

        if (messageBox == 1) {

            #ifdef _WIN32

            MessageBox(0, Commit, "ErrorBox",0);

            #endif
        }
    } else {
        printf("le fichier : Log.txt n'a pas pue etre ouvert \n");
        fclose(fichier);
        return 1;
    }

    fclose(fichier);
    return 0;
}
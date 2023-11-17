#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
//#include <option.h>
//#include <algo.h>
//#include <fichier.h>
//#include <game.h>

int main(int argc, char* argv[]){
    int nb_joueurs;
    int des[2] = {0};
    printf("Nombre de joueurs entre 2 et 4: ");
    scanf(" %d", &nb_joueurs);
    if (nb_joueurs <= 1 || nb_joueurs > 4) { perror("Nb jouers impossible\n"); return 1; }

    while (1) {
        MLV_Keyboard_button touche;
        // ajouter des dés alétoires à l'avenir

        printf("Deux valeurs de deux dés: ");
        scanf(" %d %d", des, (des + 1));

        /*
        MLV_wait_keyboard( &touche, NULL, NULL );
        if (touche == MLV_KEYBOARD_q){  // q - quit, sortir
            MLV_free_window(); // la férmeture
        }

        MLV_actualise_window();
        */
    }


    return 0;
}

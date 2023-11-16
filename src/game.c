#include "game.h"

void initTab(char* plateau, int* position, int* attente, int nbJoueur){
    for(int i = 0; i < 100; i++){
        switch (i){  // Pas alétoirement (discord)

            case 10 || 19 || 30 || 70 || 79 || 80:
                plateau[i] = 'O';
                break;
            
            case 53:
                plateau[i] = 'T';
                break;
            
            case 8:
                plateau[i] = 'R';
                break;
            
            case 74:
                plateau[i] = 'P';
                break;
            
            case 31:
                plateau[i] = 'H';
                break;
            
            case 65:
                plateau[i] = 'L';
                break;
            
            case 94:
                plateau[i] = 'X';
                break;
            
            default:
                plateau[i] = ' ';
                break;
        }
    }

    for(int i = 0; i < 4; ++i){
        if(i < nbJoueur){
            position[i] = 0;
            attente[i] = 0;
        }

        else{ // s'il y a moins de 4 joueur je met -1 pour dire que le joueur n'existe pas
            position[i] = -1;
            attente[i] = -1;
        }
    }

}

int avancerJoueur(char* plateau, int* position, int* attente, int joueurCourant, int nbJoueur, int des[2], int premierTour){
    int somme = 0;
    int newPos = 0;

    if(premierTour){
        if((des[1] == 3 && des[2] == 6) || (des[1] == 6 && des[2] == 3)) { position[joueurCourant] = 40; }

        if((des[1] == 4 && des[2] == 5) || (des[1] == 5 && des[2] == 4)) { position[joueurCourant] = 89; }
    }

    else{
        if(attente[joueurCourant] > 0){
            attente[joueurCourant]--;
            return -1;
        }
        
        if(attente[joueurCourant] == -1)
            return -1;
    
        somme = des[0] + des[1];

        if(position[joueurCourant] + somme == 99) { return joueurCourant; }  // gagné par joueurCourant, YOUPI
        
        if(position[joueurCourant] + somme > 99)  { newPos = 99 - (somme - (99 - position[joueurCourant])); }
        
        else { newPos = position[joueurCourant] + somme; }
    }

    switch (plateau[newPos]){
    
        case 'O':
            // pas de break pour vérifier sur quel case je tombe
            do {
                newPos += somme;
            } while(plateau[newPos] != 'O'); 

        case 'T':
            for(int i = 0; i < nbJoueur; i++){
                // si joueur_i qui est dans la case "T", lui, il peut jouer pourtant joueur courant ne peut plus jouer
                if(i != joueurCourant && plateau[position[i]] == 'T' && attente[i] == -1) { attente[i] = 0; }
            }
            attente[joueurCourant] = -1;
            break;
    
        case 'R':
            newPos = 16;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos); 
            break;
    
        case 'P':
            // prison_fonction(int *attente...)
            attente[joueurCourant] = -1;
            for(int i = 0; i < nbJoueur; i++){
                // si joueur_i qui est dans la case "P", alors jouer courant et jouer_i peuvent jouer
                if(i != joueurCourant && plateau[position[i]] == 'P' && attente[i] == -1){
                    attente[i] = 0;
                    attente[joueurCourant] = 0;
                }
            }
            break;
    
        case 'H':  // Hôtel, joueurCourant perd deux tours
            attente[joueurCourant] = 2;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
    
        case 'L':
            newPos = 52;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
    
        case 'X':  // on recommance du début
            newPos = 0;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
    
        default:  // si case normal
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
        }
    
    return -1;
}



void collision(char* plateau, int* position, int* attente, int nbJoueur, int joueurCourant, int nouvellePosition){
    for(int i = 0; i < nbJoueur; ++i){
        if(i != joueurCourant && position[i] == position[joueurCourant] &&
            plateau[position[i]] != 'P' && plateau[position[i]] != 'T'){
            if(plateau[position[i]] == 'H')
                attente[i] = 0;
            
            position[i] = position[joueurCourant];
            position[joueurCourant] = nouvellePosition;

            switch (plateau[position[i]]){
                case 'T':
                    for(int i = 0; i < nbJoueur; i++){
                        if(i != joueurCourant &&
                        plateau[position[i]] == 'T' && attente[i] == -1){
                            attente[i] = 0;
                        }
                    }
                    attente[joueurCourant] = -1;
                    break;
        
                case 'P':
                    attente[joueurCourant] = -1;
                    for(int i = 0; i < nbJoueur; i++){
                        if(i != joueurCourant && plateau[position[i]] == 'P' && attente[i] == -1){
                            attente[i] = 0;
                            attente[joueurCourant] = 0;
                        }
                    }
                    break;
        
                case 'H':
                    attente[joueurCourant] = 2;
                    break;
        
                default:
                    break;
            }
        }
    }

}

/* Dans cette fonction on modifie x et y du tableau avec coordonnées en spirale */
void conversion(int pos, int* x, int* y){

    if (pos <= 50){  // La moitié pour ne pas chercher longtemps
        if (pos < 28){
            if (0 <= pos && pos <= 9) { *x = 0; *y = pos; }
            else if (10 <= pos && pos <= 18) { *x = pos - 9;  *y = 9;}
            else { *x = 9; *y = 27 - pos; }  // (19 <= pos && pos <= 27)
        }
        else {
            if (28 <= pos && pos <= 35) { *x = 36 - pos; *y = 0; }
            else if (36 <= pos && pos <= 43) { *x = 1;        *y = pos - 35; }
            else { *x = pos - 42; *y = 8; }  // (44 <= pos && pos <= 50)
        }
    }
    else {
        if (pos <= 83){
            if (pos <= 63){
                if (51 <= pos && pos <= 57) { *x = 8; *y = 58 - pos; }
                else { *x = 65 - pos; *y = 1; }  // (58 <= pos && pos <= 63)
            }
            
            else if (pos <= 74){
                if (64 <= pos && pos <= 69) { *x = 2; *y = pos - 62; }
                else { *x = pos - 67; *y = 7; }  // (70 <= pos && pos <= 74)
            }
            
            else {
                if (75 <= pos && pos <= 79) { *x = 7; *y = 81 - pos; }
                else { *x = 86 - pos; *y = 2; }  // (80 <= pos && pos <= 83)
            }
        }

        else if (pos <= 98){
            if (pos <= 90)
                if (84 <= pos && pos <= 87) { *x = 3; *y = pos - 81; }
                else { *x = pos - 84; *y = 6; }  // (88 <= pos && pos <= 90)
            
            else if (pos <= 95) {
                if (91 <= pos && pos <= 93) { *x = 6; *y = 96 - pos; }
                else { *x = 99 - pos; *y = 3; }  // (94 <= pos && pos <= 95)
            }
            
            else {
                if (96 <= pos && pos <= 97) { *x = 4; *y = pos - 92; }
                else { *x = 5; *y = 5; }
            }
        }
        else { *x = 4; *y = 5; }  // si pos == 99 je sais pas si on en a besoin
    }

}

// plateau[100] = {0, ... ,99}, positions[n] = {pos_joueur1, ... , pos_joueur_n}
// où n = nb_joueurs
void afficherPlateau(int plateau[], int positions[], int nb joueurs){
    /* PAS ENCORE FINI */
    
    int pos = 0;
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            pos = (10 * i) + j;
        }
    }


    /*int ** tab = (int **) malloc(10 * sizeof(int *));
    for (int i = 0; i < 10; ++i){
        *(tab + i) = (int *) malloc(10 * sizeof(int));
    }
    // libérer la mémoire
    for (int i = 0; i < 10; ++i){ free(tab + i); }
    free(tab);*/

}
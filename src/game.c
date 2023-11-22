#include "game.h"
#include <stdio.h>  // pour les tests
void initTab(char* plateau, int* position, int* attente, int nbJoueur){
    for(int i = 0; i < 100; i++){
        switch (i){  
            case 10 :
                plateau[i] = 'O';
                break;
            
            case 20 :
                plateau[i] = 'O';
                break;
            
            case 77 :
                plateau[i] = 'O';
                break;
            

            case 79 :
                plateau[i] = 'O';
                break;
            
            case 80 :
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
        if((des[0] == 3 && des[1] == 6) || (des[0] == 6 && des[1] == 3)){ 
            newPos = 40;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            return -1;
        }


        if((des[0] == 4 && des[1] == 5) || (des[0] == 5 && des[1] == 4)) { 
            newPos = 89;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            return -1;
        }
    }

    if(attente[joueurCourant] > 0){
        attente[joueurCourant]--;
        return -1;
    }
    
    if(attente[joueurCourant] == -1)
        return -1;

    somme = des[0] + des[1];
    if(position[joueurCourant] + somme == 99){ 
        position[joueurCourant] = 99;
        return joueurCourant; // gagné par joueurCourant, YOUPI
    }  
    
    if(position[joueurCourant] + somme > 99)  { newPos = 99 - (somme - (99 - position[joueurCourant])); }
    
    else { newPos = position[joueurCourant] + somme; }

    switch (plateau[newPos]){
    
        case 'T':
            position[joueurCourant] = newPos;
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
            position[joueurCourant] = newPos;
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
        
        case 'O':
            // pas de break pour vérifier sur quel case je tombe
            do {
                newPos += somme;
            } while(plateau[newPos] == 'O');

    
        default:  // si case normal
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
        }
    
    return -1;
}



void collision(char* plateau, int* position, int* attente, int nbJoueur, int joueurCourant, int nouvellePosition){
    int cmpt = 0;

    for(int i = 0; i < nbJoueur; ++i){
        if(i != joueurCourant && position[i] == nouvellePosition && plateau[position[i]] != 'P' && plateau[position[i]] != 'T'){
            
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
                    attente[i] = -1;
                    for(int j = 0; i < nbJoueur; i++){
                        if(j != i && plateau[position[j]] == 'P' && attente[j] == -1){
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
        cmpt++;
    }

    if(cmpt == nbJoueur)
        position[joueurCourant] = nouvellePosition;

}

void conversion(int pos, int* x, int* y) {
    // Si la position demandée est invalide, on sort directement.
    if (pos < 0 || pos > 99) return;

    int xPos = 0; 
    int yPos = 0;
    int direction = 0;

    int lastCorner = 0;
    int sideLength = 9;
    int cornerCount = 0;

    for (int i = 0; i < pos; i += 1) {
        // Si on a atteint un coin, on augmente le compteur de coins, on marque notre position comme le dernier coin et on change de direction
        if (i == lastCorner + sideLength) {
            cornerCount += 1;
            lastCorner = i;

            direction += 1;
            if (direction == 4) direction = 0;
        }

        // Si on a atteint 3 coins sur l'anneau extérieur ou 2 coins autrement, on réduit la taille du côté.
        if ((sideLength == 9 && cornerCount == 3) || (sideLength < 9 && cornerCount == 2)) {
            sideLength -= 1;
            cornerCount = 0;
        }

        // On se déplace dans la direction actuelle
        if (direction == 0) xPos += 1;
        else if (direction == 1) yPos += 1;
        else if (direction == 2) xPos -= 1;
        else yPos -= 1;
    }

    // On attribue le résultat aux 2 pointeurs.
    *x = xPos;
    *y = yPos;
}

// plateau[100] = {0, ... ,99}, positions[n] = {pos_joueur1, ... , pos_joueur_n}
// où n = nb_joueurs
void affiche(int taille, char tab[][taille]){  // On suppose que taille = 10 par défault
    for (int i = 0; i < taille; ++i){
        for (int j = 0; j < taille; ++j){ printf("|%c", tab[j][i]); }
        printf("|\n");
    }
}
    

void afficherTableau(char plateau[], int positions[], int nb_joueurs, int joueurCourant){
    char tab[10][10];
    int x, y;

    for (int i = 0; i < 100; ++i){
        conversion(i, &x,  &y);
        tab[x][y] = plateau[i];
    }

    for(int i = 0; i < nb_joueurs; i++){
        for(int j = i+1; j < nb_joueurs; j++){
            // verifie si j est sur j
            if(positions[i] == positions[j]){
                conversion(positions[i], &x, &y);
                tab[x][y] = (i - joueurCourant) % nb_joueurs + '0'; // onaffiche celui qui minimise
            }

        }

        // si i est sur personne on l'affiche
        conversion(positions[i], &x, &y);
        tab[x][y] = i + '0';
    }

    conversion(positions[joueurCourant], &x, &y);
    tab[x][y] = joueurCourant + '0';


    affiche(10, tab);
    
    for (int i = 0; i < nb_joueurs; ++i){ // de 2 à 4 joueurs
        printf("Joueur %d : case %d \n", i, positions[i]);
    }

}

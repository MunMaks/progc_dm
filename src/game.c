#include "game.h"

void initTab(char* plateau, int* position, int* attente, int nbJoueur){
    // pas encore mis les case oie car je ne sais pas combien on doit en mettre et si certain sont aleatoire
    for(int i = 0; i < 100; i++){
        switch (i)
        {
        case 53:
            plateau[i] = 'T';
            break;
        
        case 8:
            plateau[i] = 'R';
            break;
        
        case 74:
            plateau[i] = 'P';
        
        case 31:
            plateau[i] = 'H';
            break;
        
        case 65:
            plateau[i] = 'L';
            break;
        
        case 94:
            plateau[i] = 'X';
        
        default:
            plateau[i] = ' ';
            break;
        }
    }

    for(int i = 0; i < 4; i++){
        if(i < nbJoueur){
            position[i] = 0;
            attente[i] = 0;
        }

        else{
            //si il y a moins de 4 joueur je met -1 pour dire que le joueur n'existe pas
            position[i] = -1;
            attente[i] = -1;
        }
    }

}

int avancerJoueur(char* plateau, int* position, int* attente, int joueurCourant, int nbJoueur, int des[2], int premierTour){
    int somme = 0;
    int newPos = 0;

    if(premierTour){
        if((des[1] == 3 && des[2] == 6) || (des[1] == 6 && des[2] == 3))
            position[joueurCourant] = 40;
        
        if((des[1] == 4 && des[2] == 5) || (des[1] == 5 && des[2] == 4))
            position[joueurCourant] = 89;
    }

    else{
        if(attente[joueurCourant] > 0){
            attente[joueurCourant]--;
            return -1;
        }
        
        if(attente[joueurCourant] == -1)
            return -1;
    
        somme = des[0] + des[1];

        if(position[joueurCourant] + somme == 99)
            return joueurCourant;

        if(position[joueurCourant] + somme > 99)
            newPos = 99 - (somme - (99 - position[joueurCourant]));
        
        else
            newPos = position[joueurCourant] + somme;
    }
        
        collision(plateau, position, attente, nbJoueur, joueurCourant, newPos); //encore non coder donc argument peut encore changer

        switch (plateau[position[joueurCourant]])
        {
        case 'O':
            avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, 0);
            break;
        
        case 'T':
            for(int i = 0; i < nbJoueur; i++){
                if(i != joueurCourant && plateau[position[i]] == 'T' && attente[i] == -1){
                    attente[i] = 0;
                }
            }

            attente[joueurCourant] = -1;
            break;
        
        case 'R':
            newPos = 16;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos); //encore non coder donc argument peut encore changer
            des[0] = 0;
            des[1] = 0;
            avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, 0);
        
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
        
        case 'L':
            newPos = 52;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos); //encore non coder donc argument peut encore changer
            des[0] = 0;
            des[1] = 0;
            avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, 0);
        
        case 'X':
            newPos = 0;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos); //encore non coder donc argument peut encore changer
            des[0] = 0;
            des[1] = 0;
            avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, 0);
        
        default:
            break;
        }

    return -1;
}

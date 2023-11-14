#include "game.h"

void initTab(char* plateau, int* position, int* attente, int nbJoueur){
    // pas encore mis les case oie car je ne sais pas combien on doit en mettre et si certain sont aleatoire
    for(int i = 0; i < 100; i++){
        switch (i)
        {

        case 10:
            plateau[i] = 'O';
            break;
        
        case 19:
            plateau[i] = 'O';
            break;
        
        case 30:
            plateau[i] = 'O';
            break;
        
        case 70:
            plateau[i] = 'O';
            break;
        
        case 79:
            plateau[i] = 'O';
            break;
        
        case 80:
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

    switch (plateau[newPos]){
    
        case 'O':
            //je ne met pas de break pour pouvoir tester sur quel j'arrive apres la case oie et je ne teste pas de collision car se sera fait dans les autre case
            do{
                newPos += somme;
            }while(plateau[newPos] != 'O');
    
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
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos); 
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
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
    
        case 'L':
            newPos = 52;
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
        
            break;
    
            case 'X':
                newPos = 0;
                collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
                break;
    
        default:
            collision(plateau, position, attente, nbJoueur, joueurCourant, newPos);
            break;
        }
    
    return -1;
}

void collision(char* plateau, int* position, int* attente, int nbJoueur, int joueurCourant, int nouvellePosition){

    for(int i = 0; i < nbJoueur; i++){
        if(i != joueurCourant && position[i] == position[joueurCourant] && plateau[position[i]] != 'P' && plateau[position[i]] != 'T'){
            if(plateau[position[i]] == 'H')
                attente[i] = 0;
            
            position[i] = position[joueurCourant];
            position[joueurCourant] = nouvellePosition;

            switch (plateau[position[i]]){
    
            case 'T':
                for(int i = 0; i < nbJoueur; i++){
                    if(i != joueurCourant && plateau[position[i]] == 'T' && attente[i] == -1){
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

#include "option.h"


void initOption(Option* option){
    option->nbJoueur = 2; //om par du principe que il y a au mon 2 joueur obligatoirement
    option->nbsimule = 0;
    option->seed = -1; // -1 pour dire que il n'y a pas de seed
    option->fichier = 0;
}


void choixOption(int nbArg, char* arg[], Option* option, FILE* f){



    if(nbArg == 1){
        printf("entrez le nombre de joueur : ");
        scanf("%d", &option->nbJoueur);
        return;
    }

    if(arg[1][0] != '-'){
        option->fichier = 1;
       return;
    }


    for(int i = 1; i < nbArg; i++){
        if(arg[i][0] == '-'){
            if(arg[i][1] == 'W'){
                option->nbJoueur = atoi(arg[i+1]);
                option->nbsimule = atoi(arg[i+2]);
            }

            if(arg[i][1] == 'S'){
                option->seed = atoi(arg[i+1]);
            }
        }
    }
    
}


void lanceAlgo(Option option, char* plateau, int* position, int* attente, FILE* f){
    
    if(option.nbsimule != 0)
        partieSimuler(option.nbJoueur, plateau, position, attente, option.nbsimule, option.seed);

    else
        partieNormal(option.nbJoueur, plateau, position, attente, f);
    
}

#include "algo.h"


void partieNormal(int nbJoueur, char* plateau, int* position, int* attente){
    int continuer = -1, joueurCourant = 0, des[2], premier = 1;;

    do{
        if(joueurCourant == nbJoueur){
            joueurCourant = 0;
            if(premier)
                premier = 0;
        }

        
        afficherTableau(plateau, position, nbJoueur);

        printf("entrez vos 2 lancer de dés : ");
        scanf("%d %d", des[0], des[1]);

        continuer = avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des[2], premier);
        
        joueurCourant++;

    }while(continuer == -1);

    printf("J%d, a gagner\n", continuer);
}

#include "algo.h"


void partieNormal(int nbJoueur, char* plateau, int* position, int* attente, FILE* f){
    int continuer = -1, joueurCourant = 0, des[2], premier = 1, sauv = 1;
    char des1, des2;

    if(!f){
        printf("la partie ne sera pas sauvegarder\n");
        sauv = 0;
    }

    else{
        joueurCourant = charger(f, plateau, position, attente, nbJoueur, &premier);
    }
    
    do{
        if(joueurCourant == nbJoueur){
            joueurCourant = 0;
            if(premier)
                premier = 0;
        }

        
        afficherTableau(plateau, position, nbJoueur, joueurCourant);

        printf("J%d entrez vos 2 lancer de dés : ", joueurCourant);

        scanf(" %c", &des1);

        if(des1 == 'q')
            return;
        
        scanf(" %c", &des2);

        des[0] = des1 - '0';

        des[1] = des2 - '0';

        while((des[0] > 6 || des[0] < 0) || (des[1] > 7 || des[1] < 0)){
            printf("mauvaise saisie il s'agit de 2 Dés a 6 face recommancer : ");
            scanf(" %c", &des1);

            if(des1 == 'q')
                return;
        
            scanf(" %c", &des2);

            des[0] = des1 - '0';

            des[1] = des2 - '0';
        }

        if(sauv)
            sauvegarder(f, des);

        continuer = avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, premier);
        
        joueurCourant++;

    }while(continuer == -1);

    printf("J%d, a gagner\n", continuer);
}

void partieSimuler(int nbJoueur, char* plateau, int* position, int* attente, int n, int seed){
    int tour, tourTotal = 0, min = 0, max = 0, planter = 0, continuer, joueurCourant, des[2], premier, cmpt;

    if(seed != -1)
        srand(seed);

    else
        srand(time(NULL));
    
    for(int i = 0; i < n; i++){
        continuer = -1;
        joueurCourant = 0;
        premier = 1;
        tour = 1;
        cmpt = 0;

        for(int j = 0; j < nbJoueur; j++){
            position[j] = 0;
            attente[j] = 0;
        }

        do{
            if(joueurCourant == nbJoueur){
                joueurCourant = 0;
                tour++;
                if(premier)
                    premier = 0;
            }

            des[0] = rand() % 6 + 1;
            des[1] = rand() % 6 + 1;
            

            continuer = avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, premier);
        
            joueurCourant++;

            for(int j = 0; j < nbJoueur; j++){
                if(attente[j] == -1)
                    cmpt++;
            }
            
            if(cmpt == nbJoueur){
                planter++;
                continuer = 0;
            }

            else
                cmpt = 0;

            
        }while(continuer == -1);

        tourTotal += tour;

        if(min == 0)
            min = tour;

        if(min > tour)
            min = tour;
        
        if(max < tour)
            max = tour;
    }

    printf("nombre de simulation a %d joueur : %d\n", nbJoueur, n);
    printf("nombre tour moyen : %f\n", (float) tourTotal / n);
    printf("nombre de tour minimum : %d\n", min);
    printf("nombre de tour maximum : %d\n", max);
    printf("nombre de fois ou le jeu a bloqué : %d\n", planter);

}

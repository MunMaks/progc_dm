#ifndef __OPTION__
#define __OPTION__

#include "algo.h"

typedef struct{
    int nbJoueur;
    int simulation; //si on fait une simulation ou non
    int nbsimule;
    int seed;
}Option;


/**
 * @brief fonction qui va déterminer les options de choix de l'utilisateur
 * 
 * @param arg 
 * @param nbArg 
 * @param option
 */
void choixOption(int nbArg, char* arg[], Option* option);

/**
 * @brief initialise la structure option
 * 
 * @param option 
 */
void initOption(Option* option);

/**
 * @brief lance le bonne algo que l'uttilisateur a demander
 * 
 * @param option 
 * @param plateau 
 * @param position 
 * @param attente 
 */
void lanceAlgo(Option option, char* plateau, int* position, int* attente, char* nomFichier);

#endif

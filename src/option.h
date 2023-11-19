#ifndef __OPTION__
#define __OPTION__

#include "algo.h"

typedef struct{
    int nbJoueur;
    int nbsimule; // si il est egal a 0 alors il n'y a pas de simulation;
    int seed;
    int fichier; //si y a un fichier a lire
}Option;


/**
 * @brief initialise la structure option
 * 
 * @param option 
 */
void initOption(Option* option);

/**
 * @brief fonction qui va déterminer les options de choix de l'utilisateur
 * 
 * @param arg 
 * @param nbArg 
 * @param option
 */
void choixOption(int nbArg, char* arg[], Option* option, FILE* f);

/**
 * @brief lance le bonne algo que l'uttilisateur a demander
 * 
 * @param option 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param f 
 */
void lanceAlgo(Option option, char* plateau, int* position, int* attente, FILE* f);

#endif

#ifndef __FICHIER__
#define __FICHIER__

#include "game.h"
#include <string.h>
#define LIGNE_LONGUEUR 32

/**
 * @brief ouvre le fichier
 * 
 * @param nomFichier 
 * @param nbJoueur 
 */
FILE* ouvreFichier(const char* nomFichier, int* nbJoueur);

/**
 * @brief simule la partie sauvegarder dans le fichier
 * 
 * @param f 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param nbJoueur 
 * @param premier 
 * @return int 
 */
int charger(FILE* f, char* plateau, int* position, int* attente, int nbJoueur, int* premier);

/**
 * @brief sauvegarde a chaque tour le lancer de de afin de pouvoir  simuler la parite quand on charge
 * 
 * @param f 
 */
void sauvegarder(FILE* f, int des[2]);

#endif

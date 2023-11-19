#ifndef __ALGO__
#define __ALGO__

#include "game.h"
#include "fichier.h"
#include <time.h>
#include <string.h>

/**
 * @brief lance l'algorithme pour une partie normale entre 2 et 4 joueur
 * 
 * @param nbJoueur 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param f 
 */
void partieNormal(int nbJoueur, char* plateau, int* position, int* attente, FILE* f);

/**
 * @brief lance l'algorithme pour une partie simuler entre 2 et 4 joueur 
 * si il n'y a pas de seed mettre NULL pour se dernier
 * 
 * @param nbJoueur 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param n 
 * @param seed 
 */
void partieSimuler(int nbJoueur, char* plateau, int* position, int* attente, int n, int seed);

#endif

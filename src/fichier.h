#ifndef __FICHIER__
#define __FICHIER__

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief ouvre le fichier
 * 
 * @param nom 
 * @return FILE* 
 */
FILE* ouvreFichier(char* nom);

/**
 * @brief simule la partie sauvegarder dans le fichier
 * 
 * @param f 
 */
void charger(FILE* f);

#endif

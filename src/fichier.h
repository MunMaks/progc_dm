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
* @brief sauvegarde les jet de des
*
* @param f
* @param des
*/
void sauvegarder(FILE* f, int des[2]);

/**
 * @brief simule la partie sauvegarder dans le fichier
 * 
 * @param f 
 */
void charger(FILE* f);

#endif

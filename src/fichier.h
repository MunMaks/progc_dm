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
FILE* ouvreFichier(const char* nomFichier, int nbJoeur);

/**
 * @brief simule la partie sauvegardée dans le fichier
 * 
 * @param fptr
 */
void charger(FILE* fptr);

/**
 * @brief sauvegarde à chaque tour le lancement des dès pour simuler la partie quand on la charge
 * 
 * @param fptr
 */
void sauvegarder(FILE* fptr, int des[2]);

#endif

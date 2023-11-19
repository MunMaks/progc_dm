#ifndef __GAME__
#define __GAME__

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief initialise les differrent plateau necessaire au bon fonctionnement du jeux
 * 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param nbJoueur
 */
void initTab(char* plateau, int* position, int* attente, int nbJoueur);

/**
 * @brief effectue le tour de jeu d’un joueur,
 * elle renvoie le num´ero du joueur s’il gagne la partie et -1 si la partie n’est pas finie
 * 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param joueurCourant 
 * @param nbJoueur 
 * @param des 
 * @param premierTour 
 * @return int 
 */
int avancerJoueur(char* plateau, int* position, int* attente, int joueurCourant, int nbJoueur, int des[2], int premierTour);


/**
 * @brief gere le cas de collision entre 2 joueur et met a jour quoi qu'il arrive la position du joueur
 * 
 * @param plateau 
 * @param position 
 * @param attente 
 * @param nbJoueur 
 * @param joueurCourant 
 * @param nouvellePosition 
 */
void collision(char* plateau, int* position, int* attente, int nbJoueur, int joueurCourant, int nouvellePosition);

/**
 * @brief prend la position pos (entre 0 et 99) et la transforme en coordonner x et y
 * 
 * @param pos 
 * @param x 
 * @param y 
 */
void conversion(int pos, int* x, int* y); // to do


/**
 * @brief affiche le plateau de jeu en spiral sur le terminal
 * 
 * @param plateau 
 * @param position 
 * @param nbJoueur 
 */
void afficherTableau(char* plateau, int* position, int nbJoueur, int joueurCourant); // to do

#endif

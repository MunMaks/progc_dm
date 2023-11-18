#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/stat.h>
#include "fichier.h"
#include "option.h"
#include "algo.h"
#include "fichier.h"
#include "game.h"
#define LIGNE_LONGUEUR 32

FILE* ouvreFichier(const char* nomFichier, int nbJoeur){
    if (2 > nbJoeur || 4 < nbJoeur){ return NULL; }  // nbJoueur entre 2 et 4
    
    FILE * fptr;
    fptr = fopen(nomFichier, "r+");
    char ligne[LIGNE_LONGUEUR];
    if (!fptr) {   // Le fichier n'existe pas, on va le créer

        fptr = fopen(nomFichier, "w");  // "w" mode peut être utiliser pour créer un fichier

        fprintf(fptr, "JO\n");  // Insérer le bon format
        fprintf(fptr, "%d\n", nbJoeur);  // Cette construction ajoute le nbJoueur dans le fichier
        
        fclose(fptr);
        fptr = fopen(nomFichier, "r+");  // La lécture et l'écriture 
    }
    else {  // Le fichier existe, on vérifie le format
        if (fgets(ligne, LIGNE_LONGUEUR, fptr) && (strcmp(ligne, "JO\n"))) {
            printf("Le fichier, %s ne respecte pas de format ERREUR\n", nomFichier);
            return NULL;
            }
        
        // Si on a un bon format, on vérifie le bon nombre de joueurs
        fgets(ligne, LIGNE_LONGUEUR, fptr);  // deuxième ligne du fichier
        // on compare le code ASCII
        if ((ligne[0] < '2' || ligne[0] > '4') && (ligne[1] == '\n')){ return NULL; } 
    }
    
    // On ne fermer pas de fichier en plus on a vu la première ligne.
    return fptr;
}

void charger(FILE* fptr);  // pour l'instant rien


void sauvegarder(FILE* fptr, int des[2]){
    //  ouverture en mode "r+" pour pouvoir lire et écrire sans  la perte du contenue précédente
    if (fptr == NULL) { perror("Échoé d'ouvrir le fichier\n"); return; }
    
    char ligne[256];  // pow(2, 10);

    // Si fichier.jo n'existe pas...
    if (fgets(ligne, 256, fptr)){
        if (strcmp(ligne, "JO\n")){  // si "JO\n" == "JO\n" alors strcmp() renvoye 0
            fprintf(fptr, "JO\n");  // ou on peut utliser fputc()
        }
    }

    // le nombre de joueurs
    // if (fgetc(fptr) != nbJoueur){
    //    fputc(nbJoueur, fptr);
    // }
    // fputc("\n", fptr); 
    
}

int main(int argc, char* argv[]){
    // char nom[9] = "test.txt"; nom[8] = '\0';
    char name[9] = "text.txt"; name[8] = '\0';
    
    int des[2] = {4, 5};
    int nbJoueur = 4;

    FILE * fptr = ouvreFichier(name, nbJoueur);
    sauvegarder(fptr, des);

    printf("\n");

    fclose(fptr);
    return 0;
}

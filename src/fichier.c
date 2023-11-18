#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <sys/stat.h>
#include "fichier.h"
#include "option.h"
#include "algo.h"
#include "fichier.h"
#include "game.h"

FILE* ouvreFichier(const char* nomFichier, int nbJoeur){
    FILE * fptr;
    fptr = fopen(nomFichier, "r+");

    if (NULL == fptr) { perror("Impossible d'ouvrir le fichier "); return NULL; }
    
    // fclose(fptr);
    // int c;
    // while((c = fgetc(fptr)) != EOF) { putchar(c); }
    return fptr;
}

void charger(FILE* fptr);  // pour l'instant rien


void sauvegarder(FILE* fptr, int des[2]){
    //  ouverture en mode "r+" pour pouvoir lire et écrire sans  la perte du contenue précédente
    // if (fptr == NULL) { perror("Échoé d'ouvrir le fichier\n"); return; }
    
    char ligne[256];  // pow(2, 10);

    // Si fichier.jo n'existe pas...
    if (fgets(ligne, 256, fptr)){
        if (strcmp(ligne, "JO\n")){  // si "JO\n" == "JO\n" alors strcmp() renvoye 0
            fputs("JO\n", fptr);  // ou on peut utliser fputc()
        }
    }

    // le nombre de joueurs
    //if (fgetc(fptr) != nbJoueur){
    //    fputc(nbJoueur, fptr);
    //}
    //fputc("\n", fptr); 
    
}

int main(int argc, char* argv[]){

    char name[9] = "test.txt"; name[8] = '\0';
    
    int des[2] = {4, 5};
    int nbJoueur = 4;

    FILE * fptr = ouvreFichier(name, nbJoueur);
    sauvegarder(fptr, des);

    printf("\n");

    fclose(fptr);
    return 0;
}

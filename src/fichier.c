#include "fichier.h"


FILE* ouvreFichier(const char* nomFichier, int* nbJoueur){
    FILE * f;

    f = fopen(nomFichier, "r+");
    char ligne[LIGNE_LONGUEUR];
    if (!f) {   // Le fichier n'existe pas, on va le créer

        f = fopen(nomFichier, "w");  // "w" mode peut être utiliser pour créer un fichier

        fprintf(f, "JO\n");  // Insérer le bon format

        printf("entrez le nombre de joueur : ");

        scanf("%d", nbJoueur);

        fprintf(f, "%d\n", *nbJoueur);
        
        fclose(f);

        f = fopen(nomFichier, "r+"); // La lécture et l'écriture

        fseek(f, 5, SEEK_SET);
    }

    else {  // Le fichier existe, on vérifie le format
        if (fgets(ligne, LIGNE_LONGUEUR, f) && (strcmp(ligne, "JO\n"))) {
            printf("Le fichier, %s ne respecte pas de format ERREUR\n", nomFichier);
            return NULL;
        }
        
        
        fgets(ligne, LIGNE_LONGUEUR, f);  // deuxième ligne du fichier

        *nbJoueur = atoi(ligne);
    }
    
    // On ne fermer pas de fichier en plus on a vu les 2 premières ligne.
    return f;
}

int charger(FILE* f, char* plateau, int* position, int* attente, int nbJoueur, int* premier){
    int des[2], joueurCourant = 0;
    char ligne[10], c;

    if((c = fgetc(f)) == -1)
        return joueurCourant;
    
    else
        fseek(f, -1, SEEK_CUR);    

    fgets(ligne, 10, f);

    while(feof(f) == 0){

        if(joueurCourant == nbJoueur){
            joueurCourant = 0;
            if(*premier)
                *premier = 0;
        }

        
        
        des[0] = ligne[0] - '0';

        des[1] = ligne[2] - '0';

        avancerJoueur(plateau, position, attente, joueurCourant, nbJoueur, des, *premier);

        joueurCourant++;

        fgets(ligne, 10, f);

    }

    return joueurCourant;
    
}


void sauvegarder(FILE* f, int des[2]){

    fprintf(f, "%d %d\n", des[0], des[1]);
    
}

#include "option.h"

int main(int argc, char* argv[]){
    Option option;
    char plateau[100];
    int position[4], attente[4];
    FILE* f = NULL;

    initOption(&option);

    choixOption(argc, argv, &option, f);
    
    if(option.fichier)
        f = ouvreFichier(argv[1], &option.nbJoueur);

    initTab(plateau, position, attente, option.nbJoueur);

    lanceAlgo(option, plateau, position, attente, f);

    if(f)
        fclose(f);

    return 0;
}

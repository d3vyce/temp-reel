#include "part1.h"

void print(int result[], int F) {
    int i;

    for(i=0; i<F; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void output(int result[], int F) {
    FILE * out;
    int i;

    if((out = fopen("output", "w")) == NULL) {
        printf("Erreur ouverture fichier ! bis\n");
        exit(-1);
    }
    
    for(i=0; i<F; i++) {
        fprintf(out, "%d", result[i]);
    }

    fclose(out);
}

int main(int argc, char const *argv[]) {
    int i, nb_tache, duree;
    int * result;
    FILE * fichier;
    task * tache;
    
    /*Check argument*/
    if(argc != 4) {
        printf("Erreur argument !\n");
        printf("Usage : ./main [FILE] [Algorithme] [Durée]\n");
        exit(-1);
    }

    /*Création des variables*/
    duree = strtol(argv[3], NULL, 10);
    result = malloc(sizeof(int)*duree);

    if((fichier = fopen(argv[1], "r")) == NULL) {
        printf("Erreur ouverture fichier !\n");
        exit(-1);
    }
    fscanf(fichier, "%d", &nb_tache);
    tache = malloc(sizeof(task)*nb_tache);

    for(i=0; i<nb_tache; i++) {
        fscanf(fichier, "%d %d %d", &tache[i].Cn, &tache[i].Dn, &tache[i].Tn);
    }
    fclose(fichier);

    /*Choix de l'algo*/
    if(strcmp(argv[2], "fp") == 0) {
        result = fp(tache, duree, nb_tache);
        printf("Algo FP :\n");
    } else if(strcmp(argv[2], "edf") == 0) {
        result = edf(tache, duree, nb_tache);
        printf("Algo EDF :\n");
    } else {
        printf("Erreur Algo !\n");
        printf("Algo possible : fp, edf\n");
        exit(-1);
    }

    print(result, duree);
    output(result, duree);

    return 0;
}

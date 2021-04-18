#include "part2.h"

void compute(Taskset tache[], int nb_tache, int code) {
    int i;

    for(i=0; i < nb_tache; i++) {
        printf("Tache %d :\n", i+1);
        if(code == 1) {
            printf("Pire temps de réponse (non preemptive): %d \n\n", get_worst_case_responce_time(tache, i));
        } else if(code == 2) {
            printf("Pire temps de réponse (preemptive): %d \n\n", get_worst_case_responce_time_preemptive(tache, i, nb_tache));
        } else {
            printf("Erreur code (code dispo : 1, 2)\n");
            exit(-1);
        }
    }
}

int main(int argc, char const *argv[]) {
    int i, nb_tache;
    Taskset * tache;
    FILE * input;
    
    if(argc != 3) {
        printf("Erreur argument !\n");
        printf("Usage : ./part2 [FILE] [CODE]\n");
        exit(-1);
    }

    if((input = fopen(argv[1], "r")) == NULL) {
        printf("Erreur ouverture fichier !\n");
        exit(-1);
    }
    fscanf(input, "%d", &nb_tache);
    tache = malloc(sizeof(Taskset)*nb_tache);

    for(i=0; i<nb_tache; i++) {
        fscanf(input, "%d %d %d", &tache[i].Cn, &tache[i].Dn, &tache[i].Tn);
    }
    fclose(input);

    printf("Résultat de la fonction test_load : %d \n\n", test_load(tache, nb_tache));

    compute(tache, nb_tache, atoi(argv[2]));

    return 0;
}

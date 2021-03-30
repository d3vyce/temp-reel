#include "part2.h"

int test_load(Taskset tache[]) {
    //TODO
    return 0;
}

int get_busy_period(Taskset tache[], int i) {
    //TODO
    return 0;
}

int get_nb_critical_job(Taskset tache[], int i, int bp) {
    //TODO
    return 0;
}

int get_responce_time(Taskset tache[], int i, int k) {
    //TODO
    return 0;
}

int get_worst_case_responce_time(Taskset tache[], int i) {
    //TODO
    return 0;
}

int main(int argc, char const *argv[]) {
    int i, nb_tache;
    Taskset * tache;
    FILE * input;
    
    if(argv != 2) {
        printf("Erreur argument !\n");
        printf("Usage : ./part2 [FILE]\n");
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

    printf("Résultat de la fonction test_load : %d", test_load(tache));

    return 0;
}

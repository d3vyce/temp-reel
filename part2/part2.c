#include "part2.h"

int test_load(Taskset tache[], int nb_tache) {
    double borne;
    double result = 0;
    int i;

    borne = nb_tache*(pow(2,1.0/nb_tache)-1);

    for(i = 0; i < nb_tache; i++) {
        result = result + (double)tache[i].Cn/(double)tache[i].Tn;
    }
    
    if(result < borne) {
        return 1;
    } else if (result < 1){
        return 0;
    } else {
        return -1;
    }
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
    
    if(argc != 2) {
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

    printf("Résultat de la fonction test_load : %d \n", test_load(tache, nb_tache));

    return 0;
}

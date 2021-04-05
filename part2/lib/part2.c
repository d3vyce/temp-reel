#include "part2.h"

void compute(Taskset tache[], int nb_tache) {
    int i;

    for(i=0; i < nb_tache; i++) {
        printf("Tache %d :\n", i+1);
        printf("Pire temps de réponse pour la tâche %d : %d \n\n", 1, get_worst_case_responce_time(tache, i));
    }
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

    printf("Résultat de la fonction test_load : %d \n\n", test_load(tache, nb_tache));

    get_nb_critical_job(tache, 0, get_busy_period(tache, 0));
    get_nb_critical_job(tache, 1, get_busy_period(tache, 1));
    get_nb_critical_job(tache, 2, get_busy_period(tache, 2));

    return 0;
}

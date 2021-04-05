#include "part2.h"

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

    /*
    get_responce_time(tache, 2, 1);
    get_responce_time(tache, 2, 2);
    get_responce_time(tache, 2, 3);
    */

    /*
    printf("Pire temps de réponse pour la tâche %d : %d \n\n", 1, get_worst_case_responce_time(tache, 0));
    printf("Pire temps de réponse pour la tâche %d : %d \n\n", 2, get_worst_case_responce_time(tache, 1));
    printf("Pire temps de réponse pour la tâche %d : %d \n\n", 3, get_worst_case_responce_time(tache, 2));
    */


    return 0;
}

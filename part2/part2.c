#include "part2.h"

int test_load(Taskset tache[], int nb_tache) {
    double borne, result = 0;
    int i, cases;

    borne = nb_tache*(pow(2,1.0/nb_tache)-1);
    
    for(i = 0; i < nb_tache; i++) {
        if(tache[i].Dn <= tache[i].Tn) {
            if(tache[i].Dn == tache[i].Tn) {
                cases = 1;
            } else {
                cases = 2;
            }
        } else {
            printf("Erreur : D%d n'est pas inférieur à T%d\n", i, i);
            exit(-1);
        }
    }

    if(cases == 1) {
        printf("case 1\n"); // Case Di = Ti -> donc somme de Ci/Ti
        for(i = 0; i < nb_tache; i++) {
            result += (double)tache[i].Cn/(double)tache[i].Tn;
        }
    } else if (cases == 2) {
        printf("case 2\n"); // Case Di != Ti -> vérification que les taches classées par échéances croissantes -> puis somme Ci/Di
        for(i = 0; i < nb_tache-1; i++) {
            if(tache[i].Dn > tache[i+1].Dn) {
                printf("Les tâches ne sont pas classées par échéances croissantes\n");
                exit(-1); //TODO auto tri par ordre échéances croissantes
            }
        }
        for(i = 0; i < nb_tache; i++) {
            result += (double)tache[i].Cn/(double)tache[i].Dn;
        }
    }

    printf("borne : %f      result : %f\n", borne, result);
    
    if(result <= borne) {
        return 1;
    } else if (result <= 1){
        return 0;
    } else {
        return -1;
    }
}

int get_busy_period(Taskset tache[], int i) {
    int busy_period = 0, k, t = 0;
    
    do {
        busy_period = 0;
        t++;
        for(k = 0; k <= i; k++) {
            busy_period += (ceil((double)t/(double)tache[k].Tn))*tache[k].Cn;
            //printf("busy_period : %d, %d\n", t, busy_period);
        }
    } while (t != busy_period);

    printf("Résultat de la fonction get_busy_period pour la tâche %d : %d \n", i, busy_period);
    return busy_period;
}

int get_nb_critical_job(Taskset tache[], int i, int bp) {
    int nb_critical_job = ceil((double)bp/(double)tache[i].Tn);

    printf("Nombre d'instance de la tâche %d pendant la busy period  : %d \n", i, nb_critical_job);
    
    return nb_critical_job;
}

int get_responce_time(Taskset tache[], int i, int k) {
    int responce_time, date_terminaison = 0, date_terminaisonbis, date_activation, t = 0, xxx = 1, j;

    while(date_terminaison != date_terminaisonbis || date_terminaison < tache[i].Dn) {
        date_terminaisonbis = date_terminaison;
        date_terminaison = tache[i].Cn;
        for(j = 0; j < i; j++) {
            date_terminaison += (ceil((double)t/(double)tache[j].Tn))*tache[j].Cn+tache[i].Cn;
        }
        printf("%d, %d, %d\n", date_terminaison, date_terminaisonbis, t);
        t++;
    }
    
    //date_activation = tache[i].Tn*(k-1);
    //responce_time = date_terminaison - date_activation;

    //printf("Date de terminaison : %d, date d'activation : %d -> %d\n", date_terminaison, date_activation, responce_time);

    return 1;
}

int get_worst_case_responce_time(Taskset tache[], int i) {
    int nb_critical_time, j, worst_case_responce_time = 0, tempo;

    nb_critical_time = get_nb_critical_job(tache, i, get_busy_period(tache, i));

    for(j = 1; j <= nb_critical_time; j++) {
        tempo = get_responce_time(tache, i, j);
        if(worst_case_responce_time < tempo) {
            worst_case_responce_time = tempo;
        }
    }

    return worst_case_responce_time;
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

    /*
    get_responce_time(tache, 2, 1);
    get_responce_time(tache, 2, 2);
    get_responce_time(tache, 2, 3);
    */

    //printf("Pire temps de réponse pour la tâche %d : %d \n\n", 1, get_worst_case_responce_time(tache, 0));
    //printf("Pire temps de réponse pour la tâche %d : %d \n\n", 2, get_worst_case_responce_time(tache, 1));
    //printf("Pire temps de réponse pour la tâche %d : %d \n\n", 3, get_worst_case_responce_time(tache, 2));


    return 0;
}

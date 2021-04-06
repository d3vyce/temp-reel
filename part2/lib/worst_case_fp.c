#include "worst_case_fp.h"

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
        /* Case Di = Ti -> donc somme de Ci/Ti */
        for(i = 0; i < nb_tache; i++) {
            result += (double)tache[i].Cn/(double)tache[i].Tn;
        }
    } else if (cases == 2) {
        /* Case Di != Ti -> vérification que les taches classées par échéances croissantes -> puis somme Ci/Di */
        for(i = 0; i < nb_tache-1; i++) {
            if(tache[i].Dn > tache[i+1].Dn) {
                printf("Les tâches ne sont pas classées par échéances croissantes\n");
                exit(-1); /* TODO auto tri par ordre échéances croissantes */
            }
        }
        for(i = 0; i < nb_tache; i++) {
            result += (double)tache[i].Cn/(double)tache[i].Dn;
        }
    }

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
            /*printf("busy_period : %d, %d\n", t, busy_period);*/
        }
    } while (t != busy_period);

    printf("Résultat de la fonction get_busy_period : %d \n", busy_period);
    return busy_period;
}

int get_nb_critical_job(Taskset tache[], int i, int bp) {
    int nb_critical_job = ceil((double)bp/(double)tache[i].Tn);

    printf("Nombre d'instance pendant la busy period  : %d \n", nb_critical_job);
    
    return nb_critical_job;
}

int get_responce_time(Taskset tache[], int i, int k) {
    int date_activation, date_terminaison = 1, t = 0, j;

    date_activation = (k-1)*tache[i].Tn;

    while(t != date_terminaison) {
        t = date_terminaison;
        date_terminaison = 0;

        for(j = 0; j < i; j++) {
            date_terminaison += (ceil((double)t/(double)tache[j].Tn))*tache[j].Cn;
        }
        date_terminaison += k*tache[i].Cn;
    }

    return date_terminaison-date_activation;
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

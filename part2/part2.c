#include "part2.h"

int test_load(Taskset tache[], int nb_tache) {
    double borne;
    double result = 0;
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
    int busy_period = 0, a = 1, j;

    busy_period = (1+(a/tache[i].Tn)*tache[i].Cn);
    
    for(j = 0; j < i; j++) {
        printf("busy_period : %d\n", busy_period);
        busy_period += (busy_period/tache[j].Tn)*tache[j].Cn;
    }

    return busy_period;
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
    //printf("Résultat de la fonction get_busy_period pour la tâche 1 : %d \n", get_busy_period(tache, 0));

    return 0;
}

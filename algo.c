#include "algo.h"

int * fp(task tache[], int F, int n) {
    int i, t;
    int *tab = malloc(sizeof(int)*n);
    int *result = malloc(sizeof(int)*F);

    /*Création de tab[i]*/
    for(i=0; i<n; i++) {
        tab[i] = tache[i].Cn;
    }

    /*Boucle 1 à F*/
    for(t=0; t<F; t++) {
        for(i=0; i<n; i++) {
            if(((t/tache[i].Tn)*tache[i].Tn) == t && t != 0) {
                tab[i] = tache[i].Cn;
            }
        }
        for(i=0; i<n; i++) {
            if(tab[i] != 0) {
                result[t] = i+1;
                tab[i]--;
                break;
            } else if(i == n-1) {
                result[t] = 0;
                break;
            }
        }
    }

    return result;
}

int * edf(task tache[], int F, int K) {
    SortedJobList list = create_empty_list();
    int *result = malloc(sizeof(int)*F);
    int i, t;
    
    /*add_job()*/
    for(i=0; i<K; i++) {
        add_job(&list,i+1,tache[i].Cn,tache[i].Dn);
    }
    
    /*Boucle 1 à F*/
    for(t=0; t<F; t++) {
        for(i=0; i<K; i++) {
            if(((t/tache[i].Tn)*tache[i].Tn) == t && t != 0) {
                add_job(&list,i+1,tache[i].Cn,tache[i].Dn+t);
            }
        }
        result[t] = schedule_first(&list);
    }

    free_list(&list);
    return result;
}

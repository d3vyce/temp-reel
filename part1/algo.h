#include <stdlib.h>

#include "sorted_job_list.h"

typedef struct task{
    int Cn;
    int Dn;
    int Tn;
}task;

int * fp(task tache[], int F, int n);

int * edf(task tache[], int F, int K);

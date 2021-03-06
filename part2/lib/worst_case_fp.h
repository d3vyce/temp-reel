#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Taskset{
    int Cn;
    int Dn;
    int Tn;
}Taskset;

int test_load(Taskset tache[], int nb_tache);
int get_busy_period(Taskset tache[], int i);
int get_nb_critical_job(Taskset tache[], int i, int bp);
int get_responce_time(Taskset tache[], int i, int k);
int get_worst_case_responce_time(Taskset tache[], int i);
int get_responce_time_preemptive(Taskset tache[], int i, int k, int nb_tache);
int get_worst_case_responce_time_preemptive(Taskset tache[], int i, int nb_tache);

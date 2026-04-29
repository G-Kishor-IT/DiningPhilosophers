#include "deadlock.h"
#include "forks.h"
#include "config.h"
#include <stdio.h>
#include <pthread.h>

void pick_up_forks(int philosopher_id) {
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    int first_fork, second_fork;

    if (left_fork < right_fork) {
        first_fork = left_fork;
        second_fork = right_fork;
    } else {
        first_fork = right_fork;
        second_fork = left_fork;
    }

    pthread_mutex_lock(&forks[first_fork]);
    printf("Philosopher %d picked up fork %d\n", philosopher_id + 1, first_fork + 1);

    pthread_mutex_lock(&forks[second_fork]);
    printf("Philosopher %d picked up fork %d\n", philosopher_id + 1, second_fork + 1);
}

void release_forks(int philosopher_id) {
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;
    pthread_mutex_unlock(&forks[left_fork]);
    pthread_mutex_unlock(&forks[right_fork]);
    
    printf("Philosopher %d released forks\n", philosopher_id + 1);
}

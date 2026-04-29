#include "forks.h"
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t forks[NUM_PHILOSOPHERS];

void init_forks() {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        if (pthread_mutex_init(&forks[i], NULL) != 0) {
            perror("Failed to initialize fork mutex");
            exit(EXIT_FAILURE);
        }
    }
}

void destroy_forks() {
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }
}

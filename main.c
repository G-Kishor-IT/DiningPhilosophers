#include "config.h"
#include "forks.h"
#include "philosopher.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    srand(time(NULL));

    printf("Starting Deadlock-Aware Dining Philosophers Simulation...\n");
    printf("Rule: Philosophers must pick up the lower-numbered fork first.\n\n");

    init_forks();

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        if (pthread_create(&philosophers[i], NULL, philosopher_lifecycle, &philosopher_ids[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    destroy_forks();

    return EXIT_SUCCESS;
}

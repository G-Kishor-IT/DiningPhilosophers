#include "philosopher.h"
#include "deadlock.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* philosopher_lifecycle(void* arg) {
    int id = *((int*)arg);

    while (1) {
        printf("Philosopher %d is thinking\n", id + 1);
        sleep(rand() % 3 + 1);

        pick_up_forks(id);

        printf("Philosopher %d is eating\n", id + 1);
        sleep(rand() % 3 + 1);

        release_forks(id);
    }

    return NULL;
}

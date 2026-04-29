#ifndef FORKS_H
#define FORKS_H

#include <pthread.h>
#include "config.h"

extern pthread_mutex_t forks[NUM_PHILOSOPHERS];

void init_forks();
void destroy_forks();

#endif

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ITERATIONS 1000000

//shared and unsynchronized
long counter = 0;

void *worker(void *arg)
{
	int i;

	for (i = 0; i < ITERATIONS; i++)
		counter++; //not atomic

	return NULL;
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	int i;

	for (i = 0; i < NUM_THREADS; i++)
		pthread_create(&threads[i], NULL, worker, NULL);

	for (i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	printf("expected: %d, got: %ld\n", NUM_THREADS * ITERATIONS, counter);
	return 0;
}

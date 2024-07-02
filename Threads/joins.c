#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NTHREADS 10

void *thread_func(void *);
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void main()
{
    pthread_t thread_id[NTHREADS];
    int i, j;

    for(i = 0; i < NTHREADS; i++)
    {
        /* create a new thread */
        pthread_create(&thread_id[i], NULL, thread_func, NULL);
    }

    for(j = 0; j < NTHREADS; j++)
    {
        /* wait for termination of another thread */
        pthread_join(thread_id[j], NULL);
    }

    /* At this points i watied for all threads to be completed due to join */
    printf("Final Counter value %d\n", counter);
}

void *thread_func(void *ptr)
{
    /* return identifier of current thread */
    printf("Thrad number %ld\n", pthread_self());
    pthread_mutex_lock(&mutex);
    counter++;
    pthread_mutex_unlock(&mutex);
}
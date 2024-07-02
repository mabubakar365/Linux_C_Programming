#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *func(void *ptr);

int mutex_counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void main(void)
{
    int tret[10];
    pthread_t thread[10];

    const char *message1[10] = {"Thread1", "Thread2", "Thread3", "Thread4", "Thread5", "Thread6", "Thread7", "Thread8", "Thread9", "Thread10"};

    for(int i = 0; i < 10; i++)
    {
        tret[i] = pthread_create(&thread[i], NULL, func, (void *) message1[i]);
        if(tret[i])
        {
            printf("%d thread creation failed %d\n", i, tret[i]);
        }
    }

    for(int  i = 0; i < 10; i++)
    {
        pthread_join(thread[i], NULL);
    }
    
    exit(EXIT_SUCCESS);
}

void *func(void *ptr)
{
    /* When a mutex lock is attempted against a mutex which is held by another thread, the thread is blocked until the mutex is unlocked. When a thread terminates, the mutex does not unless explicitly unlocked. Nothing happens by default. */
    /*  acquire a lock on the specified mutex variable. If the mutex is already locked by another thread, this call will block the calling thread until the mutex is unlocked. */
    pthread_mutex_lock(&mutex);
    mutex_counter++;
    printf("mutex_counter value %d\n", mutex_counter);
    printf("%s\n", (char *)ptr);
    /* unlock a mutex variable. An error is returned if mutex is already unlocked or owned by another thread. */
    pthread_mutex_unlock(&mutex);
    /* pthread_mutex_trylock() attempt to lock a mutex or will return error code if busy. Useful for preventing deadlock conditions. */
}
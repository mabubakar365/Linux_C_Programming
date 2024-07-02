#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message_function(void * ptr);

void *print_message_function(void * ptr)
{
    char *message;
    message = (char *) ptr;
    printf("%s\n", message);
}

int main(void)
{
    pthread_t thread1, thread2;

    const char *message1 = "Thread1";
    const char *message2 = "Thread2";

    int tret1, tret2;

    /* Create a new thread */
    tret1 = pthread_create(&thread1, NULL, print_message_function, (void *)message1);
    if(tret1)
    {
        fprintf(stderr, "Error - pthread_create() return code %d\n", tret1);
        exit(EXIT_FAILURE);
    }

    /* Create a new thread */
    tret2 = pthread_create(&thread2, NULL, print_message_function, (void *)message2);
    if(tret2)
    {
        fprintf(stderr, "Error - pthread_create() return code %d\n", tret2);
        exit(EXIT_FAILURE);
    }

    printf("pthread_create() for thread 1 returns %d\n", tret1);
    printf("pthread_create() for thread 2 returns %d\n", tret2);

    /* Main thread waits for the termination of thread1 */
    pthread_join(thread1, NULL);
    /* Main thread waits for the termination of thread2 */
    pthread_join(thread2, NULL);

    exit(EXIT_SUCCESS);

    return 0;
}
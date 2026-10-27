#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
void* func(void *arg) {
    int *ptr = (int *) arg;  /* get the argument: thread id */
    printf("Thread %d \n", *ptr);  /* print the thread id */
}

int main(void) {
    int errcode, i = 0; int *ptr;

    /* Create two pthreads */
    for (i=0; i < 2; i++) {
        ptr = (int *) malloc (sizeof(int));
        *ptr = i;
        errcode = pthread_create(&(tid[i]), NULL,
                            &func, ptr);
        if (errcode)
            printf("Error in creating pthreads \n");
    }

    /* Wait for the two pthreads to finish and join */
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
}

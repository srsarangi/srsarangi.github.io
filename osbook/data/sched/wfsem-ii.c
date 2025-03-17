#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <assert.h>

#define BUFSIZE 10
#define INC(x) ((x+1)%BUFSIZE)
#define WAIT(x) (sem_wait(& x))
#define POST(x) (sem_post(& x))
#define NUM_THREADS 4
#define NUM 40

pthread_t tid[NUM_THREADS];
volatile int queue[BUFSIZE];
volatile int head=0, tail=0;
sem_t qlock, empty, full;

void nap(){
    struct timespec rem;
    int ms = rand() % 100;
    struct timespec req = {0, ms * 1000 * 1000};
    nanosleep(&req, &rem);
}

int enq (int val) {
    int status;

    WAIT(empty);
    WAIT(qlock);

    queue[tail] = val;
    tail = INC(tail);
    printf ("Enqueued %d\n", val);

    POST(qlock);
    POST(full);

    return 0;
}

int deq () {
    int val;

    WAIT(full);
    WAIT(qlock);

    val = queue[head];
    head =INC(head);
    printf ("Dequeued %d\n", val);

    POST(qlock);
    POST(empty);

    return val;
}

void * enqfunc (void *arg) {
    int i, val;
    int thread = *((int *) arg);
    srand(thread);

    for (i=0; i< NUM; i++){
       val = rand()%10;
       enq (val);
       nap();
    }
}

void * deqfunc (void *arg){
    int i, val;
    int thread = *((int *) arg);
    srand(thread);

    for (i=0; i< NUM; i++){
       val = deq();
       nap();
    }
}

int main() {
    int errcode, i = 0; int *ptr;
    void* (*fptr) (void*); 
    sem_init (&qlock, 0, 1);
    sem_init (&empty, 0, BUFSIZE);
    sem_init (&full, 0, 0);
    assert(NUM_THREADS%2 == 0);

    for (i=0; i < NUM_THREADS; i++)
    {
        ptr = (int *) malloc (sizeof(int));
        *ptr = i;
        fptr = (i%2)? &enqfunc : &deqfunc;

        errcode = pthread_create(&(tid[i]), NULL,
                fptr, ptr);
        if (errcode)
            printf("Error in creating pthreads \n");
    }

    for(i=0; i < NUM_THREADS; i++)
        pthread_join (tid[i], NULL);

    sem_destroy(&qlock);
    sem_destroy(&empty);
    sem_destroy(&full);
}

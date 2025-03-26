#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdatomic.h>
#include <time.h>
#include <assert.h>

#define BUFSIZE 10
#define INC(x) ((x+1)%BUFSIZE)
#define LOCK(x) (pthread_mutex_lock(& x))
#define UNLOCK(x) (pthread_mutex_unlock(& x))
#define NUM_THREADS 4
#define NUM 25

pthread_t tid[NUM_THREADS];
pthread_mutex_t qlock;
volatile int queue[BUFSIZE];
volatile int head=0, tail=0;

void nap(){
    struct timespec rem;
    int ms = rand() % 100;
    struct timespec req = {0, ms * 1000 * 1000};
    nanosleep(&req, &rem);
}


int enq (int val) {
    int status;

    do {
        LOCK(qlock);
        if ( INC(tail) == head) status = -1;
        else {
            queue[tail] = val;
            tail = INC(tail);
            status = 0;
        }
        UNLOCK(qlock);
    } while (status == -1); 

    printf ("Enqueued %d\n", val);
    return status;
}

int deq () {
    int val;
    int status = -1;

    do {
        LOCK (qlock);
        if (tail == head) status = -1;
        else {
            status = 0;
            val = queue[head];
            head = INC(head);
        }
        UNLOCK (qlock);
    } while (status == -1);

    printf ("Dequeued %d\n", val);
    return val;
}

void* enqfunc (void *arg) {
    int i, val;
    int thread = *((int *) arg);
    srand(thread);

    for (i=0; i< NUM; i++){
       val = rand()%10;
       enq (val);
       nap();
    }
}

void* deqfunc (void *arg){
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
    pthread_mutex_init (&qlock, NULL); 
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

    for (i=0; i< NUM_THREADS; i++)
        pthread_join (tid[i], NULL);
    pthread_mutex_destroy (&qlock);
}

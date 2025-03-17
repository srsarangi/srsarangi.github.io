#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <assert.h>

#define BUFSIZE 10
#define INC(x) ((x+1)%BUFSIZE)
#define LOCK(x) (sem_wait(& x))
#define UNLOCK(x) (sem_post(& x))
#define NUM_THREADS 4
#define NUM 25

pthread_t tid[NUM_THREADS];
volatile int queue[BUFSIZE];
volatile int head=0, tail=0;
sem_t qlock;

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
            printf ("Enqueued %d\n", val);
        }
        UNLOCK(qlock);
    } while (status == -1); 

    return status;
}

int deq () {
    int val;

    do {
        LOCK (qlock);
        if (tail == head) val = -1;
        else {
            val = queue[head];
            head = INC(head);
            printf ("Dequeued %d\n", val);
        }
        UNLOCK (qlock);
    } while (val == -1);

    return val;
}

void * enqfunc (void *arg) {
    int i, val;
    int thread = *((int *) arg);
    srand(thread);

    for (i=0; i< NUM; i++){
       val = rand()%10;
       enq(val);
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
    void * (*fptr) (void*); 
    sem_init (&qlock, 0, 1);
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
}

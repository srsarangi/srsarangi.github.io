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
#define NUM_THREADS 6
#define NUM 40


pthread_t tid[NUM_THREADS];
volatile int queue[BUFSIZE];
volatile int head=0, tail=0, readers=0;
sem_t rwlock, read_lock, full, empty;

void nap(){
    struct timespec rem;
    int ms = rand() % 100;
    struct timespec req = {0, ms * 1000 * 1000};
    nanosleep(&req, &rem);
}

void get_write_lock(){
    WAIT(rwlock);
}
void release_write_lock(){
    POST(rwlock);
}
void get_read_lock(){
    WAIT(read_lock);
    if (readers == 0)
        WAIT(rwlock);
    readers++;
    POST(read_lock);
}

void release_read_lock(){
    WAIT(read_lock);
    readers--;
    if (readers == 0) 
        POST (rwlock);
    POST(read_lock);
}

int enq (int val) {
    int status;

    WAIT(empty);

    get_write_lock();
    queue[tail] = val;
    tail = INC(tail);
    printf ("Enqueued %d\n", val);
    release_write_lock();

    POST(full);

    return 0;
}

int deq () {
    int val;

    WAIT(full);

    get_write_lock();
    val = queue[head];
    head =INC(head);
    printf ("Dequeued %d\n", val);
    release_write_lock();

    POST(empty);
    return val;
}

int peak() {
    /* This is the read function */
    get_read_lock();
    int val = (head == tail)? -1 : queue[head];
    printf ("Queue head = %d\n",val);
    release_read_lock();

    return val;
}

void* peakfunc (void *arg) {
    int i, val;

    for (i=0; i< NUM; i++){
       val = peak();
       nap();
    }
}


void* enqfunc (void *arg) {
    int i, val;
    int tid = *((int *) arg);
    srand(tid);

    for (i=0; i< NUM; i++){
       val = rand()%10;
       enq (val);
       nap();
    }

    printf ("All enqueues done \n");
}

void* deqfunc (void *arg){
    int i, val;
    int tid = *((int *) arg);

    for (i=0; i< NUM; i++){
       val = deq();
       nap();
    }

    printf ("All dequeues done \n");
}

int main() {
    int errcode, i = 0; int *ptr;
    void * (*fptr) (void*); 
    sem_init (&rwlock, 0, 1);
    sem_init (&read_lock, 0, 1);
    sem_init (&empty, 0, BUFSIZE);
    sem_init (&full, 0, 0);

    assert (NUM_THREADS % 3 == 0);


    for (i=0; i < NUM_THREADS; i++)
    {
        ptr = (int *) malloc (sizeof(int));
        *ptr = i;
        switch (i%3) {
            case 0:
                fptr = &enqfunc;
                break;
            case 1:
                fptr = &deqfunc;
                break;
            case 2:
                fptr = &peakfunc;
                break;
        }

        errcode = pthread_create(&(tid[i]), NULL,
                fptr, ptr);
        if (errcode)
            printf("Error in creating pthreads \n");
    }

    for (i=0; i < NUM_THREADS; i++)
            pthread_join (tid[i], NULL);

    sem_destroy(&rwlock);
    sem_destroy(&read_lock);
    sem_destroy(&full);
    sem_destroy(&empty);
}

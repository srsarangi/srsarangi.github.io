#include <stdio.h>
#include <stdatomic.h>

atomic_int count = 0;
#define CAS atomic_compare_exchange_strong

int main(){
    int oldval = atomic_load (&count) + 7; 
    int newval = oldval + 1;
    printf ("count = %d, old = %d, new = %d \n", count, oldval, newval); 
    CAS (&count, &oldval, newval);
    printf ("count = %d, old = %d, new = %d \n", count, oldval, newval); 
}

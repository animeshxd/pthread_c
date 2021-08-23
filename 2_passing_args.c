//Passing arguments to function
#include <bits/pthread_types.h> //pthread_t
#include <pthread.h> //pthread_create, pthread_join
#include <unistd.h> //sleep
#include <stdio.h>

void * fun_in_thread(void * arg){
    int * var = (int *) arg;

    for (int i = 0; i < 5; i++) {
	*var += 2;
	printf("var is now: %d\n", *var);
	sleep(2);
    }
    printf("\nvar is now : %d\n", *var);
    return NULL;
}
int main(){
    
    pthread_t  newthread;
    int var = 5;
    pthread_create(&newthread, NULL, fun_in_thread, &var);
    pthread_join(newthread, NULL);
 
    return 0;
}


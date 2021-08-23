#include <bits/pthread_types.h> //pthread_t
#include <stdio.h>
#include <pthread.h> //pthread_create, pthread_join
#include <unistd.h> //sleep

void *  you(void * arg){ // We are going to run in other thread

    while (1) {
	puts("You are ...\n");
	sleep(2);
    }
    return NULL;
}

void me(){ // we are going to run in main
    while (1) {
	sleep(2);
	puts("I am ...");
    }
}


int main(){
    pthread_t new_thread;
    pthread_create(&new_thread, NULL,          you,                   NULL);
                  //new_thread, attr, , void * func(void * arg), void * arg param func
   // pthread_create(pthread_t *__pthread_ptr, const pthread_attr_t *__attr, void *(*__start_routine)(void *), void *)
    
    me();

    pthread_join(new_thread, NULL); //it will wait for new_thread to complete in main
    //pthread_join(pthread_t __pthread, void **__return_value_ptr)


    return 0;
}

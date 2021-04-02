/* Name: Herschelle Gupta
   Roll_Number: 2019045 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int myVariable = 10;

void *myThreadChild(void *arg) {
	while(myVariable > -90) {
		myVariable--;
		printf("child thread: value of variable = %d\n", myVariable);
	}
    pthread_exit(NULL);
    return NULL;
}

void *myThreadParent(void *arg) {
    while(myVariable < 100) {
        myVariable++;
        printf("Parent thread: value of variable = %d\n", myVariable);
    }
    pthread_exit(NULL);
    return NULL;	
}

int main() {
    pthread_t thread_id_child, thread_id_parent;

    pthread_create(&thread_id_child, NULL, myThreadChild, (void *) &thread_id_child);
    pthread_create(&thread_id_parent, NULL, myThreadParent, (void *) &thread_id_parent);

    pthread_join(thread_id_parent, NULL);
    pthread_join(thread_id_child, NULL);

    exit(0);
}
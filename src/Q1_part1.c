/* Name: Herschelle Gupta
   Roll_Number: 2019045 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int myVariable = 10;

int main() {
    int f = fork();
    if(f == 0) {
        while (myVariable > -90) {
            printf("Child process: value of variable = %d\n", myVariable);
            myVariable--;
        }
    }
    else if(f > 0) {
        while (myVariable < 100) {
            printf("Parent process: value of variable = %d\n", myVariable);
            myVariable++;
        }
    }
    return 0;
}


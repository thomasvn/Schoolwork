#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main () {
	int i;
	int result;

	for (i = 0; i < 16; i++) {

		/*
 			fork()
			On Success:
				Child PID returned in parent's thread of execution
				Child PID = 0 returned in child's thread of execution
			On Failure:
				Child PID = -1 returned in parent's thread of execution
		*/

		result = fork();

		// Handle Error
		if (result == -1) {
			printf("Process had an issue creating a child. Out of memory.");
		}

		// This is the parent
		if (result != 0) {
			exit(0);
		}

		// This is the Child
		else {
			printf("Created child process number: %d \n", i+1);
			printf("CHILD PID: %d \n", getpid());
			printf("PARENT PID: %d \n", getppid());
		}
		
	}

	exit(0);

	return 0;
}

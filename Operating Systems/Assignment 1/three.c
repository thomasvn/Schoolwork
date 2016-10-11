#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main () {
	int i;
	int child1;
	int child2 = '\0';
	int child3;
	int child2PID;

	for (i = 0; i < 9; i++) {
		printf("\n");

		/*
 			fork()
			On Success:
				Child PID returned in parent's thread of execution
				Child PID = 0 returned in child's thread of execution
			On Failure:
				Child PID = -1 returned in parent's thread of execution
		*/

		// Only forks if this is the initial fork or if this is the child2
		if (getpid() == child2PID || child2 == '\0') {
			child1 = fork();
		}
		// Error Handling
		if (child1 == -1) {
			printf("Process had an issue creating a child. Out of memory.");
		}

		// This is the parent of child1
		if (child1 != 0) {
			child2 = fork();

			// Error Handling
			if (child2 == -1) {
				printf("Process had an issue creating a child. Out of memory.");
			}

			// This is the parent of child1 AND child2
			if (child2 != 0) {
				// Create & exit out of third child on last iteration
				if (i == 8) {
					child3 = fork();
					if (child3 != 0) {
						exit(0);
					}
					printf("Created child3. Iteration Number: %d \n", i+1);
					printf("CHILD PID: %d \n", getpid());
					printf("PARENT PID: %d \n", getppid());
					if (child3 == 0) {
						exit(0);
					}
				}
				else {
						exit(0);
				}
			}

			// This code is applied to child2
			else {
				child2PID = getpid();
				printf("Created child2. Iteration Number: %d \n", i+1);
				printf("CHILD PID: %d \n", getpid());
				printf("PARENT PID: %d \n", getppid());
				continue;
			}
		}

		// This is the first child created
		else {
			printf("Created child1. Iteration Number: %d \n", i+1);
			printf("CHILD PID: %d \n", getpid());
			printf("PARENT PID: %d \n", getppid());
			exit(0);
		}

	}

	//exit(0);

	return 0;
}

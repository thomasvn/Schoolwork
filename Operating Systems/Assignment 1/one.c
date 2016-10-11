#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main () {
	int status;

	while (1) {
		// Read the Command from the User
		char command[100];
		char *parameter[100];

		printf("Enter your command: ");
		scanf("%s", command);

		// Check to see if the user wants to exit
		if (strcmp(command,"exit") == 0) {
			break;
		}

		// If it is a parent process, wait for child to die
		if (fork() != 0) {
			waitpid(-1, &status, 0);
		} else {
			execve (command, 0, 0);
		}
	}

	return 0;
}

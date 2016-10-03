// Thomas Nguyen
// Coen 146
// Monday 2:15 - 5:00

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// Listen

int main(int argc, char*argv[]) {

	// Variables needed for program
	char buffer[50];
	char username[20];
	char otherUsername[20];
	int i = 0;

	// Opens the Socket
	struct sockaddr_in si_server;
	
	// Clears any pre-existing data in socket
	bzero((char*) &si_server, sizeof(si_server));
	
	// Specifies which protocol family that tells user what kind of
	// addresses our socket can communicate with
	si_server.sin_family = AF_INET;

	// Default address	
	si_server.sin_addr.s_addr=INADDR_ANY;
	
	// Port number hard coded to 56781
	si_server.sin_port=htons(56781);

	// Specifies properties of socket (IPv4, Datagram, Reg. Protocol)
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	// Binds ports between clients and servers
	bind (sockfd, (struct sockaddr*) &si_server, sizeof(si_server));

	printf("Please enter your username: ");
	fgets(username, sizeof(username), stdin);

	// Receive other user's name
	int len = sizeof(si_server);
	recvfrom(sockfd, otherUsername, 20, 0, (struct sockaddr*)& si_server, &len);
	
	// Sends this user's name to the server
	sendto(sockfd, username, 20, 0, (struct sockaddr*)& si_server, sizeof(si_server));


	while (1) {
		// Receives Message from OTHER USER
		int len = sizeof(si_server);
		recvfrom(sockfd, buffer, 50, 0, (struct sockaddr*)& si_server, &len); 

		// Checks to see if OTHER USER wants to quit
		if (strcmp("quit\n", buffer) == 0) {
			break;
		}

		// Prints OTHER USERNAME
		i=0;
		while (otherUsername[i] != '\0') {
			printf("%c", otherUsername[i]);
			i++;
		}
	
		// Prints Message from OTHER USER
		i = 0;
		while (buffer[i] != '\0') {
			printf("%c", buffer[i]);
			i++;
		}

		printf("\n");

		// Prints THIS USERNAME
		i = 0;
		while (username[i] != '\0') {
			printf("%c", username[i]);
			i++;
		}
		
		// Takes in input for the message
		fgets(buffer, sizeof(buffer), stdin);

		printf("\n");
		
		// Sends buffer to server
		sendto(sockfd, buffer, 50, 0, (struct sockaddr*)& si_server, sizeof(si_server));
		
		// Checks to see if THIS USER wants to quit
		if (strcmp("quit\n", buffer) == 0) {
			break;
		}


	}
	return 0;
}










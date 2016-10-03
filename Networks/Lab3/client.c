// Thomas Nguyen
// Coen 146
// Monday 2:15 - 5:00 pm

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// TalkTo

int main(int argc, char* argv[]) {
	// Host Name passed as first argument
	if (argc != 2) {
		printf("Incorrect number of arguments");
	}

	// Variables needed for program
	char buffer[50];
	char username[20];
	char otherUsername[20];
	int i = 0;

	// Assigns Host Name and Opens Socket
	struct hostent *server;
	struct sockaddr_in si_server;
	server = gethostbyname(argv[1]);

	// Removes pre-existing data
	bzero((char*) &si_server, sizeof (si_server));
	
	// Specifies which protocol family that tells user what kind of
	// addresses our socket can communicate with
	si_server.sin_family = AF_INET;

	// Copies Byte Sequence (Copies from hostend structure to sockaddr_in)
	bcopy((char*)server->h_addr,(char*)&si_server.sin_addr,server->h_length);
	
	// Port Number hardcoded to 56781
	si_server.sin_port=htons(56781);
	
	// Specifications on what kind of socket we want (IPv4, Datagram, Reg. Protocol)
	int sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	// Enter Username
	printf("Please enter your username: ");
	fgets(username, sizeof(username), stdin);

	// Sends this user's name to server
	sendto(sockfd, username, 20, 0, (struct sockaddr*)& si_server, sizeof(si_server));

	// Receive other user's name
	int len = sizeof(si_server);
	recvfrom(sockfd, otherUsername, 20, 0, (struct sockaddr*)& si_server, &len);
			
	while (1) {
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
		
		// Checks to see if THIS USER  wants to Quit
		if (strcmp("quit\n", buffer) == 0) {
			break;
		}
	
		// Receives Message from OTHER USER
		int len = sizeof(si_server);
		recvfrom(sockfd, buffer, 50, 0, (struct sockaddr*)& si_server, &len);
			
		// Checks to see if OTHER USER wants to Quit
		if (strcmp("quit\n", buffer) == 0) {
			break;
		}
	
		// Prints OTHER USERNAME
		i=0;
		while(otherUsername[i] != '\0') {
			printf("%c", otherUsername[i]);
			i++;
		}
			
		// Prints Message from OTHER USERNAME
		i = 0;
		while (buffer[i] != '\0') {
			printf("%c", buffer[i]);
			i++;
		}

		printf("\n");
		
	}
	
	return 0;
}










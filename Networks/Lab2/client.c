#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// Client

int main(int argc, char* argv[]) {
	// Host Name passed as first argument
	// File Name passed as second argument
	// Output File Name passed as third argument
	if (argc != 4) {
		printf("Incorrect number of arguments");
	}

	// Variables needed for program
	char buffer[50];
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


	// Read File
	FILE *fp = fopen(argv[2], "r");
	if (fp == NULL) {
		printf("File Pointer is NULL");
		return (-1);
	}
	
	// Copies File into buffer
	if (fgets (buffer, 50, fp) == NULL) {
		printf("Could not read file");
		return (-1);
	}

	fclose (fp);

	// Sends buffer to server
	sendto(sockfd, buffer, 50, 0, (struct sockaddr*)& si_server, sizeof(si_server));

	// Sends output file name to server
	sendto(sockfd, argv[3], 20, 0, (struct sockaddr*)& si_server, sizeof(si_server));	
	
	return 0;
}










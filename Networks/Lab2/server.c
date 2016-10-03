#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// Server

int main(int argc, char*argv[]) {


	// Variables needed for program
	char buffer[50];
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

	int len = sizeof(si_server);

	// Receives buffer through socket
	recvfrom(sockfd, buffer, 50, 0, (struct sockaddr*)& si_server, &len); 
	
	// Creates a new file called output.txt and prepares to write to it
	FILE *fp = fopen("output.txt", "w");

	// Writes to output.txt
	while (buffer[i] != '\0') {
		fputc(buffer[i], fp);	
		i++;
	}

	fclose(fp);

	return 0;
}










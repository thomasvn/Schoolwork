// Thomas Nguyen
// Coen 146
// Monday 2:15 - 5:00

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// Server

typedef struct packet {
	int seqNum;
	char data[30];
	int checksum;
} packets;

int main(int argc, char*argv[]) {

	// Variables needed for program
	int i = 0;
	int serverSeqNum = 0;
	packets *pack;
	pack = malloc(sizeof(packets));

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

	while (1) {
		// Receives packet from client
		int len = sizeof(si_server);
		recvfrom(sockfd, pack, sizeof(packets), 0, (struct sockaddr*)& si_server, &len);

		// Print contents of packet
		printf("Original Message: ");
		i = 0;
		while (pack->data[i] != '\0') {
			printf("%c", pack->data[i]);
			i++;
		}
		
		printf("Number of Characters: %d \n", i);


		// Checks to see if proper CheckSum
		if (pack->checksum != 17) {
			printf("Checksum Value: %d", pack->checksum);
			printf(" is incorrect. Should be 17 \n");	
		}
		else {
			printf("Checksum Value: %d is correct\n", pack->checksum);
		}	
	
		// Checks to see if the seqNum is correct	
		if (serverSeqNum == pack->seqNum) {
			printf("seqNum of %d is correct \n", pack->seqNum);
		}
		else {
			printf("seqNum of %d is incorrect, should be %d \n", pack->seqNum, serverSeqNum);
		}

		// Increments the Sequence Number (Expected & Actual)
		pack->seqNum = (pack->seqNum)++;
		serverSeqNum++;

		// Converts message to uppercase
		i = 0;
		while (pack->data[i]) {
			pack->data[i]=toupper(pack->data[i]);
			i++;
		}

		printf ("\n");

		sendto(sockfd, pack, sizeof(packets), 0, (struct sockaddr*)& si_server, sizeof(si_server));
	}

	return 0;
}










// Thomas Nguyen
// Coen 146
// Monday 2:15 - 5:00 pm

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// Client

typedef struct packet {
	int seqNum;
	char data[30];
	int checksum;
} packets;


int main(int argc, char* argv[]) {
	// Host Name passed as first argument
	if (argc != 2) {
		printf("Incorrect number of arguments");
	}

	// Variables needed for program
	int i = 0;
	packets *pack;
	pack = malloc(sizeof(packets));

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

	// Instantiate values for the packet seqNum and checkSum
	pack->seqNum = 0;
	pack->checksum=17;

	for (i = 0; i < 5; i++) {
		// Client enters string
		printf("Please enter your sentence: ");
		
		if (fgets(pack->data, 30, stdin) == '\0') {
			printf("Error, message not read");
		}

		// Send packet to the server
		sendto(sockfd, pack, sizeof(packets), 0, (struct sockaddr*)& si_server, sizeof(si_server));

		// Does not send another packet until it receives confirmation
		int len = sizeof(si_server);
		recvfrom(sockfd, pack, sizeof(packets), 0, (struct sockaddr*)& si_server, &len);
		
		printf("Received Message: %s\n",pack->data);	

	}
	
	return 0;

}

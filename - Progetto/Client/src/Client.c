/*********************************************************************************
 *  Title: Lab - Reti di Calcolatori (INF) aa 21-22                              *
 *  Year:  2021                                                                  *
 *  Description: TCP client/server application,                                  *
 *  			 where the server is a remote calculator                         *
 *  			 that responds to client requests                                *
 *  Author:	Francesco de Gioia											         *
 *                                                                               *
 *********************************************************************************/

#include "protocol.h"

#include <float.h>

// Syntax check of the inserted operation
char verification(char input_string[]) {
	char bool = 't';
	char point = 'f';
	char space = 'f';
	if (strlen(input_string) < 5) bool = 'f';
	for (int i = 0; i < strlen(input_string) && bool == 't'; i++) {
		if ((i == 0)
				&& (input_string[i] != '+' && input_string[i] != '-'
						&& input_string[i] != '*' && input_string[i] != '/'))
			bool = 'f';
		if ((i == 1) && (input_string[i] != ' '))
			bool = 'f';
		if ((i > 1) && (input_string[i] < '0' || input_string[i] > '9'))
			bool = 'f';
		if ((i == 2) && (input_string[i] == '-') && (input_string[i+1] >= '0' && input_string[i+1] <= '9'))
			bool = 't';
		if ((i > 2) && (input_string[i] == '.') && (point == 'f')) {
			point = 't';
			bool = 't';
		}
		if ((i > 2) && (input_string[i] == ' ') && (space == 'f')) {
			space = 't';
			point = 'f';
			bool = 't';
			if (input_string[i + 1] == '.' || (i == (strlen(input_string) - 1)))
				bool = 'f';
			if (input_string[i + 1] == '-')
				i++;
		}
		if ((i == (strlen(input_string) - 1))
				&& ((space == 'f') || input_string[i] == '-'))
			bool = 'f';
	}
	return bool;
}

int main(void) {

#if defined WIN32
	WSADATA wsa_data;
	int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (result != 0) {
		printf("error at WSASturtup\n");
		return -1;
	}
#endif

	// SOCKET CREATION
	int c_socket;
	c_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (c_socket < 0) {
		errorhandler("socket creation failed.\n");
		system("pause");
		closesocket(c_socket);
		clearwinsock();
		return -1;
	}

	// CONSTRUCTION OF THE SERVER ADDRESS
	struct sockaddr_in sad;
	int port = 0;
	char portProv[6];
	char addr[16];
	memset(&sad, 0, sizeof(sad));
	sad.sin_family = AF_INET;
	printf("Enter an IP address or press ENTER to set a default IP: ");
	gets(addr);
	if (strcmp(addr, "") == 0)
		strcpy(addr, DEFAULTIP);
	sad.sin_addr.s_addr = inet_addr(addr); // IP server
	printf("Enter a port number or press ENTER to set a default port: ");
	gets(portProv);
	if (strcmp(portProv, "") == 0)
		port = PROTOPORT; // use default port number
	else
		port = atoi(portProv);
	sad.sin_port = htons(port); // Server port
	// CONNECTION TO THE SERVER
	if (connect(c_socket, (struct sockaddr*) &sad, sizeof(sad)) < 0) {
		errorhandler("Failed to connect.\n");
		system("pause");
		closesocket(c_socket);
		clearwinsock();
		return -1;
	} else
		printf("Connection established with %s:%i\n", addr, port);

	// INPUT ASSIGNMENT
	char input_string[BUFFERSIZE]; // String to send
	int string_len;
	char bool;
	do {
		do {
			bool = 't';
			printf("Enter an operation or = to exit: ");
			gets(input_string);
			fflush(stdin);
			if (strcmp(input_string, "=") != 0)
				bool = verification(input_string);
			if (bool == 'f')
				printf("Invalid operation! Syntax example: + 23 45\n");
		} while (bool == 'f');
		string_len = strlen(input_string); // Determine the length
		input_string[string_len] = '\0';
		string_len++;
		// SEND DATA TO THE SERVER
		if (send(c_socket, input_string, string_len, 0) != string_len) {
			errorhandler("send() sent a different number of bytes than expected");
			closesocket(c_socket);
			clearwinsock();
			return -1;
		}
		// RECEIVE TOTAL TO THE SERVER
		if (input_string[0] != '=') {
			float tot;
			char conf[5] = "\0";
			recv(c_socket, &tot, BUFFERSIZE, 0);
			gcvt(tot, 3, conf);
			if (strcmp(conf, "1.#J") == 0 || strcmp(conf, "-1.#J") == 0 || strcmp(conf, "-nan") == 0 ||
					strcmp(conf, "nan") == 0 || strcmp(conf, "1.#INF00") == 0 || strcmp(conf, "-1.#IND00") == 0 ||
					strcmp(conf, "-1.#IND") == 0 || strcmp(conf, "1.$NaN") == 0)
				printf("Math Error\n");
			else{
				int intpart = (int)tot;
				float decpart = tot - intpart;

				if(decpart == 0.000) printf("Total: %i\n", (int)tot);
				else printf("Total: %0.2f\n", tot);
			}

		}
	} while (input_string[0] != '=');
	// CLOSING THE CONNECTION
	closesocket(c_socket);
	clearwinsock();
	printf("\n"); // Print a final line feed
	system("pause");
	return EXIT_SUCCESS;
}

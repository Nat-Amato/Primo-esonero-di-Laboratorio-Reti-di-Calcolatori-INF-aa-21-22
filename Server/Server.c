/*********************************************************************************
 *  Title: Lab - Reti di Calcolatori (INF) aa 21-22                              *
 *  Year:  2021                                                                  *
 *  Description: TCP client/server application,                                  *
 *  			 where the server is a remote calculator                 *
 *  			 that responds to client requests                        *
 *  Author:	Natale Amato			                                 *
 *                                                                               *
 *********************************************************************************/
#include "protocol.h"

float add(float a, float b) {
	return a + b;
}

float sub(float a, float b) {
	return a - b;
}

float mult(float a, float b) {
	return a * b;
}

float division(float a, float b) {
	return a / b;
}

// Extrapolates the numbers from the string coming from the client
void extrap(char output[], char input[], int n) {
	if (n == 1) {
		for (int i = 2; input[i] != ' '; i++)
			strncat(output, &input[i], 1);
	} else {
		int i;
		for (i = 2; input[i] != ' '; i++)
			;
		i++;
		for (; i < strlen(input); i++)
			strncat(output, &input[i], 1);
	}
}

int main(void) {

	int port;
	char portProv[6];
	do {
		printf("Enter a port number or press ENTER to set a default port: ");
		gets(portProv);
		if (strcmp(portProv, "") == 0)
			port = PROTOPORT; // use default port number
		else
			port = atoi(portProv);
		if (port < 49152 || port > 65535)
			printf(
					"Bad port number %i, please insert a port number between 49152 and 65535 \n",
					port);
	} while (port < 49152 || port > 65535);

#if defined WIN32 // initialize Winsock
	WSADATA wsa_data;
	int result = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	if (result != 0) {
		errorhandler("Error at WSAStartup()\n");
		return 0;
	}
#endif

	// SOCKET CREATION
	int my_socket;
	my_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (my_socket < 0) {
		errorhandler("socket creation failed.\n");
		system("pause");
		clearwinsock();
		return -1;
	}

	// ASSIGNING A SOCKET ADDRESS
	struct sockaddr_in sad;
	char addr[16];
	memset(&sad, 0, sizeof(sad)); // ensures that extra bytes contain 0
	sad.sin_family = AF_INET;
	printf("Enter an IP address or press ENTER to set a default IP: ");
	gets(addr);
	if (strcmp(addr, "") == 0)
		strcpy(addr, DEFAULTIP);
	sad.sin_addr.s_addr = inet_addr(addr);
	sad.sin_port = htons(port); /* converts values between the host and
	 network byte order. Specifically, htons() converts 16-bit quantities
	 from host byte order to network byte order. */
	if (bind(my_socket, (struct sockaddr*) &sad, sizeof(sad)) < 0) {
		errorhandler("bind() failed.\n");
		system("pause");
		closesocket(my_socket);
		clearwinsock();
		return -1;
	}

	// SETTING LISTENING SOCKET
	if (listen(my_socket, QLEN) < 0) {
		errorhandler("listen() failed.\n");
		system("pause");
		closesocket(my_socket);
		clearwinsock();
		return -1;
	}

	// ACCEPT A NEW CONNECTION
	struct sockaddr_in cad; // structure for the client address
	int client_socket; // socket descriptor for the client
	int client_len; // the size of the client address
	printf("IP: %s	Port: %i\n", inet_ntoa(sad.sin_addr), ntohs(sad.sin_port));
	printf("Waiting for a client to connect...\n");
	while (1) {
		client_len = sizeof(cad); // set the size of the client address
		if ((client_socket = accept(my_socket, (struct sockaddr*) &cad,
				&client_len)) < 0) {
			errorhandler("accept() failed.\n");
			system("pause");
			// CLOSING THE CONNECTION
			closesocket(client_socket);
			clearwinsock();
			return 0;
		}
		printf("Connection established with %s:%i\n", inet_ntoa(cad.sin_addr),
				ntohs(cad.sin_port));
		char buf[BUFFERSIZE];
		char strRecv[BUFFERSIZE] = "\0";
		float num1, num2, tot;
		do {
			// RECEIVE OPERATION
			recv(client_socket, buf, BUFFERSIZE, 0);
			if (buf[0] != '=') {
				extrap(strRecv, buf, 1);
				num1 = atof(strRecv);
				memset(strRecv, 0, sizeof(strRecv));
				extrap(strRecv, buf, 2);
				num2 = atof(strRecv);
				memset(strRecv, 0, sizeof(strRecv));
				// OPERATION DEVELOPMENT
				if (buf[0] == '+')
					tot = add(num1, num2);
				if (buf[0] == '-')
					tot = sub(num1, num2);
				if (buf[0] == '*')
					tot = mult(num1, num2);
				if (buf[0] == '/')
					tot = division(num1, num2);
				// SEND TOTAL
				if (send(client_socket, &tot, sizeof(float), 0) != sizeof(float)) {
					errorhandler("send() sent a different number of bytes than expected\n");
					buf[0] = '=';
				}

			}

		} while (buf[0] != '=');
	} // end-while

	return EXIT_SUCCESS;
}

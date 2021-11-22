/*********************************************************************************
 *  Title: Lab - Reti di Calcolatori (INF) aa 21-22                              *
 *  Year:  2021                                                                  *
 *  Description: TCP client/server application,                                  *
 *  			 where the server is a remote calculator                 *
 *  			 that responds to client requests                        *
 *  Author:	Francesco de Gioia					         *
 *                                                                               *
 *********************************************************************************/

#ifndef PROTOCOL_H_
#define PROTOCOL_H_

#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h> // for atoi()
#include <string.h>
#define BUFFERSIZE 512
#define PROTOPORT 60000 // default protocol port number
#define QLEN 5 // size of request queue
#define DEFAULTIP "127.0.0.1" // default IP

void errorhandler(char *errorMessage) {
	printf ("%s", errorMessage);
}
void clearwinsock() {
	#if defined WIN32
	WSACleanup();
	#endif
}

#endif /* PROTOCOL_H_ */

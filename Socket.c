
#if defined WIN32
#include <winsock.h>
#else
	#define closesocket close
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <unistd.h>
#endif

#include "Socket.h"

int Initialize() {
#if defined WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	return iResult;
#endif

	return 0; //no initialization needed for Unix based
}

void ClearWinSock() {
#if defined WIN32
	WSACleanup();
#endif
}

char * GetIPAddress(Socket mySocket) {
	struct sockaddr_in cad;
	int cadLen = sizeof(cad);

	getsockname(mySocket, (struct sockaddr *) &cad, &cadLen);

	return inet_ntoa(cad.sin_addr);
}

int GetPortNumber(Socket mySocket) {
	struct sockaddr_in cad;
	int cadLen = sizeof(cad);

	getsockname(mySocket, (struct sockaddr *) &cad, &cadLen);

	return (int) (ntohs(cad.sin_port));
}

Socket Create(){
	Socket mySocket;
	mySocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	return mySocket;
}

int Send(Socket receiver, char * string) {
	int stringLen = strlen(string);

	if (send(receiver, string, stringLen, 0) != stringLen)
		return -1;

	return 0;
}

int Receive(Socket sender, char * buffer, int bufferSize){
	return recv(sender, buffer, bufferSize - 1, 0);
}

void Close(Socket mySocket) {
	closesocket(mySocket);
}

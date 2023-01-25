#if defined WIN32
#include <winsock.h>
#else
	#define closesocket close
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <unistd.h>
#endif

#include "ServerSocket.h"

int Listen(ServerSocket mySocket, int qLen) {
	return listen(mySocket, qLen);
}

int Bind(ServerSocket mySocket, char * ip, int port) {
	struct sockaddr_in sad;
	memset(&sad, 0, sizeof(sad));
	sad.sin_family = AF_INET;
	sad.sin_addr.s_addr = inet_addr("127.0.0.1");
	sad.sin_port = htons(port);

	return bind(mySocket, (struct sockaddr*) &sad, sizeof(sad));
}

ClientSocket Accept(ServerSocket mySocket) {
	struct sockaddr_in cad;
	int clientLen;

	clientLen = sizeof(cad);

	return accept(mySocket, (struct sockaddr *) &cad, &clientLen);
}

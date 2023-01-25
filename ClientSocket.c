#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#include "ClientSocket.h"

int Connect(ClientSocket mySocket, char * ip, int port) {
	struct sockaddr_in sad;
	memset(&sad, 0, sizeof(sad));
	sad.sin_family = AF_INET;
	sad.sin_addr.s_addr = inet_addr(ip);
	sad.sin_port = htons(port);

	return connect(mySocket, (struct sockaddr *) &sad, sizeof(sad));
}

int ConnectByName(ClientSocket mySocket, char * name, int port) {
	struct hostent *host;

	host = gethostbyname(name);
	if (host == NULL)
		return -1;
	else {
		struct in_addr* ina = (struct in_addr*) host->h_addr_list[0];
		struct sockaddr_in sad;
		memset(&sad, 0, sizeof(sad));
		sad.sin_family = AF_INET;
		sad.sin_addr.s_addr = ina->s_addr;
		sad.sin_port = htons(port);

		return connect(mySocket, (struct sockaddr *) &sad, sizeof(sad));
	}
}

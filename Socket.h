#ifndef SOCKET_H_
#define SOCKET_H_

typedef int Socket;

int Initialize();
char * GetIPAddress(Socket );
int GetPortNumber(Socket );
void ClearWinSock();
Socket Create();
int Send(Socket receiver, char * string);
int Receive(Socket sender, char * buffer, int bufferSize);
void Close(Socket mySocket);

#endif /* SOCKET_H_ */




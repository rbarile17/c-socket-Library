#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_

typedef int ClientSocket;

int Connect(ClientSocket , char * , int );
int ConnectByName(ClientSocket , char * , int );

#endif /* CLIENTSOCKET_H_ */

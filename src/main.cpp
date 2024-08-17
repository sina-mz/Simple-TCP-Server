#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(int argc, char* argv[]) {
	std::cout << "Basic TCP server.\n";
	const int PORT_NUMBER = 1010;

	int fd_serverSocket, fd_clientSocket; // File Descriptors for server and the incoming client(s)
	struct sockaddr_in servAddr;
	struct sockaddr_in clienAddr;

	// create a socket for server (sockets are treated like files, so it's a File Descriptor)
	fd_serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	// we need to bind the socket with an IP address
	// so let's create an IP address:
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = INADDR_ANY;
	servAddr.sin_port = htons(PORT_NUMBER);

	// bind the socket to the configure IP address above
	int status = bind(fd_serverSocket, (struct sockaddr*) &servAddr, sizeof(struct sockaddr_in));

	// start listening to new connections
	status = listen(fd_serverSocket, 1);

	// wait and accept one client
	unsigned int theSize = sizeof(clienAddr);
	fd_clientSocket = accept(fd_serverSocket, (struct sockaddr*) &clienAddr, &theSize);


	return 0;
}

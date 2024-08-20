#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
// for read() func
#include <unistd.h>

int main(int argc, char* argv[]) {
	std::cout << "Basic TCP server.\n";
	const int PORT_NUMBER = 1222;

	int fd_serverSocket, fd_clientSocket; // File Descriptors for server and the incoming client(s)
	struct sockaddr_in servAddr;
	struct sockaddr_in clienAddr;

	// create a socket for server (sockets are treated like files, so it's a File Descriptor)
	fd_serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	std::cout << "socket fd: " << fd_serverSocket << std::endl;

	// we need to bind the socket with an IP address
	// so let's create an IP address:
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = INADDR_ANY;
	servAddr.sin_port = htons(1222);

	// bind the socket to the configure IP address above
	int status = bind(fd_serverSocket, (struct sockaddr*) &servAddr, sizeof(struct sockaddr));
	if (status < 0) {std::cout << "Error binding socket to address. EC: " << status << std::endl; return 1; };

	// start listening to new connections
	status = listen(fd_serverSocket, 1);
	if (status < 0) {std::cout << "Error on listening via socket"; return 1; };

	// wait and accept one client
	unsigned int theSize = sizeof(clienAddr);
	fd_clientSocket = accept(fd_serverSocket, (struct sockaddr*) &clienAddr, &theSize);

	if (fd_clientSocket >= 0) {
	   std::cout << "A client connected... Data:\n" ;

		char buf[512];
		read(fd_clientSocket, buf,99);
		buf[100]='\0';
		std::cout << buf << std::endl;
		std::cout << "Reading done.\n";
	}

	return 0;
}

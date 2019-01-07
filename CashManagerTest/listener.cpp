#include "listener.h"
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#endif

#define PORT_LISTEN 8085

using namespace std;

Listener::Listener()
{

}

void Listener::run() {
    while(1) {
        listenForClient();
    }
}

void Listener::listenForClient() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        exit(EXIT_FAILURE);
    }
#ifdef SO_REUSEPORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, (char *)&opt, sizeof(opt))) {
        exit(EXIT_FAILURE);
    }
#endif
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT_LISTEN);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        exit(EXIT_FAILURE);
    }
    read(new_socket, buffer, 1024);
    string message = string(buffer);
    string id = message.substr(1,3);
    string name, content;
    if (id != "rnc") {
        content = message.substr(message.find_first_of("/") + 1);
        //TODO appeler fonction création produit depuis code
    }
    close(server_fd);
}

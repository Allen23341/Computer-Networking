#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char buffer[50], IP[20];
    int listenfd, connfd;
    socklen_t length;
    struct sockaddr_in serverAddress, clientAddress;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listenfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    /*
    inet_ntop(AF_INET, (struct sockaddr*)&serverAddress, IP, sizeof(serverAddress));
    printf("%s\n", IP);
    */
    listen(listenfd, 1);
    int num = 0;
    while(1)
    {
        length = sizeof(clientAddress);
        connfd = accept(listenfd, (struct sockaddr*)&clientAddress, &length);
        write(connfd, "Hello World!\n", 13);
        printf("%d\n", (num += 1));
        close(connfd);
    }
}
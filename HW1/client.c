#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char buffer[50];
    int sockfd;
    struct sockaddr_in serverAddress;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(5000);
    

    printf("==================\n");

    inet_pton(AF_INET, argv[1], &serverAddress.sin_addr);
    connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    printf("==================\n");
        
    bzero(buffer, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);
    close(sockfd);
}
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("error args!\n"); 
        exit(0); 
    }

/// creat socket 
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0); 
    if (socket_fd < 0) {
        perror("socket()"); 
        exit(EXIT_FAILURE); 
    }

/// set server 
    struct sockaddr_in local; 
    bzero(&local, sizeof(local)); 
    local.sin_family = AF_INET; 
    local.sin_addr.s_addr = inet_addr(argv[1]);  // local ip
    local.sin_port = htons(atoi(argv[2]));       // local port 

/// bind socket and local 
    int ret = bind(socket_fd, (struct sockaddr*)&local, sizeof(struct sockaddr)); 
    if (ret < 0) {
        perror("bind"); 
        exit(EXIT_FAILURE); 
    }

    char buf[128]; 
    bzero(buf, sizeof(buf)); 

    struct sockaddr_in client; 
    bzero(&client, sizeof(struct sockaddr_in)); 
    int clen = sizeof(struct sockaddr); 

    ret = recvfrom(socket_fd, buf, sizeof(buf), 0, (struct sockaddr*)&client, &clen); 
    if (ret < 0) {
        perror("recvfrom()"); 
        exit(EXIT_FAILURE); 
    }
    printf("Client: IP = %s, Port = %d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port)); 
    printf("%s\n", buf); 

    ret = sendto(socket_fd, "Wellcome!", 10, 0, (struct sockaddr*)&client, sizeof(struct sockaddr)); 
    if (ret < 0) {
        perror("sendto()"); 
        exit(EXIT_FAILURE); 
    }

    close(socket_fd); 
    unlink(argv[1]); 

    return 0; 
}

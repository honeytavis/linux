#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("error args!\n"); 
        exit(0); 
    }

/// creat socket 
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0); // UDP
    if (socket_fd < 0) {
        perror("socket()"); 
        exit(EXIT_FAILURE); 
    }

/// set server 
    struct sockaddr_in server; 
    bzero(&server, sizeof(server)); 
    server.sin_family = AF_INET; 
    server.sin_addr.s_addr = inet_addr(argv[1]);  // server ip
    server.sin_port = htons(atoi(argv[2]));	  // server port

    int ret = sendto(socket_fd, "Hello?", 10, 0, (struct sockaddr*)&server, sizeof(struct sockaddr)); 
    if (ret < 0) {
        perror("sendto()"); 
        exit(EXIT_FAILURE); 
    }

    char buf[128]; 
    bzero(buf, sizeof(buf)); 
    struct sockaddr_in local; 
    bzero(&local, sizeof(struct sockaddr_in)); 

    int clen = sizeof(struct sockaddr); 
    ret = recvfrom(socket_fd, buf, sizeof(buf), 0, (struct sockaddr*)&local, &clen); 
    if (ret < 0) {
        perror("recvfrom()"); 
        exit(EXIT_FAILURE); 
    }
    printf("Server: IP = %s, Port = %d\n", inet_ntoa(local.sin_addr), ntohs(local.sin_port)); 
    printf("%s\n", buf);
    
    close(socket_fd); 

    return 0; 
}

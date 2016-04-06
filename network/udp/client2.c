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
    server.sin_port = htons(atoi(argv[2]));	      // server port

    char buf[128]; 
    struct sockaddr_in local; 
    fd_set rdset; 
    for (;;) {
        FD_ZERO(&rdset); 
        FD_SET(0, &rdset); 
        FD_SET(socket_fd, &rdset); 

        int ret = select(socket_fd+1, &rdset, NULL, NULL, NULL); 
        if (ret > 0) {
            if (FD_ISSET(0, &rdset)) {
                bzero(buf, sizeof(buf)); 
                read(0, buf, sizeof(buf)); 
                ret = sendto(socket_fd, buf, strlen(buf)-1, 0, \
                    (struct sockaddr*)&server, sizeof(struct sockaddr)); 
                if (-1 == ret) {
                    perror("sendto()"); 
                    exit(EXIT_FAILURE); 
                }
            }

            if (FD_ISSET(socket_fd, &rdset)) {
                bzero(buf, sizeof(buf)); 
                bzero(&local, sizeof(struct sockaddr_in)); 
                int clen = sizeof(struct sockaddr); 
                ret = recvfrom(socket_fd, buf, sizeof(buf), 0, \
                    (struct sockaddr*)&local, &clen); 
                if (-1 == ret) {
                    perror("recvfrom()"); 
                    exit(EXIT_FAILURE); 
                }
                printf("%s\n", buf);
            }
        }
    }
    
    close(socket_fd); 

    return 0; 
}

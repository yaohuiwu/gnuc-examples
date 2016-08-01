/*
 Created by yaohui on 16-8-1.
*/

#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>

#define BACKLOG 10

/*
* init a server sock that listen at a port and specified addr
*/
int init_server(int port, u_int32_t addr){
    int s_sock_fd, one = 1;
    struct sockaddr_in s_addr;

    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons((uint16_t)port);
    s_addr.sin_addr.s_addr = htonl(addr);

    s_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(s_sock_fd == -1){
        printf("create socket failed\n");
        close(s_sock_fd);
        return -1;
    }
    if (setsockopt(s_sock_fd, SOL_SOCKET, SO_REUSEADDR,
                   (char *)&one, sizeof(one)) < 0) {
        printf("set sockopt failed\n");
        close(s_sock_fd);
        return -1;
    }

    if(bind(s_sock_fd, (struct sockaddr *)&s_addr, sizeof(s_addr)) == -1){
        printf("bind failed\n");
        close(s_sock_fd);
        return -1;
    }

    if(listen(s_sock_fd, BACKLOG) == -1){
        printf("listen failed\n");
        close(s_sock_fd);
        return -1;
    }

    return s_sock_fd;
}


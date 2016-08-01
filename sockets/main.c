#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int init_server(int port, u_int32_t addr);
//remove '\r' or '\n' at end of the str. It's the caller's responsibility to free the return *char.
char * rstrip(char s[], int len);

//
// Created by yaohui on 16-8-1.
//
int main(int argc, char ** argv){

    int port;

    if(argc <= 1){
        printf("usage: ./echo_server port\n");
        return -1;
    }
	port = atoi(argv[1]);
	if(port == 0){
		printf("bad port: %s\n", argv[1]);
		return -1;
	}
    printf("port is %d\n", port);

    int server_sock_fd = init_server(port, INADDR_ANY);
    if(server_sock_fd == -1){
        return -1;
    }

    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t socklen = sizeof(client_addr);

    while(1){
        int con = accept(server_sock_fd, (struct sockaddr *)&client_addr, &socklen);
        if(con < 0){
            printf("accept failed");
            close(con);
            return -1;
        }

        printf("recv client connection %s %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while(1){
            memset(buffer, 0, sizeof(buffer));
            ssize_t len = recv(con, buffer, sizeof(buffer), 0);
            char *word = rstrip(buffer, (int)len);
            if(strcmp(word, "exit") == 0){
                free(word);
                break;
            }
            free(word);
            fputs(buffer, stdout);
            send(con, buffer, (size_t)len, 0);
        }
        printf("closing client");
        fflush(stdout);
        close(con);
    }
//
//    clean:
//    printf("bye!\n");
//    close(server_sock_fd);
//
//	return 0;
}

char * rstrip(char s[], int len){
    int i;
    for(i=len-1; i>=0; i--){
        if(!(s[i] == '\n' || s[i] == '\r')){
            break;
        }
    }
    char *nc = malloc(sizeof(char) * (i+2));
    nc[i+2] = '\0';
    int j;
    for(j=0;j<=i;j++){
        nc[j] = s[j];
    }
    return nc;
}

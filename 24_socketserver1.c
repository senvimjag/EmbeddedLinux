#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define PORT 8080
int main(){
    int ser, soc;
    struct sockaddr_in add;
    char buf[1024] = {0};
    ser = socket(AF_INET, SOCK_STREAM, 0); //Create a socket
    add.sin_family = AF_INET;
    add.sin_addr.s_addr = INADDR_ANY;
    add.sin_port = htons(PORT);
    bind(ser, (struct sockaddr *)&add, sizeof(add)); //Bind socket
    listen(ser, 3); //Listen
    printf("Server waiting for connection...\n");
    soc = accept(ser, NULL, NULL); //Accept
    recv(soc, buf, sizeof(buf), 0); //Receive
    printf("Message from client: %s\n", buf);
    close(soc); //Close socket
    close(ser); 
    return 0;
}


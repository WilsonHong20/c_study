#include"mysocket.h"

#define BUFFER_SIZE 1024

#define SERVER_ADDRESS "127.0.0.1"
#define PORT 8888
#define BUFFER_SIZE 1024
int main(){
    int client_fd;
    struct  sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    // 创建socket
    client_fd = socket(AF_INET,SOCK_STREAM,0);
    if(client_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    // 连接服务器
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_addr.sin_port = htons(PORT);
    if(connect(client_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server, address=%s\n",SERVER_ADDRESS);
    
    // 发送数据
    strcpy(buffer,"Hello, server!");
    send(client_fd,buffer,strlen(buffer),0);
    
    // 接收响应
    ssize_t n = recv(client_fd,buffer,BUFFER_SIZE,0);
    if(n > 0)
    {
        buffer[n] = '\0';
        printf("Received message: %s\n",buffer);
    }


    // 关闭连接
    close(client_fd);
}
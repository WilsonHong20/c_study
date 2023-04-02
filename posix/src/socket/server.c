#include"mysocket.h"

#define PORT 8888
#define BUF_SIZE 1024

int main(){
    int server_fd,client_fd;

    struct  sockaddr_in server_addr,client_addr;
    char buffer[BUF_SIZE];

    //创建socket
    server_fd = socket(AF_INET,SOCK_STREAM,0);
    if(server_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    //绑定地址和端口
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)) == -1){
        perror("bind");
        exit(EXIT_FAILURE);
    }
    //监听连接请求
    if(listen(server_fd,5) == -1){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started,listening on port %d ...\n",PORT);


    //接受连接请求
    socklen_t client_len = sizeof(client_addr);

    client_fd = accept(server_fd,(struct sockaddr*)&client_addr,&client_len);
    if(client_fd == -1){
        perror("accpet");
        exit(EXIT_FAILURE);
    }
    printf("Client connected,address=%s\n",inet_ntoa(client_addr.sin_addr));


    //接受数据
    while (1)
    {       
        ssize_t n = recv(client_fd,buffer,BUF_SIZE,0);
        if(n <= 0)
        {
            break;
        }
        buffer[n] = '\0';
        printf("Received message: %s\n",buffer);

        //发送响应
        strcpy(buffer,"Hello Client!");
        send(client_fd,buffer,strlen(buffer),0);
    }
    //关闭连接
    close(server_fd);
    close(client_fd);
    return 0;
}
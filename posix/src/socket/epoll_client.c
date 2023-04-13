/**
该客户端程序首先创建一个TCP socket，并将它设置为非阻塞模式。然后它使用connect()函数连接到服务器，如果连接不能立即建立，则它会返回EINPROGRESS错误。

接下来，该客户端程序创建一个epoll实例，并将client_fd加入到epoll监听列表中，以便在可读和可写事件发生时得到通知。在主循环中，程序调用epoll_wait()函数等待事件发生，并在事件发生时处理它们。如果可读事件发生，则程序使用recv()函数读取服务端发送的数据，并将其显示在终端上。如果可写事件发生，则程序使用send()函数向服务端发送一条简单的消息。

当服务端关闭连接或发生错误时，程序会退出主循环，关闭socket并退出。

请注意，此示例程序仅用于演示目的。在实际应用中，您应该添加错误处理以及其他
*/
#include"mysocket.h"
#define MAX_EVENTS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 12345

int main(int argc, char **argv){
    int client_fd, epoll_fd, nfds, n;
    struct epoll_event ev, events[MAX_EVENTS];
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    bool running = true;

    //创建TCP socket
    if((client_fd = socket(AF_INET, SOCK_STREAM, 0))){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    //设置socket为非阻塞模式
    if(fcntl(client_fd, F_SETFL, fcntl(client_fd, F_GETFL, 0)| O_NONBLOCK) < 0){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    //设置服务器IP地址和端口号
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    //连接服务器
    if(connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        if(errno != EINPROGRESS){
            perror("connect");
            exit(EXIT_FAILURE);
        }
    }

    //创建epoll实例并将client_fd加入到epoll监听列表中
    if((epoll_fd = epoll_create1(0)) < 0){
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }
    ev.events = EPOLLIN | EPOLLOUT | EPOLLET;
    ev.data.fd = client_fd;
    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev) < 0){
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    //开始监听
    while (running)
    {
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if(nfds < 0){
            perror("epoll wait");
            exit(EXIT_FAILURE);
        }
        for(n = 0; n < nfds; ++n){
            if(events[n].events & EPOLLIN){
                //可读事-件
                int bytes_read = recv(events[n].data.fd, buffer, BUFFER_SIZE, 0);
                if(bytes_read <= 0){
                    //服务器关闭连接或发生错误
                    printf("Server disconnected\n");
                    running = false;
                }else{
                    //显示服务器发送的数据
                    buffer[bytes_read] = '\0';
                    printf("Received message from server: %s\n", buffer);
                }
            }else if(events[n].events & EPOLLOUT){
                //可写事件
                const char *message = "Hello World!";
                if(send(events[n].data.fd, message, strlen(message), 0) < 0){
                    perror("send");
                    exit(EXIT_FAILURE);
                }
            }else{
                //出错或连接关闭事件
                printf("Server disconnected\n");
                running = false;
            }
        }
    }
    //关闭socket
    close(client_fd);
    return 0;
}
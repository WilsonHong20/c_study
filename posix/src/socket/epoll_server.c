#include"mysocket.h"

#define MAX_EVENTS 10
#define BUFFER_SIZE 1024
#define PORT 12345

int main(int argc,char **argv)
{
    int server_fd,client_fd,epoll_fd,nfds,n;
    struct epoll_event ev,events[MAX_EVENTS];
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr,client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    bool running = true;

    //创建TCP socket
    if((server_fd = socket(AF_INET,SOCK_STREAM,0)) < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    //设置socket为非阻塞模式
    if(fcntl(server_fd, F_SETFL, fcntl(server_fd, F_GETFL, 0) | O_NONBLOCK) < 0){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    
    //绑定IP地址和端口号
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0){
        perror("bind");
        exit(EXIT_FAILURE);
    }

    //监听端口
    if(listen(server_fd, 5) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //创建epoll实例并将server_fd加入到epoll监听列表中
    if((epoll_fd = epoll_create1(0)) < 0){
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }
    ev.events = EPOLLIN;
    ev.data.fd = server_fd;
    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev) < 0){
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    //开始监听
    while (running)
    {
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if(nfds < 0){
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (n = 0; n < nfds; ++n)
        {
            if(events[n].data.fd == server_fd){
                //接受新的连接
                if((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len)) < 0){
                    perror("accept");
                    exit(EXIT_FAILURE);
                }

                //将新连接加入到epoll监听列表中
                ev.events = EPOLLIN | EPOLLRDHUP;
                ev.data.fd = client_fd;
                if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev) < 0){
                    perror("epoll_ctl");
                    exit(EXIT_FAILURE);
                }

                printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            }else
            {
                //处理已连接的客户端
                if(events[n].events & EPOLLRDHUP){
                    //客户端关闭连接
                    printf("Client disconnected\n");
                    close(events[n].data.fd);
                }else
                {
                    //接收客户端发送的数据
                    int bytes_read = recv(events[n].data.fd, buffer, BUFFER_SIZE, 0);
                    if(bytes_read <= 0){
                        //客户端关闭连接或发生错误
                        printf("Client disconnected\n");
                        close(events->data.fd);
                    }else{
                        //回显客户端发送的数据
                        buffer[bytes_read] = '\0';
                        printf("Received message from client: %s\n", buffer);
                        send(events->data.fd, buffer, bytes_read, 0);
                    }
                }
            }
        }
    }
    //关闭socket 
    close(server_fd);
    return 0;
}
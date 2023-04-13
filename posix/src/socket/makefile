

.PHONY:build_socket build_epoll clean
build_socket:
	gcc -o server server.c  -I../../include/
	gcc -o client client.c  -I../../include/

build_epoll:

	gcc -o epoll_server epoll_server.c  -I../../include/
	gcc -o epoll_client epoll_client.c  -I../../include/
clean:
	rm -rf client server epoll_server epoll_client
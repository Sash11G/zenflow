#ifndef LINUX_SOCKET_UTILS_H
#define LINUX_SOCKET_UTILS_H

int setup_server_socket(int port);
int accept_client(int server_fd);

#endif


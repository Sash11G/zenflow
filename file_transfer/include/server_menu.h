#ifndef SERVER_MENU_H
#define SERVER_MENU_H

#include <netinet/in.h>
#include <stdbool.h>

typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info;

extern client_info clients[];
extern int client_count;
extern bool server_running;
    
void *handle_client(void *arg);
void send_menu(int client_socket);
void *server_menu_thread(void *arg);

#endif


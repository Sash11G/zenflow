#include "server_menu.h"
#include "config.h"
#include "linux_socket_utils.h"
#include <unistd.h>
int main() {
    int server_fd = setup_server_socket(PORT);
    if (server_fd < 0) return 1;

    int client_fd = accept_client(server_fd);
    if (client_fd < 0) return 1;

    run_server_menu(client_fd);

    close(client_fd);
    close(server_fd);
    return 0;
}

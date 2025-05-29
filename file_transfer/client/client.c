
#include "client.h"
#include "../include/config.h"
#include "win_socket_utils.h"

int main() {
    int sockfd = connect_to_server("127.0.0.1", PORT);  // Replace with actual IP
    if (sockfd < 0) return 1;

    run_client_menu(sockfd);

    closesocket(sockfd);
    WSACleanup();
    return 0;
}

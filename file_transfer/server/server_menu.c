
#include "server_menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include "transfer.h"
#include "config.h"

void run_server_menu(int client_fd) {
    int choice;
    // char filename[128];

    while (1) {
        printf("\n--- Server Menu ---\n");
        printf("1. View connected client\n");
        printf("2. Send file to client\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n'); // clear input
            continue;
        }
        while (getchar() != '\n'); // clear newline

        switch (choice) {
            case 1:
                printf("Client is connected on socket %d\n", client_fd);
                break;

            case 2:
                printf("Sending file to client...\n");
                if (send_text_file(client_fd, "example.txt") == 0)
                    printf("File sent.\n");
                else
                    printf("Failed to send file.\n");
                break;

            case 3:
                printf("Exiting server...\n");
                return;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}


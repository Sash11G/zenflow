
#include "transfer.h"
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <winsock2.h>

void run_client_menu(SOCKET sockfd) {

    int choice;
    char filename[128];

    while (1) {
        printf("1. Send file\n");
        printf("2. Wait to receive file\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;

                send(sock, "CMD:SEND_FILE", strlen("CMD:SEND_FILE"), 0);
                if (send_file(sock, filename) == 0)
                    printf("File sent.\n");
                else
                    printf("Failed to send.\n");
                break;

            case 2:
                printf("Waiting to receive file...\n");
                if (receive_text_file(sockfd, "received.txt") == 0)
                    printf("File received.\n");
                else
                    printf("Failed to receive file.\n");
                break;

            case 3:
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}
    


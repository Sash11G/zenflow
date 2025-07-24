
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5001
#define BUF_SIZE 4096

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUF_SIZE];
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "192.168.1.2", &servaddr.sin_addr); // Change to your phone's IP

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

    fp = fopen("file_to_send.txt", "rb");
    if (!fp) { perror("fopen"); exit(1); }

    int bytes;
    while ((bytes = fread(buffer, 1, BUF_SIZE, fp)) > 0) {
        send(sockfd, buffer, bytes, 0);
    }

    fclose(fp);
    close(sockfd);
    printf("File sent.\n");
    return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "transfer.h"
#include "config.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#define PATH_SEP '\\'
#else
#include <sys/socket.h>
#include <unistd.h>
#define PATH_SEP '/'
#endif


int send_text_file(int sock, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen (send)");
        return -1;
    }

    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        send(sock, buffer, (int)bytes_read, 0);
    }

    fclose(fp);
    return 0;
}

int receive_text_file(int sock, const char *output_name) {
    FILE *fp = fopen(output_name, "wb");
    if (!fp) {
        perror("fopen (receive)");
        return -1;
    }

    char buffer[1024];
    int bytes;
    while ((bytes = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes, fp);
        if (bytes < sizeof(buffer)) break;  // assume end of file
    }

    fclose(fp);
    return 0;
}


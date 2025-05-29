#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define CHUNK_SIZE 1024



// Struct to hold client information
typedef struct {
    int socket;
    struct sockaddr_in address;
} client_info;

client_info clients[MAX_CONNECTIONS];
int client_count = 0;

void *handle_client(void *arg);
void send_menu(int client_socket);
void send_file(int client_socket);
void receive_file(int client_socket);

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t client_thread;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Main loop to accept connections
    while (1) {
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Add client to the list
        if (client_count < MAX_CONNECTIONS) {
            clients[client_count].socket = client_socket;
            clients[client_count].address = client_addr;
            client_count++;
        }

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        // Create a new thread for the client
        pthread_create(&client_thread, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024] = {0};
    
    // Send the menu to the client
    send_menu(client_socket);

    while (1) {
        // Receive option from client
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Client chose option: %s", buffer);

        if (strcmp(buffer, "send") == 0) {
            send_file(client_socket);
        } else if (strcmp(buffer, "1\n") == 0) {
            receive_file(client_socket);
        } else if (strcmp(buffer, "exit") == 0) {
            break;
        }

        // Send the menu again after the operation
        send_menu(client_socket);
    }

    // Close the client connection
    close(client_socket);
    printf("Client disconnected\n");
    return NULL;
}

void send_menu(int client_socket) {
    char *menu = "Choose an option:\n1. Send file\n2. Receive file\n3. Exit\n";
    send(client_socket, menu, strlen(menu), 0);
}

void send_file(int client_socket) {
    char filename[256];
    FILE *file;
    size_t bytes_read;
    char buffer[1024];

    // Ask for file to send
    send(client_socket, "Enter the filename to send: ", 26, 0);
    recv(client_socket, filename, sizeof(filename), 0);

    file = fopen(filename, "rb");
    if (file == NULL) {
        send(client_socket, "File not found", 14, 0);
        return;
    }

    // Send the file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    fclose(file);
    send(client_socket, "File transfer complete.", 23, 0);
}
/*
void receive_file(int client_socket) {
    char filename[256];
    FILE *file;
    size_t bytes_received;
    char buffer[1024];

    // Ask for filename to receive
    send(client_socket, "Enter the filename to receive: ", 30, 0);
    recv(client_socket, filename, sizeof(filename), 0);

    file = fopen(filename, "wb");
    if (file == NULL) {
        send(client_socket, "Failed to create file", 21, 0);
        return;
    }

    // Receive the file
    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    send(client_socket, "File received successfully.", 26, 0);
}
*/



void receive_file(int client_sock) {
    char filename[256] = {0};
    char buffer[CHUNK_SIZE] = {0};

    // Receive filename first
    int bytes_received = recv(client_sock, filename, sizeof(filename), 0);
    if (bytes_received <= 0) {
        perror("Failed to receive filename");
        return;
    }
    filename[bytes_received] = '\0';
    printf("Receiving file: %s\n", filename);

    // Open file for writing (Linux will create it if not exists)
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return;
    }

    // Receive file content
    while (1) {
        bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) break;

        // Check for EOF marker
        if (bytes_received == 3 && memcmp(buffer, "EOF\n", 3) == 0) {
            break;
        }

        fwrite(buffer, 1, bytes_received, file);
    }

    fclose(file);
    printf("File received successfully: %s\n", filename);
}


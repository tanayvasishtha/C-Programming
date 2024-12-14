/*1. Design a connection oriented concurrent chat server using fork () in C where the
server will serve multiple chart clients simultaneously. When the chat server receives a
“logout” message from a particular client then it terminates the respective connection
with that chat client.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define MAX_MSG_SIZE 1024   

int clients[MAX_CLIENTS];
int client_count = 0;


void handle_client(int client_socket) {
    char buffer[MAX_MSG_SIZE];
    int read_size;
    while ((read_size = recv(client_socket, buffer, MAX_MSG_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client: %s\n", buffer);
        if (strcmp(buffer, "logout") == 0) {
            break;
        }
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

void handle_sigchld(int sig) {
    int status;
    while (waitpid(-1, &status, WNOHANG) > 0);
}
void handle_new_connection(int server_socket) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
    if (client_socket < 0) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }
    if (client_count >= MAX_CLIENTS) {
        printf("Maximum number of clients reached. Connection rejected.\n");
        close(client_socket);
        return;
    }
    clients[client_count++] = client_socket;
    printf("New connection accepted. Client socket: %d\n", client_socket);
    pid_t pid = fork();
    if (pid < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        close(server_socket);
        handle_client(client_socket);
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(client_socket);
        signal(SIGCHLD, handle_sigchld);
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started. Listening on port %d\n", PORT);

    while (1) {
        handle_new_connection(server_socket);
    }

    return 0;
}
    
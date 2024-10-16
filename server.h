#ifndef SERVER_H
#define SERVER_H

#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT "8080"
#define BUFFSIZE 1025
#define RESPONSE_SIZE 4024

const char *get_mime_type(char *file_path);
void handle_client(int client_fd);
int create_server_socket();

#endif

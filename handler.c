#include "server.h"

void handle_client(int client_fd) {
  char buff[BUFFSIZE] = {0};
  char method[10], path[255], protocol[10];
  char response[RESPONSE_SIZE] = {0};
  char file_path[512] = {0};

  read(client_fd, buff, BUFFSIZE);
  sscanf(buff, "%s %s %s", method, path, protocol);

  if (strcmp(method, "GET") == 0) {
    if (strcmp(path, "/") == 0) {
      strcpy(file_path, "index.html");
    } else {
      strcpy(file_path, path + 1);
    }

    int file_fd = open(file_path, O_RDONLY);
    if (file_fd == -1) {
      sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
      write(client_fd, response, strlen(response));
      return;
    }

    struct stat file_stat;
    fstat(file_fd, &file_stat);

    const char *mime_type = get_mime_type(file_path);

    sprintf(
        response,
        "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n",
        mime_type, file_stat.st_size);

    write(client_fd, response, strlen(response));

    ssize_t read_bytes;
    while ((read_bytes = read(file_fd, buff, BUFFSIZE)) > 0) {
      write(client_fd, buff, read_bytes);
    }

    close(file_fd);
  } else {
    sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
    write(client_fd, response, strlen(response));
  }

  write(client_fd, response, strlen(response));
}

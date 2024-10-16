#include "server.h"

int create_server_socket() {
  struct addrinfo hints, *res, *p;
  int status, sock_fd;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  if ((status = getaddrinfo(NULL, PORT, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return -1;
  }

  for (p = res; p != NULL; p = p->ai_next) {
    if ((sock_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) ==
        -1) {
      perror("socket");
      continue;
    }

    if (bind(sock_fd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sock_fd);
      perror("bind");
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "failed to bind\n");
    return -1;
  }

  freeaddrinfo(res);

  if (listen(sock_fd, 10) == -1) {
    perror("listen");
    return -1;
  }

  return sock_fd;
}

int main() {
  int sock_fd, client_fd;

  if ((sock_fd = create_server_socket()) == -1) {
    return 1;
  }

  printf("listening on port %s\n", PORT);

  while (1) {
    struct sockaddr_storage client_addr;
    socklen_t addr_size = sizeof client_addr;
    char client_ip[INET6_ADDRSTRLEN];

    if ((client_fd = accept(sock_fd, (struct sockaddr *)&client_addr,
                            &addr_size)) == -1) {
      perror("accept");
      continue;
    }

    handle_client(client_fd);

    close(client_fd);
  }

  close(sock_fd);
  return 0;
}

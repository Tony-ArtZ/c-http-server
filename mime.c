#include "server.h"

const char *get_mime_type(char *file_path) {
  char *ext = strrchr(file_path, '.');
  if (!ext) {
    return "text/plain";
  }
  if (strcmp(ext, ".html") == 0 || strcmp(ext, ".htm") == 0) {
    return "text/html";
  }
  if (strcmp(ext, ".css") == 0) {
    return "text/css";
  }
  if (strcmp(ext, ".js") == 0) {
    return "application/javascript";
  }
  if (strcmp(ext, ".jpg") == 0 || strcmp(ext, ".jpeg") == 0) {
    return "image/jpeg";
  }
  if (strcmp(ext, ".png") == 0) {
    return "image/png";
  }
  if (strcmp(ext, ".gif") == 0) {
    return "image/gif";
  }
  if (strcmp(ext, ".ico") == 0) {
    return "image/x-icon";
  }
  return "text/plain";
}

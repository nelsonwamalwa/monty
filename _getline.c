#include <stdio.h>
#include <stdlib.h>

size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
  char *buffer = NULL;
  size_t buffer_size = 0;

  while (1) {
    char c = fgetc(stream);
    if (c == EOF) {
      break;
    }

    if (buffer_size == 0 || buffer_size <= *n) {
      buffer = realloc(buffer, buffer_size + 1);
      if (buffer == NULL) {
        return -1;
      }
      buffer_size = buffer_size + 1;
    }

    buffer[*n] = c;
    *n = *n + 1;
    if (c == '\n') {
      break;
    }
  }

  buffer[*n] = '\0';
  *lineptr = buffer;
  return *n;
}
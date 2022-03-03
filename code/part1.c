#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "part1.h"

int main(int argc, char const *argv[])
{
  InputBuffer *input_buffer = new_input_buffer();
  while (true)
  {
    print_prompt();
    read_input(input_buffer);

    if (strcmp(input_buffer->buffer, ".exit") == 0)
    {
      close_input_buffer(input_buffer);
      exit(EXIT_SUCCESS);
    }
    else
    {
      printf("Unrecognized command '%s'.\n", input_buffer->buffer);
    }
  }
  return 0;
}

InputBuffer *new_input_buffer() {
  InputBuffer *input_buffer = malloc(sizeof(InputBuffer));
  input_buffer->buffer = NULL;
  input_buffer->buffer_length = 0;
  input_buffer->input_length = 0;
  return input_buffer;
}

void print_prompt() {
  printf("db > ");
}

void read_input(InputBuffer *input_buffer) {
  ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
  if (bytes_read <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }
  // ignore trailing new line
  input_buffer->input_length = bytes_read - 1;
  input_buffer->buffer[bytes_read-1] = 0;
}

void close_input_buffer(InputBuffer *input_buffer) {
  free(input_buffer->buffer);
  free(input_buffer);
}
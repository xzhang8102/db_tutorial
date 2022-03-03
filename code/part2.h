#include <sys/types.h>

typedef struct
{
  char *buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer *new_input_buffer();
void close_input_buffer(InputBuffer *input_buffer);
void print_prompt();
void read_input(InputBuffer *input_buffer);

typedef enum
{
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer *input_buffer);

typedef enum
{
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum
{
  STATMENT_INSERT,
  STATEMENT_SELECT
} StatementType;

typedef struct
{
  StatementType type;
} Statement;

PrepareResult prepare_statement(InputBuffer *input_buffer, Statement *stmt);

void execute_statement(Statement *stmt);
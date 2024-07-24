#include "config.h"
#include "errors.h"
#include "toml_parser.h"
#include <stdlib.h>
#include <string.h>  
#include <stdio.h>

// TODO: Потом поменять по понятным причинам
// ~/ не работает, нужно вручную получать ENV переменную HOME
char file_path[] = "/home/hyperborean-8/Projects/c.time_left/example.toml"; 

ErrorCode get_config(Config *config){

  ErrorCode result;

  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    perror("Failed to open file");
    result = FILE_OPEN_ERROR;
    return result;
  };

  parse_toml_file(file);

  // Попытаться закрыть файл
  if (fclose(file) != 0) {
    perror("Failed to close file");
    result = FILE_CLOSE_ERROR;
    return result;
    };

  result = SUCCESS;
  return result;
};

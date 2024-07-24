#include "config.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>  
#include <stdio.h>

Config create_new_config();

char file_path[] = "~/Projects/c.time_left/example.toml"; // TODO: Потом поменять по понятным причинам

ErrorCode get_config(Config *config){

  ErrorCode result;

  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    perror("Failed to open file");
    result = FILE_OPEN_ERROR;
    return result;
  };
  
  

  // Попытаться закрыть файл
  if (fclose(file) != 0) {
    perror("Failed to close file");
    result = FILE_CLOSE_ERROR;
    return result;
    };

  result = SUCCESS;
  return result;
};

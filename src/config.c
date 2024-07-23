#include "config.h"
#include "errors.h"
#include <stdlib.h>
#include <string.h>  
#include <stdio.h>

Config create_new_config();

char file_path[] = "~/Projects/c.time_left/example.toml"; // TODO: Потом поменять по понятным причинам

ConfigResult get_config(){
  Config config = {};
  ConfigResult result = {0, config};

  FILE *file = fopen(file_path, "r");
  if (file == NULL) {
    perror("Failed to open file");
    result.error_code = FILE_OPEN_ERROR;
    return result;
  };
  
  

  // Попытаться закрыть файл
  if (fclose(file) != 0) {
    perror("Failed to close file");
    result.error_code = FILE_CLOSE_ERROR;
    return result;
    };

  result.error_code = 0;
  return result;
};

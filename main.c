#include <stdio.h>
#include <stdlib.h>
#include "src/config.h"
#include "src/errors.h"

Config *config = NULL;
char *config_path = NULL;

void free_all();

int main(int argc, char *argv[])
{

  printf("Starting the application...\n");

  // Config
  config = malloc(sizeof(Config));
  if (config == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  ErrorCode result = get_config(config);

  if (result != SUCCESS){
    printf("Error occured, closing the application...\n");
    printf("Error code: %d", result);
    free_all();
    return 1;
  }

  free_all();
  return 0;
}

void free_all(){
  if (config != NULL) {
    free(config);
    config = NULL;  // Set to NULL after freeing
    }
  // Other global will be here
};


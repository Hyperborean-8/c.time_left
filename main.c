#include <stdio.h>
#include <stdlib.h>
#include "src/config.h"
#include "src/errors.h"

Config *config;

void free_all();

int main(int argc, char *argv[])
{

  printf("Starting the application...\n");

  // Config
  config = malloc(sizeof(Config));

  ErrorCode result = get_config(config);

  if (result != SUCCESS){
    printf("Error occured, closing the application...\n");
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


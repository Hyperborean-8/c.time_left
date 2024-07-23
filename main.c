#include <stdio.h>
#include "src/config.h"

int main(int argc, char *argv[])
{
  printf("Start of the program...\n");

  ConfigResult result = get_config();
  if (result.error_code != 0){
    return 1;
  }

  return 0;
}

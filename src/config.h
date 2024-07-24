#ifndef CONFIG_H_
#define CONFIG_H_

#include "errors.h"
#define DEFAULT_CONFIG_PATH "~/.config/time_left/config.toml"

typedef struct {
  int test_setting; 
} Config;

ErrorCode get_config(Config *config);

#endif // CONFIG_H_

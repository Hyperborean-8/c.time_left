#ifndef CONFIG_H_
#define CONFIG_H_

#include "errors.h"
#define DEFAULT_CONFIG_PATH "~/.config/time_left/config.toml"

typedef struct {
  int test_setting; 
} Config;

typedef struct {
    int error_code; // 0 означает успех, другое значение - код ошибки 
    Config config;
} ConfigResult;

ErrorCode get_config(Config *config);

#endif // CONFIG_H_

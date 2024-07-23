#ifndef CONFIG_H_
#define CONFIG_H_
#define DEFAULT_CONFIG_PATH "~/.config/time_left/config.toml"

typedef struct {
  int test_setting; 
} Config;

typedef struct {
    int error_code; // 0 означает успех, другое значение - код ошибки 
    Config config;
} ConfigResult;

ConfigResult get_config(void);

#endif // CONFIG_H_

#ifndef TOML_PARSER_H_
#define TOML_PARSER_H_

// Виды токенов
typedef enum {
    TOKEN_TABLE_START,
    TOKEN_TABLE_END,
    TOKEN_KEY,
    TOKEN_EQUALS,
    TOKEN_STRING,
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_BOOLEAN,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_COMMA,
    TOKEN_NEWLINE,
    TOKEN_EOF
} TokenType;

// Виды значений токенов
typedef union {
    char* string_value;
    int int_value;
    double float_value;
    int bool_value; 
} TokenValue;

// Токен
typedef struct {
    TokenType type;
    TokenValue value;
} Token;

void getconfig(void);

#endif // TOML_PARSER_H_

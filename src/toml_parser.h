#ifndef TOML_PARSER_H_
#define TOML_PARSER_H_

#include "errors.h"
#include <stdio.h>
#include <stdbool.h>

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
  bool bool_value; 
} TokenValue;

// Токен
typedef struct {
  TokenType type;
  TokenValue value;
  bool has_value;
} Token;

// Тип значения узла
typedef enum {
    TYPE_STRING,
    TYPE_INTEGER,
    TYPE_FLOAT,
    TYPE_BOOLEAN,
    TYPE_ARRAY,
    TYPE_TABLE
} ValueType;

// Узел древа
typedef struct Node {
    char* key;
    ValueType type;
    union {
        char* string_value;
        int int_value;
        double float_value;
        int bool_value;
        /*struct Node** array_value;*/
        /*struct Node** table_value;*/
    } value;
    int children_count;
    struct Node* parent;
    struct Node** children;
} Node;

typedef struct {
  ErrorCode error_code;
  
} ParceResult;

void parse_toml_file(FILE *toml_file);

#endif // TOML_PARSER_H_

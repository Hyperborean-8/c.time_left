#include "toml_parser.h"
#include "errors.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

ErrorCode tokenize_toml_file(FILE *toml_file);
void add_token(Token newToken);
Token* tokens = NULL;
size_t token_count = 0;

void parse_toml_file(FILE *toml_file){;
  
  tokenize_toml_file(toml_file);
  
};

ErrorCode tokenize_toml_file(FILE *toml_file){
  
  int ch;

  while ((ch = fgetc(toml_file)) != EOF) {
    printf("\n");
    printf("CHARACTER: %c (ASCII: %d)\n", ch, ch);


    if (isalpha(ch)) {
      DynamicString new_dynamic_string = {NULL, 0, 2};
      new_dynamic_string.data = (char *)malloc(sizeof(char) * (new_dynamic_string.capacity)); 
      if (new_dynamic_string.data == NULL){
        perror("Cannot allocate memory for dynamic string");
        return MEMORY_ALLOCATION_ERROR;
      }; 
      new_dynamic_string.data[0] = ch;
      new_dynamic_string.length++;
      ch = fgetc(toml_file);
      
      while (isalpha(ch)){
        new_dynamic_string.capacity++;
        new_dynamic_string.data = realloc(new_dynamic_string.data, sizeof(char[new_dynamic_string.capacity]));
        if (new_dynamic_string.data == NULL){
          perror("Cannot allocate memory for dynamic string");
          return MEMORY_ALLOCATION_ERROR; 
        };
        new_dynamic_string.data[new_dynamic_string.length] = ch;
        new_dynamic_string.length++;
        ch = fgetc(toml_file);
      }
         
      printf("STARTED PRINTING STRING\n");
      for (size_t i = 0; i < new_dynamic_string.length; i++){
      printf("%c", new_dynamic_string.data[i]);
      }
      printf("\n");

      Token new_token = {TOKEN_KEY, {.string_value = new_dynamic_string.data}, true};
      add_token(new_token);

    } else if (isdigit(ch)) {

    } else if (ch == '[') {
      Token new_token = {TOKEN_TABLE_START, {.string_value = NULL}, false};
      add_token(new_token);
    } else if (ch == ']') {
      Token new_token = {TOKEN_TABLE_END, {.string_value = NULL}, false};
      add_token(new_token);
    } else if (ch == '=') {
      Token new_token = {TOKEN_EQUALS, {.string_value = NULL}, false};
      add_token(new_token);  
    } else if (ch == '\n') {
      Token new_token = {TOKEN_NEWLINE, {.string_value = NULL}, false};
      add_token(new_token);
    };
  };
  
  printf("\nFINAL\n");
  // DEBUG
  for (size_t i = 0; i < token_count; i++) {
    printf("%d", tokens[i].type);
    if ((tokens[i].has_value == true) && (tokens[i].type == TOKEN_KEY)){
      printf("|%s", tokens[i].value.string_value);
    };
    printf(" ");
  }
  printf("\n");
  printf("Token array size is %zu\n", token_count);

  return SUCCESS;
};

void add_token(Token new_token) {
  token_count++;
  tokens = realloc(tokens, token_count * sizeof(Token));

  if (tokens == NULL) {
    perror("Memory allocation for tokens failed\n");
  }

  tokens[token_count - 1] = new_token;
}

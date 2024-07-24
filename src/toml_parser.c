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
    /*putchar(ch);*/
    printf("CHARACTER: %c\n", ch);


    if (isalpha(ch)) {
      // TODO: Feels awkward, maybe refactor later
      // Never fucking mind, it doesn't work anyway because of fgetch()
      // This is fucked, I give up for today
      DynamicString new_dynamic_string = {NULL,0,1};
      char *str;
      str = (char *)malloc(sizeof(char) * (new_dynamic_string.length + 1));
      new_dynamic_string.data = str;

      while ((ch = isalpha(ch))){
        new_dynamic_string.capacity++;
        new_dynamic_string.data = realloc(new_dynamic_string.data, sizeof(char[new_dynamic_string.capacity]));
        new_dynamic_string.data[new_dynamic_string.length] = ch;
        new_dynamic_string.length++;        

        printf("ADDED SYMBOL %c\n", ch);
        ch = fgetc(toml_file);
      }

      Token new_token = {TOKEN_KEY, {.string_value = new_dynamic_string.data}, true};
      add_token(new_token);

      printf("WHOLE STRING IS %s\n", new_dynamic_string.data);

      free(str);

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

  // DEBUG
  for (size_t i = 0; i < token_count; i++) {
    printf("%d ", tokens[i].type);  }
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

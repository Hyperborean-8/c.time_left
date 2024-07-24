#include "toml_parser.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

ErrorCode tokenize_toml_file(FILE *toml_file);
void add_token(Token newToken);
Token* tokens = NULL;
size_t tokenCount = 0;

void parse_toml_file(FILE *toml_file){;
  
  tokenize_toml_file(toml_file);
  
};

ErrorCode tokenize_toml_file(FILE *toml_file){
  
  int ch;

  while ((ch = fgetc(toml_file)) != EOF) {
    putchar(ch);
  }

  Token token1 = {TOKEN_TABLE_START, {.string_value = NULL}, false};
  Token token2 = {TOKEN_KEY, {.string_value = NULL}, false};
  Token token3 = {TOKEN_TABLE_END, {.string_value = NULL}, false};
  Token token4 = {TOKEN_EQUALS, {.string_value = NULL}, false};

  add_token(token1);
  add_token(token2);
  add_token(token3);
  add_token(token4);

  // DEBUG
  for (size_t i = 0; i < tokenCount; i++) {
    printf("%d ", tokens[i].type);  }
  printf("\n");

  return SUCCESS;
};

void add_token(Token newToken) {
  tokenCount++;
  tokens = realloc(tokens, tokenCount * sizeof(Token));

  if (tokens == NULL) {
    perror("Memory allocation for tokens failed\n");
  }

  tokens[tokenCount - 1] = newToken;
}

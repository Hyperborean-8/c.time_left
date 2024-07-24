#include "toml_parser.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

ErrorCode tokenize_toml_file();
void add_token(Token newToken);
Token* tokens = NULL;
size_t tokenCount = 0;

void parse_toml_file(const FILE *toml_file){;
  
  tokenize_toml_file();
  
};

ErrorCode tokenize_toml_file(){
  
  Token token1 = {TOKEN_TABLE_START};

  add_token(token1);
  
  for (int i = 0; i < tokenCount; i++) {
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

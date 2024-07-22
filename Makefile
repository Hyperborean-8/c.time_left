CC = gcc
CFLAGS = -Wall -Wextra -I./src
LDFLAGS = -lncurses
SRC = main.c 
OBJ = $(addprefix dist/,$(SRC:.c=.o))
EXEC = dist/time_left

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

dist/%.o: %.c
	@mkdir -p dist
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

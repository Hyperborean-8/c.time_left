# Честно, я сделал это с помощью ChatGPT, это что за п***** а не язык
# Define compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I./include
LDFLAGS = -lncurses

# Define directories
SRC_DIR = src
DIST_DIR = dist

# Define source files and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) main.c
OBJ_FILES = $(patsubst %.c, $(DIST_DIR)/%.o, $(notdir $(SRC_FILES)))

# Define the target executable
TARGET = $(DIST_DIR)/app

# Rule to build the target executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to build object files
$(DIST_DIR)/%.o: %.c
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIST_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(DIST_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
.PHONY: clean
clean:
	rm -rf $(DIST_DIR)

# Convenience target for rebuilding everything
.PHONY: all
all: clean $(TARGET)


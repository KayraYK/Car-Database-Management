CC = gcc
CFLAGS = -std=c99 -Wall
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
DEPS = $(wildcard $(INCLUDE_DIR)/*.h)
TARGET = $(BIN_DIR)/carBase

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDE_DIR)

clean:
	rm -f $(OBJ) $(TARGET)

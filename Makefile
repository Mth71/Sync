
SRC_DIR = src
INC_DIR = include

CC = gcc
CFLAGS = -Wall -I$(INC_DIR) -pthread -Wextra

SRCS   = $(SRC_DIR)/sync_car.c $(SRC_DIR)/sync_car-runner.c
HEADER = $(INC_DIR)/sync_car.h
TARGET = sync_car

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean

SRC_DIR = src
INC_DIR = include
CC = gcc
CFLAGS = -Wall -I$(INC_DIR) -pthread -Wextra

SRCS   = $(SRC_DIR)/sync_car.c $(SRC_DIR)/sync_car-runner.c
HEADER = $(INC_DIR)/sync_car.h
TARGET = sync_car
TEST_SRCS = $(SRC_DIR)/sync_car.c $(SRC_DIR)/test_invalid.c
TEST_TARGET = test_invalid


all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

$(TEST_TARGET): $(TEST_SRCS) $(HEADER)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SRCS)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all clean
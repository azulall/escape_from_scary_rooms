
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = main.c creature.c player.c room.c
OBJS = $(SRCS:.c=.o)
TARGET = escape_room

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run


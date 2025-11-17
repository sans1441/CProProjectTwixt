CC = gcc
CFLAGS = -Wall -Wextra -O2

TARGET = main
OBJ = main.o node.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c node.h
	$(CC) $(CFLAGS) -c main.c

node.o: node.c node.h
	$(CC) $(CFLAGS) -c node.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra
SOURCES = main.c lexer.c parser.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = skibidi

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET) 
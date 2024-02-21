TARGET = main
CC = gcc
CFLAGS = -Wall -std=c99 -g

SOURCES = main.c funcoes_jogo.c funcoes_bombas.c
OBJECTS = $(SOURCES:.c=.o)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(TARGET)

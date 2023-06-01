# used this SO page to help me with the Makefile
# https://stackoverflow.com/questions/26409648/how-to-compile-a-c-program-with-make-on-mac-os-x-terminal

CC = cc
CFLAGS = -std=c99 -pedantic -Wall -lSDL2
OBJECTS = src/*.c

all: 3d_renderer

3d_renderer: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o 3d_renderer

clean:
	rm -f *.o 3d_renderer

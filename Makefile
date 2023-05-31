CC = cc
CFLAGS = -std=c99 -pedantic -Wall
OBJECTS = src/*.c

all: 3d_renderer

3d_renderer: $(OBJECTS)
	$(CC) $(OBJECTS) -o 3d_renderer

clean:
	rm -f *.o 3d_renderer

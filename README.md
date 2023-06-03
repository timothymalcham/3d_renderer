# 3d Renderer

Learning how 3d rendering works by building a 3d renderer in C. 

Utilizes cpu/software rendering, no gpu or graphics API. 

Build binary:

```bash
make
```

## Notes

Learnin's and stuff

#### Hexadecimal colors

Hexadecimal representation of a color (Red, RGBA):

```c
0xFFFF0000

'FF' -> Alpha (A)
'FF' -> Red (R)
'00' -> Blue (B)
'00' -> Green (G)
```

#### Fixed-sized types

```c
sizeof(int) = ??? // depends on the specifics of the compiler, architecture of the machine.
```

Colors need to be certain sizes (of bits, e.g. 32 bits).

```c
uint8_t 
uint16_t
uint32_t
```

`uint8_t` -> C standard way of declaring fixed-sized int type:
- unsigned
- 8 bits (fixed size)

#### Color Buffer 

Array of colors (32 bits)

```c
uint32_t* color_buffer = NULL;

// allocate how many bytes? 
// gets the number of pixels on screen, gets the size of uint32_t, times the # of pixels, the allocation needed, cast to a uint32_t pointer
// malloc = memory allocation, use to dynamically allocate a certain number of bytes in the heap
// there is a possibility that malloc fails to allocate that number of bytes in memory (maybe the machine does not have enough free memory). If that happens, malloc will return a NULL pointer.
color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * window_width * window_height);

// calloc() is a good option for allocating and also seting the allocated memory to zero.
// Good for dynamic arrays

// set pixel at "row" 10, "column" 20 to the color red
// y = window_width * "the row" 
// x = the row + "column"
// not a grid per se, instead memory allocation is just one long row/array. Imagine a rect grid smushed into one long sequence...
color_buffer[(window_width * 10) + 20] = 0xFFFF0000
```

Points to the first element (in array) at that memory address. 

How many elements to allocate for the color buffer? Depends on the width x height of the window.

#### Vectors

__Qualities of vectors:__
Magnitude (how intense/strong is push/pull)
Direction (where is it pointing)

__Scalar vs Vector (quantities)__

- Scalar (single number, e.g. a single number/scalar can tell us temperture, area, length, pressure, etc.)
- Vector (something described with multiple values (e.g. intensity/direction), e.g. velocity, acceleration, force, lift, drag, displacement, etc.)

In graphics programming, 2D/3D points are thought of as Vectors: (0, 0), (0, 0, 0).


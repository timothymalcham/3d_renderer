# 3d Renderer

Learning how 3d rendering works by building a 3d renderer in C. 

Utilizes cpu/software rendering, no gpu or graphics API. 

Build binary:

```bash
make
```

## Notes

Hexidecimal representation of a color (Red, RGBA):

```c
0xFFFF0000

'FF' -> Alpha (A)
'FF' -> Red (R)
'00' -> Blue (B)
'00' -> Green (G)
```

__Fixed-sized types__

```c
sizeof(int) = ??? // depends on the specifics of the compiler, architecture of the machine.
```

Colors need to be certain sizes (of bits, e.g. 32 bits).

```c
uint8_t 
uint16_t
uint32_t
```

C standard way of declaring types:
- unsigned
- 8 bits (fixed size)

__Color Buffer__ 

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

How many elements to allocate for the color buffer? Depends on the w x h of the window.

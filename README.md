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

### Color Buffer 

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

### Vectors

__Qualities of vectors:__
Magnitude (how intense/strong is push/pull)
Direction (where is it pointing)

__Scalar vs Vector (quantities)__

- Scalar (single number, e.g. a single number/scalar can tell us temperture, area, length, pressure, etc.)
- Vector (something described with multiple values (e.g. intensity/direction), e.g. velocity, acceleration, force, lift, drag, displacement, etc.)

In graphics programming, 2D/3D points are thought of as Vectors: (0, 0), (0, 0, 0).

<img width="543" alt="image" src="https://github.com/timothymalcham/3d_renderer/assets/2825063/40bda1e6-d5d0-4acd-b117-0e254e05383a">

"Direction" is where the arrow points from the origin, "Magnitude" is how far that arrow goes (destination, the actual point itself).

A 3D is a set of 3D Vectors. A component with 2 components: (3.0, 6.0) x/y components, possibly a z component if 3D.


### Array of Points

<img width="385" alt="image" src="https://github.com/timothymalcham/3d_renderer/assets/2825063/942f1e1f-98f0-4f88-a963-b38c18aad122">

In C, you have to define an array with a specific size:

```c
int numbers[7]; // allows for 7 integer
```

### Projecting Points

<img width="807" alt="image" src="https://github.com/timothymalcham/3d_renderer/assets/2825063/37f65b8e-9d2f-484b-b605-4dc36de47b49">

#### Orthographic projection

An Orthographic projection is a 2D representation of a 3D object. The 6 principal views (top, rear, right side, bottom, front, left side) are created by looking at the object (straight on) in the directions indicated. You will always view the 3d object in such a way that you are looking straight on to one of these six views. 

A form of parallel projection in which all the projection lines are orthogonal to the projection plane.

"Points" and "Vectors" can be used interchangeably. They both refer to the same thing.

#### Isometric Projection

Another way to represent 3D objects in a 2D way. All the angles between the x-axis, y-axis, and z-axis equal 120 degrees.

<img width="854" alt="image" src="https://github.com/timothymalcham/3d_renderer/assets/2825063/726e6fd7-2b6e-4e26-9963-fd80e5cddec5">


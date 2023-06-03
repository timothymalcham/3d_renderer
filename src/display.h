#ifndef DISPLAY_H
#define DISPLAY_H
// #include guard - avoids double inclusion issue

#include <stdint.h> 
#include <stdbool.h>
#include <SDL2/SDL.h>

////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////

extern SDL_Window* window;

extern SDL_Renderer* renderer;

extern uint32_t* color_buffer;

// texture that is used to display the color buffer onscreen
extern SDL_Texture* color_buffer_texture;

extern int window_width;

extern int window_height;

////////////////////////////////////////////////////////
// Functions
////////////////////////////////////////////////////////

bool initialize_window(void);

void draw_dot_grid(void);

void draw_rect(int posX, int posY, int width, int height, uint32_t color);

void render_color_buffer(void);

void clear_color_buffer(uint32_t color);

void destroy_window(void);

#endif

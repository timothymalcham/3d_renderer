#include <stdio.h>
#include <stdint.h> 
#include <stdbool.h>

#include "display.h"
#include "vector.h"

// Declare array of vectors
// Constant array size declaration
const int N_POINTS = 9 * 9 * 9;
vector3_t cube_points[N_POINTS]; // 9x9x9 3D cube

bool is_running = false;

void setup(void) {
    // allocate x amount of memory for the color buffer
    color_buffer = (uint32_t*) malloc(sizeof(uint32_t) * window_width * window_height);

    // check if malloc was successful
    if (!color_buffer) {
        fprintf(stderr, "Error allocating memory for color buffer: %s\n", SDL_GetError());
        is_running = false;
    }

    color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ABGR8888,       // Alpha, Blue, Green, Red, 8 bits for each channel
        SDL_TEXTUREACCESS_STREAMING,    // Texture will change frequently, lockable
        window_width,
        window_height
    );

    int cube_point_count = 0;

    // start loading the array of vectors
    // from -1 to 1 (in this 9x9x9 cube)
    for (float x = -1; x <= 1; x += 0.25) {
        for (float y = -1; y <= 1; y += 0.25) {
            for (float z = -1; z <= 1; z += 0.25) {
                vector3_t new_point = {.x = x, .y = y, .z = z};
                cube_point_count++;
                cube_points[cube_point_count] = new_point;
            }
        }
    }

    fprintf(stdout, "Setup complete\n");
}

void process_input(void) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            is_running = false;
            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                is_running = false;
            }
            break;
    }
}

void update(void) {
    
}

void render(void) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    draw_dot_grid();
    draw_rect(100, 200, 400, 200, 0xFF0000FF);

    render_color_buffer();
    clear_color_buffer(0xFF000000);

    SDL_RenderPresent(renderer);
}

int main(void) {
    is_running = initialize_window();

    setup();

    while (is_running) {
        process_input();
        update();
        render();
    }

    destroy_window();

    return 0;
}

#include "display.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
uint32_t* color_buffer = NULL;
SDL_Texture* color_buffer_texture = NULL;
int window_width = 0;
int window_height = 0;

bool initialize_window(void) {
    printf("Initializing window\n");

    // if SDL_Init returns 0, then there was an error
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return false;
    }

    // Use SDL to get the fullscreen width x height
    SDL_DisplayMode display_mode;
    SDL_GetCurrentDisplayMode(0, &display_mode);
    window_width = display_mode.w;
    window_height = display_mode.h;

    // create a SDL window
    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        window_width,
        window_height,
        SDL_WINDOW_BORDERLESS
    );

    if (!window) {
        fprintf(stderr, "Error creating SDL window: %s\n", SDL_GetError());
        return false;
    }

    // Create a SDL renderer
    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer: %s\n", SDL_GetError());
        return false;
    }

    // Set to "real" fullscreen mode
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

    return true;
}

void draw_dot_grid(void) {
    for (int y = 0; y < window_height; y += 25) {
        for (int x = 0; x < window_width; x += 25) {
            color_buffer[(window_width * y) + x] = 0xFFFFFFFF;     
        }
    }
}

void draw_rect(int posX, int posY, int width, int height, uint32_t color) {
    if ((posX > window_width || posX + width > window_width) || (posY > window_height || posY + height > window_height)) {
        fprintf(stderr, "Rect would be drawn outside of the bounds of the screen\n");
    }

    for (int y = 0; y < window_height; y++) {
        for (int x = 0; x < window_width; x++) {
            if ((x >= posX && x <= posX + width) && (y >= posY && y <= posY + height)) {
                color_buffer[(window_width * y) + x] = color;     
            }
        }
    }
}

void render_color_buffer(void) {
    SDL_UpdateTexture(
        color_buffer_texture,
        NULL,
        color_buffer,
        (int)(window_width * sizeof(uint32_t))
    );

    SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL);
}

void clear_color_buffer(uint32_t color) {
    for (int y = 0; y < window_height; y++) {
        for (int x = 0; x < window_width; x++) {
            color_buffer[(window_width * y) + x] = color;     
        }
    }
}

void destroy_window(void) {
    // free up allocated memory
    free(color_buffer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

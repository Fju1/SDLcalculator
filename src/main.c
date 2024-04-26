#define  SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main() {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    const Uint8* state = SDL_GetKeyboardState(NULL);

    SDL_Rect button[10] = {
        (SDL_Rect){50, 300, 60, 40},
        (SDL_Rect){120, 300, 60, 40},
        (SDL_Rect){190, 300, 60, 40},
        (SDL_Rect){50, 250, 60, 40},
        (SDL_Rect){120, 250, 60, 40},
        (SDL_Rect){190, 250, 60, 40},
        (SDL_Rect){50, 200, 60, 40},
        (SDL_Rect){120, 200, 60, 40},
        (SDL_Rect){190, 200, 60, 40},
        (SDL_Rect){50, 350, 60, 40}
    };

    SDL_Event event;
    bool quit = false;
    while (!quit){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = true;
            }
        }

        // Set render color to blue
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        // Clear the window with the render color
        SDL_RenderClear(renderer);

        // Render
    for(int i = 0; i < 10; i++){
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderFillRect(renderer, &button[i]);
    }

        
        // Update the screen
        SDL_RenderPresent(renderer);

    }

    // Clean up resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
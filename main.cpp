#include <SDL.h>
#include <cmath>

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);


    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 700;

    SDL_Window* window = SDL_CreateWindow(
        "",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    bool running = true;
    int mouse_x = WINDOW_WIDTH / 2 - 50;
    int mouse_y = WINDOW_HEIGHT / 2 - 50;


    while (running) {



        SDL_Event event;


        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_MOUSEMOTION) {
                mouse_x = event.motion.x;
                mouse_y = event.motion.y;
            }

            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }

        SDL_Rect gegam;
        gegam.x = -50;
        gegam.y = -50;
        gegam.h = 100;
        gegam.w = 100;

     
        gegam.x += mouse_x;
        gegam.y += mouse_y;




        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, mouse_x, mouse_y, mouse_x - mouse_y, 255);
        SDL_RenderFillRect(renderer, &gegam);
        SDL_RenderPresent(renderer);

        SDL_Delay(32);



    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
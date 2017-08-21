#include <iostream>

//proper sdl header inclusion as per documentation
#include <SDL.h>

using namespace std;

int main() {

    Screen Screen;

   bool quit = false;

    SDL_Event event;

    while (!quit) {
//        Update particles
//        Draw particles
//        Check for messages or events

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }


    return 0;
}

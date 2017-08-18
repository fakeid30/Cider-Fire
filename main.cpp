#include <iostream>

//proper sdl header inclusion as per documentation
#include <SDL.h>

using namespace std;

int main() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }

    cout << "SDL Init succeeded." << endl;

    SDL_Quit();

    return 0;
}

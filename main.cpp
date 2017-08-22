#include <iostream>
#include "Screen.h"

using namespace std;
using namespace ciderFireNamespace;

int main() {

    Screen screen;

//    if (screen.init() == false) {
    if (!screen.init()) {
        cout << "Error" << endl;
    }


    while (true) {
//        Update particles
//        Draw particles
        int elapsed = SDL_GetTicks();
        auto green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
        auto red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
        auto blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

        for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
            for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
                screen.setPixel(x, y, red, green, blue);
            }
        }


//        Draw the screen
        screen.update();
//        Check for messages or events

        if (screen.processEvents() == false) {
            break;
        }
    }

    screen.close();

    return 0;
}


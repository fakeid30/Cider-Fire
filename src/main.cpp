#include <iostream>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace ciderFireNamespace;

int main() {

    srand(time(NULL));

    Screen screen;

//    if (screen.init() == false) {
    if (!screen.init()) {
        cout << "Error" << endl;
    }

    Swarm swarm;

    while (true) {
//        Update particles
//        Draw particles
        int elapsed = SDL_GetTicks();

        swarm.update(elapsed);

        auto green = (unsigned char) ((1 + sin(elapsed * 0.0001)) * 128);
        auto red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 128);
        auto blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 128);

        const Particle *const pParticles = swarm.getParticles();

        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
            int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

            screen.setPixel(x, y, red, green, blue);
        }

        screen.boxBlur();

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
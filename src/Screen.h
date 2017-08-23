//
// Created by nirjhor on 8/21/17.
//

#pragma once

#include <SDL.h>

namespace ciderFireNamespace {

    class Screen {
    public:
        const static int SCREEN_HEIGHT = 600;
        const static int SCREEN_WIDTH = 800;


    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;

    public:
        Screen();

        bool init();

        bool processEvents();

        void close();

        void update();

        void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

        void clear();
    };
}

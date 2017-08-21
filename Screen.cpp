//
// Created by nirjhor on 8/21/17.
//

#include "Screen.h"

namespace ciderFireNamespace {

    Screen::Screen() :
            m_window(NULL),
            m_renderer(NULL),
            m_texture(NULL),
            m_buffer(NULL) {

    }


    bool Screen::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }

        m_window = SDL_CreateWindow("Cider Fire",
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);

        if (m_window == NULL) {
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                      SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (m_renderer == NULL) {
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        if (m_texture == NULL) {
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        //RGBA 8888 = 32

        Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

        memset(buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        buffer[30000] = 0x0080FFFF;

        // Same as memset

        for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
            buffer[i] = 0xFFFFFFFF;
        }


        SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);

        return true;
    }

    bool Screen::processEvewnts() {

        return false;
    }

    void Screen::close() {

        delete[] m_buffer;
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyTexture(m_texture);
        SDL_DestroyWindow(m_window);
        SDL_Quit();

    }
}
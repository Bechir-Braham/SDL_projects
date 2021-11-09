//
// Created by bechir on 1/24/2020.
//
#ifndef TEST_CLASSSDL_SCREEN_H
#define TEST_CLASSSDL_SCREEN_H

#include <iostream>
#include "SDL2/SDL.h"


class Screen {
public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

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

    ~Screen();

    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);

    void setScreen(Uint8 red, Uint8 green, Uint8 blue);

    void update();

    SDL_Renderer* getRenderer();
};


#endif /* SCREEN_H_ */
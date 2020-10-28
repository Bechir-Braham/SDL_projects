//
// Created by bechir on 1/24/2020.
//
#include <random>
#include <ctime>
#include "BubbleSort.h"
#include "Rectangle.h"

using namespace std;

void color(Rectangle *bars, int a, int b, SDL_Renderer *renderer);

void swapBars(Rectangle &bar1, Rectangle &bar2, int N);

void bubbleSort::barsInit(int N, Rectangle *bars, SDL_Renderer *renderer) {
    mt19937 mt(time(0));
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < N; i++) {
        bars[i].value = dist(mt);
        bars[i].rect.x = (Screen::SCREEN_WIDTH / N) * i;
        bars[i].rect.w = static_cast<int>((Screen::SCREEN_WIDTH*1.0 / N) - Screen::SCREEN_WIDTH*1.0 / (2*N));
        bars[i].rect.h = static_cast<int>(Screen::SCREEN_HEIGHT * bars[i].value*1.0 / 100);
        bars[i].rect.y = Screen::SCREEN_HEIGHT - bars[i].rect.h;
        bars[i].draw(renderer);
    }
}

void bubbleSort::sort(int N, Rectangle *bars, SDL_Renderer *renderer, bool &quit) {
    int i = 0, j = 0;
    SDL_Rect blank = {0, 0, Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT};
    bool sorted = false;
    SDL_Event event;
    while (!sorted) {
        sorted = true;
        for (i = 0; (i < N - 1 - j) and !quit; i++) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    sorted = true;
                    quit = true;
                }
            }
            if (bars[i].value > bars[i + 1].value) {
                swap(bars[i].value, bars[i + 1].value);
                bars[i].rect.h = Screen::SCREEN_HEIGHT * bars[i].value / 100;
                bars[i + 1].rect.h = Screen::SCREEN_HEIGHT * bars[i + 1].value / 100;
                bars[i].rect.y = Screen::SCREEN_HEIGHT - bars[i].rect.h;
                bars[i + 1].rect.y = Screen::SCREEN_HEIGHT - bars[i + 1].rect.h;
                sorted = false;
            }

            SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(renderer, &blank);
            for (int k = 0; k < N; k++) {
                bars[k].draw(renderer);
            }
            color(bars, i, i + 1, renderer);
            SDL_RenderPresent(renderer);

        }
        j++;

    }

}


void color(Rectangle *bars, int a, int b, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &(bars[a].rect));
    SDL_RenderFillRect(renderer, &(bars[b].rect));
}




//
// Created by bechir on 1/25/2020.
//

#include "QuickSort.h"
#include <random>
#include <ctime>

using namespace std;


void qSort(int N, Rectangle *bars, int low, int high, SDL_Renderer *, bool &);

void quickSort::sort(int N, Rectangle *bars, SDL_Renderer *renderer, bool &quit) {
    int i = 0, j = 0;
    SDL_Rect blank = {0, 0, Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT};
    bool sorted = false;
    SDL_Event event;
    qSort(N, bars, 0, N - 1, renderer, quit);

}

int partition(int N, Rectangle *bars, int low, int high, SDL_Renderer *renderer, bool &quit) {
    int pivot = bars[high].value;
    bars[high].isPivot = 1;
    int i = (low - 1);
    SDL_Event event;
    SDL_Rect blank = {0, 0, Screen::SCREEN_WIDTH, Screen::SCREEN_HEIGHT};
    for (int j = low; (j <= high - 1) and !quit; j++) {
        if (bars[j].value < pivot) {
            i++;
            swap(bars[i].value, bars[j].value);
            bars[i].rect.h = Screen::SCREEN_HEIGHT * bars[i].value / 100;
            bars[i].rect.y = Screen::SCREEN_HEIGHT - bars[i].rect.h;

            bars[j].rect.h = Screen::SCREEN_HEIGHT * bars[j].value / 100;
            bars[j].rect.y = Screen::SCREEN_HEIGHT - bars[j].rect.h;

        }
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &blank);

        for (int k = 0; k < N; k++) {
            bars[k].draw(renderer);
        }

        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }
    swap(bars[i + 1].value, bars[high].value);
    bars[i + 1].rect.h = Screen::SCREEN_HEIGHT * bars[i + 1].value / 100;
    bars[i + 1].rect.y = Screen::SCREEN_HEIGHT - bars[i + 1].rect.h;
    bars[high].rect.h = Screen::SCREEN_HEIGHT * bars[high].value / 100;
    bars[high].rect.y = Screen::SCREEN_HEIGHT - bars[high].rect.h;

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &blank);
    for (int k = 0; k < N; k++) {
        bars[k].draw(renderer);
    }
    SDL_RenderPresent(renderer);
    return (i + 1);
}

void qSort(int N, Rectangle *bars, int low, int high, SDL_Renderer *renderer, bool &quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
    }
    if ((low < high) and (!quit)) {
        int pi = partition(N, bars, low, high, renderer, quit);

        qSort(N, bars, low, pi - 1, renderer, quit);
        qSort(N, bars, pi + 1, high, renderer, quit);
    }
}


void quickSort::barsInit(int N, Rectangle *bars, SDL_Renderer *renderer) {
    mt19937 mt(time(0));
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < N; i++) {
        bars[i].value = dist(mt);
        bars[i].rect.x = (Screen::SCREEN_WIDTH / N) * i;
        bars[i].rect.w = static_cast<int>((Screen::SCREEN_WIDTH * 1.0 / N) - Screen::SCREEN_WIDTH * 1.0 / (2 * N));
        bars[i].rect.h = static_cast<int>(Screen::SCREEN_HEIGHT * bars[i].value * 1.0 / 100);
        bars[i].rect.y = Screen::SCREEN_HEIGHT - bars[i].rect.h;
        bars[i].draw(renderer);
    }
}

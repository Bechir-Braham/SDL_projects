//
// Created by bechir on 1/24/2020.
//

#include "Rectangle.h"


void Rectangle::draw(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &rect);
}

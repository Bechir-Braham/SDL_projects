//
// Created by bechir on 1/24/2020.
//

#ifndef SDL_SORT_RECTANGLE_H
#define SDL_SORT_RECTANGLE_H

#include "Screen.h"

class Rectangle {
public:
    int rectH = 100;
    int rectW = 100;
    int value=0;
    int sortPos = 0;
    SDL_Rect rect = {0, 0, rectW, rectH};
public:
    void draw(SDL_Renderer* renderer);

};


#endif //SDL_SORT_RECTANGLE_H

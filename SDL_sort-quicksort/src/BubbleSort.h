//
// Created by bechir on 1/24/2020.
//

#ifndef SDL_SORT_BUBBLESORT_H
#define SDL_SORT_BUBBLESORT_H


#include "Rectangle.h"

class bubbleSort {
public:
    void barsInit(int N, Rectangle *rectangles, SDL_Renderer *renderer);

    void sort(int N, Rectangle *, SDL_Renderer *,bool& quit);
};


#endif //SDL_SORT_BUBBLESORT_H

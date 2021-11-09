//
// Created by bechir on 1/25/2020.
//

#ifndef SDL_SORT_QUICKSORT_H
#define SDL_SORT_QUICKSORT_H

#include "Rectangle.h"

class quickSort {
public:
    void static barsInit(int N, Rectangle *bars, SDL_Renderer *renderer);

    static void sort(int N, Rectangle *bars, SDL_Renderer *renderer, bool &quit);
};


#endif //SDL_SORT_QUICKSORT_H

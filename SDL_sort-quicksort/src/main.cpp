#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SDL2/SDL.h"
#include "Screen.h"
#include "Rectangle.h"
#include "BubbleSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
    int N = 200;
//    while (N > 200) {
//        std::cout << "type the number of bars to sort (less than 200)\n";
//        std::cin >> N;
//    }
    Screen screen;
    screen.setScreen(0, 0, 0);
    Rectangle bars[N];
    bubbleSort bubble;
    quickSort qs;
//    bubble.barsInit(N, bars, screen.getRenderer());
    qs.barsInit(N, bars, screen.getRenderer());
    for (int i = 0; i < N; i++) {
        cout <<bars[i].value<<"\t";
    }cout<<"\n";
    bool quit = false;
    bool sorted = false;
    while (!quit) {
        if (!sorted) {
//            bubble.sort(N, bars, screen.getRenderer(),quit);
            qs.sort(N, bars, screen.getRenderer(), quit);
            sorted = true;
        }

        screen.update();
        if (!screen.processEvents()) {
            quit = true;
        }
    }
    return 0;
}
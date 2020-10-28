#include "Screen.h"
#include "Rectangle.h"
#include "BubbleSort.h"

int main() {
    int N = 100;
    /*while(N>200)
    {
        std::cout<<"type the number of bars to sort (less than 200)\n";
        std::cin>>N;
    }*/
    Screen screen;
    screen.setScreen(0, 0, 0);
    Rectangle bars[N];
    bubbleSort bubble;
    bubble.barsInit(N, bars, screen.getRenderer());
    bool quit = false;
    bool sorted=false;
    while (!quit) {
        if (!sorted) {
            bubble.sort(N, bars, screen.getRenderer(),quit);
            sorted=true;
        }
        screen.update();
        if (!screen.processEvents()) {
            quit = true;
        }
    }
    return 0;
}
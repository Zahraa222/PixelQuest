#include <iostream>
#include "SDL.h"
using namespace std;

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){ //testing if SDL is working
        cout << "Working!" << endl;
    }
    return 0;
}

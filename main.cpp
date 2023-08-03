#include "Engine.h"
using namespace std;

int main(int argc, char** argv)
{
    /*
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){ //testing if SDL is working
        cout << "Working!" << endl;
    }
    */

    Engine::GetInstance() -> Init();

    while (Engine::GetInstance() -> IsRunning()){
            Engine::GetInstance() -> Events(); //checks if player make an action (push button, move, etc)
            Engine::GetInstance() -> Update(); //update game based on player movement/action
            Engine::GetInstance() -> Render(); //display results on screen
    }

    Engine::GetInstance() -> Clean();  //reset game engine

    return 0;
}

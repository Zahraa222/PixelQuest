#include "Engine.h"
#include <iostream>
using namespace std;

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
    //When SDL initialization is successful, SDL will return 0. if not, then initialization failedhz
    if(SDL_Init(SDL_INIT_VIDEO) !=0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0){
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
         memb_IsRunning = false;
         return memb_IsRunning;
    }
    //Create a window
    memb_window = SDL_CreateWindow("Soft Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_HEIGHT, 0); //disables full screen mode

    if(memb_window ==nullptr){ //if window is not initialized, output error message
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }
    memb_Renderer = SDL_CreateRenderer(memb_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(memb_Renderer == nullptr){ //if renderer is not initialized, output error message
        SDL_Log("Failed to create Renderer: %s", SDL_GetError);
        return false;
    }
    return memb_IsRunning = true;
}

void Engine::Update()
{

}

void Engine::Render()
{
    SDL_SetRenderDrawColor(memb_Renderer, 124, 218, 254, 255);
    SDL_RenderPresent(memb_Renderer);
}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            Quit();

    }
}

Engine::Engine()
{

}
bool Engine::Clean()
{

}

bool Engine::Quit()
{

}

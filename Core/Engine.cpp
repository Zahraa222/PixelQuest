#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"
#include <iostream>
using namespace std;

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
    //When SDL initialization is successful, SDL will return 0. if not, then initialization failed
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

    TextureManager::GetInstance()->Load("mushroom", "assets/mushroom.png"); //loading image

    //creating vector
    Vector2D v1(1,1), v2(1,1), v3;
    v3 = v1+v2;
    v3.Log("v3: ");

    Transform tf;
    tf.Log();

    return memb_IsRunning = true;
}

void Engine::Update()
{

}

void Engine::Render()
{
    SDL_SetRenderDrawColor(memb_Renderer, 124, 218, 254, 255);

    SDL_RenderClear(memb_Renderer);
    TextureManager::GetInstance()->Draw("mushroom", 100, 100, 217, 232);
    SDL_RenderPresent(memb_Renderer);
    //SDL_Log("%s", SDL_GetError());

}

void Engine::Events()
{
    SDL_Event event;
    (SDL_PollEvent(&event));
    switch(event.type){
        case SDL_QUIT:
            memb_IsRunning = false;
    }

}

Engine::Engine()
{

}
bool Engine::Clean()
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(memb_Renderer);
    SDL_DestroyWindow(memb_window);
    IMG_Quit();
    SDL_Quit();

}

bool Engine::Quit()
{

}

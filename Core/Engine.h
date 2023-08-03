#ifndef ENGINE_H
#define ENGINE_H

#include "SDL.h"
#include "SDL_image.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine
{


    public:
        //virtual ~Engine();
        static Engine* GetInstance(){ //check if an instance is created. if it is then return it. if not, create and return the instance
            return s_Instance = (s_Instance != nullptr)? s_Instance : new Engine();
                    //condition ? result_if_true : result_if_false;
            //ensures that s_instance always points to an Engine before it is returned.
        }

        bool Init();
        bool Clean();
        bool Quit();
        void Update();
        void Render();
        void Events();

        inline bool IsRunning(){return memb_IsRunning;} //checks if engine is running or not
        inline SDL_Renderer* GetRenderer(){
            return memb_Renderer;
        }


    private:
        Engine();
        bool memb_IsRunning;
        SDL_Window* memb_window;
        SDL_Renderer* memb_Renderer;
        static Engine* s_Instance;

};

#endif // ENGINE_H

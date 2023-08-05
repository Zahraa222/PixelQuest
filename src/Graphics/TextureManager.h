#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <string>
#include "SDL.h"
#include <map>
using namespace std;

class TextureManager
{
    public:
        static TextureManager* GetInstance(){ return s_instance = (s_instance != nullptr)? s_instance : new TextureManager();}
        bool Load(string id, string filename); //loads texture
        void Drop(string id);
        void Clean();
        void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip=SDL_FLIP_NONE);

    private:
        TextureManager(){};
        map<string, SDL_Texture*> memb_TextureMap;
        static TextureManager* s_instance;
};

#endif // TEXTUREMANAGER_H

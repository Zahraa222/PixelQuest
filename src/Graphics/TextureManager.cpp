#include "TextureManager.h"
#include "Engine.h"

TextureManager* TextureManager::s_instance = nullptr;

bool TextureManager::Load(string id, string filename)
{
    SDL_Surface* surface = IMG_Load(filename.c_str()); //need to convert to char per function syntax
    if(surface == nullptr){
            SDL_Log("Failed to load texture: %s, %s", filename.c_str(), SDL_GetError());
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::GetInstance()->GetRenderer(), surface);
    //SDL_Log("Created texture address: %p", texture);
    if(texture == nullptr){
            SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return false;
    }

    memb_TextureMap[id] = texture;
    return true;
}

void TextureManager::Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
    SDL_Rect srcRect = {0,0,width, height};
    SDL_Rect destinationRect = {x, y, width, height};
   // SDL_Texture* textureToDraw = memb_TextureMap[id];
   // SDL_Log("Drawing texture address: %p", textureToDraw);
    SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), memb_TextureMap[id], &srcRect, &destinationRect, 0, nullptr, flip);

}

void TextureManager::Drop(string id)
{
    SDL_DestroyTexture(memb_TextureMap[id]); //removes the texture from the map/level when no longer needed
    memb_TextureMap.erase(id);
}

void TextureManager::Clean()
{
    map<string, SDL_Texture*>::iterator it;
    for (it = memb_TextureMap.begin(); it != memb_TextureMap.end(); it++){ //clear all elements between beginning and anything that's not the end
        SDL_DestroyTexture(it->second);
    }

    memb_TextureMap.clear();
    SDL_Log("Texture Path Cleaned!");
}



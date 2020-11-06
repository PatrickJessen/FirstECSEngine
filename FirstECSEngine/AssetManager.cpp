#include "AssetManager.h"
#include <iostream>
#include "Engine.h"

AssetManager* AssetManager::isInstance = nullptr;

AssetManager::AssetManager()
{
	if (TTF_Init() != 0)
	{
		std::cerr << TTF_GetError() << std::endl;
	}
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) != 0)
	{
		std::cerr << TTF_GetError() << std::endl;
	}
}

void AssetManager::Clean()
{
	for (auto i = textures.begin(); i != textures.end(); i++)
	{
		SDL_DestroyTexture(i->second);
		textures.erase(i);
	}

	textures.clear();

	for (auto i = fonts.begin(); i != fonts.end(); i++)
	{
		TTF_CloseFont(i->second);
		fonts.erase(i);
	}

	fonts.clear();

	std::cout << "Assets cleared successfully!" << std::endl;
}

SDL_Texture* AssetManager::GetTexture(std::string id)
{
	return (textures.count(id) > 0) ? textures[id] : nullptr;
}

void AssetManager::LoadTexture(std::string id, std::string path)
{
	if (textures.count(id) <= 0)
	{
		SDL_Texture* texture = IMG_LoadTexture(Engine::Get().GetRenderer(), path.c_str());


		std::cout << SDL_GetError() << '\n';
		
		if (texture)
		{
			textures[id] = texture;
			std::cout << "Texture: [" << path << "] loaded!" << std::endl;
		}
		else
		{
			std::cout << "test";
			std::cerr << SDL_GetError() << std::endl;
		}
	}
}

TTF_Font* AssetManager::getFont(std::string id)
{
	if (fonts.count(id) > 0)
	{
		return fonts[id];
	}
	return nullptr;
}

void AssetManager::LoadFont(std::string id, std::string path, int fontSize)
{
	TTF_Font* newFont = TTF_OpenFont(path.c_str(), fontSize);
	if (newFont != nullptr)
	{
		fonts.emplace(id, newFont);
		std::cout << "Font: [" << path << "] loaded!" << std::endl;
	}
	else
	{
		std::cout << TTF_GetError() << std::endl;
	}
}

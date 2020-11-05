#pragma once
#include <map>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>

class AssetManager
{
public:
	AssetManager();
	~AssetManager() = default;

	void Clean();

	SDL_Texture* GetTexture(std::string id);
	void LoadTexture(std::string id, std::string path);

	TTF_Font* getFont(std::string id);
	void LoadFont(std::string id, std::string path, int fontSize);

	inline static AssetManager& Get()
	{
		if (isInstance == nullptr)
		{
			isInstance = new AssetManager();
		}
		return *isInstance;
	}

private:
	static AssetManager* isInstance;
	std::map<std::string, TTF_Font*> fonts;
	std::map<std::string, SDL_Texture*> textures;
};


#pragma once
#include <string>
#include <SDL.h>
#include "Entity.h"
#include "Component.h"
#include "AssetManager.h"
#include <iostream>

class Sprite : public Component
{
public:
	Sprite() = default;
	virtual ~Sprite() = default;

	Sprite(SDL_Renderer* target, std::string textureid): renderTarget(target), textureID(textureid) {}

	bool init() override final
	{
		transform = &entity->getComponent<Transform>();
		texture = AssetManager::Get().GetTexture(textureID);
		SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);


		destRect.x = transform->position.x;
		destRect.y = transform->position.y;
		destRect.w = width* transform->scale.x;
		destRect.h = height* transform->scale.y;

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.w = width;
		srcRect.h = height;

		return true;
	}

	void Draw() override final
	{
		SDL_RenderCopyEx(renderTarget, texture, &srcRect, &destRect, transform->rotation, nullptr, flip);
	}

	void Update() override final
	{
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = static_cast<int>(width);
		destRect.h = static_cast<int>(height);
	}

private:
	int width = 0;
	int height = 0;
	SDL_Rect srcRect = { 0, 0, 0 ,0 };
	SDL_Rect destRect = { 0, 0, 0 ,0 };

	Transform* transform = nullptr;
	std::string textureID = "";
	SDL_Texture* texture = nullptr;
	SDL_Renderer* renderTarget = nullptr;
	SDL_RendererFlip flip = SDL_FLIP_NONE;

};


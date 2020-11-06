#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "EntityManager.h"

constexpr int SCREEN_WIDTH = 900;
constexpr int SCREEN_HEIGHT = 700;
constexpr SDL_Color DARK = { 30, 30, 30, 255 };

class Engine
{
public:
	Engine();
	~Engine();

	void Quit();
	void Init();
	void Clean();


	void Render();
	void Update();
	void Event();

	inline static Engine& Get()
	{
		if (isInstance == nullptr)
		{
			isInstance = new Engine();
		}
		return *isInstance;
	}

	inline bool IsRunning()
	{
		return running;
	}

	inline SDL_Renderer* GetRenderer()
	{
		return renderer;
	}

private:
	EntityManager* manager;

	bool running;
	SDL_Window* window;
	SDL_Color clearColor;
	SDL_Renderer* renderer;

	static Engine* isInstance;
};


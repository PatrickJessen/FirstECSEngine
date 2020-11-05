#include "Engine.h"
#include <iostream>
#include "AssetManager.h"
#include "Sprite.h"

Engine* Engine::isInstance = nullptr;

Engine::Engine()
{
	running = false;
	window = nullptr;
	renderer = nullptr;
}

Engine::~Engine()
{
}

void Engine::Quit()
{
	running = false;
}

void Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cerr << SDL_GetError() << std::endl;
	}

	auto wflags = (SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_ALLOW_HIGHDPI);
	window = SDL_CreateWindow("Engine Wroom wroom", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, wflags);
	if (!window)
	{
		std::cerr << SDL_GetError() << std::endl;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
	{
		std::cerr << SDL_GetError() << std::endl;
	}

	AssetManager::Get().LoadTexture("test", "Assets/test.png");

	manager = new EntityManager();

	Entity* entity = new Entity();
	entity->addComponent<Sprite>(renderer, "test");
	entity->getComponent<Transform>().position = Vector2DF(100.0f, 100.0f);
	manager->AddEntity(entity);

	clearColor = DARK;
	running = true;
}

void Engine::Clean()
{
	AssetManager::Get().Clean();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	SDL_RenderClear(renderer);
	manager->Draw();

	SDL_RenderPresent(renderer);
}

void Engine::Update()
{
	manager->Update();
}

void Engine::Event()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
	}
}

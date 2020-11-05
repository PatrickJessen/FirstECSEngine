#include "EntityManager.h"
#include "Entity.h"
#include <chrono>

static auto tp1 = std::chrono::system_clock::now();
static auto tp2 = std::chrono::system_clock::now();

void EntityManager::Draw()
{
	for (auto& entity : entities)
	{
		entity->Draw();
	}
}

void EntityManager::Update()
{

	for (auto& entity : entities)
	{
		entity->Update();
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		deltaTime = elapsedTime.count() * 100.0f;
	}
}

void EntityManager::Refresh()
{
}

void EntityManager::AddEntity(Entity* player)
{
	std::unique_ptr<Entity> uniquePtr{ player };
	entities.emplace_back(std::move(uniquePtr));
}

void EntityManager::EraseEntity(Entity* player)
{
}

Entity* EntityManager::CloneEntity(Entity* player)
{
	return nullptr;
}

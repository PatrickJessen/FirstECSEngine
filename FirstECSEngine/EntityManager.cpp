#include "EntityManager.h"
#include "Entity.h"

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

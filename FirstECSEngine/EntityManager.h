#pragma once
#include "Entity.h"
#include <vector>
#include <memory>

class Entity;

class EntityManager
{
public:

	EntityManager() = default;
	~EntityManager() = default;

	void Draw();
	void Update();
	void Refresh();

	void AddEntity(Entity* player);
	void EraseEntity(Entity* player);
	Entity* CloneEntity(Entity* player);

private:
	std::vector<std::unique_ptr<Entity>> entities;
	float deltaTime;
};
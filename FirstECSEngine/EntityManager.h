#pragma once

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

	std::vector<std::unique_ptr<Entity>> entities;
private:
	float deltaTime;
};
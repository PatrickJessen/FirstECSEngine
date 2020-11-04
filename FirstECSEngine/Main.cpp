#include <iostream>
#include "ECS.h"
#include "Transform.h"
#include "Entity.h"
#include "EntityManager.h"

int main()
{
	EntityManager* manager = new EntityManager();
	Entity* entity = new Entity();

	manager->AddEntity(entity);

	entity->getComponent<Transform>().position = Vector2DF(20000, 30000);

	while (true)
	{
		manager->Update();
		manager->Draw();
	}
	std::cout << entity->getComponent<Transform>().position;

}
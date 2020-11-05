#include <iostream>
#include "Transform.h"
#include "Entity.h"
#include <Windows.h>
#include "EntityManager.h"

int main()
{
	EntityManager* manager = new EntityManager();
	Entity* entity = new Entity();

	manager->AddEntity(entity);

	entity->getComponent<Transform>().position = Vector2DF(20000, 30000);
	entity->getComponent<Transform>().position.ones().x = 10;


	while (true)
	{
		std::cout << entity->getComponent<Transform>().position;
		manager->Update();
		manager->Draw();
	}

}
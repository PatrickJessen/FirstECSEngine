#pragma once
#include "ECS.h"
#include <vector>
#include <memory>
#include "Component.h"
#include "Transform.h"


class Entity
{
public:
	
	Entity()
	{
		this->addComponent<Transform>(0, 0);
	}
	virtual ~Entity() = default;

	template<typename T, typename... TArgs>
	inline T& addComponent(TArgs&&... args)
	{
		T* comp(new T(std::forward<TArgs>(args)...));
		//comp->entity = this;
		std::unique_ptr<Component> uptr { comp };
		components.emplace_back(std::move(uptr));

		if (comp->init())
		{
			compList[getComponentID<T>()] = comp;
			compBitset[getComponentID<T>()] = true;
			comp->entity = this;
			return *comp;
		}

		return *static_cast<T*>(nullptr);
	}

	template<typename T>
	inline T& getComponent() const
	{
		auto ptr(compList[getComponentID<T>()]);
		return *static_cast<T*>(ptr);
	}

	template<typename T>
	inline bool hasComponent() const
	{
		return compBitset[getComponentID<T>()];
	}

	inline bool isActive() const
	{
		return active;
	}

	inline void Destroy()
	{
		active = false;
	}

	inline void Draw()
	{
		for (auto& comp : components)
		{
			comp->Draw();
		}
	}

	inline void Update()
	{
		for (auto& comp : components)
		{
			comp->Update();
		}
	}

private:

	bool active;
	ComponentList compList;
	ComponentBitset compBitset;
	std::vector<std::unique_ptr<Component>> components;
};
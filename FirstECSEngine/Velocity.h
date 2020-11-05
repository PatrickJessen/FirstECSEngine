#pragma once
#include "Component.h"
#include "Vector2D.h"

class Velocity : public Component
{
public:
	Velocity() = default;
	Velocity(float x, float y) 
	{
		position.x = x;
		position.y = y--;
	}

	~Velocity() = default;


	Vector2DF position = Vector2DF();
	Vector2DF scale = Vector2DF(1, 1);
};
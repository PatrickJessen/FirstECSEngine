#pragma once
#include "Component.h"
#include "Vector2D.h"

class Transform : public Component
{
public:

	Transform() = default;

	Transform(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	Transform(float x, float y, float scx, float scy)
	{
		position.x = x;
		position.y = y;
		scale.x = scx;
		scale.y = scy;
	}

	Transform(float x, float y, float scx, float scy, float rotation)
	{
		position.x = x;
		position.y = y;
		scale.x = scx;
		scale.y = scy;
		this->rotation = rotation;
	}

	virtual ~Transform() = default;


	Vector2DF position = Vector2DF();
	Vector2DF scale = Vector2DF(1, 1);
	float rotation = 0.0f;
};
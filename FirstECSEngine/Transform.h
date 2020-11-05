#pragma once
#include "Component.h"
#include "Vector2D.h"

class Transform : public Component
{
public:

	Transform()
	{
		position.zero();
		scale.x = 1.0f;
		scale.y = 1.0f;
		rotation = 0.0f;
	};

	Transform(float x, float y)
	{
		position = Vector2DF(x, y);
		scale.ones();
		rotation = 0;
	}

	Transform(float x, float y, float scx, float scy)
	{
		position.x = x;
		position.y = y;
		scale.x = scx;
		scale.y = scy;
		rotation = 0;
	}

	Transform(float x, float y, float scx, float scy, float rot)
	{
		position.x = x;
		position.y = y;
		scale.x = scx;
		scale.y = scy;
		rotation = rot;
	}

	virtual ~Transform() = default;


	Vector2DF position = Vector2DF();
	Vector2DF scale = Vector2DF(1.0f, 1.0f);
	float rotation = 0.0f;
};
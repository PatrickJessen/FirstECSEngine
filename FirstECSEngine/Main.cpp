#include <iostream>
#include "Engine.h"

int main()
{
	Engine& engine = Engine::Get();

	engine.Init();
	while (engine.IsRunning())
	{
		engine.Event();
		engine.Update();
		engine.Render();
	}

	return 0;
}
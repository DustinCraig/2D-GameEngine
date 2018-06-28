#include "Engine.h"
#include "Sprite.h"
#include <iostream>

int main()
{
	Engine engine; 
	engine.Initialize("Game"); 

	Sprite testSprite = Sprite("Assets/Art/Biplane.png", -100, -100);

	while (true)
	{
		engine.Update();
		testSprite.Update();

		engine.BeginRender();

		testSprite.Render();

		engine.EndRender();
	}

	return 0; 
}
#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "GLFW/glfw3.h"

//Windows only 
#pragma comment(lib, "opengl32.lib")

class Engine
{
public:
	static int SCREEN_WIDTH; 
	static int SCREEN_HEIGHT;

	Engine();
	~Engine(); 

	bool Initialize(const char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	static GLFWwindow* window;
};
#endif // !GAME_ENGINE

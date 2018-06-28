#include "Engine.h"
#include <iostream>

//Static members set up here 
int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;
GLFWwindow* Engine::window = NULL; 

Engine::Engine() 
{

}

Engine::~Engine()
{

}

bool Engine::Initialize(const char* windowTitle)
{
	if (!glfwInit()) 
	{
		std::cout << "Error initializing glfw" << std::endl; 

		return false; 
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Error creating window" << std::endl; 
		return false; 
	}

	//OpenGl Setup
	glfwMakeContextCurrent(window);
	int width, height; 
	glfwGetFramebufferSize(window, &width, &height); 

	//Basically to prevent flickering, swap buffers every frame 
	glfwSwapInterval(1);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor()); 
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos); 

	//Viewport 
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	//As Y increases you move up the screen, as X increases you move right. So (0,0) is at the bottom left
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10); 
	glMatrixMode(GL_MODELVIEW); 

	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;

}

void Engine::Update()
{
	//Let opengl handle all i/o updates in the queue
	glfwPollEvents(); 
}

void Engine::BeginRender()
{
	//Clear buffer
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	
}

void Engine::EndRender()
{
	glfwSwapBuffers(window);
}
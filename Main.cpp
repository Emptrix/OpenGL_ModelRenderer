#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() 
{
	//Initialize GLFW
	glfwInit();

	//Set the GLFW Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Tell GLFW we are using the CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create a GLFWWindow of 720 by 720 pixels
	GLFWwindow* window = glfwCreateWindow(720, 720, "Open GL Window", NULL, NULL);
	
	//Null guard if window fails to initialize
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//Introduce Window into current context
	glfwMakeContextCurrent(window);

	//Load Glad so it configures OpenGL
	gladLoadGL();

	//Positioning and Sizing of the Viewport of OpenGL in the Window
	glViewport(0, 0, 800, 800);
	
	//Color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	//Clean the back buffer and assign the new color
	glClear(GL_COLOR_BUFFER_BIT);

	//Swap the back buffer with the front buffer
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window))
		glfwPollEvents(); //Execute GLFW Events

	//Delete window before ending program
	glfwDestroyWindow(window);

	//Terminate GLFW on EXIT program
	glfwTerminate();
	return 0;
}
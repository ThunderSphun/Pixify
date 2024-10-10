#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <GLFW/glfw3.h>

#include <iostream>

void printGlfwError() {
	const static char* errorDescription;
	glfwGetError(&errorDescription);
	std::cerr << "Error: " << errorDescription << std::endl;
}

int main(int argc, char** argv) {
	int width = 480;
	int height = 360;
	GLFWwindow* window;

	if (!glfwInit()) {
		printGlfwError();
		return -1;
	}

	const struct
	{
		float r, g, b;
	} color = {0.95f, 0.32f, 0.11f};

	glfwWindowHint(GLFW_FOCUS_ON_SHOW, GLFW_FALSE);

	window = glfwCreateWindow(width, height, "Test Window", NULL, NULL);
	if (!window) {
		printGlfwError();
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);

	glfwMakeContextCurrent(window);
	glClearColor(1.f, 0.f, 0.5f, 1.f);

	while(true) {
		glfwMakeContextCurrent(window);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);

		if (glfwWindowShouldClose(window) || glfwGetKey(window, GLFW_KEY_ESCAPE)) {
			glfwTerminate();
			return 0;
		}

		glfwPollEvents();
	}

	glfwWaitEvents();
}
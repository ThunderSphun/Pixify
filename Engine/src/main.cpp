#include "lifetime.h"

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include <iostream>

Application::Handler nullHandler = Application::Handler{};

int main(int argc, char** argv) {
	Application::Specs specs = Lifetime::preInit(argc, argv);

	if (!glfwInit()) {
		const static char* errorDescription;
		glfwGetError(&errorDescription);
		std::cerr << "glfwInit gave the error: \"" << errorDescription << "\"" << std::endl;
		return EXIT_FAILURE;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(specs.width, specs.height, specs.title, nullptr, nullptr);
	if (window == nullptr) {
		const static char* errorDescription;
		glfwGetError(&errorDescription);
		std::cerr << "glfwCreateWindow gave the error: \"" << errorDescription << "\"" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	// io.ConfigFlags |= ImGuiConfigFlags_DpiEnableScaleFonts;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	Lifetime::postInit(argc, argv);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0) {
			ImGui_ImplGlfw_Sleep(10);
			continue;
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::ShowDemoWindow();

		ImGui::Render();
		int displayWidth;
		int displayHeigh;
		glfwGetFramebufferSize(window, &displayWidth, &displayHeigh);
		glViewport(0, 0, displayWidth, displayHeigh);
		glClearColor(0.95f, 0.32f, 0.11f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(window);
	}

	Lifetime::preShutdown();

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(window);
	glfwTerminate();

	return Lifetime::postShutdown();
}
#include <iostream>

#include <startup.h>

void Startup::preInit(int argc, char** argv) {
	std::cout << "before init code" << std::endl;
}

void Startup::postInit(int argc, char** argv) {
	std::cout << "after init code" << std::endl;
}

std::unique_ptr<Application::App> Startup::createApplication(int argc, char** argv) {
	return std::make_unique<Application::App>(nullptr);
}
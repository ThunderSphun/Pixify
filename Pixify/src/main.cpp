#include <iostream>

#include <lifetime.h>

Application::Specs Lifetime::preInit(int argc, char** argv) {
	std::cout << "before init code" << std::endl;

	return Application::Specs{};
}

void Lifetime::postInit(int argc, char** argv) {
	std::cout << "after init code" << std::endl;
}

void Lifetime::preShutdown() {
	std::cout << "before shutdown code" << std::endl;
}

int Lifetime::postShutdown() {
	std::cout << "after shutdown code" << std::endl;

	return EXIT_SUCCESS;
}
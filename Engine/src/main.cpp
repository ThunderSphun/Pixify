#include "startup.h"

int main(int argc, char** argv) {
	Startup::preInit(argc, argv);

	// init code

	Startup::postInit(argc, argv);

	std::unique_ptr<Application::App> app = Startup::createApplication(argc, argv);

	return EXIT_SUCCESS;
}
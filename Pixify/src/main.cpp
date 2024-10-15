#include <iostream>

#include <startup.h>

void Startup::preInit(int argc, char** argv) {
	std::cout << "before init code" << std::endl;
}

void Startup::postInit(int argc, char** argv) {
	std::cout << "after init code" << std::endl;
}
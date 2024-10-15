#include "startup.h"

int main(int argc, char** argv) {
	Startup::preInit(argc, argv);

	// init code

	Startup::postInit(argc, argv);
}
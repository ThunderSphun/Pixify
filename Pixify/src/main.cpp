#include "engine.h"

#include <iostream>

int main(int argc, char** argv) {
	EngineSpecs specs;
	
	specs.lifetime.postInit = [](){std::cout << "initialized" << std::endl;};

	specs.application.title = "Pixify";

	return Engine::launch(specs);
}
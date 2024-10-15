#pragma once
#include "application.h"

#include <memory>

namespace Startup {
	extern void preInit(int argc, char** argv);
	extern void postInit(int argc, char** argv);
	extern std::unique_ptr<Application::App> createApplication(int argc, char** argv);
}
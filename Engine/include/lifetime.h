#pragma once
#include "application.h"

#include <memory>

namespace Lifetime {
	extern Application::Specs preInit(int argc, char** argv);
	extern void postInit(int argc, char** argv);

	extern void preShutdown();
	extern int postShutdown();
}
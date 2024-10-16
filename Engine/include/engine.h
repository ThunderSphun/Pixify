#pragma once

#include <functional>
#include <stdint.h>

struct EngineSpecs {
	struct {
		std::function<void()> preInit;
		std::function<void()> postInit;

		std::function<void()> preExit;
		std::function<int()> postExit;
	} lifetime;

	struct {
		const char* title = "window title";
		uint32_t width = 720;
		uint32_t height = 480;
	} application;

	struct {
		std::function<void()> update;
		std::function<void(float elapsed)> draw;
	} appEventHandles;
};

namespace Engine {
	int launch(const EngineSpecs& specs);
}
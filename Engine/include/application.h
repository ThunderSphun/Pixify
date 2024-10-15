#pragma once

#include <stdint.h>
#include <string>
#include <memory>

namespace Application {
	struct Handler {
	public:
		virtual void draw() {};
		virtual void update() {};
	};

	static std::unique_ptr<Handler> nullHandler = std::make_unique<Handler>();

	struct Specs {
	public:
		uint32_t width = 480;
		uint32_t height = 320;
		std::string title = "window title";
	};

	class App final {
	public:
		explicit App(const Specs& specs);
		App(std::unique_ptr<Handler> handler, const Specs specs = Specs{});
	private:
		std::unique_ptr<Handler> handler;
	};
}
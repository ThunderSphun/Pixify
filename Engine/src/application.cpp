#include "application.h"

Application::App::App(const Specs &specs) : Application::App(std::move(Application::nullHandler), specs) {}

Application::App::App(std::unique_ptr<Handler> handler, const Specs specs) : handler(std::move(handler)) {

}

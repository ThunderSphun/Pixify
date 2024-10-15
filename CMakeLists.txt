cmake_minimum_required(VERSION 3.26)
project(pixify)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

add_subdirectory(Engine)
add_subdirectory(Pixify)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

# Dear ImGui doesn't have a cmake file, so lets construct a library in place
add_library(DearImGui STATIC vendor/dearImgui/imgui.cpp vendor/dearImgui/imgui_demo.cpp vendor/dearImgui/imgui_draw.cpp vendor/dearImgui/imgui_tables.cpp vendor/dearImgui/imgui_widgets.cpp vendor/dearImgui/misc/cpp/imgui_stdlib.cpp vendor/dearImgui/backends/imgui_impl_opengl3.cpp vendor/dearImgui/backends/imgui_impl_glfw.cpp)
target_include_directories(DearImGui PUBLIC vendor/dearImgui vendor/dearImgui/misc/cpp)
# Dear ImGui must be linked against glfw for its backend
target_link_libraries(DearImGui glfw)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE vendor/stb)

target_link_libraries(ApplicationCore OpenGL::GL)
target_link_libraries(ApplicationCore glfw)
target_link_libraries(ApplicationCore DearImGui)
target_link_libraries(ApplicationCore stb)

target_link_libraries(PixifyEditor ApplicationCore)
cmake_minimum_required(VERSION 3.22)
project(fractalDrawing)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "C:\\Qt\\6.3.0\\mingw_64")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        OpenGL
        OpenGLWidgets
        REQUIRED)

add_executable(fractalDrawing main.cpp)
target_link_libraries(fractalDrawing
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::OpenGL
        Qt6::OpenGLWidgets
        )


target_link_libraries(fractalDrawing -lfreeglut -lglew32 -lopengl32 -lglu32)

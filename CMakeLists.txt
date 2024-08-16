# CMakeList.txt: проект CMake для curves3d; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.

add_library(curveslib SHARED shapes.cpp shapes.h)

add_executable (curves3d main.cpp shapes.cpp shapes.h)

#

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

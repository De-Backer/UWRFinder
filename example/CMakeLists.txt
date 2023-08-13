cmake_minimum_required(VERSION 3.5)

project(Ultrasonic_Range_Finder_example)

set(EXTRA_COMPONENT_DIRS "../")
set(COMPONENT_SRCS main.c)

register_component()

add_compile_options(-fdiagnostics-color=always)
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
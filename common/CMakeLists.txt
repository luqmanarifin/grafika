cmake_minimum_required (VERSION 2.8.11)
project (common)

add_library(grafika SHARED
	curve.cpp
	font.cpp
	color.cpp
	line.cpp
	framebuffer.cpp
	polygon.cpp
)

set_target_properties(grafika PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_link_libraries(grafika)
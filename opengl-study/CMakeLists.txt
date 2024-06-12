project(opengl-study)

add_executable(template main.cpp glad.c)

find_package(GLFW3 REQUIRED)

target_link_libraries( executable_name glfw )



include_directories(${GLFW_INCLUDE_DIRS})

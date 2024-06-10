cmake_minimum_required(VERSION 3.20)
project(path_tracing)

find_package(glm REQUIRED)

add_subdirectory(lib/stb)

add_executable(main 
  src/main.cpp
  src/image2d.cpp)
target_link_libraries(main glm::glm stb_image)
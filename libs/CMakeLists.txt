cmake_minimum_required(VERSION 3.0.0)

add_library(discpp-libs deps-maker.cc)

add_subdirectory(spdlog/)
add_subdirectory(function2/)
add_subdirectory(continuable/)

target_link_libraries(discpp-libs PUBLIC spdlog function2 continuable)
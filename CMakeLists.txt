cmake_minimum_required(VERSION 3.0.0)
project(discpp VERSION 0.1.0)

file(GLOB_RECURSE DISCPP_SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(discpp ${DISCPP_SOURCES})
target_include_directories(discpp PUBLIC include/)

############################
# Add third-party libraries
############################
add_subdirectory(libs/)
target_link_libraries(discpp PUBLIC discpp-libs)

############################
# Building tests
############################
enable_testing()
add_subdirectory(tests/)
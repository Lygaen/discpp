cmake_minimum_required(VERSION 3.0.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest/)
include(GoogleTest)

function(ntest arg)
    add_executable(${arg}-test ${arg}.cpp)
    target_link_libraries(${arg}-test gtest_main discpp)
    gtest_discover_tests(${arg}-test)
endfunction()

ntest(should_succeed)

cmake_minimum_required(VERSION 3.20)

project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(raytracer_core
    src/greeting.cpp
)
target_include_directories(raytracer_core PUBLIC include)

add_executable(raytracer
    src/main.cpp
)
target_link_libraries(raytracer PRIVATE raytracer_core)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(raytracer_tests
        tests/greeting_tests.cpp
    )
    target_link_libraries(raytracer_tests PRIVATE raytracer_core Catch2::Catch2WithMain)
    add_test(NAME raytracer_tests COMMAND raytracer_tests)
endif()

cmake_minimum_required(VERSION 3.20)

project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(raytracer_core
    src/colour/colour.cpp
    src/geometry/ray.cpp
    src/geometry/sphere.cpp
    src/image/image.cpp
    src/math/vector.cpp
    src/render/camera.cpp
    src/render/trace.cpp
)
target_include_directories(raytracer_core PUBLIC include src)

add_executable(raytracer
    src/main.cpp
)
target_link_libraries(raytracer PRIVATE raytracer_core)

add_custom_target(run
    COMMAND $<TARGET_FILE:raytracer>
    DEPENDS raytracer
    USES_TERMINAL
)

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

    add_subdirectory(tests)
endif()

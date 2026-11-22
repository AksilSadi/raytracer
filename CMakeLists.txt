cmake_minimum_required(VERSION 3.20)

project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(raytracer_core
    src/colour/colour.cpp
    src/geometry/plane.cpp
    src/geometry/ray.cpp
    src/geometry/sphere.cpp
    src/image/image.cpp
    src/material/material.cpp
    src/math/vector.cpp
    src/output/png_saver.cpp
    src/render/camera.cpp
    src/render/trace.cpp
)
target_include_directories(raytracer_core PUBLIC include src)

include(FetchContent)

FetchContent_Declare(
    lodepng
    GIT_REPOSITORY https://github.com/lvandeve/lodepng.git
    GIT_TAG        7b2893e35891c0c85bee5595caafaf3c2044b409
)
FetchContent_MakeAvailable(lodepng)

add_library(lodepng STATIC ${lodepng_SOURCE_DIR}/lodepng.cpp)
target_include_directories(lodepng PUBLIC ${lodepng_SOURCE_DIR})

target_link_libraries(raytracer_core PRIVATE lodepng)

add_executable(raytracer
    src/main.cpp
)
target_link_libraries(raytracer PRIVATE raytracer_core)

add_custom_target(run
    COMMAND $<TARGET_FILE:raytracer>
    DEPENDS raytracer
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
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

add_executable(raytracer_tests
    colour/test_colour.cpp
    greeting_tests.cpp
    geometry/test_ray.cpp
    geometry/test_sphere.cpp
    math/test_vector.cpp
    render/test_camera.cpp
    test_helpers.cpp
)
target_include_directories(raytracer_tests PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}"
)
target_link_libraries(raytracer_tests PRIVATE raytracer_core Catch2::Catch2WithMain)

add_test(NAME raytracer_tests COMMAND raytracer_tests)

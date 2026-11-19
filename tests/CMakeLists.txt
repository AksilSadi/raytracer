add_executable(raytracer_tests
    greeting_tests.cpp
    math/test_vector.cpp
)
target_include_directories(raytracer_tests PRIVATE "${PROJECT_SOURCE_DIR}/src")
target_link_libraries(raytracer_tests PRIVATE raytracer_core Catch2::Catch2WithMain)

add_test(NAME raytracer_tests COMMAND raytracer_tests)

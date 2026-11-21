#include "output/png_saver.h"

#include <catch2/catch_test_macros.hpp>
#include <lodepng.h>

#include <cstdio>
#include <string>
#include <vector>

TEST_CASE("PngSaver saves the pixels from top to bottom", "[output]") {
    Image image(2, 2);
    image.setPixel(1, 0, Colour(1, 0.5, 0));

    PngSaver saver;
    const std::string path = "test_output.png";
    saver.save(image, path);

    std::vector<unsigned char> bytes;
    unsigned width = 0;
    unsigned height = 0;
    const unsigned error = lodepng::decode(bytes, width, height, path, LCT_RGB);

    REQUIRE(error == 0);
    CHECK(width == 2);
    CHECK(height == 2);

    const std::vector<int> expected = {
        0, 0, 0,
        255, 128, 0,
        0, 0, 0,
        0, 0, 0
    };
    REQUIRE(bytes.size() == expected.size());
    for (std::size_t i = 0; i < bytes.size(); ++i) {
        CHECK(static_cast<int>(bytes[i]) == expected[i]);
    }

    std::remove(path.c_str());
}

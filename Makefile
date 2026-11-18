.PHONY: build run test clean

build:
	cmake --preset default
	cmake --build --preset default

run: build
	cmake --build --preset default --target run

test: build
	ctest --preset default

clean:
	cmake -E rm -rf build

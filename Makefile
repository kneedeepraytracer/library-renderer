.PHONY: config build tests clean

config:
	conan install . --build=missing

build:
	conan build .

tests: build
	./build/Debug/tests/unit_tests --gtest_color=yes

clean:
	rm -rf ./build

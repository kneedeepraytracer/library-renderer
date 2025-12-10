.PHONY: config build tests clean

config:
	conan install . --build=missing

build:
	conan build .

tests: build
	./build/Debug/tests/unit_tests --gtest_color=yes

coverage: tests
	llvm-profdata merge -sparse default.profraw -o default.profdata
	llvm-cov report ./build/Debug/tests/unit_tests -instr-profile=default.profdata

clean:
	rm -rf ./build

// No. Only the first definition is valid.
// The second is invalid because the first + operator
// has two string literals on either side, and + can
// only concatenate std::string objects, or a std::string
// with a string literal or character literal
#include <iostream>
#include <string>

int main() {
	const std::string exclam = "!";
	const std::string message = "Hello" + ", world" + exclam;

	std::cout << message << std::endl;

	return 0;
}

// g++ output:
// ex0102.cpp: In function ‘int main()’:
// ex0102.cpp:9:40: error: invalid operands of types ‘const char [6]’ and ‘const char [8]’ to binary ‘operator+’
//   const std::string message = "Hello" + ", world" + exclam;

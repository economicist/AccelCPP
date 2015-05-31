// Yes, the following definitions are valid
// since hello is a constant string with initialization
// and message is created by concatenating strings.

// The concatenations in the second definition are okay
// because of the left-associativity of the + operator.
// The leftmost + operator has a std::string on the left
// and a string literal on the right, so its result is a
// std::string, which can then be concatenated with the
// final string literal by the second + operator, yielding
// a std::string as the final result.

#include <iostream>
#include <string>

int main() {
	const std::string hello = "Hello";
	const std::string message = hello + ", world" + "!";

	std::cout << message << std::endl;

	return 0;
}
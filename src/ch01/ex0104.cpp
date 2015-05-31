// This program is also valid since the nested
// curly braces define yet another scope in
// which a same-named const can be declared
// and initialized
#include <iostream>
#include <string>

int main() {
	{ const std::string s = "a string";
		std::cout << s << std::endl;
		{ const std::string s = "another string";
			std::cout << s << std::endl;
		}	// compiles in g++ with or without a semicolon here.
	}		// I don't understand why I'd want one, though.

	return 0;
}
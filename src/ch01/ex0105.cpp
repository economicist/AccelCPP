// This is NOT a valid program since x is declared
// within a scope and then called from outside it.

#include <iostream>
#include <string>

int main() {
	{
		std::string s = "a string"
		{
			std::string x = s + ", really";
			std::cout << s << std::endl;
		}
		std::cout << x << std::endl;
	}
	return 0;
}

// g++ output
// ex0105.cpp: In function ‘int main()’:
// ex0105.cpp:10:3: error: expected ‘,’ or ‘;’ before ‘{’ token
//    {
//    ^
// ex0105.cpp:14:16: error: ‘x’ was not declared in this scope
//    std::cout << x << std::endl;

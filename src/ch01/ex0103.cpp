// This program is valid since the same-named const objects
// are all defined in their own scopes as determined by
// separate sets of curly braces.
#include <iostream>
#include <string>

int main() {
	{ const std::string s = "a string";
	  std::cout << s << std::endl; }

	{ const std::string s = "another string"; 
	  std::cout << s << std::endl; }

	return 0;
}
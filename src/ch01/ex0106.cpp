// This program will have undesired output if we give two names
// as input to the first name request.  std::cin only passes
// input up to the first white space into the variable name,
// so if I say "Robert Roper" to the first question, "Robert"
// will be passed to name first, and then "Roper" will automatically
// be passed to name after the second request since "Roper" is
// still in the buffer.

#include <iostream>
#include <string>

int main() {
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
			  << std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
			  << "; nice to meet you too!" << std::endl;
	return 0;
}

// Sample output:
// What is your name? Robert Roper
// Hello, Robert
// And what is yours? Hello, Roper; nice to meet you too!

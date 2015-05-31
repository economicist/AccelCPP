// The following is NOT a valid program.
// The main function body is not enclosed in curly braces.
// Also, the return 0; expression is missing, but it seems
// that it is not strictly required by my compiler.
#include <iostream>
int main()	std::cout << "Hello, world!" << std::endl;

// Output from g++:
// ex0005.cpp:6:12: error: expected initializer before ‘std’
//  int main() std::cout << "Hello, world!" << std::endl;
// The following is a valid program
// but there is an excessive number of curly braces.
#include <iostream>
int main()	{{{{{{ std::cout << "Hello, world!" << std::endl; }}}}}}

// Compiles in g++ and runs as expected.
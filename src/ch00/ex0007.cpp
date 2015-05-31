// The following is not a valid program.
// The closing */ ends the freeform comment and leaves
// "as its starting and ending delimiters */" uncommented.
#include <iostream>

int main() {
	/* This is a comment that extends over several lines
		because it uses /* and */ as its starting and ending delimiters */
	std::cout << "Does this work?" << std::endl;
	return 0;
}

// g++ output:
// ex0007.cpp: In function ‘int main()’:
// ex0007.cpp:8:29: error: ‘as’ was not declared in this scope
//    because it uses /* and */ as its starting and ending delimiters */
//                              ^
// ex0007.cpp:8:32: error: expected ‘;’ before ‘its’
//    because it uses /* and */ as its starting and ending delimiters */